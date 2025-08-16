#include "hvpot.h"
#include "qsafe.h"
#include "stdbool.h"

Q_DEFINE_THIS_MODULE("hvpot");

#define AD5160_resolution        256
#define MAX1771_Vref             ((float) 1.5)
#define HV_supply_R_upper        ((float) 1500)  // kilo ohms
#define HV_supply_R_lower        ((float) 6.2)   // kilo ohms
#define HV_dpot_full_scale       ((float) 50)    // kilo ohms
#define HV_dpot_wiper_resistance ((float) 0.060) // kilo ohms

uint8_t HVPot_CalcRegisterValue(uint16_t voltage)
{
    Q_ASSERT(voltage > 0);

    // Desired DPOT resistance in kΩ
    float dpot_resistance = HV_supply_R_upper * MAX1771_Vref / (voltage - MAX1771_Vref) -
        HV_supply_R_lower - HV_dpot_wiper_resistance;

    Q_ASSERT(dpot_resistance > 0);

    uint16_t dpot_setting = dpot_resistance / HV_dpot_full_scale * AD5160_resolution;

    // Limit setting to 255 as this is the max value that can be sent
    if (dpot_setting > 255)
    {
        dpot_setting = 255;
    }

    return (uint8_t) dpot_setting;
}
