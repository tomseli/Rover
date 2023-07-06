/*
 * crsf.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Tom
 */
#include "csrf.h"

extern PwmRcChannels_t rc_pwm_raw;

// incoming message has format [dest] [len] [type] [payload] [crc8]

void CsrfDecode(uint8_t* ext_buf)
{
	// copy over a buf to avoid change of DMA buf
	uint8_t buf[CRSF_MAX_FRAME];
	uint8_t payload[CRSF_MAX_PAYLOAD];
	CsrfRcChannels_t data;
	memcpy(buf, ext_buf, CRSF_MAX_FRAME);

	//TODO: CRC check

	// copy payload to a seperate buffer
	for(int i = 0; i < CRSF_MAX_PAYLOAD; i++)
		payload[i] = buf[i + 3];

	switch(buf[2])
	{
	// link statistics
	case 0x14:
		break;

	// RC channels
	case 0x16:
		CsrfLinkStatistics(payload, data);
		break;

	// Device ping
	case 0x28:
		break;

	// Device info
	case 0x29:
		break;

	// Parameter settings entry
	case 0x2B:
		break;

	// Parameter read
	case 0x2C:
		break;

	// Parameter write
	case 0x2D:
		break;

	// Command
	case 0x32:
		break;

	default:
		break;
	}
}

void CsrfLinkStatistics(uint8_t* buf, CsrfRcChannels_t* data)
{
	for(int i = 0; i < CRSF_MAX_PAYLOAD; i++)
		data->payload[i] = buf[i];

	CsrfToPwm(data);
}

void CsrfToPwm(CsrfRcChannels_t* data)
{
	// (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	rc_pwm_raw.ch00 = (data->channels.ch00 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch01 = (data->channels.ch01 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch02 = (data->channels.ch02 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch03 = (data->channels.ch03 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch04 = (data->channels.ch04 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch05 = (data->channels.ch05 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch06 = (data->channels.ch06 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch07 = (data->channels.ch07 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch08 = (data->channels.ch08 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch09 = (data->channels.ch09 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch11 = (data->channels.ch11 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch10 = (data->channels.ch10 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch12 = (data->channels.ch12 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch13 = (data->channels.ch13 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch14 = (data->channels.ch14 - 172) * 1024 / 1639 + 988;
	rc_pwm_raw.ch15 = (data->channels.ch15 - 172) * 1024 / 1639 + 988;
}

