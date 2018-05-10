/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                           (c) Copyright 2009-2013; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                      APPLICATION CONFIGURATION
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                         Evaluation Board
*
* Filename      : app_cfg.h
* Version       : V1.00
* Programmer(s) : JJL
*                 EHS
*                 DC
*********************************************************************************************************
*/

#ifndef  __APP_CFG_H__
#define  __APP_CFG_H__


/*
*********************************************************************************************************
*                                       MODULE ENABLE / DISABLE
*********************************************************************************************************
*/

#define  APP_CFG_SERIAL_EN                          DEF_ENABLED
#define  APP_CFG_MODBUS_EN                          DEF_ENABLED                 /* uc/modbus 模块 启动或禁止*/



/*
*********************************************************************************************************
*                                            TASK PRIORITIES（任务优先级）保证文档整洁，请清除无效任务定义
*********************************************************************************************************
*/
#define  MB_OS_CFG_RX_TASK_PRIO     (OS_CFG_PRIO_MAX - 14)  /* ModBus任务的优先级（没有用到ModBus则不需要关注）   */
#define  APP_TASK_START_PRIO        (OS_CFG_PRIO_MAX - 13)  /* start的任务优先级                                  */ 

#define  APP_TASK_OSAL_PRIO         (OS_CFG_PRIO_MAX -  3)  /* OSAL任务优先级                                     */




/*
*********************************************************************************************************
*                                           配置任务堆栈的大小
*                                            TASK STACK SIZES
*                             Size of the task stacks (# of OS_STK entries)
*                      堆栈的字节大小 = CPU数据宽度 * 8 * size = 4 * 8 * size(字节)
*                           如：APP_TASK_SAMPLE_STK_SIZE = 128u，实际为 128u * 4 = 512（字节）
*                             可以在IAR仿真中查看堆栈大小分配是否充足。
*********************************************************************************************************
*/
#define  MB_OS_CFG_RX_TASK_STK_SIZE                 512u        // ModBus任务堆栈的大小
#define  APP_TASK_START_STK_SIZE                    128u        // 给起始任务分配堆栈
#define  APP_TASK_OSAL_STK_SIZE                     512u



/*
*********************************************************************************************************
*                                    BSP CONFIGURATION: RS-232
*********************************************************************************************************
*/

#define  BSP_CFG_SER_COMM_SEL             			BSP_SER_COMM_UART_02
#define  BSP_CFG_TS_TMR_SEL                         2


/*
*********************************************************************************************************
*                                     TRACE / DEBUG CONFIGURATION
*********************************************************************************************************
*/
#if 0
#define  TRACE_LEVEL_OFF                            0
#define  TRACE_LEVEL_INFO                           1
#define  TRACE_LEVEL_DEBUG                          2
#endif

#define  APP_TRACE_LEVEL                            TRACE_LEVEL_INFO
#define  APP_TRACE                                  BSP_Ser_Printf

#define  APP_TRACE_INFO(x)            ((APP_TRACE_LEVEL >= TRACE_LEVEL_INFO)  ? (void)(APP_TRACE x) : (void)0)
#define  APP_TRACE_DEBUG(x)           ((APP_TRACE_LEVEL >= TRACE_LEVEL_DEBUG) ? (void)(APP_TRACE x) : (void)0)


#endif
