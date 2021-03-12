//
// Created by shivan on 2/28/21.
//

#ifndef ENCODERS_MOTORS_H
#define ENCODERS_MOTORS_H

#include "Encoders.h"

#define FORWARD HIGH
#define REVERSE LOW

#define MIN_SPEED 140
#define MAX_POWER 255

namespace Motor
{

class Motor {

public:
  Motor(int dir_pin, int speed_pin, int enc_pin, int thresh);
  void TurnWheel(uint8_t dir, int power);
  void UpdateEncoder();
  float GetDistanceTurned();
  void SetDirection(uint8_t dir);

private:
  Encoders::Wheel wheel_enc_;
  uint8_t speed_pin_;
  uint8_t dir_pin_;
  uint8_t direction_;

};

}
#endif //ENCODERS_MOTORS_H
