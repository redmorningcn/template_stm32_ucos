/*******************************************************************************
* Description  : ����ͨ�ýṹ��
* Author       : 2018/5/10 ������, by redmorningcn
*******************************************************************************/
#ifndef  APP_TYPE_H_
#define  APP_TYPE_H_

#include    "stm32f10x_type.h"
#include    <app_com_type.h>


typedef union _Unnctrl_ {
   struct{
//        /***************************************************
//        * ������ ϵͳ��������ʼ��ַ = 000   ͨѶ���룬����汾����¼�ţ���Ʒ��Ϣ
//        */ 
//        StrRecHeadInfo      sHeadInfo;                      // 16
//        /***************************************************
//        * ��������¼�Ź����ַ����ʼ��ַ = 016
//        */
//        StrRecNumMgr        sRecNumMgr;			            // 16
//        /***************************************************
//        * ��������Ʒ��Ϣ����ʼ��ַ = 032
//        */
//        StrProductInfo	    sProductInfo;			        // 32
// 
        StrCOMCtrl      ComCtrl[4];
    };
    u16   buf[512];
        
}Unnctrl;

//��������
extern    Unnctrl     Ctrl;

extern    StrCOMCtrl  * DtuCom;
extern    StrCOMCtrl  * MtrCom;
extern    StrCOMCtrl  * TaxCom;

#endif                                                          /* End of  include.                       */

