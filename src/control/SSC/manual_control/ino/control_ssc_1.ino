#include <PID_v1.h>

// ========== 파라미터 선언 ==========
// 스티어링 핀 설정
#define CUR_ANG 0  // 스티어링 각도 센서 (아날로그 핀)
#define ST_DIR 7   // 스티어링 방향 핀
#define ST_PWM 6   // 스티어링 PWM 핀
#define RIGHT 1    // 우회전 방향값
#define LEFT 0     // 좌회전 방향값

// 모터 핀 설정
#define MT_DIR 4   // 모터 방향 핀
#define MT_PWM 5   // 모터 PWM 핀
#define FORWARD 0  // 전진 방향값
#define BACK 1     // 후진 방향값
#define MT_A 2     // 엔코더 A상
#define MT_B 3     // 엔코더 B상

// 모터 PID 게인값
double KpDC = 0.3;  // P 게인 (비례)
double KiDC = 1.0;  // I 게인 (적분)
double KdDC = 0.1;  // D 게인 (미분)

// 스티어링 PID 게인값  
double KpST = 3.0;  // P 게인 (비례제어만 사용)
double KiST = 0.0;  // I 게인 (미사용)
double KdST = 0.0;  // D 게인 (미사용)

// 엔코더 설정
const int PPR = 144;                    // 모터 1회전당 펄스 수
const int MEASURE_INTERVAL = 100;       // RPM 측정 주기 (ms)
const float RPM_CALC_FACTOR = 4.167;    // RPM 계산 상수 (600/144)

// lowpassfilter
float alpha = 0.2;  // 필터 계수 (0.2 = 20% 새값 + 80% 이전값)

// 시리얼 통신 설정
const long SERIAL_BAUD = 115200;
const int SERIAL_SEND_INTERVAL = 100; // 전송주기 (ms)

// PWM 출력 제한값

// Arduino analogWrite() 범위: 0 ~ 255

const int MOTOR_PWM_MAX = 190; // 모터 rpm duty cycle = (MOTOR_PWM_MAX / 255) × 100
const int STEER_PWM_MAX = 115; // 스티어링 duty cycle = (STEER_PWM_MAX / 255) × 100

// ========== 전역 변수 ==========
// PID 제어 변수
double motor_target = 0;    // motor target RPM
double current_rpm = 0;     // current RPM
double motorPwmOutput = 0;  // motor PWM output
double steer_target = 512;  // steering target (0~1024, 512=중앙)
double current_val = 512;   // current steering
double steerPwmOutput = 0;  // steering PWM output

// PID 객체
PID PIDDC(&current_rpm, &motorPwmOutput, &motor_target, KpDC, KiDC, KdDC, DIRECT);
PID PIDST(&current_val, &steerPwmOutput, &steer_target, KpST, KiST, KdST, DIRECT);

// 엔코더 카운트
volatile int pulseCount = 0;     // 펄스 카운트
unsigned long lastMeasurement = 0;  // 마지막 측정 시간

// 방향 및 정지 제어
int Direction = 0;       // 현재 회전 방향 (1=전진, -1=후진)
int lastDirection = 0;   // 마지막 명령 방향
int stopPID = 0;        // PID 정지 모드 (0=정상, 1=정지중)
int realStop = 0;       // 완전 정지 플래그

// 필터 변수
float filteredRPM = 0;   // 필터링된 RPM 저장

// 스티어링 입력값
int steer_input = 0;     // 스티어링 명령값 (-25 ~ 25)

// 시리얼 통신 변수
String inputString = "";         // 수신 버퍼
boolean stringComplete = false;   // 수신 완료 플래그
unsigned long lastSerialSend = 0;  // 마지막 전송 시간

