// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 ROBOTSDK_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// ROBOTSDK_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。


#ifdef ROBOTSDK_EXPORTS
#define ROBOTSDK_API extern "C" __declspec(dllexport)
#else
#define ROBOTSDK_API extern "C" __declspec(dllimport)
#endif

#include "Robot_Datatype.h"
// 此类是从 RobotSDK.dll 导出的


ROBOTSDK_API int RobotInit();
ROBOTSDK_API int RobotRelease();

/*********************网络接口*******************************/

/**连接控制器.
@param StrIP(in) 控制器IP地址
@param port (in) 端口号
@return 若成功返回当前IP的网络连接ID,ID值大于0，否则返回错误码
*/
ROBOTSDK_API int Connect(const char* StrIP,short port);

ROBOTSDK_API int ConnectUDP(const char* StrIP,short port);
/**断开网络连接.
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Disconnect(int ConnectID);

/*********************运动类指令*******************************/

/**单点直线型运动.
@param N (in) 位姿矩阵N分量
@param O (in) 位姿矩阵O分量
@param A (in) 位姿矩阵A分量
@param P (in) 位姿矩阵P分量,位置.
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movl_P2P(float* N,float* O,float* A,float* P,float* exAxis ,int Tool,float Speed,int ConnectID);

/**连续直线运动，到达该点后不减速*/
ROBOTSDK_API int Movl_CP(float* N,float* O,float* A,float* P,float* exAxis ,int Tool,float Speed,int ConnectID);

/**单点关节型运动.
@param Joint (in) 关节值
@param JointNum (in) 关节数
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_P2P(float* Joint, int Tool,float Speed,int ConnectID);

/**连续关节运动，到达该点后不减速*/
ROBOTSDK_API int Movj_CP( float* Joint, int Tool,float Speed ,int ConnectID);

/**单点直线型运动.
@param RPY (in) 位置变量结构体
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movl_P2P_RPY(RPY *rpy,float* exAxis ,int Tool,float Speed,int ConnectID);

/**连续直线运动，到达该点后不减速*/
ROBOTSDK_API int Movl_CP_RPY(RPY *rpy,float* exAxis ,int Tool,float Speed,int ConnectID);

/*********************查询接口********************************/

/**查询当前关节值.
@param pJoint (out) 关节值存放地址
@param JointNum (in) 要查询的关节数
@param ConnectID（in）网络连接ID，Connect(const char* StrIP,short port)的返回值
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadJoint(float* pJoint,int JointNum,int ConnectID);

/**查询当前工具末端TCP点的姿态,分别为N,O,A,P，各自由三个浮点数表示.
@param exAxis (out)返回三个外部轴结果
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadPOSE(float *N,float* O,float* A,float* P,float* exAxis ,int& mWord,int ConnectID);

/**查询当前工具末端TCP点的姿态,RPY形式
@param rpy (out) 位置变量结构体
@param exAxis (out)返回三个外部轴结果
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadPOSE_RPY(RPY *rpy,float* exAxis ,int ConnectID);

/**查询当前使用的工具号
@param ToolIndex (out) 工具号
@param Px (out) 工具坐标参数Px分量
@param Py (out) 工具坐标参数Py分量
@param Pz (out) 工具坐标参数Pz分量
@param Rx (out) 工具坐标参数Rx分量
@param Ry (out) 工具坐标参数Ry分量
@param Rz (out) 工具坐标参数Rz分量
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadTool(BYTE ToolIndex,float& Px,float & Py,float& Pz,float& Rx,float& Ry,float& Rz,int ConnectID);

/**读报警.
@param ErrCode(out) 报警码
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadAlarm(int& ErrCode,int ConnectID);

/**读状态.
@param status (out) 状态缓存地址
@param len (in) 缓存大小,最多4个字节
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadStatus(BYTE* status,int len,int ConnectID);

/**读单个用户IO输出状态.
@param IOMap (in) IO索引号
@param IOStatus (out) 等待的IO状态
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadUO(int IOMap,BYTE& IOStatus,int ConnectID );

/**读用户IO输出.
@param IOStatus (out) 8位或16位组IO状态
@param Channel (in) IO通道号 1~8
@param IOGroupFlag (in) IO组标识
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadGUO(int &IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**读单个用户IO输入.
@param IOMap (in) IO索引号
@param IOStatus (out) 等待的IO状态
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadUI(int IOMap,BYTE& IOStatus,int ConnectID);

/**读用户IO输入.
@param IOStatus (out) 8位或16位组IO状态
@param Channel (in) IO通道号 1~8
@param IOGroupFlag (in) IO组标识
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadGUI(int &IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**查询RC参数  add 20131021
@param rcParam (out) RC参数结构体指针
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadRCParam(T_SEND_ROBOT_PARA *rcParam,int ConnectID);


/**读取rc程序版本号，add by tongyan 20150818
@param version（out）版本号
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadOfflineVersion(char *version,int ConnectID);

/***********************执行接口***********************************************/

