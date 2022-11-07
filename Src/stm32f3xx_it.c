/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "can_as.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */
extern volatile uint32_t _20ms;
extern volatile uint32_t _500ms;
extern data_t data;
extern output_t serwa;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	static uint32_t TIMER_500ms, TIMER_20ms;

	  if(++TIMER_500ms>=500)
	  {
		  TIMER_500ms=0;
		  _500ms=1;
	  }
	  if(++TIMER_20ms>=20)
	    {
	  	  TIMER_20ms=0;
	  	  _20ms=1;
	    }
  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void USB_LP_CAN_RX0_IRQHandler(void)
{
   data_t *pdata = &data;
   can_message_t can_rx;

   if((CAN->RF0R & CAN_RF0R_FMP0) != 0)
   {
      can_receive(CAN_FIFO_0, &can_rx);

      switch(can_rx.can_id)
      {
         case(CAN_AS_ID_AX):   pdata->ax = can_rx.data.f;   break;
         case(CAN_AS_ID_AY):   pdata->ay = can_rx.data.f;   break;
         case(CAN_AS_ID_AZ):   pdata->az = can_rx.data.f;   break;
         case(CAN_AS_ID_Q):    pdata->gx = can_rx.data.f;   break;
         case(CAN_AS_ID_P):    pdata->gy = can_rx.data.f;   break;
         case(CAN_AS_ID_R):    pdata->gz = can_rx.data.f;   break;
         case(CAN_AS_ID_MX):   pdata->mx = can_rx.data.f;   break;
         case(CAN_AS_ID_MY):   pdata->my = can_rx.data.f;   break;
         case(CAN_AS_ID_MZ):   pdata->mz = can_rx.data.f;   break;
         case(CAN_AS_ID_TETA): pdata->teta = can_rx.data.f; break;
         case(CAN_AS_ID_FI):   pdata->fi = can_rx.data.f;   break;
         case(CAN_AS_ID_PSI):  pdata->psi = can_rx.data.f;  break;

         case(CAN_AS_ID_VS):       pdata->vs = can_rx.data.f;       break;
         case(CAN_AS_ID_IAS):      pdata->ias = can_rx.data.f;      break;
         case(CAN_AS_ID_TAS):      pdata->tas = can_rx.data.f;      break;
         case(CAN_AS_ID_BARO_ALT): pdata->baro_alt = can_rx.data.f; break;
         case(CAN_AS_ID_STD_ALT):  pdata->std_alt = can_rx.data.f;  break;
         case(CAN_AS_ID_PD):       pdata->pd = can_rx.data.f;       break;
         case(CAN_AS_ID_PS):       pdata->ps = can_rx.data.f;       break;
         case(CAN_AS_ID_TRUE_ALT): pdata->true_alt = can_rx.data.f; break;

         case(CAN_AS_ID_GPS_LAT):        pdata->gps_lat = can_rx.data.f;  break;
         case(CAN_AS_ID_GPS_LONG):       pdata->gps_long = can_rx.data.f; break;
         case(CAN_AS_ID_GPS_H):          pdata->gps_alt  = can_rx.data.f; break;
         case(CAN_AS_ID_GPS_GS):         pdata->gps_gs = can_rx.data.f;   break;
         case(CAN_AS_ID_GPS_TT):         pdata->gps_tt = can_rx.data.f;   break;
         case(CAN_AS_ID_GPS_SATELLITES): pdata->qsat = can_rx.data.f;     break;
      }
   }
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
