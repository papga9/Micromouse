// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "input_handling.h"


//uint Buffer[]

void MM::read_sensors()
{
    comp.ir_frontleft.read();
    comp.ir_frontright.read();
    comp.ir_left.read();
    comp.ir_right.read();
}

void MM::pre_process()
{
    //TODO actuall filter implementation
    vars.ir_frontleft_filt = vars.ir_frontleft_raw;
    vars.ir_frontright_filt = vars.ir_frontright_raw;
    vars.ir_left_filt = vars.ir_left_raw;
    vars.ir_right_filt = vars.ir_right_raw;
}

/*void MM::Filter::add(std::vector<int*> input, uint16_t value)
{
    //TODO
}

int MM::Filter::getValue()
{
    //TODO
    return 0;
}*/
