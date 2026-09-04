/* Derived from HW_LILYGO2CAN*/

#ifndef __HW_CHADEMOBOX_H__
#define __HW_CHADEMOBOX_H__

#include "hal.h"
#include "../utils/types.h"

class ChademoBOXHal : public Esp32Hal {
 public:
	const char* name() { return "ChademoBOX"; }

	virtual gpio_num_t CAN_TX_PIN() { return GPIO_NUM_20; }
	virtual gpio_num_t CAN_RX_PIN() { return GPIO_NUM_19; }

	virtual gpio_num_t RS485_DE_PIN() { return GPIO_NUM_NC; }
	virtual gpio_num_t RS485_TX_PIN() { return GPIO_NUM_1; }
	virtual gpio_num_t RS485_RX_PIN() { return GPIO_NUM_0; }

	// CHAdeMO support pin dependencies
	virtual gpio_num_t CHADEMO_PIN_2() { return GPIO_NUM_3; }
	virtual gpio_num_t CHADEMO_PIN_10() { return GPIO_NUM_2; }
	virtual gpio_num_t CHADEMO_PIN_7() { return GPIO_NUM_NC; }
	virtual gpio_num_t CHADEMO_PIN_4() { return GPIO_NUM_4; }
	virtual gpio_num_t CHADEMO_LOCK() { return GPIO_NUM_NC; }
	virtual gpio_num_t CHADEMO_CT_PIN() { return GPIO_NUM_5; }

	// Contactor handling
	virtual gpio_num_t POSITIVE_CONTACTOR_PIN() { return GPIO_NUM_NC; }
	virtual gpio_num_t NEGATIVE_CONTACTOR_PIN() { return GPIO_NUM_NC; }
	virtual gpio_num_t PRECHARGE_PIN() { return GPIO_NUM_NC; }

	// LED
	virtual gpio_num_t LED_PIN() { return GPIO_NUM_35; }
	virtual uint8_t LED_MAX_BRIGHTNESS() { return 40; }

	// i2c display
	virtual gpio_num_t DISPLAY_SDA_PIN() {
	return GPIO_NUM_NC;
	}
	virtual gpio_num_t DISPLAY_SCL_PIN() {
	return GPIO_NUM_NC;
	}

	std::vector<comm_interface> available_interfaces() {
		return {comm_interface::Modbus, comm_interface::RS485, comm_interface::CanNative};
	}

	virtual const char* name_for_comm_interface(comm_interface comm) {
		switch (comm) {
			case comm_interface::CanNative:
				return "CAN A (Native)";
			case comm_interface::CanFdNative:
				return "";
			case comm_interface::CanAddonMcp2515:
				return "CAN A (MCP2515)";
			case comm_interface::CanFdAddonMcp2518:
				return "CAN FD (MCP2518 add-on)";
			case comm_interface::CanFdAddonMcp2518_2:
				return "CAN FD (MCP2518 add-on)";
			case comm_interface::Modbus:
				return "Modbus (Add-on)";
			case comm_interface::RS485:
				return "RS485 (Add-on)";
			case comm_interface::Highest:
				return "";
			default:
				return Esp32Hal::name_for_comm_interface(comm);
		}
	}
};

#define HalClass ChademoBOXHal

/* ----- Error checks below, don't change (can't be moved to separate file) ----- */
#ifndef HW_CONFIGURED
#define HW_CONFIGURED
#else
#error Multiple HW defined! Please select a single HW
#endif

#endif