void onAChange() {
  static int lastState = LOW;
  int currentState = digitalRead(MT_A);
  if (currentState != lastState) { 
    int stateB = digitalRead(MT_B);
    if (currentState == stateB) {
      Direction = 1;    // 시계방향
    } else {
      Direction = -1;   // 반시계방향
    }
    pulseCount++;
    lastState = currentState;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  
  // pin mode
  pinMode(ST_DIR, OUTPUT);
  pinMode(MT_DIR, OUTPUT);
  pinMode(MT_A, INPUT_PULLUP);
  pinMode(MT_B, INPUT_PULLUP);

  digitalWrite(MT_DIR, FORWARD);
  analogWrite(MT_PWM, 0);
  
  // PID 설정
  PIDDC.SetOutputLimits(0, MOTOR_PWM_MAX);
  PIDDC.SetMode(AUTOMATIC);
  PIDST.SetOutputLimits(-STEER_PWM_MAX, STEER_PWM_MAX);
  PIDST.SetMode(AUTOMATIC);
  
  // 엔코더 인터럽트 연결
  attachInterrupt(digitalPinToInterrupt(MT_A), onAChange, CHANGE);
  
  // 시리얼 버퍼
  inputString.reserve(200);
}


void loop() {
  unsigned long currentMillis = millis();
  
  // rpm 측정 및 pid 게산 (100ms)
  if (currentMillis - lastMeasurement >= MEASURE_INTERVAL) {
    noInterrupts();
    int pulses = pulseCount;
    pulseCount = 0;
    interrupts();
    lastMeasurement = currentMillis;
    
    // RPM = (pulses × 600ms) / 144
    float raw_rpm = pulses * RPM_CALC_FACTOR;
    
    // low pass filter = 20%(new data) + 80% (prev data)
    filteredRPM = alpha * raw_rpm + (1 - alpha) * filteredRPM;
    current_rpm = filteredRPM;
  }
  
  // PID 계산
  PIDDC.Compute();
  
  if (stringComplete) {
    inputString.trim();
    
    // 스티어링 명령: S:-25 ~ S:25
    if (inputString.startsWith("S:")) {
      steer_input = inputString.substring(2).toInt();
    }
    // 모터 명령: M:0100(전진100rpm), M:1100(후진100rpm), M:2000(정지)
    else if (inputString.startsWith("M:")) {
      int dir_val = inputString.substring(2).toInt();
      int inst = dir_val / 1000;  // 명령 종류
      int val = dir_val % 1000;   // 속도값
      
      realStop = 0;
      
      if(inst == 4) {  // 강제 정지
        digitalWrite(MT_DIR, FORWARD);
        motor_target = 0;
        stopPID = 0;
        realStop = 1;
      }
      else if(inst == 0) {  // 전진
        digitalWrite(MT_DIR, FORWARD);
        motor_target = val;
        lastDirection = 1;
        stopPID = 0;
      }
      else if(inst == 1) {  // 후진
        digitalWrite(MT_DIR, BACK);
        motor_target = val;
        lastDirection = -1;
        stopPID = 0;
      }
      else if(inst == 2) {  // 부드러운 정지
        if(lastDirection != Direction && stopPID == 0){
          // 역방향 제동 시작
          digitalWrite(MT_DIR, (Direction == 1) ? FORWARD : BACK);
          stopPID = 1;
          motor_target = 0;
        }
        else if(stopPID == 1){
          // 정지 과정 모니터링
          current_rpm = current_rpm * Direction;
          if(lastDirection == 1 && current_rpm < 0){
            digitalWrite(MT_DIR, FORWARD);
            motor_target = 0;
          }
          else if(lastDirection == -1 && current_rpm > 0){
            digitalWrite(MT_DIR, BACK);
            current_rpm = current_rpm * -1;
            motor_target = 0;
          }
          else{
            digitalWrite(MT_DIR, FORWARD);
            motor_target = 0;
            realStop = 1;
          }
        }
        else{
          digitalWrite(MT_DIR, (lastDirection == 1) ? FORWARD : BACK);
          motor_target = 0;
        }
      }
      else{  // 기본값: 전진
        digitalWrite(MT_DIR, FORWARD);
        lastDirection = 1;
        motor_target = val;
        stopPID = 0;
      }
    }
    
    inputString = "";
    stringComplete = false;
  }
  
  // ===== 스티어링 제어 =====
  // 입력값(-25~25)을 ADC값(0~1024)으로 변환
  steer_target = map((-1 * steer_input), -25, 25, 0, 1024);
  current_val = analogRead(CUR_ANG);
  PIDST.Compute();
  
  // 스티어링 모터 구동
  if (steer_target > current_val) {
    digitalWrite(ST_DIR, LEFT);
    analogWrite(ST_PWM, abs(steerPwmOutput));
  } else if (steer_target < current_val) {
    digitalWrite(ST_DIR, RIGHT);
    analogWrite(ST_PWM, abs(steerPwmOutput));
  } else {
    analogWrite(ST_PWM, 0);
  }
  
  // ===== 모터 제어 =====
  if(realStop == 1){
    analogWrite(MT_PWM, 0);  // 완전 정지
  }
  else{
    analogWrite(MT_PWM, motorPwmOutput);  // PID 출력
  }
  
  // ===== 시리얼 데이터 전송 (100ms마다) =====
  if (currentMillis - lastSerialSend >= SERIAL_SEND_INTERVAL) {
    lastSerialSend = currentMillis;
    
    // 전송 형식: ST:값,RPM:값,DIR:값,PWM:값
    Serial.print("ST:");
    Serial.print(analogRead(CUR_ANG));
    Serial.print(",RPM:");
    Serial.print(int(current_rpm));
    Serial.print(",DIR:");
    Serial.print(Direction);
    Serial.print(",PWM:");
    Serial.println(int(motorPwmOutput));
  }
}