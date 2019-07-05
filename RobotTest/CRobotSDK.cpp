#include "stdafx.h"
#include "CRobotSDK.h"
#include "Robot_Datatype.h"
#include "RobotSDK.h"

CRobotSDK::CRobotSDK()
{
	m_bConnected = false;
	int re = RobotInit();
	if(re != 0)
	{
		vector<CString> vResult;
		CString str;
		str.Format(_T("%d"), re);
		vResult.push_back(str);
	}
	LoadFunction();
}

CRobotSDK::~CRobotSDK()
{
	RobotRelease();
}

bool CRobotSDK::GetConnectStatus()
{
	return this->m_bConnected;
}

CString CRobotSDK::GetErrorMessage(int ErrorCode)
{
	CString ErrorMessage;

	switch (ErrorCode)
	{
		case 0:
		{
			ErrorMessage = _T("发送成功");
			break;
		}
		case -1:
		{
			ErrorMessage = _T("发送失败返回值，代表应答超时");
			break;
		}
		case -2:
		{
			ErrorMessage = _T("发送失败返回值，代表网络断开");
			break;
		}
		case -3:
		{
			ErrorMessage = _T("参数无效");
			break;
		}
		case -4:
		{
			ErrorMessage = _T("返回数据校验码错误");
			break;
		}
		case -5:
		{
			ErrorMessage = _T("返回数据无效");
			break;
		}
		case -6:
		{
			ErrorMessage = _T("未初始化");
			break;
		}
		case -7:
		{
			ErrorMessage = _T("网络连接超时");
			break;
		}
		case -8:
		{
			ErrorMessage = _T("网络连接失败");
			break;
		}
		case -9:
		{
			ErrorMessage = _T("控制器状态错误");
			break;
		}
		case -10:
		{
			ErrorMessage = _T("作业下载同名，已覆盖");
			break;
		}
		case -11:
		{
			ErrorMessage = _T("作业空间已满");
			break;
		}
		case -12:
		{
			ErrorMessage = _T("作业第一包有错误");
			break;
		}
		case -13:
		{
			ErrorMessage = _T("机器人处于执行状态，禁止该功能");
			break;
		}
		case -14:
		{
			ErrorMessage = _T("远程控制功能未启动");
			break;
		}
		case -15:
			{
				ErrorMessage = _T("RC不支持该功能");
				break;
			}
		case -16:
			{
				ErrorMessage = _T("RC不能打开InstConfig配置文件");
				break;
			}
		case -17:
			{
				ErrorMessage = _T("接收数据包大小为0");
				break;
			}
			
		case -18:
			{
				ErrorMessage = _T("接收数据包消息体长度错误");
				break;
			}
			
		case -19:
			{
				ErrorMessage = _T("接收数据包对象为空");
				break;
			}
		case -20:
			{
				ErrorMessage = _T("子功能码不存在");
				break;
			}
		case -21:
			{
				ErrorMessage = _T("SOCKETID错误");
				break;
			}
		case -22:
			{
				ErrorMessage = _T("授权文件无效");
				break;
			}
		case -23:
			{
				ErrorMessage = _T("COM组件初始化错误");
				break;
			}
		case -24:
			{
				ErrorMessage = _T("授权文件不存在");
				break;
			}
		//不是离线编程接口库内部错误
		case -100:
			{
				ErrorMessage = _T("输入参数类型错误");
				break;
			}

		default:
			if (ErrorCode < 0)
			{
				ErrorMessage = _T("未知错误");
			}
			else
			{
				ErrorMessage = _T("发送成功");
			}
			break;
	}

	return ErrorMessage;
}

