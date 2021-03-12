//
// Created by shivan on 2/28/21.
//
#include "Arduino.h"
#include "Motors.h"

namespace Motor
{
  Motor::Motor(int dir_pin, int speed_pin , int enc_pin, int thresh):
  wheel_enc_(enc_pin,thresh),
  speed_pin_(speed_pin),
  dir_pin_(dir_pin){
    pinMode(dir_pin_, OUTPUT);
  }

  void Motor::TurnWheel(uint8_t dir, int power) {
    direction_ = dir;
    analogWrite (speed_pin_,power);
    digitalWrite(dir_pin_,dir);
  }
void Motor::SetDirection(uint8_t dir) {direction_ = dir;}

  void Motor::UpdateEncoder() {
    //Should be called in a timed loop
    wheel_enc_.Update(static_cast<bool>(this->direction_));
  }

  float Motor::GetDistanceTurned() {
    return wheel_enc_.GetDistanceTurned();
  }
}