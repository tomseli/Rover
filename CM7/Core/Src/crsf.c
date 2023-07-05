/*
 * crsf.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Tom
 */
#include "csrf.h"

// incoming message has format [dest] [len] [type] [payload] [crc8]

void CsrfDecode(uint8_t* ext_buf)
{
	// copy over a buf to avoid change of DMA buf
	uint8_t buf[CRSF_MAX_PAYLOAD];
	memcpy(buf, ext_buf, CRSF_MAX_PAYLOAD);

	//TODO: CRC check


	// call function per packet type
	UartInt(buf[2]);
	UartChar('\n');

	switch(buf[2])
	{
	case 0x16:
		HAL_GPIO_TogglePin(LED_Yellow_GPIO_Port, LED_Yellow_Pin);
		break;
	default:
		break;
	}
}