void CRobotSDK::LoadFunction()
{
	CString strFunction;
	strFunction = _T("ReadJoint");
	this->m_FunctionMap[strFunction] = API_READJOINT;
	strFunction = _T("ReadPOSE");
	this->m_FunctionMap[strFunction] = API_READPOSE;
	strFunction = _T("ReadTool");
	this->m_FunctionMap[strFunction] = API_READTOOL;
	strFunction = _T("ReadAlarm");
	this->m_FunctionMap[strFunction] = API_READALARM;
	strFunction = _T("ReadStatus");
	this->m_FunctionMap[strFunction] = API_READSTATUS;
	strFunction = _T("ReadUO");
	this->m_FunctionMap[strFunction] = API_READUO;
	strFunction = _T("ReadGUO");
	this->m_FunctionMap[strFunction] = API_READGUO;
	strFunction = _T("ReadUI");
	this->m_FunctionMap[strFunction] = API_READUI;
	strFunction = _T("ReadGUI");
	this->m_FunctionMap[strFunction] = API_READGUI;
	strFunction = _T("SetOfflineMode");
	this->m_FunctionMap[strFunction] = API_SETOFFLINE;
	/*strFunction = _T("Start");
	this->m_FunctionMap[strFunction] = API_START;
	strFunction = _T("MovePause");
	this->m_FunctionMap[strFunction] = API_MOVEPAUSE;*/
	strFunction = _T("ClearBuffer");
	this->m_FunctionMap[strFunction] = API_CLEARBUFFER;
	strFunction = _T("Movl_P2P");
	this->m_FunctionMap[strFunction] = API_MOVL_P2P;
	strFunction = _T("Movl_CP");
	this->m_FunctionMap[strFunction] = API_MOVL_CP;
	strFunction = _T("Movj_P2P");
	this->m_FunctionMap[strFunction] = API_MOVJ_P2P;
	strFunction = _T("Movj_CP");
	this->m_FunctionMap[strFunction] = API_MOVJ_CP;
	strFunction = _T("SendJobT6");
	this->m_FunctionMap[strFunction] = API_SENDJOBT6;
	strFunction = _T("SendJobJts");
	this->m_FunctionMap[strFunction] = API_SENDJOBJTS;
	strFunction = _T("ReadJobNameList");
	this->m_FunctionMap[strFunction] = API_READJOBNAMELIST;
	strFunction = _T("ReceiveJob");
	this->m_FunctionMap[strFunction] = API_RECEIVEJOB;
	strFunction = _T("ReadRCParam");
	this->m_FunctionMap[strFunction] = API_READRCPARAM;
	strFunction = _T("SendRCInst");
	this->m_FunctionMap[strFunction] = API_SENDRCINST;
	strFunction = _T("DelJob");
	this->m_FunctionMap[strFunction] = API_DELJOB;
	strFunction = _T("ClearJobList");
	this->m_FunctionMap[strFunction] = API_CLEARJOBLIST;
	strFunction = _T("OpenJob");
	this->m_FunctionMap[strFunction] = API_OPENJOB;
	strFunction = _T("WriteUserVarBYTE");
	this->m_FunctionMap[strFunction] = API_WRITEUSERVARBYTE;
	strFunction = _T("WriteUserVarINT");
	this->m_FunctionMap[strFunction] = API_WRITEUSERVARINT;
	strFunction = _T("WriteUserVarFLOAT");
	this->m_FunctionMap[strFunction] = API_WRITEUSERVARFLOAT;
	strFunction = _T("WriteUserVarRPY");
	this->m_FunctionMap[strFunction] = API_WRITEUSERVARRPY;
	strFunction = _T("WriteUserVarRPYS");
	this->m_FunctionMap[strFunction] = API_WRITEUSERVARRPYS;
	strFunction = _T("SendRectifyData");
	this->m_FunctionMap[strFunction] = API_SENDRECTIFYDATA;
	strFunction = _T("ARCON");
	this->m_FunctionMap[strFunction] = API_ARCON;
	strFunction = _T("ARCONSet");
	this->m_FunctionMap[strFunction] = API_ARCONSET;
	strFunction = _T("ARCONASF");
	this->m_FunctionMap[strFunction] = API_ARCONASF;
	strFunction = _T("ARCOFF");
	this->m_FunctionMap[strFunction] = API_ARCOFF;
	strFunction = _T("ARCOFFSet");
	this->m_FunctionMap[strFunction] = API_ARCOFFSET;
	strFunction = _T("ARCOFFASF");
	this->m_FunctionMap[strFunction] = API_ARCOFFASF;
	strFunction = _T("SendJobNet");
	this->m_FunctionMap[strFunction] = API_SENDJOBNET;
	strFunction = _T("Wait");
	this->m_FunctionMap[strFunction] = API_WAIT;
	strFunction = _T("DO_Out");
	this->m_FunctionMap[strFunction] = API_DO_OUT;
	strFunction = _T("DGO_Out");
	this->m_FunctionMap[strFunction] = API_DGO_OUT;
	strFunction = _T("DGO_Out8");
	this->m_FunctionMap[strFunction] = API_DGO_OUT8;
	strFunction = _T("WriteGUO");
	this->m_FunctionMap[strFunction] = API_WRUTEUGO;
	strFunction = _T("WriteUO");
	this->m_FunctionMap[strFunction] = API_WRITEUO;
	strFunction = _T("SimWriteGUI");
	this->m_FunctionMap[strFunction] = API_SIMWRITEGUI;
	strFunction = _T("SimWriteUI");
	this->m_FunctionMap[strFunction] = API_SIMWRITEUI;
	strFunction = _T("Delay");
	this->m_FunctionMap[strFunction] = API_DELAY;
	//add by tongyan 20150512
	strFunction = _T("ChangeJobRunMode");
	this->m_FunctionMap[strFunction] = API_JOBRUMMODE;
	//远程控制
	//strFunction = _T("RemoteControl");
	//this->m_FunctionMap[strFunction] = API_REMOTECONTROL;
	//读取
	strFunction = _T("Read_MainJobOpen");
	this->m_FunctionMap[strFunction] = API_READ_MAINJOPEN;
	strFunction = _T("Read_SafeDoor");
	this->m_FunctionMap[strFunction] = API_READ_SAFEDOOR;
	strFunction = _T("Read_OnPath");
	this->m_FunctionMap[strFunction] = API_READ_ONPATH;
	strFunction = _T("Read_Position1");
	this->m_FunctionMap[strFunction] = API_READ_POSIRION1;
	strFunction = _T("Read_Position2");
	this->m_FunctionMap[strFunction] = API_READ_POSITION2;
	strFunction = _T("Read_Warning");
	this->m_FunctionMap[strFunction] = API_READ_WARNING;
	strFunction = _T("Read_Online");
	this->m_FunctionMap[strFunction] = API_READ_ONLINE;
	strFunction = _T("Read_AutoRun");
	this->m_FunctionMap[strFunction] = API_READ_AUTORUN;
	strFunction = _T("Read_PowerOn");
	this->m_FunctionMap[strFunction] = API_READ_POWERON;
	strFunction = _T("Read_Play");
	this->m_FunctionMap[strFunction] = API_READ_PLAY;
	strFunction = _T("Read_MainJobRun");
	this->m_FunctionMap[strFunction] = API_READ_MAINJOBRUN;
	strFunction = _T("Read_Teach");
	this->m_FunctionMap[strFunction] = API_READ_TEACH;
	//add by tongyan 20150630
	strFunction = _T("Movl_P2P_RPY");
	this->m_FunctionMap[strFunction] = API_MOVL_P2P_RPY;
	strFunction = _T("Movl_CP_RPY");
	this->m_FunctionMap[strFunction] = API_MOVL_CP_RPY;
	strFunction = _T("Read_POSE_RPY");
	this->m_FunctionMap[strFunction] = API_READ_POSERPY;
	strFunction = _T("Read_OfflineVersion");
	this->m_FunctionMap[strFunction] = API_READ_OFFLINEVERSION;
	
	//add by tongyan 20151119
	strFunction = _T("Read_BYTE_USERVAR");
	this->m_FunctionMap[strFunction] = API_READ_BYTE_USERVAR;
	strFunction = _T("Read_INT_USERVAR");
	this->m_FunctionMap[strFunction] = API_READ_INT_USERVAR;
	strFunction = _T("Read_FLOAT_USERVAR");
	this->m_FunctionMap[strFunction] = API_READ_FLOAT_USERVAR;
	strFunction = _T("Read_RPY_USERVAR");
	this->m_FunctionMap[strFunction] = API_READ_RPY_USERVAR;
	strFunction = _T("Read_AXISNUM");
	this->m_FunctionMap[strFunction] = API_READ_AXISNUM;
	strFunction = _T("Read_INT_SYSVAR");
	this->m_FunctionMap[strFunction] = API_READ_INT_SYSVAR;
	/*strFunction = _T("Read_FLOAT_SYSVAR");
	this->m_FunctionMap[strFunction] = API_READ_FLOAT_SYSVAR;*/
	//add by tongyan 20150802
	strFunction = _T("Read_RobAllData");
	this->m_FunctionMap[strFunction] = API_READ_ROBALLDATA;
	strFunction = _T("Read_WeldAllData");
	this->m_FunctionMap[strFunction] = API_READ_WELDALLDATA;
	//add by tongyan 20160927
	/*strFunction = _T("Send_SysIO");
	this->m_FunctionMap[strFunction] = API_SEND_SYSIO;*/
	strFunction = _T("Send_Open");
	this->m_FunctionMap[strFunction] = API_SEND_OPEN;
	strFunction = _T("Send_Reset");
	this->m_FunctionMap[strFunction] = API_SEND_RESET;
	strFunction = _T("Send_Pause");
	this->m_FunctionMap[strFunction] = API_SEND_PAUSE;
	strFunction = _T("Send_Stop");
	this->m_FunctionMap[strFunction] = API_SEND_STOP;
	strFunction = _T("Send_SafeDoorOFF");
	this->m_FunctionMap[strFunction] = API_SEND_SAFEDOOROFF;
	strFunction = _T("Send_PowerOn");
	this->m_FunctionMap[strFunction] = API_SEND_POWERON;
	strFunction = _T("Send_Start");
	this->m_FunctionMap[strFunction] = API_SEND_START;
	//add by tongyan 20161026
	strFunction = _T("Send_StackFlagData");
	this->m_FunctionMap[strFunction] = API_SEND_STACKFLAGDATA;
	//add by tongyan 20161123
	strFunction = _T("Read_JointBaseNOAP");
	this->m_FunctionMap[strFunction] = API_READ_JOINTBASENOAP;
	//add by qgt 20170908
	strFunction = _T("SendWeldCraftPara");
	this->m_FunctionMap[strFunction] = API_WELD_SEND_CRAFTPARA;
	//add by tongyan 20171013
	strFunction = _T("Send_StackProData");
	this->m_FunctionMap[strFunction] = API_SEND_STACKPRODATA;
	strFunction = _T("Send_StackCount");
	this->m_FunctionMap[strFunction] = API_SEND_STACKCOUNT;
	strFunction = _T("Send_StackPointData");
	this->m_FunctionMap[strFunction] = API_SEND_STACKPOINTDATA;
	strFunction = _T("Send_StackPointData2");
	this->m_FunctionMap[strFunction] = API_SEND_STACKPOINTDATA2;
	//add by tongyan 20171106
	strFunction = _T("SetAxisInsertData");
	this->m_FunctionMap[strFunction] = API_SET_AXIS_INTERF_DATA;
	strFunction = _T("SetCubeInsertData");
	this->m_FunctionMap[strFunction] = API_SET_CUBE_INTERF_DATA;

	strFunction = _T("Send_ShiftOnP");
	this->m_FunctionMap[strFunction] = API_SEND_SHIFTPON;
	strFunction = _T("Send_ShiftOnPOff");
	this->m_FunctionMap[strFunction] = API_SEND_SHIFTPONOFF;

	strFunction = _T("ReadCurStacCount");
	this->m_FunctionMap[strFunction] = API_READ_CURSTACKCOUNT;
	strFunction = _T("SendStackFileNum");
	this->m_FunctionMap[strFunction] = API_SEND_STACKFILENUM;
	
	strFunction = _T("SetToolCoordinate");
	this->m_FunctionMap[strFunction] = API_SET_TOOLCOORD;
	strFunction = _T("SetUserCoordinate");
	this->m_FunctionMap[strFunction] = API_SET_USERCOORD;
	strFunction = _T("Movj_P2P_NOAP");
	this->m_FunctionMap[strFunction] = API_MOVJ_P2P_NOAP;
	strFunction = _T("Movj_CP_NOAP");
	this->m_FunctionMap[strFunction] = API_MOVJ_CP_NOAP;
	strFunction = _T("Movj_P2P_RPY");
	this->m_FunctionMap[strFunction] = API_MOVJ_P2P_RPY;
	strFunction = _T("Movj_CP_RPY");
	this->m_FunctionMap[strFunction] = API_MOVJ_CP_RPY;
	//add by baidongni 20180410
	strFunction = _T("ReadForceControlData");
	this->m_FunctionMap[strFunction] = API_READ_FROCECONTROLDATA;
	strFunction = _T("ReadVisualSenseData");
	this->m_FunctionMap[strFunction] = API_READ_VISUALSENSEDATA;

	strFunction = _T("Movj_P2P_NOAP_NoEndBack");
	this->m_FunctionMap[strFunction] = API_MOVJ_P2P_NOAP_NoEndBack;
	strFunction = _T("Movj_P2P_RPY_NoEndBack");
	this->m_FunctionMap[strFunction] = API_MOVJ_P2P_RPY_NoEndBack;
	strFunction = _T("Movl_P2P_RPY_NoEndBack");
	this->m_FunctionMap[strFunction] = API_MOVL_P2P_RPY_NoEndBack;
	strFunction = _T("Movl_P2P_NoEndBack");
	this->m_FunctionMap[strFunction] = API_MOVL_P2P_NoEndBack;
	strFunction = _T("Movj_P2P_NoEndBack");
	this->m_FunctionMap[strFunction] = API_MOVJ_P2P_NoEndBack;
	strFunction = _T("Movc_P2P");
	this->m_FunctionMap[strFunction] = API_MOVC_P2P;
	strFunction = _T("Movc_CP");
	this->m_FunctionMap[strFunction] = API_MOVC_CP;	
}

map<CString,int> CRobotSDK::GetFunctionMap()
{
	return this->m_FunctionMap;
}

int CRobotSDK::ConnectIP(CString strIP, short sPort)
{
	char* cIP = CStringToChar(strIP);
	int res = Connect(cIP,sPort);
	//int res = ConnectUDP(cIP,sPort);
	if (res > 0)
	{
		m_bConnected = true;
		this->connectID = res;
		vector<CString> vResult;
		CString strTemp;
		strTemp.Format(_T("%d"), res);
		vResult.push_back(strTemp);
	}
	free(cIP);
	return res;
}

int CRobotSDK::ConnectUdp(CString strIP, short sPort)
{
	char* cIP = CStringToChar(strIP);
	int res = ConnectUDP(cIP,sPort);
	if (res > 0)
	{
		m_bConnected = true;
		this->connectID = res;
		vector<CString> vResult;
		CString strTemp;
		strTemp.Format(_T("%d"), res);
		vResult.push_back(strTemp);
	}
	free(cIP);
	return res;
}

int CRobotSDK::DisconnectIP()
{
	int res = Disconnect(this->connectID);
	m_bConnected = false;
	return res;
}

