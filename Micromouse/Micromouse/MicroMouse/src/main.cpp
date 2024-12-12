// Micromouse course - evosoft

#include <Arduino.h>
#include <functional>
#include "utils/logging.h"
#include "utils/task.h"
#include "hal/micromouse.h"
#include "variables.h"
#include "components.h"
#include "control/controller.h"
#include "control/input_handling.h"
#include "control/output_handling.h"

using namespace std::chrono_literals;

void debug();

#ifdef BLE_LOGGING
BleSerial ble;
#endif

MM::Variables vars {};
MM::Components comp {};

MM::Task task_read_sensors   {MM::read_sensors, 50ms};
MM::Task task_pre_process    {MM::pre_process, 50ms};
MM::Task task_evaluate       {MM::evaluate, 50ms};
MM::Task task_post_process   {MM::post_process, 50ms};
MM::Task task_update_outputs {MM::update_outputs, 50ms};
MM::Task task_debug          {debug, 1000ms};


void debug() {
  
  //LOG_INFO("Hello World\n");
  // digitalWrite(DEBUG_LED_1, 1-digitalRead(DEBUG_LED_1));
  // delay(100);
  // digitalWrite(DEBUG_LED_2, 1-digitalRead(DEBUG_LED_2));
  // delay(900);

    LOG_INFO("FL:%d ,L:%d, R:%d, FR:%d \n", vars.ir_frontleft_raw,
                                         vars.ir_left_filt,
                                         vars.ir_right_raw, 
                                         vars.ir_frontright_raw);                                       

}

void setup() {
  LOGGING_BEGIN();
  LOG_INFO("Setup Done\n");
  pinMode(DEBUG_LED_1, OUTPUT);
  pinMode(DEBUG_LED_2, OUTPUT);
  
  pinMode(DEBUG_LED_3, OUTPUT);
  pinMode(DEBUG_LED_4, OUTPUT);

  vars.myTimer.begin();
}

void loop() {
  delay(500);
  task_read_sensors();
  task_pre_process();
  task_evaluate();
  task_post_process();
  task_update_outputs();
  task_debug();
}