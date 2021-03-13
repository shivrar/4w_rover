//
// Created by shivan on 1/21/21.
//
#include "Arduino.h"
#include "Encoders.h"

namespace Encoders{

  Wheel::Wheel(uint8_t out, uint16_t thresh):
  out_pin(out),
  last_val(ReadRaw()),
  thresh(thresh),
  rotations(0){

  }

  int  Wheel::ReadRaw() const {
    return analogRead(out_pin);
  }

  void Wheel::Update(bool direction) {
    if(abs(last_val - ReadRaw()) > thresh)
    {
      direction ? rotations++ : rotations--;
      last_val = ReadRaw();
    }
  }

  float Wheel::GetDistanceTurned() const {
    return static_cast<float>(rotations)/(16.0);
  }

  int Wheel::GetDiff() {
    return ReadRaw() - last_val;
  }

}