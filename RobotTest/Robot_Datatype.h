#include <string>
using namespace std;
#pragma once
#define SIA_NO_ERROR 0
#define SIA_ERR_SNDTIMEOUT -1 ///<发送失败返回值，代表应答超时
#define SIA_ERR_NETDISCNT -2 ///<发送失败返回值，代表网络断开
#define SIA_ERR_PARAMINVALID -3 ///<参数无效
#define SIA_ERR_CHECKCODE	-4  ///< 返回数据校验码错误
#define SIA_ERR_DATAINVALID -5  ///<返回数据无效
#define SIA_ERR_NOTINITION	-6 ///<未初始化
#define SIA_ERR_CONNECT_TIMEOUT -7 ///<网络连接超时
#define SIA_ERR_CONNECT_FAILED -8 ///<网络连接失败
#define SIA_ERR_STATUSFAULT  -9 ///控制器状态错误
#define SIA_ERR_JOBOVERLAP	-10 ///作业下载同名，已覆盖
#define SIA_ERR_JOBSPACE_SHORTAGE -11 ///< 作业空间已满
#define SIA_ERR_FIRST  -12  ///作业第一包有错误
#define SIA_ERR_RUNNING -13  ///机器人处于执行状态，禁止下发作业  add by tongyan 20131224 
#define SIA_ERR_REMOTE -14				///远程控制功能未启动  add by ytj 20150409
#define SIA_ERR_NOFUNCTION -15				///rc不支持该功能 add by tongyan 20150818
#define SIA_ERR_OPENFILERROR -16				///配置文件打开失败 add by tongyan 20151119
#define SIA_ERR_RESPACKAGESIZEZERO -17			///接收数据包大小为0 add by tongyan 20151228
#define SIA_ERR_MESBODYLENERROR -18		///接收数据包消息体长度错误 add by tongyan 20151228
#define SIA_ERR_RESPACKAGENULL -19		///接收数据包对象为空 add by tongyan 20151228
#define SIA_ERR_CHILDCODE -20		///子功能码 add by tongyan 20151228
#define SIA_ERR_SOCKETID -21        ///SOCKEID错误，add by tongyan 20161028
#define SIA_ERR_LICENCEINVALID -22        ///授权文件无效,add by tongyan 20170217
#define SIA_ERR_COMINITIAL -23        ///COM组件初始化错误,add by tongyan 20170310
#define SIA_ERR_LICEXIST -24      ///授权文件不存在,add by tongyan 20170310
#define SIA_ERR_LOADSYSCONFIG  -25    ///加载系统配置文件失败
#define SYSTEM_AXIS 12  //add by tongyan 20151119 ,兼容9轴和12轴

/**监控自动执行状态的函数指针*/
typedef int (*LPMONITOR_CALLBACK)(int Param1,int Param2);

/**监控暂停、急停、中断信息的函数指针，add by tongyan 20160801*/
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

//RC参数结构体
typedef struct t_send_robot_para
{
	char VER_DISP_PART1[32];						//系统号    
	char VER_DISP_PART2[30];                      //版本号
	char cToolNo;                                   //当前工具坐标系
	char cUserNo;                                   //当前用户坐标系
	T_SYSTEM_AXES system_axes;                   //系统轴数配置
	TRANS WPT6;                                  //工件坐标系
	TOOLF ToolCFile[8];                    //工具坐标系
	TRANS UserCFile[8];                    //用户坐标系
	INT Kepc[SYSTEM_AXIS];                                    //码盘限  mod by tongyan 20151119 由9改成12
	INT rc_trdla[SYSTEM_AXIS];                                  //RC跟踪差
	INT rc_sp_limit[SYSTEM_AXIS];                               //RC速度限
	INT max_trdla[SYSTEM_AXIS];                                //设置最大值
	float Kr[SYSTEM_AXIS];                                      //减速比
	float JtMin[SYSTEM_AXIS];                                    //软限位的最小值
	float JtMax[SYSTEM_AXIS];                                    //软限位的最大值
	float JtVmax[SYSTEM_AXIS];                                   //最大速度
	float JtAmax[SYSTEM_AXIS];                                   //最大加速度
	SET_TRDLA setTrdlaPara;                          //设置跟踪差参数
	WORD wRealDI[80];                              //IO输入
	WORD wRealDO[80];                            //IO输出
	float fc_sensor[6];                          //力控信息，add by tongyan 20150907
}T_SEND_ROBOT_PARA;
//add end

