class pidController:  ## 속도 제어를 위한 PID 적용 ##
    def __init__(self, p=1.0, i=1.0, d=1.0, rate=30):
        self.base_p_gain = p
        self.p_gain = p
        self.base_d_gain = d
        self.d_gain = d
        self.i_gain = i
        self.controlTime = 1/rate
        self.prev_error = 0
        self.i_control = 0

    def update_gains(self, error):
        # 오차에 따른 비례 및 미분 이득의 동적 조정
        if abs(error) > 10:
            self.p_gain = self.base_p_gain * 1.5  # 오차가 크면 P 이득 증가
            self.d_gain = self.base_d_gain * 1.2  # D 이득도 약간 증가
        elif abs(error) > 5:
            self.p_gain = self.base_p_gain * 1.2  # 중간 범위 오차에서는 P 이득을 약간 증가
            self.d_gain = self.base_d_gain       # D 이득은 기본값 유지
        else:
            self.p_gain = self.base_p_gain       # 오차가 작으면 기본 이득 사용
            self.d_gain = self.base_d_gain * 0.8 # 미세 조정에 더 섬세한 D 이득 사용

    def pid_1(self, target_vel, current_vel):
        error = target_vel - current_vel
        print(target_vel, current_vel)
        # 비례 및 미분 이득 업데이트
        self.update_gains(error)

        p_control = self.p_gain * error
        self.i_control += self.i_gain * error * self.controlTime
        d_control = self.d_gain * (error - self.prev_error) / self.controlTime

        output = p_control + self.i_control + d_control
        self.prev_error = error
        return output