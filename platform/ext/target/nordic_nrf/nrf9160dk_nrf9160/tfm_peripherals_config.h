/*
 * Copyright (c) 2021, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef TFM_PERIPHERALS_CONFIG_H__
#define TFM_PERIPHERALS_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SECURE_UART1
#if NRF_SECURE_UART_INSTANCE == 0
#define TFM_PERIPHERAL_UARTE0_SECURE 1
#elif NRF_SECURE_UART_INSTANCE == 1
#define TFM_PERIPHERAL_UARTE1_SECURE 1
#endif
#endif

#if TEST_NS_SLIH_IRQ || TEST_NS_FLIH_IRQ
#define TFM_PERIPHERAL_TIMER0_SECURE 1
#endif

#ifdef PSA_API_TEST_IPC
#define TFM_PERIPHERAL_EGU5_SECURE 1

#define TFM_PERIPHERAL_WDT_SECURE 1
#endif

#if defined(NRF5340_XXAA_APPLICATION)
    #include <tfm_peripherals_config_nrf5340_application.h>
#elif defined(NRF9160_XXAA)
    #include <tfm_peripherals_config_nrf9160.h>
#else
    #error "Unknown device."
#endif

#ifdef __cplusplus
}
#endif

#endif /* TFM_PERIPHERAL_CONFIG_H__ */
