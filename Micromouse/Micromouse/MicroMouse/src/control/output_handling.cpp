// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "output_handling.h"
#include "Arduino.h"

//This is for testing  TODO delete

void MM::turnLedOff(){
    digitalWrite(DEBUG_LED_1, LOW);
    digitalWrite(DEBUG_LED_2, LOW);
    digitalWrite(DEBUG_LED_3, LOW);
    digitalWrite(DEBUG_LED_4, LOW);
}

void MM::setMotorTo(MX1508 motor, int8_t value){
    if (!vars.directionChanged){
        motor.motorGoP(value);
    } else {
        if(vars.myTimer){
            motor.motorGoP(value);
            vars.myTimer.begin();
        }
    }
}

void MM::post_process()
{
    /* Write your code here */
}

void MM::update_outputs()
{
    /* Write your code here */


    /*switch (vars.goHere){
        case GO:
             comp.motor_left.motorGoP(10);
             comp.motor_right.motorGoP(10);
        break;

        case TURN_LEFT:
            comp.motor_left.motorGoP(10);
            comp.motor_right.motorGoP(-10);
        break;

        case TURN_RIGHT:
            comp.motor_left.motorGoP(-10);
            comp.motor_right.motorGoP(10);
        break;

        case STOP:
            comp.motor_left.motorStop();
            comp.motor_right.motorStop();
        break;

        default:
            comp.motor_left.motorStop();
            comp.motor_right.motorStop();
        break;
    }
    */

///This is for testing  TODO delete
   switch (vars.goHere){
        case GO:
             turnLedOff();
        break;

        case TURN_LEFT:
            turnLedOff();
             digitalWrite(DEBUG_LED_1, HIGH);
        break;

        case TURN_RIGHT:
            turnLedOff();
             digitalWrite(DEBUG_LED_2, HIGH);
        break;

        case STOP:
            turnLedOff();
             digitalWrite(DEBUG_LED_2, HIGH);
             digitalWrite(DEBUG_LED_1, HIGH);
        break;

        default:
            
        break;
    }

    LOG_INFO("GOmode: %d", vars.goHere);
    
}