///**设置离线控制模式，在开始离线控制之前必须发送此命令.
//@param ConnectID（in）网络连接ID
//@return 若成功返回0，否则返回错误码
//*/
//ROBOTSDK_API int SetOfflineMode(bool bOffline,int ConnectID);

///**开始准备执行指令.
//@brief 收到此命令后，如指令缓存队列不为空，则开始执行指令。
//@param ConnectID（in）网络连接ID
//@return 若成功返回0，否则返回错误码
//*/
//ROBOTSDK_API int Start(int ConnectID);
//
///**暂停.
//@param ConnectID（in）网络连接ID
//@return 若成功返回0，否则返回错误码
//*/
//ROBOTSDK_API int MovePause(int ConnectID);

/**清空控制器缓存的所有指令.
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ClearBuffer(int ConnectID);

/**下载作业,格式1：存储位置点的T6阵.
@param pJobStream (in) 作业流，注意，这里使用的是二进制编码，而不是ASCII码
@param byteLen (in)作业字节长度,包含作业头和所有指令的字节长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendJobT6(BYTE* pJobStream,int byteLen,int ConnectID);

/**下载作业，格式2：存储位置点的关节值
@param pJobStream (in) 作业流，注意，这里使用的是二进制编码，而不是ASCII码
@param byteLen (in)作业字节长度,包含作业头和所有指令的字节长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendJobJts(BYTE* pJobStream,int byteLen,int ConnectID);

/**网口下载作业
@param pJobStream (in) 作业流
@param byteLen (in) 作业流长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendJobNet(BYTE* pJobStream,int byteLen,int ConnectID);

/**查询RC现有作业列表
@param jobNameList (out) RC现有作业列表
@param jobNumber (out) 现有作业的个数
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadJobNameList(char* jobNameList,int& jobNumber,int ConnectID);


/**上传作业
@param jobName (in) 指定的作业名称
@param jobStream (out)  作业数据流
@param streamLength (out) 作业数据流的长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReceiveJob(char* jobName,BYTE* jobStream,int& streamLenth,int ConnectID);

///**发送通用RC指令
//@param RCInst (in) RC指令流
//@param ConnectID（in）网络连接ID
//@return 若成功则返回0，否则返回错误码
//*/
//ROBOTSDK_API int SendRCInst(BYTE* RCInst,int ConnectID);

/**删除指定作业
@param jobName (in) 指定的作业名称
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int DelJob(char* jobName,int ConnectID);

/**清空作业列表
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ClearJobList(int ConnectID);

/**打开指定作业
@param jobName (in) 指定的作业名称
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int OpenJob(char* jobName,int ConnectID);

/**发送字节型用户变量
@param varID(in) 变量编号
@param varBYTE(in) 变量值
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int WriteUserVarBYTE(int varID, BYTE varBYTE,int ConnectID);
/**发送32位整型用户变量
@param varID(in) 变量编号
@param varFloat(in) 变量值
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int WriteUserVarINT(int varID, int varINT,int ConnectID);
/**发送浮点型用户变量
@param varID(in) 变量编号
@param varINT(in) 变量值
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int WriteUserVarFLOAT(int varID, float varFloat,int ConnectID);

/**发送位置变量（RPY中的mWord起作用）
@param varRPY(in) 位置变量结构体
@param exAxis(in) RC外部轴数据组 
@param coordinate(in) 坐标系 1~3
@param TOOLNUM(in) 工具坐标系号 1~8
@param USERNUM(in) 用户坐标系号 1~8
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int WriteUserVarRPY(int varID,RPY varRPY, float* exAxis, int coordinate, int TOOLNUM,int USERNUM,int ConnectID);

/**发送位置变量（RPY中的mWord不起作用）
@param varRPY(in) 位置变量结构体
@param exAxis(in) RC外部轴数据组 
@param coordinate(in) 坐标系 1~3
@param TOOLNUM(in) 工具坐标系号 1~8
@param USERNUM(in) 用户坐标系号 1~8
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int WriteUserVarRPYS(int varID,RPY varRPY, float* exAxis, int coordinate, int TOOLNUM,int USERNUM,int ConnectID);

/**发送实时纠偏数据
@param varRPY(in) 位置变量结构体
@param exAxis(in) RC外部轴数据组 
@param coordinate(in) 坐标系类型 1~3
@param coordNum(in) 坐标系号 1~8
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendRectifyData(RPY varRPY, float* exAxis, int coordType, int coordNum,int ConnectID);

/***********************IO类指令**********************************************/

