#include <string>
using namespace std;
#pragma once
#define SIA_NO_ERROR 0
#define SIA_ERR_SNDTIMEOUT -1 ///<����ʧ�ܷ���ֵ������Ӧ��ʱ
#define SIA_ERR_NETDISCNT -2 ///<����ʧ�ܷ���ֵ����������Ͽ�
#define SIA_ERR_PARAMINVALID -3 ///<������Ч
#define SIA_ERR_CHECKCODE	-4  ///< ��������У�������
#define SIA_ERR_DATAINVALID -5  ///<����������Ч
#define SIA_ERR_NOTINITION	-6 ///<δ��ʼ��
#define SIA_ERR_CONNECT_TIMEOUT -7 ///<�������ӳ�ʱ
#define SIA_ERR_CONNECT_FAILED -8 ///<��������ʧ��
#define SIA_ERR_STATUSFAULT  -9 ///������״̬����
#define SIA_ERR_JOBOVERLAP	-10 ///��ҵ����ͬ�����Ѹ���
#define SIA_ERR_JOBSPACE_SHORTAGE -11 ///< ��ҵ�ռ�����
#define SIA_ERR_FIRST  -12  ///��ҵ��һ���д���
#define SIA_ERR_RUNNING -13  ///�����˴���ִ��״̬����ֹ�·���ҵ  add by tongyan 20131224 
#define SIA_ERR_REMOTE -14				///Զ�̿��ƹ���δ����  add by ytj 20150409
#define SIA_ERR_NOFUNCTION -15				///rc��֧�ָù��� add by tongyan 20150818
#define SIA_ERR_OPENFILERROR -16				///�����ļ���ʧ�� add by tongyan 20151119
#define SIA_ERR_RESPACKAGESIZEZERO -17			///�������ݰ���СΪ0 add by tongyan 20151228
#define SIA_ERR_MESBODYLENERROR -18		///�������ݰ���Ϣ�峤�ȴ��� add by tongyan 20151228
#define SIA_ERR_RESPACKAGENULL -19		///�������ݰ�����Ϊ�� add by tongyan 20151228
#define SIA_ERR_CHILDCODE -20		///�ӹ����� add by tongyan 20151228
#define SIA_ERR_SOCKETID -21        ///SOCKEID����add by tongyan 20161028
#define SIA_ERR_LICENCEINVALID -22        ///��Ȩ�ļ���Ч,add by tongyan 20170217
#define SIA_ERR_COMINITIAL -23        ///COM�����ʼ������,add by tongyan 20170310
#define SIA_ERR_LICEXIST -24      ///��Ȩ�ļ�������,add by tongyan 20170310
#define SIA_ERR_LOADSYSCONFIG  -25    ///����ϵͳ�����ļ�ʧ��
#define SYSTEM_AXIS 12  //add by tongyan 20151119 ,����9���12��

/**����Զ�ִ��״̬�ĺ���ָ��*/
typedef int (*LPMONITOR_CALLBACK)(int Param1,int Param2);

/**�����ͣ����ͣ���ж���Ϣ�ĺ���ָ�룬add by tongyan 20160801*/
typedef int (*RSMONITOR_CALLBACK)(BYTE* dataStream,int streamLenth);

enum API_CODE
{
	API_READJOINT = 1,
	API_READPOSE,
	API_READTOOL,
	API_READALARM,
	API_READSTATUS,
	API_READUO,
	API_READGUO,
	API_READUI,
	API_READGUI,
	API_SETOFFLINE,
	/*API_START,
	API_MOVEPAUSE,*/
	API_CLEARBUFFER,
	API_MOVL_P2P,
	API_MOVL_CP,
	API_MOVJ_P2P,
	API_MOVJ_CP,
	API_SENDJOBT6,
	API_SENDJOBJTS,
	API_READJOBNAMELIST,
	API_RECEIVEJOB,
	API_READRCPARAM,
	API_SENDRCINST,
	API_DELJOB,
	API_CLEARJOBLIST,
	API_OPENJOB,
	API_WRITEUSERVARBYTE,
	API_WRITEUSERVARINT,
	API_WRITEUSERVARFLOAT,
	API_WRITEUSERVARRPY,
	API_WRITEUSERVARRPYS,
	API_SENDRECTIFYDATA,
	API_ARCON,
	API_ARCONSET,
	API_ARCONASF,
	API_ARCOFF,
	API_ARCOFFSET,
	API_ARCOFFASF,
	API_SENDJOBNET,
	API_WAIT,
	API_DO_OUT,
	API_DGO_OUT,
	API_DGO_OUT8,
	API_WRUTEUGO,
	API_WRITEUO,
	API_SIMWRITEGUI,
	API_SIMWRITEUI,
	API_DELAY,
	API_JOBRUMMODE,
	//API_REMOTECONTROL,
	API_READ_MAINJOPEN,
	API_READ_SAFEDOOR,
	API_READ_ONPATH,
	API_READ_POSIRION1,
	API_READ_POSITION2,
	API_READ_WARNING,
	API_READ_ONLINE,
	API_READ_AUTORUN,
	API_READ_POWERON,
	API_READ_PLAY,
	API_READ_MAINJOBRUN,
	API_READ_TEACH,
	//add by tongyan
	API_MOVL_P2P_RPY,
	API_MOVL_CP_RPY,
	API_READ_POSERPY,
	API_READ_OFFLINEVERSION,
	API_READ_BYTE_USERVAR,
	API_READ_INT_USERVAR,
	API_READ_FLOAT_USERVAR,
	API_READ_RPY_USERVAR,
	API_READ_AXISNUM,
	API_READ_INT_SYSVAR,
	//add by tongyan 20160802
	API_READ_ROBALLDATA,
	API_READ_WELDALLDATA,
	//add by tongyan 20160927
	//API_SEND_SYSIO,
	API_SEND_OPEN,
	API_SEND_RESET,
	API_SEND_PAUSE,
	API_SEND_STOP,
	API_SEND_SAFEDOOROFF,
	API_SEND_POWERON,
	API_SEND_START,
	//add by tongyan 20161026
	API_SEND_STACKFLAGDATA,
	//add by tongyan 20161123
	API_READ_JOINTBASENOAP,
	//add by qgt 20170908
	API_WELD_SEND_CRAFTPARA,
	//add by tongyan 20171013
	API_SEND_STACKPRODATA,
	API_SEND_STACKCOUNT,
	API_SEND_STACKPOINTDATA,
	API_SEND_STACKPOINTDATA2,
	//add by tongyan 20171106
	API_SET_AXIS_INTERF_DATA,
	API_SET_CUBE_INTERF_DATA,

