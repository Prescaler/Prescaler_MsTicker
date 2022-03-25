#ifndef Prescaler_MsTicker_h
#define Prescaler_MsTicker_h

#include <Arduino.h>

class Prescaler_MsTicker {
  public:
    bool begin(uint32_t _t);
    bool setInterval(uint32_t _dt);
    uint32_t getInterval();
    uint8_t update();
    bool setStatus(uint8_t _s);
    uint8_t getStatus();
    bool clearStatus();
    bool incStatus();
    bool decStatus();
  private:
    uint8_t _status = 0;
    uint32_t _interval = 0;
    uint32_t _millisNew = 0;
    uint32_t _millisBegin = 0;
};
#endif
