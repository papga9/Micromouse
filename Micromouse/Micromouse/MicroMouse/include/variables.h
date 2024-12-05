// Micromouse course - evosoft
#pragma once

#include <cstdint>
#include <Arduino_Helpers.h>
#include <AH/Timing/MillisMicrosTimer.hpp>

namespace MM {

enum whatNow {
    GO          = 1,
    STOP        = 2,
    TURN_RIGHT  = 3,
    TURN_LEFT   = 4
};

struct Variables {
// Inputs =================================================
    uint16_t ir_left_raw;
    uint16_t ir_frontleft_raw;
    uint16_t ir_frontright_raw;
    uint16_t ir_right_raw;

    uint16_t ir_left_filt;
    uint16_t ir_frontleft_filt;
    uint16_t ir_frontright_filt;
    uint16_t ir_right_filt;

    uint32_t encoder_left_raw;
    uint32_t encoder_right_raw;

// Internals ==============================================
    whatNow goHere;
    bool directionChanged;
    Timer<millis> myTimer = TRANSIENT_TIMER;
    
// Motor direction change transient time
    const int TRANSIENT_TIMER = 200;

// Outputs ================================================
    bool ir_en_left =true;
    bool ir_en_frontleft = true;
    bool ir_en_frontright = true;
    bool ir_en_right = true;

    int16_t motor_left;
    int16_t motor_right;
    bool    motor_brake;
};

} // namespace MM

extern MM::Variables vars;