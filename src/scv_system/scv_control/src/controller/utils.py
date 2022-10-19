class pidController:  ## 속도 제어를 위한 PID 적용 ##
    def __init__(self, p=1.0, i=1.0, d=1.0, rate=30):
        self.p_gain = p
        self.i_gain = i
        self.d_gain = d
        self.controlTime = 1/rate
        self.prev_error = 0
        self.i_control = 0

    def pid(self, target_vel, current_vel):
        error = target_vel - current_vel.x

        p_control = self.p_gain * error
        self.i_control += self.i_gain * error
        d_control = self.d_gain * (error - self.prev_error)

        output = p_control + self.i_control + d_control
        self.prev_error = error
        return output

    def pid_1(self, target_vel, current_vel):
        error = target_vel - current_vel.x

        p_control = self.p_gain * error
        self.i_control += self.i_gain * error * self.controlTime
        d_control = self.d_gain * (error - self.prev_error) / self.controlTime

        output = p_control + self.i_control + d_control
        self.prev_error = error
        return output