	API_SEND_SHIFTPON,
	API_SEND_SHIFTPONOFF,
	API_SET_USERCOORD,
	API_SET_TOOLCOORD,
	API_MOVJ_P2P_NOAP,
	API_MOVJ_CP_NOAP,
	API_MOVJ_P2P_RPY,
	API_MOVJ_CP_RPY,
	//add by baidongni 20180410
	API_READ_FROCECONTROLDATA,
	API_READ_VISUALSENSEDATA,
	API_READ_CURSTACKCOUNT,
	API_SEND_STACKFILENUM,
	//add by tongyan 20180830
	API_MOVL_P2P_NoEndBack,
	API_MOVL_P2P_RPY_NoEndBack,
	API_MOVJ_P2P_NoEndBack,
	API_MOVJ_P2P_NOAP_NoEndBack,
	API_MOVJ_P2P_RPY_NoEndBack,
	
	API_MOVC_P2P,
	API_MOVC_CP,

};
//add by tongyan 20131111
typedef struct t_system_axes
{
	INT r_axes;                      //robot axes
	INT s_axes;	                     //slider axes
	INT p_axes;                      //positioner axer
	INT sys_axes;                    //system axes = r_axes+ s_axes+ p_axes
}T_SYSTEM_AXES;

typedef struct toolfile
{
	float Px;
	float Rx;
	float Py;
	float Ry;
	float Pz;
	float Rz;
}TOOLF;

typedef struct vec
{
	float x;
	float y;
	float z;
}VEC;
typedef struct trans
{
	VEC N;
	VEC O;
	VEC A;
	VEC P;
}TRANS;
typedef struct set_trdla
{
	BYTE enable;                  //enable flag
	INT pc_trdla[9];                //RC->PC  pulse control tracks delta
}SET_TRDLA;

//RC�����ṹ��
typedef struct t_send_robot_para
{
	char VER_DISP_PART1[32];						//ϵͳ��    
	char VER_DISP_PART2[30];                      //�汾��
	char cToolNo;                                   //��ǰ��������ϵ
	char cUserNo;                                   //��ǰ�û�����ϵ
	T_SYSTEM_AXES system_axes;                   //ϵͳ��������
	TRANS WPT6;                                  //��������ϵ
	TOOLF ToolCFile[8];                    //��������ϵ
	TRANS UserCFile[8];                    //�û�����ϵ
	INT Kepc[SYSTEM_AXIS];                                    //������  mod by tongyan 20151119 ��9�ĳ�12
	INT rc_trdla[SYSTEM_AXIS];                                  //RC���ٲ�
	INT rc_sp_limit[SYSTEM_AXIS];                               //RC�ٶ���
	INT max_trdla[SYSTEM_AXIS];                                //�������ֵ
	float Kr[SYSTEM_AXIS];                                      //���ٱ�
	float JtMin[SYSTEM_AXIS];                                    //����λ����Сֵ
	float JtMax[SYSTEM_AXIS];                                    //����λ�����ֵ
	float JtVmax[SYSTEM_AXIS];                                   //����ٶ�
	float JtAmax[SYSTEM_AXIS];                                   //�����ٶ�
	SET_TRDLA setTrdlaPara;                          //���ø��ٲ����
	WORD wRealDI[80];                              //IO����
	WORD wRealDO[80];                            //IO���
	float fc_sensor[6];                          //������Ϣ��add by tongyan 20150907
}T_SEND_ROBOT_PARA;
//add end

