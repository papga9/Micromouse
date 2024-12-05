// Micromouse course - evosoft
#pragma once

#include <Arduino_Helpers.h>
#include <AH/Timing/MillisMicrosTimer.hpp>

namespace MM {

class Variables;

void setMotorTo(MX1508 motor ,int8_t value);

void post_process();
void update_outputs();

//This is for testing  TODO delete
void turnLedOff();


} // namespace MM