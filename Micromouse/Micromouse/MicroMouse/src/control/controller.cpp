// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"
#include <PID_v1.h>

PID myPID(&vars.Input,&vars.Output,&vars.Setpoint,vars.Kp,vars.Ki, vars.Kd,DIRECT);
bool jo =true;


void MM::evaluate()
{
    if (jo)
    {
        myPID.SetMode(AUTOMATIC);
        myPID.SetSampleTime(50); 
        myPID.SetOutputLimits(-50,50);
        vars.Setpoint=vars.Input;
        jo = false;
    }
    


    whatNow tmp = vars.goHere;
    if (vars.ir_frontleft_filt >= minimumDistance || vars.ir_frontright_filt >= minimumDistance){
        if (vars.ir_left_filt >= minimumDistance && vars.ir_right_filt >= minimumDistance){
                vars.goHere = STOP;
        } else {
            if (vars.ir_left_filt < vars.ir_right_filt) {
                vars.goHere = TURN_LEFT;
                myPID.SetTunings(0.03,0,0);
            } else {
                vars.goHere = TURN_RIGHT;
                myPID.SetTunings(0.03,0,0);
            }
        }
    } else {
                vars.goHere = GO;
                myPID.SetTunings(0.0003,0,0);
    }
    myPID.Compute();
    vars.directionChanged = (tmp != vars.goHere);
}