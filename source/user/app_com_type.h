/*******************************************************************************
* Description  : 串口通讯控制结构体定义（APP层）
* Author       : 2018/5/11 星期五, by redmorningcn
*******************************************************************************/

#ifndef	__APP_COM_TYPE_H__
#define	__APP_COM_TYPE_H__
#include <includes.h>

/*********************************************************************
* INCLUDES
*/
#define COMM_RECV_DATA_MAX_LEN   128
#define COMM_SEND_DATA_MAX_LEN   128
#define COM_CONN_NUM             4     





//串口地址定义    
#define     DTU                 0               /* DTU所用控制结构体序号         ComCtrl[]*/
#define     DTU_C0              0               /* DTU_C0地址所占用的连接编号    ConnCtrl[]*/
#define     DTU_NODE            1               /* DTU modebus编号*/

//串口地址定义    
#define     MTR                 1               /* MTR所用控制结构体序号         ComCtrl[]*/
#define     MTR_C0              0               /* MTR_C0地址所占用的连接编号    ConnCtrl[]*/
#define     MTR_NODE            1               /* MTR modebus编号*/


//串口地址定义    
#define     TAX                 2               /* TAX所用控制结构体序号         ComCtrl[]*/
#define     TAX_C0              0               /* TAX_C0地址所占用的连接编号    ConnCtrl[]*/
#define     TAX_NODE            1               /* TAX modebus编号*/

//csnc地址定义
#define     LKJ_MAINBOARD_ADDR  0x84            /* LKJ接口在线处理处理板 CSNC 协议地址*/
#define     DTU_ADDR            0xCA            /* 无线发送模块 CSNC 协议地址 */

//通讯协议类型
#define     MODBUS_PROTOCOL     0
#define     CSNC_PROTOCOL       1

/*********************************************************************
* CONSTANTS
*/


/*********************************************************************
* TYPEDEFS
*/

/*********************************************************************
* TYPEDEFS
*/
//__packed
//typedef struct {     
// 	u16     Type;       //机车类型	2	参见机车类型代码表
// 	u16     Nbr;        //机车号		2	
//} stcLocoId;
//
//typedef struct {
//    u8      buf[8];
//    u8      ack;
//} stcParaReply;

///**************************************************************
//* Description  : dtu操作命令
//* Author       : 2018/5/25 星期五, by redmorningcn
//*/
//__packed
//typedef struct{
//    u32     code;
//    union{
//        stcTime         time;
//        stcLocoId       loco;
//        stcParaReply    reply;
//        strIapdata      iap;
//        u32             recordnum;      //记录号
//        struct{                         //指定地址读取
//            u16         paraaddr;
//            u16         paralen;
//            u16         parabuf[64];       
//        };
//    };
//}strDtuRecData;


/*******************************************************************************
* Description  : 串口接收数据结构联合体
不同协议，不同指令的数据可复用。
* Author       : 2018/5/11 星期五, by redmorningcn
*******************************************************************************/
__packed
typedef union {
    
//  数据结构1
//  数据结构2、
//    union{
//        strDtuRecData   dtu;    //dtu参数设置的数据
//        strSpeed        speed;  //速度检测板数据结构
//    };
    u16             Buf16[COMM_RECV_DATA_MAX_LEN/2];		            //	
    u8              Buf[COMM_RECV_DATA_MAX_LEN];		            //	
} uRecvData;


/*******************************************************************************
* Description  : 串口发送数据联合体
* Author       : 2018/5/11 星期五, by redmorningcn
*******************************************************************************/
__packed
typedef union {
//	stcFlshRecNdp02A        sRecA;				    //数据记录     128 	
//  数据结构1
//  数据结构2
//    strSpeed        speed;                          //速度检测板数据结构

    u16             Buf16[COMM_SEND_DATA_MAX_LEN/2];		            //	
    u8              Buf[COMM_SEND_DATA_MAX_LEN];	
} uSendData;

/*******************************************************************************
* Description  : 连接控制字
* Author       : 2018/5/11 星期五, by redmorningcn
*******************************************************************************/
__packed
typedef struct {     
    u32     EnableConnFlg:1;     //连接控制：1，允许连接，0，不允许连接
    u32     RecvEndFlg  :1;     //接收标示：1，数据接收完成，0，无数据接收。
    u32     RecordSendFlg:1;     //发送标示：有数据发送，1；无数据发送，0
    u32     ErrFlg      :1;     //错误标示，连接正常，0；连接错误，1
    u32     Connflg     :1;     //连接状态：1，有连接，0，无连接。
    u32     ConnType    :3;     //连接类型：0，数据传输；1，参数设置；2，IAP传输；
            
    u32     protocol    :2;     //通信协议。0，modbus；1，csnc；
    u32     TimeOutEn   :1;     //超时计数器允许标识。
    u32     TimeOut     :5;     //超时时间，单位1s。
    
    u32     MB_Node     :5;     //modbus连接编号
    u32     COM_Num     :3;     //串口编号
        
    u32     Bits        :4;
    u32     Parity      :2;
    u32     Stops       :2;
   
    u32     Baud;
    u32     DataCode;           //控制字（数据区内部）
    
    u8      SendRecordNum;      //发送记录号
    u8      rec[3];
    union {
        struct{
            u8  DestAddr;       //源地址        master = 0x80	   
            u8  SourceAddr;     //接收地址      slave  = 0xCA	   
            u8  FramNum;        //帧序号   
            u8  FrameCode;      //帧控制字
            u8  datalen;        //数据长度     
        };
        
//        strCsnrProtocolPara sCsnc;  //CSNC协议结构体
    };
}sCOMConnCtrl;		


//接收控制字
typedef struct {     
    union {
        struct{
            u8      DestAddr;       //源地址        master = 0x80	   
            u8      SourceAddr;     //接收地址      slave  = 0xCA	   
            u8      FramNum;        //帧序号   
            u8      FrameCode;      //帧控制字
        };
        
//        strCsnrProtocolPara sCsnc;  //CSNC协议结构体
    };
    u8      Len;                    //接收有效数据长度
    u8      protocol;               //通信协议。0，modbus；1，csnc；
    u8      EvtFlag;                //时间标识组
    u8      RecvFlg     :1;         //数据接收完成
    u8      Tmp         :7;
    u32     DataCode;               //接收控制字
    
} sCOMRecvCtrl;

/*******************************************************************************
* Description  : 串口控制结构体（app层）
* Author       : 2018/5/11 星期五, by redmorningcn
*******************************************************************************/
__packed
typedef struct {  
	uRecvData	        Rd;			                    //接收数据区
	uSendData	        Wr;			                    //发送数据区
    
    MODBUS_CH           *pch;                   		// MODBUS句柄
    
    u16                 ConnectTimeOut  : 14;     	    // 连接超时计数器，秒为单位
    u16                 TimeoutEn       : 1;         	// 计算器启动
    u16                 ConnectFlag     : 1;         	// 连接标志

    /***************************************************
    * 描述： 串口控制组
    */
	sCOMRecvCtrl    	RxCtrl;				            //接收控制，包含当前接收到的控制信息 
	sCOMConnCtrl		ConnCtrl;                       //连接控制，对每个地址作为单独的数据连接，在APP运用端处理。
	
} StrCOMCtrl;



#endif	