vector<CString> CRobotSDK::SendAPI(CString apiName, CString Param1, CString Param2,CString Param3, CString Param4, CString Param5, CString Param6,CString Param7, CString Param8, CString Param9, CString Param10,CString Param11)
{
	vector<CString> vResult;
	int res = -1;
	if (apiName == "")
	{
	}
	if (apiName == _T("ReadJoint"))
	{
		float pJoint[12];
		char *param = this->CStringToChar(Param1);
		int JointNum = atoi(param);
		res = ReadJoint(pJoint, JointNum,connectID);
		if (res == 0)
		{
			for (int i = 0; i < JointNum; i++)
			{
				CString str = _T("J");
				CString strTemp;
				strTemp.Format(_T("%d"), i +1);
				str = str + strTemp + _T(": ");
				float f =  pJoint[i];
				strTemp.Format(_T("%g"), f);
				str = str + strTemp;
				vResult.push_back(str);
			}
		}
		free(param);
	}
	if (apiName == _T("ReadPOSE"))
	{
		float N[3];
		float O[3];
		float A[3];
		float P[3];
		float exAxis[6];
		int mWord = 0;
		res = ReadPOSE(N,O,A, P,exAxis ,mWord,connectID);

		if (res == 0)
		{
			CString strN = _T("1.N:");
			CString strO = _T("2.O:");
			CString strA = _T("3.A:");
			CString strP = _T("4.P:");
			CString strExAxis = _T("5.exAxis:");
			CString strMWord = _T("6.mWord:");
			CString str = _T(",");
			CString strTemp;

			strTemp.Format(_T("%g"), N[0]);
			strN = strN + strTemp;
			strN = strN + str;
			strTemp.Format(_T("%g"), N[1]);
			strN = strN + strTemp;
			strN = strN + str;
			strTemp.Format(_T("%g"), N[2]);
			strN = strN + strTemp;
			 
			strTemp.Format(_T("%g"), O[0]);
			strO = strO + strTemp;
			strO = strO + str;
			strTemp.Format(_T("%g"), O[1]);
			strO = strO + strTemp;
			strO = strO + str;
			strTemp.Format(_T("%g"), O[2]);
			strO = strO + strTemp;

			strTemp.Format(_T("%g"), A[0]);
			strA = strA + strTemp;
			strA = strA + str;
			strTemp.Format(_T("%g"), A[1]);
			strA = strA + strTemp;
			strA = strA + str;
			strTemp.Format(_T("%g"), A[2]);
			strA = strA + strTemp;

			strTemp.Format(_T("%g"), P[0]);
			strP = strP + strTemp;
			strP = strP + str;
			strTemp.Format(_T("%g"), P[1]);
			strP = strP + strTemp;
			strP = strP + str;
			strTemp.Format(_T("%g"), P[2]);
			strP = strP + strTemp;

			strTemp.Format(_T("%g"), exAxis[0]);
			strExAxis = strExAxis + strTemp;
			strExAxis = strExAxis + str;
			strTemp.Format(_T("%g"), exAxis[1]);
			strExAxis = strExAxis + strTemp;
			strExAxis = strExAxis + str;
			strTemp.Format(_T("%g"),exAxis[2]);
			strExAxis = strExAxis + strTemp;
			strExAxis = strExAxis + str;
			strTemp.Format(_T("%g"), exAxis[3]);
			strExAxis = strExAxis + strTemp;
			strExAxis = strExAxis + str;
			strTemp.Format(_T("%g"), exAxis[4]);
			strExAxis = strExAxis + strTemp;
			strExAxis = strExAxis + str;
			strTemp.Format(_T("%g"),exAxis[5]);
			strExAxis = strExAxis + strTemp;

			strTemp.Format(_T("%d"), mWord);
			strMWord = strMWord + strTemp;

			vResult.push_back(strN);
			vResult.push_back(strO);
			vResult.push_back(strA);
			vResult.push_back(strP);
			vResult.push_back(strExAxis);
			vResult.push_back(strMWord);
		}
	}
	if (apiName == _T("ReadTool"))
	{

		char * param = this->CStringToChar(Param1);
		BYTE ToolIndex = (BYTE)atoi(param);
		float Px;
		float Py;
		float Pz;
		float Rx;
		float Ry;
		float Rz;
		res = ReadTool(ToolIndex,Px,Py,Pz,Rx,Ry,Rz,connectID);

		if (res == 0)
		{
			CString str;
			CString strTemp;
			str = _T("ToolIndex: ");	
			strTemp.Format(_T("%d"), ToolIndex); 
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Px: ");	
			strTemp.Format(_T("%g"), Px); 
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Py: ");	
			strTemp.Format(_T("%g"), Py); 
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Pz: ");	
			strTemp.Format(_T("%g"), Pz); 
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Rx: ");	
			strTemp.Format(_T("%g"), Rx); 
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Ry: ");	
			strTemp.Format(_T("%g"), Ry); 
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Rz: ");	
			strTemp.Format(_T("%g"), Rz); 
			str = str + strTemp;
			vResult.push_back(str);
		}
		free(param);
	}
	if (apiName ==_T("ReadAlarm"))
	{
		char * param = this->CStringToChar(Param1);
		int ErrCode = atoi(param);
		res = ReadAlarm(ErrCode,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%d"), ErrCode);
			vResult.push_back(str);
		}
		free(param);
	}
	if (apiName == _T("ReadStatus"))
	{
		char * param = this->CStringToChar(Param1);
		int len = atoi(param);
		BYTE status[4];
		res = ReadStatus(status,len,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%s"), status[0]);
			vResult.push_back(str);
		}
		free(param);
	}
	if (apiName == _T("ReadUO"))
	{
		char * param = this->CStringToChar(Param1);
		int IOMap = atoi(param);
		BYTE IOStatus = 0;
		res = ReadUO(IOMap,IOStatus,connectID );
		if(res == 0)
		{
			CString str;
			str.Format(_T("%d"), IOStatus);
			vResult.push_back(str);
		}
		free(param);
	}
	if (apiName == _T("ReadGUO"))
	{
		char * param = this->CStringToChar(Param1);
		char * param2 = this->CStringToChar(Param2);
		int Channel = atoi(param);
		int IOGroupFlag = atoi(param2);
		int IOStatus = 0;
		res = ReadGUO(IOStatus, Channel,IOGroupFlag,connectID);
		if(res == 0)
		{
			CString str;
			str.Format(_T("%d"), IOStatus);
			vResult.push_back(str);
		}
		free(param);
	}
	if (apiName == _T("ReadUI"))
	{
		char * param = this->CStringToChar(Param1);
		int IOMap = atoi(param);
		BYTE IOStatus = 0;
		res = ReadUI(IOMap,IOStatus, connectID);
		if(res == 0)
		{
			CString str;
			str.Format(_T("%d"), IOStatus);
			vResult.push_back(str);
		}
		free(param);
	}
	if (apiName == _T("ReadGUI"))
	{
		char * param = this->CStringToChar(Param1);
		int Channel = atoi(param);
		char * param2 = this->CStringToChar(Param2);
		int IOGroupFlag = atoi(param2);
		int IOStatus = 0;
		res = ReadGUI(IOStatus, Channel,IOGroupFlag,connectID);
		if(res == 0)
		{
			CString str;
			str.Format(_T("%d"), IOStatus);
			vResult.push_back(str);
		}
		free(param);
	}
	/*if (apiName == _T("SetOfflineMode"))
	{
		res = SetOfflineMode(true,connectID);
	}*/
	/*if (apiName == _T("Start"))
	{
	res = Start(connectID);
	}
	if (apiName == _T("MovePause"))
	{
	res = MovePause(connectID);
	}*/
	if (apiName == _T("ClearBuffer"))
	{
		res = ClearBuffer(connectID);
	}
	
	if (apiName == _T("Movl_P2P"))
	{
		//6轴系统
		float N[3],O[3],A[3],P[3],exAxis[6];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		memset(exAxis,0,sizeof(exAxis));
		
		
		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		char *param = this->CStringToChar(Param5);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param6);
		float fSpeed = atof(param1);

		res = Movl_P2P(N,O,A,P,exAxis,Tool,fSpeed,connectID);

	}
	if (apiName == _T("Movl_CP"))
	{
		
		float N[3],O[3],A[3],P[3],exAxis[6];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		memset(exAxis,0,sizeof(exAxis));
		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		char *param = this->CStringToChar(Param5);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param6);
		float fSpeed = atof(param1);
		
		res = Movl_CP(N,O,A,P,exAxis,Tool,fSpeed,connectID);
		P[2] = P[2] + 1.0f;
		int res2 = Movl_CP(N,O,A,P,exAxis,Tool,fSpeed,connectID);
		P[2] = P[2] + 1.0f;
		int res3 = Movl_P2P(N,O,A,P,exAxis,Tool,fSpeed,connectID);


	}
	if (apiName == _T("Movj_P2P"))
	{
		float fJoint[12];
		memset(fJoint,0,sizeof(fJoint));
		GetParams(Param1,fJoint,6);
		fJoint[6] = 0.0f;
		fJoint[7] = 0.0f;
		fJoint[8] = 0.0f;
		fJoint[9] = 0.0f;
		fJoint[10] = 0.0f;
		fJoint[11] = 0.0f;
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movj_P2P(fJoint,Tool,fSpeed,connectID);
		/*fJoint[0] =  fJoint[0] + 10;
		res = Movj_P2P(fJoint,Tool,fSpeed,connectID);*/
	}
	if (apiName == _T("Movj_CP"))
	{
		float fJoint[12] = {10,10,10,0,0,0,0,0,0,0,0,0};
		memset(fJoint,0,sizeof(fJoint));
		GetParams(Param1,fJoint,6);
		fJoint[6] = 0.0f;
		fJoint[7] = 0.0f;
		fJoint[8] = 0.0f;
		fJoint[9] = 0.0f;
		fJoint[10] = 0.0f;
		fJoint[11] = 0.0f;
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movj_CP(fJoint,Tool,fSpeed,connectID);
		fJoint[0] =  fJoint[0] + 10;
		res = Movj_CP(fJoint,Tool,fSpeed,connectID);
		fJoint[0] =  fJoint[0] + 10;
		res = Movj_CP(fJoint,Tool,fSpeed,connectID);
		fJoint[0] =  fJoint[0] + 10;
		res = Movj_P2P(fJoint,Tool,fSpeed,connectID);
	}
	//add by tongyan 20150630   Movl_P2P_RPY和Movl_CP_RPY
	if(apiName == _T("Movl_P2P_RPY"))
	{
		float exAxis[6];
		float value[6];
		memset(exAxis,0,sizeof(exAxis));
		memset(value,0,sizeof(value));
		GetParams(Param1,value,6);
		RPY* rpy= new RPY;
		rpy->rx = value[0];
		rpy->ry = value[1];
		rpy->rz = value[2];
		rpy->px = value[3];
		rpy->py = value[4];
		rpy->pz = value[5];
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movl_P2P_RPY(rpy,exAxis ,Tool,fSpeed,connectID);

		if(rpy != NULL)
		{
			delete rpy;
		}
	}
	if(apiName == _T("Movl_CP_RPY"))
	{
		float exAxis[6];
		float value[6];
		memset(exAxis,0,sizeof(exAxis));
		memset(value,0,sizeof(value));
		GetParams(Param1,value,6);
		RPY* rpy = new RPY;
		rpy->rx = value[0];
		rpy->ry = value[1];
		rpy->rz = value[2];
		rpy->px = value[3];
		rpy->py = value[4];
		rpy->pz = value[5];
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movl_CP_RPY(rpy,exAxis ,Tool,fSpeed,connectID);
		float N[3],O[3],A[3],P[3];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		N[0]= 0.305486f;N[1]= -0.900789f;N[2]= -0.308639f;
		O[0] = 0.410864f;O[1] = 0.417105f;O[2] = -0.810688f;
		A[0] = 0.858993f;A[1] = 0.120845f;A[2] = 0.497521f;
		P[0] = 1780;
		P[1] = 305;
		P[2] = 1968;
		res = Movl_P2P(N,O,A,P,exAxis,Tool,fSpeed,connectID);
		if(rpy != NULL)
		{
			delete rpy;
		}

	}
	if (apiName == _T("Read_POSE_RPY"))
	{
		float exAxis[6];
		RPY* rpy = new RPY;
		res = ReadPOSE_RPY(rpy,exAxis,connectID);

		if (res == 0)
		{
			CString strN = _T("1.RPY->R:");
			CString strP = _T("1.RPY->P:");
			CString strMWord = _T("1.RPY->mWord:");
			CString str = _T(",");
			CString strTemp;

			strTemp.Format(_T("%g"), rpy->rx);
			strN = strN + strTemp;
			strN = strN + str;
			strTemp.Format(_T("%g"), rpy->ry);
			strN = strN + strTemp;
			strN = strN + str;
			strTemp.Format(_T("%g"), rpy->rz);
			strN = strN + strTemp;
			 
			strTemp.Format(_T("%g"), rpy->px);
			strP = strP + strTemp;
			strP = strP + str;
			strTemp.Format(_T("%g"), rpy->py);
			strP = strP + strTemp;
			strP = strP + str;
			strTemp.Format(_T("%g"), rpy->pz);
			strP = strP + strTemp;
			strTemp.Format(_T("%d"), rpy->mWord);
			strMWord = strMWord + strTemp;
			vResult.push_back(strN);
			vResult.push_back(strP);
			vResult.push_back(strMWord);
		}
	}
		
	if (apiName == _T("SendJobT6"))
	{
		CString filePath;
		BYTE jobStream[40960];
		int streamLenth = 0;
		int iConnect = connectID;
		CFileDialog dlg(TRUE);
		if(dlg.DoModal() == IDOK)
		{
			filePath = dlg.GetPathName();
			CFile file(filePath,CFile::modeRead);
			streamLenth = (int)file.GetLength();
			file.Read(jobStream,streamLenth);
			file.Close();  

			res = SendJobT6(jobStream, streamLenth, iConnect);
		}
	}
	if (apiName == _T("SendJobJts"))
	{
		CString filePath;
		BYTE jobStream[40960];
		int streamLenth = 0;
		int iConnect = connectID;

		CFileDialog dlg(TRUE);
		if(dlg.DoModal() == IDOK)
		{
			filePath = dlg.GetPathName(); 
			CFile file(filePath,CFile::modeRead);
			streamLenth = (int)file.GetLength();
			file.Read(jobStream,streamLenth);
			file.Close();  

			res = SendJobJts(jobStream, streamLenth, iConnect);
		}
	}
	if (apiName == _T("ReadJobNameList"))
	{
		int jobNumber = 0;
		char jobNameList[512];

		res = ReadJobNameList(jobNameList,jobNumber,connectID);

		unsigned char jobName[8] = {};

		
		for (int i = 0; i < jobNumber; i++)
		{
			for (int j =0 ;j < 8; j++)
			{
				jobName[j] = jobNameList[i*9+j];
			}
			if(res == 0)
			{
				CString str;
				//str.Format(_T("%s"), (char*)jobName);
				str = jobName;
				vResult.push_back(str);
			}
		}
		
		
	}
	if (apiName == _T("ReceiveJob"))
	{
		CString filePath;
		char* jobName ;
		jobName = CStringToChar(Param1);
		BYTE* jobStream = new BYTE[409600];
		int streamLenth = 0;
		res = ReceiveJob(jobName,jobStream, streamLenth, connectID);

		if (res == 0)
		{
			LPCTSTR szFilter = _T("JOB Files (*.Job)|*.job|");
			CString fileName; 
			fileName = "";
			
			CFileDialog dlg(FALSE,_T("job"),fileName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	
			if(dlg.DoModal() == IDOK)
			{
				fileName = dlg.GetPathName();
				CFile file;
				file.Open(fileName,CFile::modeCreate | CFile::modeReadWrite);
				file.Write(jobStream,streamLenth);  
				file.Close();  
			}

		}
		else
		{
			CString errorMessage = this->GetErrorMessage(res);
			vResult.push_back(errorMessage);
		}
		if(jobStream != NULL)
		{
			delete []jobStream;
		}
		free(jobName);
	}
	
	if (apiName == _T("ReadRCParam"))
	{
		T_SEND_ROBOT_PARA param;
		res = ReadRCParam(&param,connectID);
		if (res == 0)
		{
			CString strFC = _T("FC:");
			CString str = _T(",");
			CString strTemp;

			strTemp.Format(_T("%g"), param.fc_sensor[0]);
			strFC = strFC + strTemp;
			strFC = strFC + str;
			strTemp.Format(_T("%g"), param.fc_sensor[1]);
			strFC = strFC + strTemp;
			strFC = strFC + str;
			strTemp.Format(_T("%g"), param.fc_sensor[2]);
			strFC = strFC + strTemp;
			strFC = strFC + str;
			strTemp.Format(_T("%g"), param.fc_sensor[3]);
			strFC = strFC + strTemp;
			strFC = strFC + str;
			strTemp.Format(_T("%g"), param.fc_sensor[4]);
			strFC = strFC + strTemp;
			strFC = strFC + str;
			strTemp.Format(_T("%g"), param.fc_sensor[5]);
			strFC = strFC + strTemp;
			vResult.push_back(strFC);
		}
		

	}
	
	if (apiName == _T("SendRCInst"))
	{
		BYTE* RCInst;
		RCInst = (BYTE*)(LPCTSTR)Param1;
		INST tempInst;
		tempInst.code = 175;
		vector<string> strArray;
		strArray.push_back("30.5");
		strArray.push_back("0");
		strArray.push_back("1");
		strArray.push_back("0");
		strArray.push_back("0");
		strArray.push_back("0");
		strArray.push_back("1");
		strArray.push_back("100.5");
		strArray.push_back("300");
		strArray.push_back("200");
		strArray.push_back("5");
		strArray.push_back("0");
		strArray.push_back("0");
		strArray.push_back("0");
		for (int i = 0;i<(int)strArray.size();i++)
		{
			string tempStr = strArray[i];
			for (int j = 0;j<(int)tempStr.length();j++)
			{
				tempInst.para[i].val[j] = tempStr[j];
			}
			tempInst.para[i].val[tempStr.length()] = '\0';
		}

		
		res = Send_RCInst(tempInst,connectID);
	}
	if (apiName == _T("DelJob"))
	{
		char* jobName ;
		jobName = CStringToChar(Param1);
		res = DelJob(jobName,connectID);
		free(jobName);
	}
	if (apiName == _T("ClearJobList"))
	{
		res = ClearJobList(connectID);
	}
	if (apiName == _T("OpenJob"))
	{
		char* jobName ;
		jobName = CStringToChar(Param1);
		res = OpenJob(jobName,connectID);
		free(jobName);
	}
	if (apiName == _T("WriteUserVarBYTE"))
	{
		int varID;
		BYTE varBYTE;
		varID = _ttoi(Param1);
		varBYTE = (BYTE)_ttoi(Param2);
		res = WriteUserVarBYTE(varID, varBYTE,connectID);
	}
	if (apiName == _T("WriteUserVarINT"))
	{
		int varID;
		int varINT;
		varID = _ttoi(Param1);
		string strIntVal = CT2CA(Param2.GetBuffer(0));
		bool isValTypeError = false;
		for(int i = 0;i<(int)strIntVal.size();i++)
		{
			if(strIntVal[i] == '.')
			{
				isValTypeError = true;
				break;
			}
		}
		if(isValTypeError == false)
		{
			varINT = _ttoi(Param2);
			res = WriteUserVarINT(varID, varINT,connectID);
		}
		else
		{
			res = -100;
		}
		
	}
	if (apiName == _T("WriteUserVarFLOAT"))
	{
		int varID;
		float varFloat;
		varID = _ttoi(Param1);
		char * param = this->CStringToChar(Param2);
		varFloat = (float)atof(param);
		res =  WriteUserVarFLOAT( varID, varFloat,connectID);
		free(param);
	}
	if (apiName == _T("WriteUserVarRPY"))
	{
		int varID;
		varID = _ttoi(Param1);
		RPY varRPY;
		float rpy[6],exAxis[3];
		int coordinate;
		int TOOLNUM;
		int USERNUM;
		int mWord;
		
		memset(rpy,0,sizeof(rpy));
		memset(exAxis,0,sizeof(exAxis));
		GetParams(Param2,rpy,6);
		GetParams(Param3,exAxis,3);//mod by tongyan 20150722,原先为6
		mWord = _ttoi(Param7);
		coordinate = _ttoi(Param4);
		TOOLNUM = _ttoi(Param5);
		USERNUM = _ttoi(Param6);
		varRPY.px = rpy[0];
		varRPY.py = rpy[1];
		varRPY.pz = rpy[2];
		varRPY.rx = rpy[3];
		varRPY.ry = rpy[4];
		varRPY.rz = rpy[5];
		varRPY.mWord = mWord ;
		CString str1 = _T("1.RPY:");
		CString str2 = _T("2.EXAIS:");
		CString str3 = _T("3.coordinate:");
		CString str4 = _T("4.TOOLNUM:");
		CString str5 = _T("5.USERNUM:");
		CString str6 = _T("6.mWord:");
		CString str = _T(",");
		CString strTemp;

		strTemp.Format(_T("%g"), varRPY.px);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.py);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.pz);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.rx);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.ry);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.rz);
		str1 = str1 + strTemp;
		str1 = str1 + str;	

		strTemp.Format(_T("%g"),exAxis[0] );
		str2 = str2 + strTemp;
		str2 = str2 + str;	
		strTemp.Format(_T("%g"), exAxis[1]);
		str2 = str2 + strTemp;
		str2 = str2 + str;	
		strTemp.Format(_T("%g"), exAxis[2]);
		str2 = str2 + strTemp;
		str2 = str2 + str;	

		strTemp.Format(_T("%d"),coordinate );
		str3 = str3+ strTemp;

		strTemp.Format(_T("%d"),TOOLNUM);
		str4 = str4 + strTemp;

		strTemp.Format(_T("%d"), USERNUM);
		str5 = str5 + strTemp;
		strTemp.Format(_T("%d"), varRPY.mWord);
		str6 = str6 + strTemp;

		vResult.push_back(str1);
		vResult.push_back(str2);
		vResult.push_back(str3);
		vResult.push_back(str4);
		vResult.push_back(str5);
		vResult.push_back(str6);
		//return vResult;
		res =WriteUserVarRPY(varID,varRPY, exAxis, coordinate, TOOLNUM,USERNUM,connectID);
	}

	if (apiName == _T("WriteUserVarRPYS"))
	{
		int varID;
		varID = _ttoi(Param1);
		RPY varRPY;
		float rpy[6],exAxis[3];
		int coordinate;
		int TOOLNUM;
		int USERNUM;
		int mWord;

		memset(rpy,0,sizeof(rpy));
		memset(exAxis,0,sizeof(exAxis));
		GetParams(Param2,rpy,6);
		GetParams(Param3,exAxis,3);//mod by tongyan 20150722,原先为6
		mWord = _ttoi(Param7);
		coordinate = _ttoi(Param4);
		TOOLNUM = _ttoi(Param5);
		USERNUM = _ttoi(Param6);
		varRPY.px = rpy[0];
		varRPY.py = rpy[1];
		varRPY.pz = rpy[2];
		varRPY.rx = rpy[3];
		varRPY.ry = rpy[4];
		varRPY.rz = rpy[5];
		varRPY.mWord = mWord ;
		CString str1 = _T("1.RPY:");
		CString str2 = _T("2.EXAIS:");
		CString str3 = _T("3.coordinate:");
		CString str4 = _T("4.TOOLNUM:");
		CString str5 = _T("5.USERNUM:");
		CString str6 = _T("6.mWord:");
		CString str = _T(",");
		CString strTemp;

		strTemp.Format(_T("%g"), varRPY.px);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.py);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.pz);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.rx);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.ry);
		str1 = str1 + strTemp;
		str1 = str1 + str;	
		strTemp.Format(_T("%g"), varRPY.rz);
		str1 = str1 + strTemp;
		str1 = str1 + str;	

		strTemp.Format(_T("%g"),exAxis[0] );
		str2 = str2 + strTemp;
		str2 = str2 + str;	
		strTemp.Format(_T("%g"), exAxis[1]);
		str2 = str2 + strTemp;
		str2 = str2 + str;	
		strTemp.Format(_T("%g"), exAxis[2]);
		str2 = str2 + strTemp;
		str2 = str2 + str;	

		strTemp.Format(_T("%d"),coordinate );
		str3 = str3+ strTemp;

		strTemp.Format(_T("%d"),TOOLNUM);
		str4 = str4 + strTemp;

		strTemp.Format(_T("%d"), USERNUM);
		str5 = str5 + strTemp;
		strTemp.Format(_T("%d"), varRPY.mWord);
		str6 = str6 + strTemp;

		vResult.push_back(str1);
		vResult.push_back(str2);
		vResult.push_back(str3);
		vResult.push_back(str4);
		vResult.push_back(str5);
		vResult.push_back(str6);
		//return vResult;
		res =WriteUserVarRPYS(varID,varRPY, exAxis, coordinate, TOOLNUM,USERNUM,connectID);
	}
	if (apiName == _T("SendRectifyData"))
	{
		int varID;
		RPY varRPY;
		float rpy[6],exAxis[3];
		int coordType;
		int coordNum;
		memset(rpy,0,sizeof(rpy));
		memset(exAxis,0,sizeof(exAxis));
		GetParams(Param1,rpy,6);
		GetParams(Param2,exAxis,6);
		coordType = _ttoi(Param3);
		coordNum = _ttoi(Param4);
		varRPY.px = rpy[0];
		varRPY.py = rpy[1];
		varRPY.pz = rpy[2];
		varRPY.rx = rpy[3];
		varRPY.ry = rpy[4];
		varRPY.rz = rpy[5];
		res =SendRectifyData(varRPY, exAxis, coordType,coordNum,connectID);
	}
	if (apiName == _T("ARCON"))
	{
		res = ARCON(connectID);
	}
	if (apiName == _T("ARCONSet"))
	{
		float varI;
		float varU;
		char * param = this->CStringToChar(Param1);
		varI = (float)atof(param);
		param = this->CStringToChar(Param2);
		varU = (float)atof(param);
		res = ARCONSet(varI, varU,connectID);
		free(param);
		
	}	
	if (apiName == _T("ARCONASF"))
	{
		short ASFNumber;
		ASFNumber = (short)_ttoi(Param1);
		res = ARCONASF(ASFNumber,connectID);
	}
	if (apiName == _T("ARCOFF"))
	{
		res = ARCOFF(connectID);
	}
	if (apiName == _T("ARCOFFSet"))
	{
		float varI;
		float varU;
		char * param = this->CStringToChar(Param1);
		varI = (float)atof(param);
		param = this->CStringToChar(Param2);
		varU = (float)atof(param);
		res = ARCOFFSet(varI, varU,connectID);
		free(param);
	}
	if (apiName == _T("ARCOFFASF"))
	{
		short ASFNumber;
		ASFNumber = (short)_ttoi(Param1);
		res = ARCOFFASF(ASFNumber,connectID);
	}
	if (apiName == _T("SendJobNet"))
	{
		CString filePath;
		BYTE* jobStream = new BYTE[409600];
		int streamLenth = 0;
		int iConnect = connectID;

		CFileDialog dlg(TRUE);
		if(dlg.DoModal() == IDOK)
		{
			filePath = dlg.GetPathName(); 
			CFile file(filePath,CFile::modeRead);
			streamLenth = (int)file.GetLength();
			file.Read(jobStream,streamLenth);
			file.Close();  

			res = SendJobNet(jobStream, streamLenth, iConnect);
		}
		if(jobStream != NULL)
		{
			delete []jobStream;
		}
	}
	if (apiName == _T("Wait"))
	{
		int IoMap;
		BYTE IoStatus;
		IoMap = _ttoi(Param1);
		IoStatus = (BYTE)_ttoi(Param2);
		res = Wait(IoMap,IoStatus,connectID);
	}
	if (apiName == _T("DO_Out"))//mod by tongyan  20170710 
	{
		int IoMap;
		char *param;
		IoMap = _ttoi(Param1);
		param = this->CStringToChar(Param2);
		BYTE IoStatus = (BYTE)atoi(param);
		res = DO_Out(IoMap,IoStatus,connectID);
		free(param);
	}
	if (apiName == _T("DGO_Out"))
	{
		int IOStatus = _ttoi(Param1);
		int Channel =  _ttoi(Param2);
		res = DGO_Out(IOStatus, Channel,connectID);
	}
	if (apiName == _T("DGO_Out8"))
	{
		int IOStatus = _ttoi(Param1);
		int Channel =  _ttoi(Param2);
		res = DGO_Out8(IOStatus, Channel,connectID);
	}
	if (apiName == _T("WriteGUO"))
	{
		int IOStatus = _ttoi(Param1);
		int Channel =  _ttoi(Param2);
		int IOGroupFlag =  _ttoi(Param3);
		res = WriteGUO(IOStatus, Channel,IOGroupFlag,connectID);
	}
	if (apiName == _T("WriteUO")) //mod by tongyan  20170710 库里的char型其实是unsigned Char
	{
		int IOMap = _ttoi(Param1);
		char *param;
		param = this->CStringToChar(Param2);
		BYTE IoStatus =(BYTE) atoi(param);
		res = WriteUO(IOMap, IoStatus,connectID);
		free(param);
	}
	if (apiName == _T("SimWriteGUI"))
	{
		int IOStatus = _ttoi(Param1);
		int Channel =  _ttoi(Param2);
		int IOGroupFlag =  _ttoi(Param3);
		res = SimWriteGUI(IOStatus, Channel,IOGroupFlag,connectID);
	}
	if (apiName == _T("SimWriteUI"))
	{
		int IOMap= _ttoi(Param1);
		char *param;
		param = this->CStringToChar(Param2);
		BYTE IoStatus =(BYTE) atoi(param);
		res = SimWriteUI(IOMap, IoStatus,connectID);
		free(param);
	}
	if (apiName == _T("Delay"))
	{ 
		float DelayTime ;
		char * param = this->CStringToChar(Param1);
		DelayTime = (float)atof(param);
		res = Delay(DelayTime,connectID);
		free(param);
	}
	if (apiName == _T("ChangeJobRunMode"))
	{ 
		BYTE mode ;
		char * param = this->CStringToChar(Param1);
		mode = (BYTE)atoi(param);
		res =ChangeJobRunMode(mode,connectID);
		free(param);
	}
	
	//if (apiName == _T("RemoteControl"))
	//{
	//	/*
	//	char* strIP = CStringToChar(Param1);
	//	char * param = this->CStringToChar(Param2);

	//	if (atoi(param) == 1)
	//	{
	//		RemoteControl(strIP,false);
	//	}
	//	if (atoi(param) == 0)
	//	{
	//		RemoteControl(strIP,true);
	//	}
	//	*/
	//}
	if (apiName == _T("Read_MainJobOpen"))
	{
		res = Read_MainJobOpen(connectID);
	
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_SafeDoor"))
	{
		res = Read_SafeDoor(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_OnPath"))
	{
		res = Read_OnPath(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_Position1"))
	{
		res = Read_Position1(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_Position2"))
	{
		res = Read_Position2(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_Warning"))
	{
		res = Read_Warning(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_Online"))
	{
		res = Read_Online(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_AutoRun"))
	{
		res = Read_AutoRun(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_PowerOn"))
	{
		res = Read_PowerOn(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_Play"))
	{
		res = Read_Play(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_MainJobRun"))
	{
		res = Read_MainJobRun(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	if (apiName == _T("Read_Teach"))
	{
		res = Read_Teach(connectID);
		if (res >= 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	}
	
	if (apiName ==_T("Read_OfflineVersion"))
	{
		char version[100]= {};
		res = ReadOfflineVersion(version,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
			str = version;
			vResult.push_back(str);
		}
	}
	//add by tongyan 20151119

	if (apiName ==_T("Read_BYTE_USERVAR"))
	{
		int varID = _ttoi(Param1);
		BYTE var;
		res = ReadUserVarBYTE(varID,var,connectID);
		if (res == 0)
		{
			CString str;	
			str.Format(_T("%d"), var); 
			vResult.push_back(str);
		}
	}
	if (apiName ==_T("Read_INT_USERVAR"))
	{
		int varID = _ttoi(Param1);
		int varINT;
		res = ReadUserVarINT(varID,varINT,connectID);
		if (res == 0)
		{
			CString str;	
			str.Format(_T("%d"), varINT); 
			vResult.push_back(str);
		}
	}
	
	if (apiName ==_T("Read_FLOAT_USERVAR"))
	{
		int varID = _ttoi(Param1);
		float varF;
		res = ReadUserVarFLOAT(varID,varF,connectID);
		if (res == 0)
		{
			CString str;	
			str.Format(_T("%f"), varF); 
			vResult.push_back(str);
		}
	}


	if (apiName ==_T("Read_RPY_USERVAR"))
	{
		int varID = _ttoi(Param1);
		RPY varRPY;
		float exAxis[6] = {-1,-1,-1,-1,-1,-1};
		int coordinate = 0;
		int ToolNum = 0;
		int UserNum =0;
		res = ReadUserVarRPY(varID,&varRPY,exAxis,coordinate,ToolNum,UserNum,connectID);
		if (res == 0)
		{
			CString str;	
			str.Format(_T("%f %f %f %f %f %f "), varRPY.rx,varRPY.ry,varRPY.rz,varRPY.px,varRPY.py,varRPY.pz);
			CString strTemp;
			strTemp.Format(_T("%f %f %f %f %f %f"),exAxis[0],exAxis[1],exAxis[2],exAxis[3],exAxis[4],exAxis[5]);
			CString strTemp1;
			strTemp1.Format(_T("%d"),coordinate);
			CString strTemp2;
			strTemp2.Format(_T("%d"),ToolNum);
			CString strTemp3;
			strTemp3.Format(_T("%d"),UserNum);
			vResult.push_back(str);
			vResult.push_back(strTemp);
			vResult.push_back(strTemp1);
			vResult.push_back(strTemp2);
			vResult.push_back(strTemp3);
		}
	}
	if (apiName == _T("Read_AXISNUM"))
	{
		int axisNum = 0;
		res = Read_AxisNum(axisNum,connectID);
		if (res == 0)
		{
			CString str;	
			str.Format(_T("%d"), axisNum); 
			vResult.push_back(str);
		}
	}
	if (apiName ==_T("Read_INT_SYSVAR"))
	{
		int varID1 = _ttoi(Param1);
		int varINT1;
		res = ReadSysVarINT(varID1,varINT1,connectID);
		if (res == 0)
		{
			CString str;	
			str.Format(_T("%d"), varINT1); 
			vResult.push_back(str);
		}
	}
	/*if (apiName ==_T("Read_FLOAT_SYSVAR"))
	{
	int varID = _ttoi(Param1);
	float varF;
	res = ReadSysVarFLOAT(varID,varF,connectID);
	if (res == 0)
	{
	CString str;	
	str.Format(_T("%f"), varF); 
	vResult.push_back(str);
	}
	}*/
	
	if (apiName ==_T("Send_StackProData"))
	{
		short filenum = 1;
		PALL_FILE_PRO prodata;
		prodata.product_length = 10; //产品长
		prodata.product_wide =5; //产品宽
		prodata.product_height = 5; //产品高
		prodata.product_weight =10; //产品重量 
		prodata.pallet_length = 20; //托盘长
		prodata.pallet_wide =30; //托盘宽
		prodata.pallet_height = 30; //托盘高
		prodata.row_space = 5; //行间距
		prodata.col_space = 6; //列间距
		prodata.stacktype = (stack_type)0; //垛型
		prodata.stacklayernum = 1;  //垛型层数
		prodata.stackrownum = 2;//行数
		prodata.stackcolnum = 3;//列数
		prodata.verirownum = 4;//型1行数
		prodata.vericolnum = 5;//型1列数
		prodata.horirownum = 6;//型2行数
		prodata.horicolnum = 7;//型2列数
		prodata.startform = 8;//起始形式
		prodata.imageflag = 9;//镜像开关
		res = SendStackProData(filenum,prodata,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	
	}

	if (apiName ==_T("Send_StackCount"))
	{
		short filenum = 1;
		pall_file_counter counter;
		counter.flagcountnum = 1;
		counter.flagrownum = 10;
		counter.flagcolnum = 5;
		counter.flaglayernum = 6;
		counter.flagstepnum = 5;
		
		res = SendStackCount(filenum,counter,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
	
	}

	if (apiName ==_T("Send_StackPointData"))
	{
		CString filePath;
		BYTE pointStream[4096*10];
		int streamLenth = 0;
		int iConnect = connectID;
		CFileDialog dlg(TRUE);
		if(dlg.DoModal() == IDOK)
		{
			filePath = dlg.GetPathName();
			CFile file(filePath,CFile::modeRead);
			streamLenth = (int)file.GetLength();
			file.Read(pointStream,streamLenth);
			file.Close();  

			short filenum = _tstoi(LPCTSTR(Param1));
			res = SendStackPointData(filenum, (BYTE*)(pointStream), streamLenth, connectID);
			if (res == 0)
			{	
				CString str;
				str.Format(_T("%d"), res);
				vResult.push_back(str);
			} 
		}
	}
	if (apiName ==_T("Send_StackPointData2"))
	{
		CString filePath;
		BYTE pointStream[4096*10];
		int streamLenth = 0;
		int iConnect = connectID;
		CFileDialog dlg(TRUE);
		if(dlg.DoModal() == IDOK)
		{
			filePath = dlg.GetPathName();
			CFile file(filePath,CFile::modeRead);
			streamLenth = (int)file.GetLength();
			file.Read(pointStream,streamLenth);
			file.Close();  

			short filenum = _tstoi(LPCTSTR(Param1));
			res = SendStackPointData2(filenum, (BYTE*)(pointStream), streamLenth, connectID);
			if (res == 0)
			{	
				CString str;
				str.Format(_T("%d"), res);
				vResult.push_back(str);
			} 
		}
	}
	if(apiName == _T("ReadCurStacCount"))
	{
		short filenum = _tstoi(LPCTSTR(Param1));
		int count = 0;
		res =ReadCurStacCount(filenum,count,connectID);
		if (res == 0)
		{	
			CString str;
			str.Format(_T("%d"), count);
			vResult.push_back(str);
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		} 

	}

	if(apiName == _T("SendStackFileNum"))
	{
		short filenum = _tstoi(LPCTSTR(Param1));
		res =SendStackFileNum(filenum,connectID);
		if (res == 0)
		{	
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		} 

	}

	if(apiName ==_T("Read_RobAllData"))
	{
		BYTE* dataStream = new BYTE[40960];
		int streamLenth = 0;
		res = ReadRobAllData(dataStream,streamLenth,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
		if(dataStream != NULL)
		{
			delete []dataStream;
		}
	}
	if(apiName ==_T("Read_WeldAllData"))
	{

		BYTE* dataStream = new BYTE[40960];
		int streamLenth = 0;
		res = ReadWeldAllData(dataStream,streamLenth,connectID);
		if (res == 0)
		{
			CString str;
			str.Format(_T("%d"), res);
			vResult.push_back(str);
		}
		if(dataStream != NULL)
		{
			delete []dataStream;
		}
	}


	/*if(apiName ==_T("Send_SysIO"))
	{
		int sysIO = _ttoi(Param1);
		res = Send_SysIO(sysIO,connectID);
	}*/
	if(apiName ==_T("Send_Open"))
	{
		res = Send_Open(connectID);
	}
	if(apiName ==_T("Send_Reset"))
	{
		res = Send_Reset(connectID);
	}
	if(apiName ==_T("Send_Pause"))
	{
		res = Send_Pause(connectID);
	}
	if(apiName ==_T("Send_Stop"))
	{
		res = Send_Stop(connectID);
	}
	if(apiName ==_T("Send_SafeDoorOFF"))
	{
		res = Send_SafeDoorOFF(connectID);
	}
	if(apiName ==_T("Send_PowerOn"))
	{
		res = Send_PowerOn(connectID);
	}
	if(apiName ==_T("Send_Start"))
	{
		res = Send_Start(connectID);
	}

	
	if(apiName == _T("Send_StackFlagData"))
	{
		PALL_FLAG_MSG flag;
		flag.filenum = (short)_tstoi(LPCTSTR(Param1));
		flag.realtotalnum = (int)_tstoi(LPCTSTR(Param2));
		flag.breakflag = (int)_tstoi(LPCTSTR(Param3));
		flag.stackcount = (int)_tstoi(LPCTSTR(Param4));
		flag.breakcount = (int)_tstoi(LPCTSTR(Param5));
		res = SendStackFlagData(flag,connectID);

	}
	if(apiName == _T("Read_JointBaseNOAP"))
	{
		float N[3],O[3],A[3],P[3];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		float pJoint[12];
		char * param = this->CStringToChar(Param5);
		int JointNum = atoi(param);;
		res = ReadJointBaseNOAP(N,O,A,P,JointNum,pJoint,connectID);
		if (res == 0)
		{
			for (int i = 0; i < JointNum; i++)
			{
				CString str = _T("J");
				CString strTemp;
				strTemp.Format(_T("%d"), i +1);
				str = str + strTemp + _T(": ");
				float f =  pJoint[i];
				strTemp.Format(_T("%g"), f);
				str = str + strTemp;
				vResult.push_back(str);
			}
		}
		free(param);

	}
	if (apiName == _T("SendWeldCraftPara"))
	{
		CString filePath;
		BYTE dataStream[4096*10];
		int streamLenth = 0;
		int iConnect = connectID;
		CFileDialog dlg(TRUE);
		if(dlg.DoModal() == IDOK)
		{
			filePath = dlg.GetPathName();
			CFile file(filePath,CFile::modeRead);
			streamLenth = (int)file.GetLength();
			file.Read(dataStream,streamLenth);
			file.Close();  

			res = SendWeldCraftPara((BYTE*)(dataStream), streamLenth, connectID);
			if (res == 0)
			{	
				CString str;
				str.Format(_T("%d"), res);
				vResult.push_back(str);
			} 
		}
	}
	//add by tongyan 20171106
	if(apiName == _T("SetAxisInsertData"))
	{
		int fileName = _ttoi(Param1);
		AXIS_INTERF_DATA data;
		data.enable = (BYTE) (_ttoi(Param2));
		res = SetAxisInsertData(fileName,data,connectID);

	}
	if(apiName == _T("SetCubeInsertData"))
	{
		int fileName = _ttoi(Param1);
		CUBE_INTERF_DATA data;
		data.enable = (BYTE) (_ttoi(Param2));
		res = SetCubeInsertData(fileName,data,connectID);
	}
	if(apiName == _T("Send_ShiftOnP"))
	{
		int posNum = _ttoi(Param1);
		int corrdingNum = _ttoi(Param2);
		res = Send_ShiftOnP(posNum,corrdingNum,connectID);

	}

	if(apiName == _T("Send_ShiftOnPOff"))
	{
		res = Send_ShiftOnPOff(connectID);

	}
	if (apiName == _T("Movj_P2P_NOAP"))
	{
		//6轴系统
		float N[3],O[3],A[3],P[3],exAxis[6];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		memset(exAxis,0,sizeof(exAxis));


		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		char *param = this->CStringToChar(Param5);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param6);
		float fSpeed = atof(param1);

		res = Movj_P2P_NOAP(N,O,A,P,exAxis,Tool,fSpeed,connectID);

	}
	if (apiName == _T("Movj_CP_NOAP"))
	{

		float N[3],O[3],A[3],P[3],exAxis[6];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		memset(exAxis,0,sizeof(exAxis));
		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		char *param = this->CStringToChar(Param5);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param6);
		float fSpeed = atof(param1);

		res = Movj_CP_NOAP(N,O,A,P,exAxis,Tool,fSpeed,connectID);
		P[2] = P[2] + 1.0f;
		int res2 = Movj_CP_NOAP(N,O,A,P,exAxis,Tool,fSpeed,connectID);
		P[2] = P[2] + 1.0f;
		int res3 = Movj_CP_NOAP(N,O,A,P,exAxis,Tool,fSpeed,connectID);
		P[2] = P[2] + 1.0f;
		res = Movj_P2P_NOAP(N,O,A,P,exAxis,Tool,fSpeed,connectID);

	}
	if(apiName == _T("Movj_P2P_RPY"))
	{
		float exAxis[6];
		float value[6];
		memset(exAxis,0,sizeof(exAxis));
		memset(value,0,sizeof(value));
		GetParams(Param1,value,6);
		RPY* rpy= new RPY;
		rpy->rx = value[0];
		rpy->ry = value[1];
		rpy->rz = value[2];
		rpy->px = value[3];
		rpy->py = value[4];
		rpy->pz = value[5];
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movj_P2P_RPY(rpy,exAxis ,Tool,fSpeed,connectID);

		if(rpy != NULL)
		{
			delete rpy;
		}
	}
	if(apiName == _T("Movj_CP_RPY"))
	{
		float exAxis[6];
		float value[6];
		memset(exAxis,0,sizeof(exAxis));
		memset(value,0,sizeof(value));
		GetParams(Param1,value,6);
		RPY* rpy = new RPY;
		rpy->rx = value[0];
		rpy->ry = value[1];
		rpy->rz = value[2];
		rpy->px = value[3];
		rpy->py = value[4];
		rpy->pz = value[5];
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movj_CP_RPY(rpy,exAxis ,Tool,fSpeed,connectID);
		rpy->pz = value[5] + 1;
		res = Movj_CP_RPY(rpy,exAxis ,Tool,fSpeed,connectID);
		res = Movj_P2P_RPY(rpy,exAxis ,Tool,fSpeed,connectID);
		if(rpy != NULL)
		{
			delete rpy;
		}
	}
	if(apiName == _T("SetToolCoordinate"))
	{
		int coordNum;
		coordNum = _ttoi(Param1);
		RPY rpyVal;
		float rpy[6];
		memset(rpy,0,sizeof(rpy));
		GetParams(Param2,rpy,6);
		rpyVal.rx = rpy[0];
		rpyVal.ry = rpy[1];
		rpyVal.rz = rpy[2];
		rpyVal.px = rpy[3];
		rpyVal.py = rpy[4];
		rpyVal.pz = rpy[5];
		rpyVal.mWord = 0;
		res =SetToolCoordinate(coordNum,rpyVal,connectID);

	}
	if(apiName == _T("SetUserCoordinate"))
	{
		int coordNum;
		coordNum = _ttoi(Param1);
		RPY rpyVal;
		float rpy[6];
		memset(rpy,0,sizeof(rpy));
		GetParams(Param2,rpy,6);
		rpyVal.rx = rpy[0];
		rpyVal.ry = rpy[1];
		rpyVal.rz = rpy[2];
		rpyVal.px = rpy[3];
		rpyVal.py = rpy[4];
		rpyVal.pz = rpy[5];
		rpyVal.mWord = 0;
		res =SetUserCoordinate(coordNum,rpyVal,connectID);
	}
	if (apiName == _T("ReadForceControlData"))
	{
		double Fx;
		double Fy;
		double Fz;
		double Mx;
		double My;
		double Mz;
		res = ReadForceControlData(Fx, Fy, Fz, Mx, My, Mz, connectID);

		if (res == 0)
		{
			CString str;
			CString strTemp;
			str = _T("Fx: ");
			strTemp.Format(_T("%f"), Fx);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Fy: ");
			strTemp.Format(_T("%f"), Fy);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Fz: ");
			strTemp.Format(_T("%f"), Fz);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Mx: ");
			strTemp.Format(_T("%f"), Mx);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("My: ");
			strTemp.Format(_T("%f"), My);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Mz: ");
			strTemp.Format(_T("%f"), Mz);
			str = str + strTemp;
			vResult.push_back(str);
		}
	}
	if (apiName == _T("ReadVisualSenseData"))
	{
		int checkout;
		float x;
		float y;
		float Rz;
		res = ReadVisualSenseData(checkout, x, y, Rz, connectID);

		if (res == 0)
		{
			CString str;
			CString strTemp;
			str = _T("校验值: ");
			strTemp.Format(_T("%d"), checkout);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("x: ");
			strTemp.Format(_T("%g"), x);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("y: ");
			strTemp.Format(_T("%g"), y);
			str = str + strTemp;
			vResult.push_back(str);
			str = _T("Rz: ");
			strTemp.Format(_T("%g"), Rz);
			str = str + strTemp;
			vResult.push_back(str);
		}
	}
		if (apiName == _T("Movl_P2P_NoEndBack"))
	{
		//6轴系统
		float N[3],O[3],A[3],P[3],exAxis[6];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		memset(exAxis,0,sizeof(exAxis));


		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		char *param = this->CStringToChar(Param5);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param6);
		float fSpeed = atof(param1);

		res = Movl_P2P_NoEndBack(N,O,A,P,exAxis,Tool,fSpeed,connectID);

	}

	if (apiName == _T("Movj_P2P_NOAP_NoEndBack"))
	{
		//6轴系统
		float N[3],O[3],A[3],P[3],exAxis[6];
		memset(N,0,sizeof(N));
		memset(O,0,sizeof(O));
		memset(A,0,sizeof(A));
		memset(P,0,sizeof(P));
		memset(exAxis,0,sizeof(exAxis));


		GetParams(Param1,N,3);
		GetParams(Param2,O,3);
		GetParams(Param3,A,3);
		GetParams(Param4,P,3);
		char *param = this->CStringToChar(Param5);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param6);
		float fSpeed = atof(param1);

		res = Movj_P2P_NOAP_NoEndBack(N,O,A,P,exAxis,Tool,fSpeed,connectID);

	}

	if(apiName == _T("Movj_P2P_RPY_NoEndBack"))
	{
		float exAxis[6];
		float value[6];
		memset(exAxis,0,sizeof(exAxis));
		memset(value,0,sizeof(value));
		GetParams(Param1,value,6);
		RPY* rpy= new RPY;
		rpy->rx = value[0];
		rpy->ry = value[1];
		rpy->rz = value[2];
		rpy->px = value[3];
		rpy->py = value[4];
		rpy->pz = value[5];
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movj_P2P_RPY_NoEndBack(rpy,exAxis ,Tool,fSpeed,connectID);

		if(rpy != NULL)
		{
			delete rpy;
		}
	}

	if (apiName == _T("Movj_P2P_NoEndBack"))
	{
		float fJoint[12];
		memset(fJoint,0,sizeof(fJoint));
		GetParams(Param1,fJoint,6);
		fJoint[6] = 0.0f;
		fJoint[7] = 0.0f;
		fJoint[8] = 0.0f;
		fJoint[9] = 0.0f;
		fJoint[10] = 0.0f;
		fJoint[11] = 0.0f;
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movj_P2P_NoEndBack(fJoint,Tool,fSpeed,connectID);
		/*fJoint[0] =  fJoint[0] + 10;
		res = Movj_P2P(fJoint,Tool,fSpeed,connectID);*/
	}

	if(apiName == _T("Movl_P2P_RPY_NoEndBack"))
	{
		float exAxis[6];
		float value[6];
		memset(exAxis,0,sizeof(exAxis));
		memset(value,0,sizeof(value));
		GetParams(Param1,value,6);
		RPY* rpy= new RPY;
		rpy->rx = value[0];
		rpy->ry = value[1];
		rpy->rz = value[2];
		rpy->px = value[3];
		rpy->py = value[4];
		rpy->pz = value[5];
		char *param = this->CStringToChar(Param2);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param3);
		float fSpeed = atof(param1);
		res = Movl_P2P_RPY_NoEndBack(rpy,exAxis ,Tool,fSpeed,connectID);

		if(rpy != NULL)
		{
			delete rpy;
		}
	}

	if (apiName == _T("Movc_P2P"))
	{
		//12轴系统
		float NAss[3],OAss[3],AAss[3],PAss[3],exAxisAss[6],NTar[3],OTar[3],ATar[3],PTar[3],exAxisTar[6];
		memset(NAss,0,sizeof(NAss));
		memset(OAss,0,sizeof(OAss));
		memset(AAss,0,sizeof(AAss));
		memset(PAss,0,sizeof(PAss));
		memset(exAxisAss,0,sizeof(exAxisAss));
		memset(NTar,0,sizeof(NTar));
		memset(OTar,0,sizeof(OTar));
		memset(ATar,0,sizeof(ATar));
		memset(PTar,0,sizeof(PTar));
		memset(exAxisTar,0,sizeof(exAxisTar));


		GetParams(Param1,NAss,3);
		GetParams(Param2,OAss,3);
		GetParams(Param3,AAss,3);
		GetParams(Param4,PAss,3);
		GetParams(Param5,NTar,3);
		GetParams(Param6,OTar,3);
		GetParams(Param7,ATar,3);
		GetParams(Param8,PTar,3);
		char *param = this->CStringToChar(Param9);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param10);
		float fSpeed = atof(param1);
		char *param2 = this->CStringToChar(Param11);
		int CircleSeg = atoi(param2);
		ROB_POS posAss;
		ROB_POS posTar;
		for(int i = 0;i<3;i++)
		{
			posAss.N[i] = NAss[i];
			posAss.O[i] = OAss[i];
			posAss.A[i] = AAss[i];
			posAss.P[i] = PAss[i];
			posTar.N[i] = NTar[i];
			posTar.O[i] = OTar[i];
			posTar.A[i] = ATar[i];
			posTar.P[i] = PTar[i];
		}
		for(int i = 0;i<6;i++)
		{
			posAss.exAxis[i] = exAxisAss[i];
			posTar.exAxis[i] = exAxisTar[i];
		}
		posAss.exAxis[4] = -1;
		posTar.exAxis[4] = -1;
		res = Movc_P2P(posAss,posTar,Tool,fSpeed,CircleSeg,connectID);

	}
	if (apiName == _T("Movc_CP"))
	{

		float NAss[3],OAss[3],AAss[3],PAss[3],exAxisAss[6],NTar[3],OTar[3],ATar[3],PTar[3],exAxisTar[6];
		memset(NAss,0,sizeof(NAss));
		memset(OAss,0,sizeof(OAss));
		memset(AAss,0,sizeof(AAss));
		memset(PAss,0,sizeof(PAss));
		memset(exAxisAss,0,sizeof(exAxisAss));
		memset(NTar,0,sizeof(NTar));
		memset(OTar,0,sizeof(OTar));
		memset(ATar,0,sizeof(ATar));
		memset(PTar,0,sizeof(PTar));
		memset(exAxisTar,0,sizeof(exAxisTar));


		GetParams(Param1,NAss,3);
		GetParams(Param2,OAss,3);
		GetParams(Param3,AAss,3);
		GetParams(Param4,PAss,3);
		GetParams(Param5,NTar,3);
		GetParams(Param6,OTar,3);
		GetParams(Param7,ATar,3);
		GetParams(Param8,PTar,3);
		char *param = this->CStringToChar(Param9);
		int Tool = atoi(param);
		char *param1 = this->CStringToChar(Param10);
		float fSpeed = atof(param1);
		char *param2 = this->CStringToChar(Param11);
		int CircleSeg = atoi(param2);
		ROB_POS posAss;
		ROB_POS posTar;
		for(int i = 0;i<3;i++)
		{
			posAss.N[i] = NAss[i];
			posAss.O[i] = OAss[i];
			posAss.A[i] = AAss[i];
			posAss.P[i] = PAss[i];
			posTar.N[i] = NTar[i];
			posTar.O[i] = OTar[i];
			posTar.A[i] = ATar[i];
			posTar.P[i] = PTar[i];
		}
		for(int i = 0;i<6;i++)
		{
			posAss.exAxis[i] = exAxisAss[i];
			posTar.exAxis[i] = exAxisTar[i];
		}
		res = Movc_CP(posAss,posTar,Tool,fSpeed,CircleSeg,connectID);
		posAss.P[0] = 563.329;
		posAss.P[1] = -260.834;
		posAss.P[2] = 814.796;
		posTar.P[0] = 507.398;
		posTar.P[1] = -298.8;
		posTar.P[2] = 797.102;
		res = Movc_P2P(posAss,posTar,Tool,fSpeed,CircleSeg,connectID);


	}
	CString errorMessage = this->GetErrorMessage(res);
	vResult.push_back(errorMessage);
	
	return vResult;
}

char* CRobotSDK::CStringToChar(CString stringIn)
{
	wchar_t* wStr = stringIn.GetBuffer(); 
	size_t len = wcslen(wStr) +1;
	size_t converted = 0;
	char* pChar = (char*)malloc(len* sizeof(char));
	wcstombs_s(&converted, pChar, len, wStr, _TRUNCATE);
	return  pChar;
}

int CRobotSDK::GetParams( LPCTSTR Str,float* Param,int len )
{
	if(len>10)
		len = 10;
	if(len <0)
		len = 0;
	if(!Str)
		return -1;
	CString StrParam = Str;
	int Paramindex=0;
	int CharIndex= 0;
	char ValBuf[256];
	memset(ValBuf,0,sizeof(ValBuf));
	for(int i=0;i<StrParam.GetLength();i++)
	{
		char ch = (char)StrParam.GetAt(i);
		if(('0' <= ch && ch <='9') || (ch == '-') || (ch == '.'))
		{
			ValBuf[CharIndex++] = ch;
		}
		else if((ch == ' ') ||(ch == ','))
		{
			if(strlen(ValBuf)>0)
			{
				Param[Paramindex++] = (float)atof(ValBuf);
				CharIndex = 0;
				memset(ValBuf,0,sizeof(ValBuf));
			}
			if(Paramindex>=len)
				break;
		}
		if(i== (StrParam.GetLength()-1))
		{
			if(strlen(ValBuf)>0)
			{
				Param[Paramindex++] = (float)atof(ValBuf);
				CharIndex = 0;
				memset(ValBuf,0,sizeof(ValBuf));
			}
		}
	}
	return 0;
}