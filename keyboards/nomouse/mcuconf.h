#pragma once
#include_next <mcuconf.h>

// Enable ADC1 (GP26, GP27, GP28 are connected to ADC1 on RP2040)
#undef RP_ADC_USE_ADC1
#define RP_ADC_USE_ADC1 TRUE


