/*******************************************************************************
* Description  : 定义通用结构体
* Author       : 2018/5/10 星期四, by redmorningcn
*******************************************************************************/
#ifndef  APP_TYPE_H_
#define  APP_TYPE_H_

#include    "stm32f10x_type.h"
#include    <app_com_type.h>


typedef union _Unnctrl_ {
   struct{
//        /***************************************************
//        * 描述： 系统参数：起始地址 = 000   通讯密码，软件版本，记录号，产品信息
//        */ 
//        StrRecHeadInfo      sHeadInfo;                      // 16
//        /***************************************************
//        * 描述：记录号管理地址：起始地址 = 016
//        */
//        StrRecNumMgr        sRecNumMgr;			            // 16
//        /***************************************************
//        * 描述：产品信息：起始地址 = 032
//        */
//        StrProductInfo	    sProductInfo;			        // 32
// 
        StrCOMCtrl      ComCtrl[4];
    };
    u16   buf[512];
        
}Unnctrl;

//变量声明
extern   volatile Unnctrl     sCtrl;

extern   volatile StrCOMCtrl  * DtuCom;
extern   volatile StrCOMCtrl  * MtrCom;
extern   volatile  StrCOMCtrl  * TaxCom;

#endif                                                          /* End of  include.                       */

