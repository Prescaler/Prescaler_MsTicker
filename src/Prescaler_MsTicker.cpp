#include "Prescaler_MsTicker.h"


bool Prescaler_MsTicker::begin(uint32_t _t) {
  _millisBegin = _t;
  return (bool) _millisBegin;
}
bool Prescaler_MsTicker::setInterval(uint32_t _dt) {
  _interval = _dt;
  return (bool) _interval;
}
uint32_t Prescaler_MsTicker::getInterval() {
  return _interval;
}
uint8_t Prescaler_MsTicker::update() {
  decStatus();
  while ((_status < 0xff) && (millis() > _millisNew)) {
    _status++;
    _millisNew += _interval;
  }
  return _status;
}
bool Prescaler_MsTicker::setStatus(uint8_t _s) {
  if (_status < 0xff) _status++;
  return (bool) _status;
}
uint8_t Prescaler_MsTicker::getStatus() {
  return _status;
}
bool Prescaler_MsTicker::clearStatus() {
  _status = 0;
  return (bool) _status;
}
bool Prescaler_MsTicker::incStatus() {
  return (bool) _status;
}
bool Prescaler_MsTicker::decStatus() {
  if (_status > 0) _status--;
  return (bool) _status;
}
