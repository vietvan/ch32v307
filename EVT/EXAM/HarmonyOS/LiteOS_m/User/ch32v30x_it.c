/********************************** (C) COPYRIGHT *******************************
* File Name          : ch32v30x_it.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main Interrupt Service Routines.
*******************************************************************************/
#include "ch32v30x_it.h"
#include "los_interrupt.h"

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      NMI_Handler
 *
 * @brief   This function handles NMI exception.
 *
 * @return  none
 */
void NMI_Handler(void)
{
    GET_INT_SP();
    HalIntEnter();
    while(1)
    {

    }

    HalIntExit();
    FREE_INT_SP();
}

/*********************************************************************
 * @fn      HardFault_Handler
 *
 * @brief   This function handles Hard Fault exception.
 *
 * @return  none
 */
void HardFault_Handler(void)
{

  GET_INT_SP();
  HalIntEnter();

  printf("mcause:%08x\r\n",__get_MCAUSE());
  printf("mtval:%08x\r\n",__get_MTVAL());
  printf("mepc:%08x\r\n",__get_MEPC());

  while (1)
  {
  }
  HalIntExit();
  FREE_INT_SP();
}


