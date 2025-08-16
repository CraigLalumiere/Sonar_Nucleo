#ifndef HVPOT_H_
#define HVPOT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t HVPot_CalcRegisterValue(uint16_t voltage);

#ifdef __cplusplus
}
#endif

#endif // HVPOT_H_