//Add by yuantianjian 20140902
//λ�ñ���RPY
typedef struct rpy
{
	float px;	//λ�ñ���x
	float py;	//λ�ñ���y
	float pz;	//λ�ñ���z
	float rx;	//�������x
	float ry;	//�������y
	float rz;	//�������z
	int mWord;
}RPY;

//��������
enum ParameterType
{
	BYTE_1,
	SHORT_2,
	INT_4,
	FLOAT_4,
	CHAR_1
};

//ָ�����
typedef struct inst_Para
{
	ParameterType paraType;
	INT typeLength;
	char val[100];
	char minVal[100];
	char maxVal[100];
}INST_PARA;

//ָ��
typedef struct inst
{
	short code;
	int paraLen;
	int paraNum;
	INST_PARA para[20];

}INST;


//�ڻ��ṹ��
typedef struct arcweavefile {
	short cMode;
	short cType;
	float Frequncy;
	float Amp;
	float Angle;
	short Time[8];
	float Amp_Left;
	float Amp_Right;
	float Amp_Cal;
	float Radius;
	float Extra[8];
} AWVF;

//���Ӳ����ṹ��
typedef struct arclinmigfile{
	float WeldCurrent;
	float WeldVoltage;
	unsigned char mode;
}LINMIGF;

//�������ز����ṹ��
typedef struct welderbackparameter{
	float WeldCurrent;
	float WeldWireSpeed;
	float WeldVoltage;
	unsigned char mode;
}WELDERBACKPARA; 

//����ö��
typedef  enum stack_type
{
	stack_type1=0,         
	stack_type2,               
	stack_type3,
	stack_type4,
	stack_type5,
	stack_type6,
}STACK_TYPE;

//������ݽṹ��
typedef struct pall_file_pro
{
	float product_length; //��Ʒ��
	float product_wide; //��Ʒ��
	float product_height; //��Ʒ��
	float product_weight; //��Ʒ���� 
	float pallet_length; //���̳�
	float pallet_wide; //���̿�
	float pallet_height; //���̸�
	float row_space; //�м��
	float col_space; //�м��
	STACK_TYPE stacktype; //����
	int stacklayernum;  //���Ͳ���
	int stackrownum;//����
	int stackcolnum;//����
	int verirownum;//��1����
	int vericolnum;//��1����
	int horirownum;//��2����
	int horicolnum;//��2����
	int startform;//��ʼ��ʽ
	int imageflag;//���񿪹�
}PALL_FILE_PRO;

//�����ṹ��
typedef struct pall_file_counter
{
	int flagcountnum; //����������
	int flagrownum;   //����������
	int flagcolnum;   //����������
	int flaglayernum; //����������
	int flagstepnum;  //����������
}PALL_FILE_COUNTER;

//����־�ṹ��
typedef struct pall_flag_msg
{
	short  filenum; //�ļ���
	int  realtotalnum;//ʵ�ʵ���������Ŀ
	int  breakflag;//�����־
	int  stackcount;//����ʼ����
	int  breakcount;	//����ʼ����
}PALL_FLAG_MSG;

////MWord�ṹ��--C++
//typedef struct mWord
//{
//	BYTE arm;
//	BYTE elbow;
//	BYTE wrist;
//	BYTE jt4s;
//	BYTE jt4;
//	BYTE jt5s;
//	BYTE jt5;
//	BYTE jt6s;
//	BYTE jt6;
//	BYTE jt8s;
//	BYTE jt9s;
//	BYTE enable;
//}MWORD;
//�������ղ����ṹ��
typedef struct weld_craft_para
{
	float weldspeed;//�����ٶ�
	int weldmode;//����ģʽ
	float weldcurrent;//���ӵ���
	float weldvoltage;//�ջ�����
	float stop_weldcurrrent;//�ջ�����
	float stop_weldvoltage;//�ջ���ѹ
	float stop_weldtime;//�ջ�ʱ��
	float burn_back_time;//����ʱ��
	float pause_time;//��ͣʱ��
	float weaverrange;//�ڷ�
	float weaverate;//Ƶ��
	float z_manual_value;//�ߵ͸����趨ֵ
	float shiftratio;//ƫ��ϵ��
	float control_x;//���ҷ�ֵ
	float control_z;//�ߵͷ�ֵ
}WELD_CRAFT_PARA;

//��������ṹ��
typedef struct AxisInterf_Data{
	unsigned char enable;          //ʹ��״̬1Ϊʹ�ܣ��������������ã�0Ϊû��ʹ��
	unsigned char reserved[105];    //Ԥ������
}AXIS_INTERF_DATA;

//����������ṹ��
typedef struct CubeInterf_Data{
	unsigned char enable;      //ʹ��״̬1Ϊʹ�ܣ��������������ã�0Ϊû��ʹ��
	unsigned char reserved[35];    //Ԥ������
}CUBE_INTERF_DATA;

//������λ�˽ṹ��
typedef struct RobPos{
	float N[3];
	float O[3];
	float A[3];
	float P[3];
	float exAxis[6];
}ROB_POS;