/**设置要使用的工具号*/
//ROBOTSDK_API  int SetTool(int index);
/**wait指令.
@param IOMap (in) IO索引号
@param IOStatus (in) 等待的IO状态
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Wait(int IoMap,BYTE IoStatus,int ConnectID);

/**IO输出指令,在控制器端需要缓存到指令执行队列.
@param IoMap (in) 用户IO索引号
@param IoStatus (in) IO状态，1:ON，0:OFF
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API  int DO_Out(int IOMap,BYTE IOstatus,int ConnectID);

/***16位组IO输出指令,在控制器端需要缓存到指令执行队列.
@param IOStatus (in)  16位IO状态
@param Channel (in) IO通道号 1~64
@param IOGroupFlag (in) IO组标识
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int DGO_Out(int IOStatus, int Channel,int ConnectID);

/***8位组IO输出指令,在控制器端需要缓存到指令执行队列.
@param IOStatus (in)  8位IO状态
@param Channel (in) IO通道号 1~8
@param IOGroupFlag (in) IO组标识
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int DGO_Out8(int IOStatus, int Channel,int ConnectID);

/**设置用户组IO输出.
@brief 控制器收到该命令后立即执行，不缓存
@param IOStatus (in)  8位或者16位IO状态
@param Channel (in) IO通道号 8位：1~8 16位：1~64
@param IOGroupFlag (in) IO组标识
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int WriteGUO(int IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**设置单个用户IO输出.
@brief 控制器收到该命令后立即执行，不缓存
@param IOMap (in) 用户IO索引号
@param IOStatus (in)   IO状态，1:ON，0:OFF
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int WriteUO(int IOMap,BYTE IOStatus,int ConnectID);

/**仿真用户组IO输入.
@brief 控制器收到该命令后立即执行，不缓存
@param IOStatus (in)  8位IO状态
@param Channel (in) IO通道号 8位：1~8 16位：1~64
@param IOGroupFlag (in) IO组标识
@return 若成功返回0，否则返回-1
*/
ROBOTSDK_API int SimWriteGUI(int IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**仿真用户IO输入.
@param IOMap (in) 用户IO索引号，见用户IO表
@param IOStatus (in)   IO状态，1:ON，0:OFF
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SimWriteUI(int IOMap,BYTE IOStatus ,int ConnectID);

/****************************设置类指令**********************************/

/**延迟指令.
@param DelayTime (in) 延迟时间，单位：S
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Delay(float DelayTime,int ConnectID);

/**设置作业运行模式  add by tongyan 20150511.
@param JobRunMode (in) 作业运行模式，1：自动，2：一次，3：单步
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ChangeJobRunMode(BYTE JobRunMode,int ConnectID);

/*设置当前作业执行状态反馈的回调函数.
@param func (in) 函数指针，由用户实现执行状态的处理
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SetPlayMonitor(LPMONITOR_CALLBACK func,int ConnectID);
ROBOTSDK_API int SetSndstreamMonitor(LPMONITOR_CALLBACK func,int ConnectID);
ROBOTSDK_API int SetBackstreamMonitor(LPMONITOR_CALLBACK func,int ConnectID);


/**获得版本号
*/
ROBOTSDK_API const char* GetSdkVersion();

/**获得sdk生成的时间
*/
ROBOTSDK_API const char* GetBuildTime();

/****************************应用类指令(弧焊)**********************************/
/**默认方式起弧
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ARCON(int ConnectID);
/**参数方式起弧
@param VarI (in) 起弧电流
@param VarU (in) 起弧电压
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ARCONSet(float varI, float varU,int ConnectID);
/**配置文件方式起弧
@param ASFNumberr (in) 配置文件号
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ARCONASF(short ASFNumber,int ConnectID);
/**默认方式息弧
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ARCOFF(int ConnectID);
/**参数方式息弧
@param VarI (in) 起弧电流
@param VarU (in) 起弧电压
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ARCOFFSet(float varI, float varU,int ConnectID);
/**配置文件方式弧
@param ASFNumberr (in) 配置文件号
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ARCOFFASF(short ASFNumber,int ConnectID);


/****************************远程控制类指令**********************************/
// Add by ytj

/**设置远程控制状态
//@param StrIP（in）要设置远程控制状态的控制器IP地址
//@param RemoteON（in）true：开启远程控制；false:关闭远程控制
//*/
//ROBOTSDK_API void RemoteControl(const char* StrIP, bool RemoteON);

/**获得远程IO——主作业打开的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_MainJobOpen(int ConnectID);
/**获得远程IO——安全门的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_SafeDoor(int ConnectID);
/**获得远程IO——在路径上的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_OnPath(int ConnectID);
/**获得远程IO——原点位置1的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_Position1(int ConnectID);
/**获得远程IO——原点位置2的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_Position2(int ConnectID);
/**获得远程IO——报警中的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_Warning(int ConnectID);
/**获得远程IO——远程模式的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_Online(int ConnectID);
/**获得远程IO——运行中的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_AutoRun(int ConnectID);
/**获得远程IO——伺服上电的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_PowerOn(int ConnectID);
/**获得远程IO——执行模式的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_Play(int ConnectID);
/**获得远程IO——主作业执行中的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_MainJobRun(int ConnectID);
/**获得远程IO——示教模式的状态
@param ConnectID（in）网络连接ID
@return 1:ON,0:OFF;否则返回错误码
*/
ROBOTSDK_API int Read_Teach(int ConnectID);

/**开启远程IO——主程序调用
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/

ROBOTSDK_API int Send_Open(int ConnectID);
/**开启远程IO——报警复位
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Send_Reset(int ConnectID);

/**开启远程IO——外部启动
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Send_Start(int ConnectID);
/**开启远程IO——外部暂停
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Send_Pause(int ConnectID);
/**开启远程IO——外部急停
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Send_Stop(int ConnectID);



/**开启远程IO——外部伺服上电
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Send_PowerOn(int ConnectID);

///**远程IO——打开安全门,add by tongyan 20160921
//@param ConnectID（in）网络连接ID
//*/
//ROBOTSDK_API int Send_SafeDoorON(int ConnectID);
/**远程IO——关闭安全门,add by tongyan 20160921
@param ConnectID（in）网络连接ID
*/
ROBOTSDK_API int Send_SafeDoorOFF(int ConnectID);

//
///**发送远程IO值，add by tongyan20160927
//@param sysIO（in）IO值
//@param ConnectID（in）网络连接ID
//@return 若成功则返回0，否则返回错误码
//*/
//ROBOTSDK_API int Send_SysIO(int sysIO,int ConnectID);
//// Add end

//add by tongyan 20151119 

/**发送RC指令
@param RCInst（in） RC指令
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Send_RCInst(INST RCInst,int ConnectID);

/**读系统总轴数
@param axis_Num（out）
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int Read_AxisNum(int& axis_Num,int ConnectID);

/**读字节型用户变量
@param varID(in) 变量编号
@param varBYTE(out) 变量值
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadUserVarBYTE(int varID, BYTE& varBYTE,int ConnectID);

/**读32位整型用户变量
@param varID(in) 变量编号
@param varINT(out) 变量值
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadUserVarINT(int varID, int& varINT,int ConnectID);

/**读浮点型用户变量
@param varID(in) 变量编号
@param varFloat(out) 变量值
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadUserVarFLOAT(int varID, float& varFloat,int ConnectID);

/**读位置变量
@param varRPY(out) 位置变量结构体
@param exAxis(out) RC外部轴数据组 
@param coordinate(out) 坐标系 1~3
@param TOOLNUM(out)  工具坐标系号 1~8
@param USERNUM(out) 用户坐标系号 1~8
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadUserVarRPY(int varID,RPY* varRPY, float* exAxis, int& coordinate, int& TOOLNUM,int& USERNUM,int ConnectID);



/**读32位整型系统变量
@param varID(in) 变量编号
@param varINT(out) 变量值
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadSysVarINT(int varID, int& varINT,int ConnectID);

///**读浮点型系统变量
//@param varID(in) 变量编号
//@param varFloat(out) 变量值
//@param ConnectID（in）网络连接ID
//@return 若成功则返回0，否则返回错误码
//*/
//ROBOTSDK_API int ReadSysVarFLOAT(int varID, float& varFloat,int ConnectID);
//add over


//add by tongyan 20160802 码垛应用
/**发送码垛产品相关数据
@param fileNum(in) 文件号
@param stackProData(in) 码垛数据结构体
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendStackProData(short fileNum,PALL_FILE_PRO stackProData,int ConnectID);

/**发送码垛计数
@param fileNum(in) 文件号
@param stackData(int) 码垛计数结构体
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendStackCount(short fileNum,PALL_FILE_COUNTER stackCount,int ConnectID);

/**发送码垛垛点数据(单一产品)
@param fileNum(in) 文件号
@param pointData(in) 码垛垛点数据
@param byteLen(in) 数据长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendStackPointData(short fileNum,BYTE* pointData,int byteLen,int ConnectID);

/**发送码垛垛点数据(多种产品)
@param fileNum(in) 文件号
@param pointData(in) 码垛垛点数据
@param byteLen(in) 数据长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendStackPointData2(short fileNum,BYTE* pointData,int byteLen,int ConnectID);

//add over

//add by tongyan20160819
/**查询机器人相关参数
@param dataStream(out) 数据流
@param streamLenth(out) 数据流长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadRobAllData(BYTE* dataStream,int& streamLenth,int ConnectID);

/**查询焊接所有参数
@param dataStream(out) 数据流
@param streamLenth(out) 数据流长度
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int ReadWeldAllData(BYTE* dataStream,int& streamLenth,int ConnectID);
//add over

//add by tongyan 20160919
/*设置监控机器人信息的回调函数.
@param func (in) 函数指针，由用户实现执行状态的处理
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SetRobAllDataMonitor(RSMONITOR_CALLBACK func,int ConnectID);
//add over

//add by tongyan 20161026
/**发送码垛标志数据
@param stackFlagData(in) 码垛标志数据
@param ConnectID（in）网络连接ID
@return 若成功则返回0，否则返回错误码
*/
ROBOTSDK_API int SendStackFlagData(PALL_FLAG_MSG stackFlagData,int ConnectID);
//add over

//add by tongyan 20161121
/**根据姿态值获得关节值.
@param N (in) 位姿矩阵N分量
@param O (in) 位姿矩阵O分量
@param A (in) 位姿矩阵A分量
@param P (in) 位姿矩阵P分量,位置.
@param jointNum（out）关节个数
@param jointVal（out）关节值
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadJointBaseNOAP(float *N,float *O,float *A,float *P,int jointNum,float *jointVal,int ConnectID);
//add over

//add by qgt 20170908
/**发送弧焊工艺参数.
@param dataStream (in) 弧焊工艺参数数据
@param streamLenth (in) 数据长度
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SendWeldCraftPara(BYTE* dataStream,int streamLenth,int ConnectID);
//add over

//add by tongyan 20171106
/**设置轴干涉区.
@param fileNum (in) 轴干涉区文件号
@param data (in) 轴干涉区结构体变量
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SetAxisInsertData(int fileNum,AXIS_INTERF_DATA data,int ConnectID);

/**设置立体干涉区.
@param fileNum (in) 立体干涉区文件号
@param data (in) 立体干涉区结构体变量
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SetCubeInsertData(int fileNum,CUBE_INTERF_DATA data,int ConnectID);
/**偏移开关.
@param posNum (in) 位置变量号
@param corrdingNum (in) 坐标系号
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Send_ShiftOnP(int posNum,int corrdingNum, int connectID);
/**偏移关闭.
@param connectID (in) 网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Send_ShiftOnPOff( int connectID);


/**查询指定码垛文件号的当前码垛计数
@param fileNum (in) 码垛文件号
@param count (out) 当前码垛数量
@param connectID (in) 网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadCurStacCount(short fileNum,int& count,int ConnectID);


/**发送码垛文件号
@param fileNum (in) 码垛文件号
@param connectID (in) 网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SendStackFileNum(short fileNum,int ConnectID);

/**设置工具坐标系
@param coordNum (in) 坐标系文件号
@param coordVal (in) 坐标系值
@param connectID (in) 网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SetToolCoordinate(int coordNum, RPY coordVal, int connectID);

/**设置用户坐标系
@param coordNum (in) 坐标系文件号
@param coordVal (in) 坐标系值
@param connectID (in) 网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int SetUserCoordinate(int coordNum, RPY coordVal, int connectID);


/**发送姿态值(NOAP形式)走单点关节型运动.
@param N (in) 位姿矩阵N分量
@param O (in) 位姿矩阵O分量
@param A (in) 位姿矩阵A分量
@param P (in) 位姿矩阵P分量,位置.
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_P2P_NOAP(float* N, float* O, float* A, float* P, float* exAxis, int Tool, float Speed, int ConnectID);

/**发送姿态值(NOAP形式)走连续关节型运动.到达该点后不减速
@param N (in) 位姿矩阵N分量
@param O (in) 位姿矩阵O分量
@param A (in) 位姿矩阵A分量
@param P (in) 位姿矩阵P分量,位置.
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_CP_NOAP(float* N, float* O, float* A, float* P, float* exAxis, int Tool, float Speed, int ConnectID);

/**发送姿态值(RPY形式)走单点关节型运动.
@param RPY (in) 位置变量结构体
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_P2P_RPY(RPY *rpy, float* exAxis, int Tool, float Speed, int ConnectID);

/**发送姿态值(RPY形式)走连续关节型运动.到达该点后不减速
@param RPY (in) 位置变量结构体
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_CP_RPY(RPY *rpy, float* exAxis, int Tool, float Speed, int ConnectID);

/**读取力控数据，add by baidongni 20180410
@param Fx（out）x方向的力
@param Fy（out）y方向的力
@param Fz（out）z方向的力
@param Mx（out）x方向的力矩
@param My（out）y方向的力矩
@param Mz（out）z方向的力矩
@param checkout（out）是否拍到照片的校验值
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadForceControlData(double& Fx, double& Fy, double& Fz, double& Mx, double& My, double& Mz, int ConnectID);

/**读取力控数据，add by baidongni 20180410
@param checkout（out）是否拍到照片的校验值
@param x（out）相机平面坐标值x
@param y（out）相机平面坐标值y
@param Rz（out）偏移角度
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int ReadVisualSenseData(int& checkout, float& x, float& y, float& Rz, int ConnectID);


/**单点直线型运动.(不带执行反馈)
@param N (in) 位姿矩阵N分量
@param O (in) 位姿矩阵O分量
@param A (in) 位姿矩阵A分量
@param P (in) 位姿矩阵P分量,位置.
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movl_P2P_NoEndBack(float* N,float* O,float* A,float* P,float* exAxis ,int Tool,float Speed,int ConnectID);


/**单点直线型运动(RPY)(不带执行反馈)
@param RPY (in) 位置变量结构体
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movl_P2P_RPY_NoEndBack(RPY *rpy,float* exAxis ,int Tool,float Speed,int ConnectID);


/**单点关节型运动.(不带执行反馈)
@param Joint (in) 关节值
@param JointNum (in) 关节数
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_P2P_NoEndBack(float* Joint, int Tool,float Speed,int ConnectID);


/**发送姿态值(NOAP形式)走单点关节型运动.(不带执行反馈)
@param N (in) 位姿矩阵N分量
@param O (in) 位姿矩阵O分量
@param A (in) 位姿矩阵A分量
@param P (in) 位姿矩阵P分量,位置.
@param P (in) 位姿矩阵P分量,位置.
@param exAxis (in) 外部轴
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_P2P_NOAP_NoEndBack(float* N, float* O, float* A, float* P, float* exAxis, int Tool, float Speed, int ConnectID);



/**发送姿态值(RPY形式)走单点关节型运动.(不带执行反馈)
@param RPY (in) 位置变量结构体
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movj_P2P_RPY_NoEndBack(RPY *rpy, float* exAxis, int Tool, float Speed, int ConnectID);

/**发送姿态值(NOAP形式)走点到点圆弧运动
@param posAss (in) 辅助点位姿
@param posTar (in) 目标点位姿
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param CircleSeg (in) 判断当前所在点处于圆弧前半段还是后半段
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movc_P2P(ROB_POS posAss,ROB_POS posTar,int Tool,float Speed,int CircleSeg,int ConnectID);

/**发送姿态值(NOAP形式)走连续圆弧运动
@param posAss (in) 辅助点位姿
@param posTar (in) 目标点位姿
@param Tool (in) 使用的工具号
@param Speed (in) 工具末端的执行速度，单位：mm/s
@param CircleSeg (in) 判断当前所在点处于圆弧前半段还是后半段
@param ConnectID（in）网络连接ID
@return 若成功返回0，否则返回错误码
*/
ROBOTSDK_API int Movc_CP(ROB_POS posAss,ROB_POS posTar,int Tool,float Speed,int CircleSeg,int ConnectID);