//Add by yuantianjian 20140902
//位置变量RPY
typedef struct rpy
{
	float px;	//位置变量x
	float py;	//位置变量y
	float pz;	//位置变量z
	float rx;	//方向变量x
	float ry;	//方向变量y
	float rz;	//方向变量z
	int mWord;
}RPY;

//参数类型
enum ParameterType
{
	BYTE_1,
	SHORT_2,
	INT_4,
	FLOAT_4,
	CHAR_1
};

//指令参数
typedef struct inst_Para
{
	ParameterType paraType;
	INT typeLength;
	char val[100];
	char minVal[100];
	char maxVal[100];
}INST_PARA;

//指令
typedef struct inst
{
	short code;
	int paraLen;
	int paraNum;
	INST_PARA para[20];

}INST;


//摆弧结构体
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

//焊接参数结构体
typedef struct arclinmigfile{
	float WeldCurrent;
	float WeldVoltage;
	unsigned char mode;
}LINMIGF;

//焊机返回参数结构体
typedef struct welderbackparameter{
	float WeldCurrent;
	float WeldWireSpeed;
	float WeldVoltage;
	unsigned char mode;
}WELDERBACKPARA; 

//剁型枚举
typedef  enum stack_type
{
	stack_type1=0,         
	stack_type2,               
	stack_type3,
	stack_type4,
	stack_type5,
	stack_type6,
}STACK_TYPE;

//码垛数据结构体
typedef struct pall_file_pro
{
	float product_length; //产品长
	float product_wide; //产品宽
	float product_height; //产品高
	float product_weight; //产品重量 
	float pallet_length; //托盘长
	float pallet_wide; //托盘宽
	float pallet_height; //托盘高
	float row_space; //行间距
	float col_space; //列间距
	STACK_TYPE stacktype; //垛型
	int stacklayernum;  //垛型层数
	int stackrownum;//行数
	int stackcolnum;//列数
	int verirownum;//型1行数
	int vericolnum;//型1列数
	int horirownum;//型2行数
	int horicolnum;//型2列数
	int startform;//起始形式
	int imageflag;//镜像开关
}PALL_FILE_PRO;

//计数结构体
typedef struct pall_file_counter
{
	int flagcountnum; //个数计数器
	int flagrownum;   //行数计数器
	int flagcolnum;   //列数计数器
	int flaglayernum; //层数计数器
	int flagstepnum;  //步数计数器
}PALL_FILE_COUNTER;

//码垛标志结构体
typedef struct pall_flag_msg
{
	short  filenum; //文件号
	int  realtotalnum;//实际的码垛的总数目
	int  breakflag;//拆码标志
	int  stackcount;//码垛初始计数
	int  breakcount;	//拆垛初始计数
}PALL_FLAG_MSG;

////MWord结构体--C++
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
//弧焊工艺参数结构体
typedef struct weld_craft_para
{
	float weldspeed;//焊接速度
	int weldmode;//焊接模式
	float weldcurrent;//焊接电流
	float weldvoltage;//收弧电流
	float stop_weldcurrrent;//收弧电流
	float stop_weldvoltage;//收弧电压
	float stop_weldtime;//收弧时间
	float burn_back_time;//回烧时间
	float pause_time;//暂停时间
	float weaverrange;//摆幅
	float weaverate;//频率
	float z_manual_value;//高低跟踪设定值
	float shiftratio;//偏移系数
	float control_x;//左右幅值
	float control_z;//高低幅值
}WELD_CRAFT_PARA;

//轴干涉区结构体
typedef struct AxisInterf_Data{
	unsigned char enable;          //使能状态1为使能，即干涉区起作用，0为没有使能
	unsigned char reserved[105];    //预留数据
}AXIS_INTERF_DATA;

//立体干涉区结构体
typedef struct CubeInterf_Data{
	unsigned char enable;      //使能状态1为使能，即干涉区起作用，0为没有使能
	unsigned char reserved[35];    //预留数据
}CUBE_INTERF_DATA;

//机器人位姿结构体
typedef struct RobPos{
	float N[3];
	float O[3];
	float A[3];
	float P[3];
	float exAxis[6];
}ROB_POS;