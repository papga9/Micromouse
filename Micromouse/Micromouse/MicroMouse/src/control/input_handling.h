// Micromouse course - evosoft
#pragma once
#include <vector>
#include "Filters/IIRFilter.hpp"
#include "Filters/Notch.hpp"
#include <AH/Timing/MillisMicrosTimer.hpp>

namespace MM {
class Variables;



/*struct Filter{
    std::vector<int> window_felt;
    std::vector<int> window_front_left;
    std::vector<int> window_right;
    std::vector<int> window_front_right;

    void add(std::vector<int*> input, uint16_t value);
    int getValue();

    
};*/

void read_sensors();
void pre_process();

} // namespace MM