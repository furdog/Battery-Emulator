#ifndef __HW_BATTBOXH1_H__
#define __HW_BATTBOXH1_H__

#include "hal.h"

#include "../utils/types.h"

class BattBOXHal : public Esp32Hal {
 public:
  const char* name() { return "Batt BOX (hw:1)"; }

  virtual gpio_num_t CAN_TX_PIN() { return GPIO_NUM_4; }
  virtual gpio_num_t CAN_RX_PIN() { return GPIO_NUM_16; }

  // CAN_ADDON
  // SCK input of MCP2515
  virtual gpio_num_t MCP2515_SCK() { return GPIO_NUM_18; }
  // SDI input of MCP2515
  virtual gpio_num_t MCP2515_MOSI() { return GPIO_NUM_23; }
  // SDO output of MCP2515
  virtual gpio_num_t MCP2515_MISO() { return GPIO_NUM_19; }
  // CS input of MCP2515
  virtual gpio_num_t MCP2515_CS() { return GPIO_NUM_17; }
  // INT output of MCP2515
  //virtual gpio_num_t MCP2515_INT() { return GPIO_NUM_35; }

  // LED
  virtual gpio_num_t LED_PIN() { return GPIO_NUM_2; }
  //virtual gpio_num_t LED_PIN() { return GPIO_NUM_15; }

  // i2c display
  virtual gpio_num_t DISPLAY_SCL_PIN() { return GPIO_NUM_22; }
  virtual gpio_num_t DISPLAY_SDA_PIN() { return GPIO_NUM_21; }

  // Contactor handling
  virtual gpio_num_t POSITIVE_CONTACTOR_PIN() { return GPIO_NUM_25; } //kn2
  virtual gpio_num_t NEGATIVE_CONTACTOR_PIN() { return GPIO_NUM_27; }
  virtual gpio_num_t PRECHARGE_PIN() { return GPIO_NUM_26; } //kn1

  std::vector<comm_interface> available_interfaces() {
    return {comm_interface::CanNative, comm_interface::CanAddonMcp2515};
  }

  virtual const char* name_for_comm_interface(comm_interface comm) {
    switch (comm) {
      case comm_interface::CanNative:
        return "CAN (Native)";
      case comm_interface::CanFdNative:
        return "";
      case comm_interface::CanAddonMcp2515:
        return "CAN (MCP2515 add-on)";
      case comm_interface::CanFdAddonMcp2518:
        return "CAN FD (MCP2518 add-on)";
      case comm_interface::Modbus:
        return "Modbus";
      case comm_interface::RS485:
        return "RS485";
      case comm_interface::Highest:
        return "";
    }
    return Esp32Hal::name_for_comm_interface(comm);
  }
};

#define HalClass BattBOXHal

/* ----- Error checks below, don't change (can't be moved to separate file) ----- */
#ifndef HW_CONFIGURED
#define HW_CONFIGURED
#else
#error Multiple HW defined! Please select a single HW
#endif

#endif
