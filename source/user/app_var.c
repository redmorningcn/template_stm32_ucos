/*******************************************************************************
* Description  : ���弰��ʼ��ȫ�ֱ���
* Author       : 2018/5/10 ������, by redmorningcn
*******************************************************************************/

#include <app_type.h>

/*******************************************************************************
* Description  : ����ȫ�ֱ���  sCtrl
* Author       : 2018/5/10 ������, by redmorningcn
*******************************************************************************/
Unnctrl     Ctrl;              //
    
/*******************************************************************************
* Description  : ���߷���ģ�����ָ��
* Author       : 2018/5/14 ����һ, by redmorningcn
*******************************************************************************/
StrCOMCtrl  * DtuCom;

/*******************************************************************************
* Description  : �ͼ��崮�ڿ���ָ��
* Author       : 2018/5/14 ����һ, by redmorningcn
*******************************************************************************/
StrCOMCtrl  * MtrCom;

/*******************************************************************************
* Description  : �ͼ��崮�ڿ���ָ��
* Author       : 2018/5/14 ����һ, by redmorningcn
*******************************************************************************/
StrCOMCtrl  * TaxCom;



/*******************************************************************************
* Description  : ȫ�ֱ�����ʼ��
* Author       : 2018/5/18 ������, by redmorningcn
*/
void app_init_sctrl(void)
{ 
//    WdtReset();
    /*******************************************************************************
    * Description  : ��ʼ���������Ӳ���Ĭ��ֵ
    * Author       : 2018/5/18 ������, by redmorningcn
    */    
    u8  i;
    for(i = 0;i <sizeof(Ctrl.ComCtrl)/sizeof(StrCOMCtrl);i++ )
    {
        Ctrl.ComCtrl[i].ConnectFlag             = 0;        //���ӱ�ʶ��0���ô��������ӣ�1�������ӡ�
        Ctrl.ComCtrl[i].ConnCtrl.TimeOut        = 5;        //���ӳ�ʱʱ�䡣��������ʱ�䣬��Ϊ���ӶϿ���
        
        Ctrl.ComCtrl[i].ConnCtrl.Baud           = 57600;
        Ctrl.ComCtrl[i].ConnCtrl.Bits           = USART_WordLength_8b;
        Ctrl.ComCtrl[i].ConnCtrl.COM_Num        = 0x01;
        Ctrl.ComCtrl[i].ConnCtrl.Connflg        = 1;        //Ĭ��������
//        Ctrl.ComCtrl[i].ConnCtrl.ConnType       = RECORD_SEND_COMM;//Ĭ��Ϊ���ݷ���
        Ctrl.ComCtrl[i].ConnCtrl.DataCode       = 0;
        Ctrl.ComCtrl[i].ConnCtrl.datalen        = 0;
        Ctrl.ComCtrl[i].ConnCtrl.DestAddr       = DTU_ADDR; //DTUģ��
        Ctrl.ComCtrl[i].ConnCtrl.EnableConnFlg  = 1;        //����������
        Ctrl.ComCtrl[i].ConnCtrl.ErrFlg         = 0;        //��������
//        Ctrl.ComCtrl[i].ConnCtrl.FrameCode      = RECORD_FRAME_CODE;//����ͨѶ
        Ctrl.ComCtrl[i].ConnCtrl.FramNum        = 1;        //��Ŵ�1��ʼ
        Ctrl.ComCtrl[i].ConnCtrl.MB_Node        = 1;
        Ctrl.ComCtrl[i].ConnCtrl.Parity         = USART_Parity_No;//��У��
        Ctrl.ComCtrl[i].ConnCtrl.protocol       = CSNC_PROTOCOL;  //CSNCЭ�� 
        //Ctrl.ComCtrl[i].ConnCtrl.rec             
        Ctrl.ComCtrl[i].ConnCtrl.RecordSendFlg  = 0;        //���޼�¼����
        Ctrl.ComCtrl[i].ConnCtrl.RecvEndFlg     = 0;        //�����ݽ���
        Ctrl.ComCtrl[i].ConnCtrl.SendRecordNum  = 1;        //��¼ ͬ���ã�ȷ�ϣ�
        Ctrl.ComCtrl[i].ConnCtrl.SourceAddr     = LKJ_MAINBOARD_ADDR;     //������ַ
        Ctrl.ComCtrl[i].ConnCtrl.Stops          = USART_StopBits_1;
        Ctrl.ComCtrl[i].ConnectTimeOut          = 5;            //��ʱʱ�䣺5���ڣ��ô��������ӣ����ݽ��գ����򴮿ڶϿ���
        Ctrl.ComCtrl[i].TimeoutEn               = 0;            //��ʱ����ֹͣ������������ʱ������

//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.databuf  = (u8 *)&Ctrl.ComCtrl[i].Wr;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.datalen  = 0;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.destaddr = Ctrl.ComCtrl[i].ConnCtrl.DestAddr;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.framcode = Ctrl.ComCtrl[i].ConnCtrl.FrameCode;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.framnum  = Ctrl.ComCtrl[i].ConnCtrl.FramNum;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.rxtxbuf  = Ctrl.ComCtrl[i].pch->TxBuf;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.rxtxlen  = 0;
//        Ctrl.ComCtrl[i].ConnCtrl.sCsnc.sourceaddr = Ctrl.ComCtrl[i].ConnCtrl.SourceAddr;
        //Ctrl.ComCtrl[i].ConnCtrl.sCsnc.tmp      =

//        Ctrl.ComCtrl[i].RxCtrl.sCsnc.databuf    = (u8 *)&Ctrl.ComCtrl[i].Rd;    
//        Ctrl.ComCtrl[i].RxCtrl.sCsnc.rxtxbuf    = (u8 *)&Ctrl.ComCtrl[i].pch->RxBuf;  
        Ctrl.ComCtrl[i].RxCtrl.protocol         =  CSNC_PROTOCOL;
    }

    /*****************************************************************
    * Description  : ��FRAM�зֱ����head��NumMgr��Porduct��RunPara
    * Author       : 2018/5/17 ������, by redmorningcn
    */
//    Ctrl.sRunPara.FramFlg.RdHead    = 1;
//    Ctrl.sRunPara.FramFlg.RdNumMgr  = 1;
//    Ctrl.sRunPara.FramFlg.RdProduct = 1;
//    Ctrl.sRunPara.FramFlg.RdRunPara = 1;
//    App_FramPara();
//    
//    Ctrl.sRunPara.Err.Errors        = 0;                //������ϴ���
//    
//    if(Ctrl.sHeadInfo.Password != MODBUS_PASSWORD){     //ͨѶ����
//        Ctrl.sHeadInfo.Password = MODBUS_PASSWORD;
//        Ctrl.sRunPara.Err.FramErr = 1;                  //������ϣ�ָ����ַ������ֵ����
//    }
//   
//    Ctrl.sRunPara.SysSts.StartFlg   = 1;                //��ʼ��ʾ 
//    
//    if ( ( Ctrl.sRunPara.StoreTime < 5 ) ||             //���ݴ洢����
//         ( Ctrl.sRunPara.StoreTime > 10*60 ) ) {
//        Ctrl.sRunPara.StoreTime    = 60;
//    }
}
