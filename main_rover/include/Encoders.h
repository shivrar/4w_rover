//
// Created by shivan on 1/21/21.
//

#ifndef ENCODERS_ENCODERS_H
#define ENCODERS_ENCODERS_H

#include <Arduino.h>

namespace Encoders {

class Wheel {
public:
  Wheel(uint8_t out, uint16_t thresh);

  float GetDistanceTurned() const;

  void Update(bool direction);

  int ReadRaw() const;

  int GetDiff();

private:
  uint8_t out_pin;
  int last_val;
  int thresh;
  int rotations;

};
}

#endif //ENCODERS_ENCODERS_H
