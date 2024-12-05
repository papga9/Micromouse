// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"


void MM::evaluate()
{
    whatNow tmp = vars.goHere;
    if (vars.ir_frontleft_filt >= minimumDistance || vars.ir_frontright_filt >= minimumDistance){
        if (vars.ir_left_filt >= minimumDistance && vars.ir_right_filt >= minimumDistance){
                vars.goHere = STOP;
        } else {
            if (vars.ir_left_filt < vars.ir_right_filt) {
                vars.goHere = TURN_LEFT;
            } else {
                vars.goHere = TURN_RIGHT;
            }
        }
    } else {
                vars.goHere = GO;
    }
    vars.directionChanged = (tmp != vars.goHere);
}