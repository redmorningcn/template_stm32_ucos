
/*******************************************************************************
* Description  : modbus初始化
* Author       : 2018/5/11 星期五, by redmorningcn
*******************************************************************************/

/*******************************************************************************
* INCLUDES
*/

#include <includes.h>
//#include <app_type.h>


/*******************************************************************************
* CONSTANTS
*/

/*******************************************************************************
* MACROS
*/

/*******************************************************************************
* TYPEDEFS
*/

/*******************************************************************************
* LOCAL VARIABLES
*/

/*******************************************************************************
* GLOBAL VARIABLES
*/

/***********************************************
* 描述： 任务控制块（TCB）
*/

/***********************************************
* 描述： 任务堆栈（STACKS）
*/

/*******************************************************************************
* LOCAL FUNCTIONS
*/
/*******************************************************************************
* 名    称： APP_ModbusInit
* 功    能： MODBUS初始化
* 入口参数： 无
* 出口参数： 无
* 作    者： 无名沈
* 创建日期： 2015-03-28
* 修    改：
* 修改日期：
* 备    注： 该初始化会创建Modbus任务。
*******************************************************************************/
void App_ModbusInit(void)
{
    MODBUS_CH   *pch;
    u8          comnum = 0;
    u32         boud   = 0;

    /***********************************************
    * 描述： uCModBus初始化，RTU时钟频率为1000HZ
    *        使用了定时器2（TIM2）
    */
    MB_Init(1000);
    
    
    /***********************************************
    * 描述： UART1连接无线模块
    *        用作从机。
    */
#if MODBUS_CFG_MASTER_EN == DEF_TRUE
    
    comnum      = 0;                                    //所用串号
    boud        = 57600;
    pch         = MB_CfgCh( DTU_NODE,                   // ... Modbus Node # for this slave channel
                            MODBUS_SLAVE,               // ... This is a MASTER
                            200,                        // ... 0 when a slave
                            MODBUS_MODE_RTU,            // ... Modbus Mode (_ASCII or _RTU)
                            comnum,                     // ... Specify UART #1
                            boud,                       // ... Baud Rate
                            USART_WordLength_8b,        // ... Number of data bits 7 or 8
                            USART_Parity_No,            // ... Parity: _NONE, _ODD or _EVEN
                            USART_StopBits_1,           // ... Number of stop bits 1 or 2
                            MODBUS_WR_EN);              // ... Enable (_EN) or disable (_DIS) writes

    Ctrl.ComCtrl[DTU].ConnCtrl.MB_Node      = DTU_NODE;     //modbus编号 
    Ctrl.ComCtrl[DTU].ConnCtrl.COM_Num      = comnum;       //串口号
    Ctrl.ComCtrl[DTU].ConnCtrl.SourceAddr   = LKJ_MAINBOARD_ADDR;   //无线发送模块地址
    Ctrl.ComCtrl[DTU].ConnCtrl.DestAddr     = DTU_ADDR;             //LKJ接口板csnc地址
    Ctrl.ComCtrl[DTU].ConnCtrl.Baud         = boud;

    Ctrl.ComCtrl[DTU].RxCtrl.EvtFlag       = COMM_EVT_FLAG_DTU_RX; //os事件标识 

    pch->RxSem  = &MB_OS_RxSemTbl[comnum];              // 接收信号量
    pch->TxSem  = &MB_OS_TxSemTbl[comnum];              // 发送信号量
    Ctrl.ComCtrl[DTU].pch  = pch;                      // ... modbus控制块和全局结构体建立连接
    
    DtuCom = &Ctrl.ComCtrl[DTU];                       //定义别名，在对应的任务中可用别名直接操作
#endif
    
    /***********************************************
    * 描述： UART2连接工况检测板及速度信号检测板。modbus通讯
    *        用作主机。
    */
#if MODBUS_CFG_MASTER_EN == DEF_TRUE
    
    comnum      = 1;                                    //所用串号
    boud        = 57600;
    
    pch         = MB_CfgCh( MTR_NODE,                   // ... Modbus Node # for this slave channel
                            MODBUS_MASTER,               // ... This is a MASTER
                            200,                        // ... 0 when a slave
                            MODBUS_MODE_RTU,            // ... Modbus Mode (_ASCII or _RTU)
                            comnum,                     // ... Specify UART #1
                            boud,                       // ... Baud Rate
                            USART_WordLength_8b,        // ... Number of data bits 7 or 8
                            USART_Parity_No,            // ... Parity: _NONE, _ODD or _EVEN
                            USART_StopBits_1,           // ... Number of stop bits 1 or 2
                            MODBUS_WR_EN);              // ... Enable (_EN) or disable (_DIS) writes

    Ctrl.ComCtrl[MTR].ConnCtrl.MB_Node     = MTR_NODE;             //modbus编号 
    Ctrl.ComCtrl[MTR].ConnCtrl.COM_Num     = comnum;               //串口号
    Ctrl.ComCtrl[MTR].ConnCtrl.SourceAddr  = LKJ_MAINBOARD_ADDR;   //无线发送模块地址（对MTR无效）
    Ctrl.ComCtrl[MTR].ConnCtrl.DestAddr    = DTU_ADDR;             //LKJ接口板csnc地址（对MTR无效）
    Ctrl.ComCtrl[MTR].ConnCtrl.Baud        = boud;
    
    Ctrl.ComCtrl[MTR].RxCtrl.EvtFlag       = COMM_EVT_FLAG_MTR_RX; //os事件标识 

    pch->RxSem  = &MB_OS_RxSemTbl[comnum];              // 接收信号量
    pch->TxSem  = &MB_OS_TxSemTbl[comnum];              // 发送信号量
    Ctrl.ComCtrl[MTR].pch  = pch;                       // ... modbus控制块和全局结构体建立连接
    
    MtrCom = &Ctrl.ComCtrl[MTR];                       //定义别名，在对应的任务中可用别名直接操作
#endif    


    /***********************************************
    * 描述： UART4连接备用通道接口
    *        用作主机。
    */
#if MODBUS_CFG_MASTER_EN == DEF_TRUE
    
    comnum      = 3;                                    //所用串号
    boud        = 57600;
    
    pch         = MB_CfgCh( TAX_NODE,                   // ... Modbus Node # for this slave channel
                            MODBUS_SLAVE,               // ... This is a MASTER
                            200,                        // ... 0 when a slave
                            MODBUS_MODE_RTU,            // ... Modbus Mode (_ASCII or _RTU)
                            comnum,                     // ... Specify UART #1
                            boud,                       // ... Baud Rate
                            USART_WordLength_8b,        // ... Number of data bits 7 or 8
                            USART_Parity_No,            // ... Parity: _NONE, _ODD or _EVEN
                            USART_StopBits_1,           // ... Number of stop bits 1 or 2
                            MODBUS_WR_EN);              // ... Enable (_EN) or disable (_DIS) writes

    Ctrl.ComCtrl[TAX].ConnCtrl.MB_Node     = TAX_NODE;             //modbus编号 
    Ctrl.ComCtrl[TAX].ConnCtrl.COM_Num     = comnum;               //串口号
    Ctrl.ComCtrl[TAX].ConnCtrl.SourceAddr  = LKJ_MAINBOARD_ADDR;   //无线发送模块地址（对MTR无效）
    Ctrl.ComCtrl[TAX].ConnCtrl.DestAddr    = DTU_ADDR;             //LKJ接口板csnc地址（对MTR无效）
    Ctrl.ComCtrl[TAX].ConnCtrl.Baud        = boud;
    Ctrl.ComCtrl[TAX].RxCtrl.EvtFlag       = COMM_EVT_FLAG_TAX_RX; //os事件标识 
    
    pch->RxSem  = &MB_OS_RxSemTbl[comnum];              // 接收信号量
    pch->TxSem  = &MB_OS_TxSemTbl[comnum];              // 发送信号量
    Ctrl.ComCtrl[TAX].pch  = pch;                       // ... modbus控制块和全局结构体建立连接
    
    TaxCom = &Ctrl.ComCtrl[TAX];                       //定义别名，在对应的任务中可用别名直接操作
#endif    
}   


    




