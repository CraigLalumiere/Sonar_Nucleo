#ifndef PUBSUB_SIGNALS_H_
#define PUBSUB_SIGNALS_H_

#include "fault_manager.h"
#include "qpc.h"
#include <stddef.h>

enum PubSubSignals
{
    PUBSUB_FIRST_SIG = Q_USER_SIG,
    PUBSUB_FAULT_GENERATED_SIG,
    PUBSUB_SAMPLE_TEMP_PWR_SIG,
    PUBSUB_ADC2_COMPLETE_SIG,
    PUBSUB_WATER_TEMP_SIG,
    PUBSUB_XDCR_PWR_SIG,
    PUBSUB_TRANSMITTER_CHARGE_SIG,
    PUBSUB_ECHO_BEGIN_SIG,
    PUBSUB_RECEIVE_COMPLETE_SIG,
    PUBSUB_MAX_SIG
};

typedef struct
{
    QEvt super;
    float value;
} FloatEvent_T;

typedef struct
{
    QEvt super;
    int16_t value;
} Int16Event_T;

typedef struct
{
    QEvt super;
    uint16_t raw;
    float value;
} ADCEvent_T;

typedef struct
{
    QEvt super;

    Fault_ID_T id;
    Fault_Type_T type;
    uint16_t code;
    char msg[FAULT_GEN_EVENT_MAX_MSG_LENGTH];
} FaultGeneratedEvent_T;

#endif // PUBSUB_SIGNALS_H_
