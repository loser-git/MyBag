// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ROBOTSDK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ROBOTSDK_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�


#ifdef ROBOTSDK_EXPORTS
#define ROBOTSDK_API extern "C" __declspec(dllexport)
#else
#define ROBOTSDK_API extern "C" __declspec(dllimport)
#endif

#include "Robot_Datatype.h"
// �����Ǵ� RobotSDK.dll ������


ROBOTSDK_API int RobotInit();
ROBOTSDK_API int RobotRelease();

/*********************����ӿ�*******************************/

/**���ӿ�����.
@param StrIP(in) ������IP��ַ
@param port (in) �˿ں�
@return ���ɹ����ص�ǰIP����������ID,IDֵ����0�����򷵻ش�����
*/
ROBOTSDK_API int Connect(const char* StrIP,short port);

ROBOTSDK_API int ConnectUDP(const char* StrIP,short port);
/**�Ͽ���������.
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Disconnect(int ConnectID);

/*********************�˶���ָ��*******************************/

/**����ֱ�����˶�.
@param N (in) λ�˾���N����
@param O (in) λ�˾���O����
@param A (in) λ�˾���A����
@param P (in) λ�˾���P����,λ��.
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movl_P2P(float* N,float* O,float* A,float* P,float* exAxis ,int Tool,float Speed,int ConnectID);

/**����ֱ���˶�������õ�󲻼���*/
ROBOTSDK_API int Movl_CP(float* N,float* O,float* A,float* P,float* exAxis ,int Tool,float Speed,int ConnectID);

/**����ؽ����˶�.
@param Joint (in) �ؽ�ֵ
@param JointNum (in) �ؽ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_P2P(float* Joint, int Tool,float Speed,int ConnectID);

/**�����ؽ��˶�������õ�󲻼���*/
ROBOTSDK_API int Movj_CP( float* Joint, int Tool,float Speed ,int ConnectID);

/**����ֱ�����˶�.
@param RPY (in) λ�ñ����ṹ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movl_P2P_RPY(RPY *rpy,float* exAxis ,int Tool,float Speed,int ConnectID);

/**����ֱ���˶�������õ�󲻼���*/
ROBOTSDK_API int Movl_CP_RPY(RPY *rpy,float* exAxis ,int Tool,float Speed,int ConnectID);

/*********************��ѯ�ӿ�********************************/

/**��ѯ��ǰ�ؽ�ֵ.
@param pJoint (out) �ؽ�ֵ��ŵ�ַ
@param JointNum (in) Ҫ��ѯ�Ĺؽ���
@param ConnectID��in����������ID��Connect(const char* StrIP,short port)�ķ���ֵ
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadJoint(float* pJoint,int JointNum,int ConnectID);

/**��ѯ��ǰ����ĩ��TCP�����̬,�ֱ�ΪN,O,A,P��������������������ʾ.
@param exAxis (out)���������ⲿ����
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadPOSE(float *N,float* O,float* A,float* P,float* exAxis ,int& mWord,int ConnectID);

/**��ѯ��ǰ����ĩ��TCP�����̬,RPY��ʽ
@param rpy (out) λ�ñ����ṹ��
@param exAxis (out)���������ⲿ����
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadPOSE_RPY(RPY *rpy,float* exAxis ,int ConnectID);

/**��ѯ��ǰʹ�õĹ��ߺ�
@param ToolIndex (out) ���ߺ�
@param Px (out) �����������Px����
@param Py (out) �����������Py����
@param Pz (out) �����������Pz����
@param Rx (out) �����������Rx����
@param Ry (out) �����������Ry����
@param Rz (out) �����������Rz����
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadTool(BYTE ToolIndex,float& Px,float & Py,float& Pz,float& Rx,float& Ry,float& Rz,int ConnectID);

/**������.
@param ErrCode(out) ������
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadAlarm(int& ErrCode,int ConnectID);

/**��״̬.
@param status (out) ״̬�����ַ
@param len (in) �����С,���4���ֽ�
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadStatus(BYTE* status,int len,int ConnectID);

/**�������û�IO���״̬.
@param IOMap (in) IO������
@param IOStatus (out) �ȴ���IO״̬
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadUO(int IOMap,BYTE& IOStatus,int ConnectID );

/**���û�IO���.
@param IOStatus (out) 8λ��16λ��IO״̬
@param Channel (in) IOͨ���� 1~8
@param IOGroupFlag (in) IO���ʶ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadGUO(int &IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**�������û�IO����.
@param IOMap (in) IO������
@param IOStatus (out) �ȴ���IO״̬
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadUI(int IOMap,BYTE& IOStatus,int ConnectID);

/**���û�IO����.
@param IOStatus (out) 8λ��16λ��IO״̬
@param Channel (in) IOͨ���� 1~8
@param IOGroupFlag (in) IO���ʶ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadGUI(int &IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**��ѯRC����  add 20131021
@param rcParam (out) RC�����ṹ��ָ��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadRCParam(T_SEND_ROBOT_PARA *rcParam,int ConnectID);


/**��ȡrc����汾�ţ�add by tongyan 20150818
@param version��out���汾��
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadOfflineVersion(char *version,int ConnectID);

/***********************ִ�нӿ�***********************************************/

///**�������߿���ģʽ���ڿ�ʼ���߿���֮ǰ���뷢�ʹ�����.
//@param ConnectID��in����������ID
//@return ���ɹ�����0�����򷵻ش�����
//*/
//ROBOTSDK_API int SetOfflineMode(bool bOffline,int ConnectID);

///**��ʼ׼��ִ��ָ��.
//@brief �յ����������ָ�����в�Ϊ�գ���ʼִ��ָ�
//@param ConnectID��in����������ID
//@return ���ɹ�����0�����򷵻ش�����
//*/
//ROBOTSDK_API int Start(int ConnectID);
//
///**��ͣ.
//@param ConnectID��in����������ID
//@return ���ɹ�����0�����򷵻ش�����
//*/
//ROBOTSDK_API int MovePause(int ConnectID);

/**��տ��������������ָ��.
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ClearBuffer(int ConnectID);

/**������ҵ,��ʽ1���洢λ�õ��T6��.
@param pJobStream (in) ��ҵ����ע�⣬����ʹ�õ��Ƕ����Ʊ��룬������ASCII��
@param byteLen (in)��ҵ�ֽڳ���,������ҵͷ������ָ����ֽڳ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendJobT6(BYTE* pJobStream,int byteLen,int ConnectID);

/**������ҵ����ʽ2���洢λ�õ�Ĺؽ�ֵ
@param pJobStream (in) ��ҵ����ע�⣬����ʹ�õ��Ƕ����Ʊ��룬������ASCII��
@param byteLen (in)��ҵ�ֽڳ���,������ҵͷ������ָ����ֽڳ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendJobJts(BYTE* pJobStream,int byteLen,int ConnectID);

/**����������ҵ
@param pJobStream (in) ��ҵ��
@param byteLen (in) ��ҵ������
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendJobNet(BYTE* pJobStream,int byteLen,int ConnectID);

/**��ѯRC������ҵ�б�
@param jobNameList (out) RC������ҵ�б�
@param jobNumber (out) ������ҵ�ĸ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadJobNameList(char* jobNameList,int& jobNumber,int ConnectID);


/**�ϴ���ҵ
@param jobName (in) ָ������ҵ����
@param jobStream (out)  ��ҵ������
@param streamLength (out) ��ҵ�������ĳ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReceiveJob(char* jobName,BYTE* jobStream,int& streamLenth,int ConnectID);

///**����ͨ��RCָ��
//@param RCInst (in) RCָ����
//@param ConnectID��in����������ID
//@return ���ɹ��򷵻�0�����򷵻ش�����
//*/
//ROBOTSDK_API int SendRCInst(BYTE* RCInst,int ConnectID);

/**ɾ��ָ����ҵ
@param jobName (in) ָ������ҵ����
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int DelJob(char* jobName,int ConnectID);

/**�����ҵ�б�
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ClearJobList(int ConnectID);

/**��ָ����ҵ
@param jobName (in) ָ������ҵ����
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int OpenJob(char* jobName,int ConnectID);

/**�����ֽ����û�����
@param varID(in) �������
@param varBYTE(in) ����ֵ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int WriteUserVarBYTE(int varID, BYTE varBYTE,int ConnectID);
/**����32λ�����û�����
@param varID(in) �������
@param varFloat(in) ����ֵ
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int WriteUserVarINT(int varID, int varINT,int ConnectID);
/**���͸������û�����
@param varID(in) �������
@param varINT(in) ����ֵ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int WriteUserVarFLOAT(int varID, float varFloat,int ConnectID);

/**����λ�ñ�����RPY�е�mWord�����ã�
@param varRPY(in) λ�ñ����ṹ��
@param exAxis(in) RC�ⲿ�������� 
@param coordinate(in) ����ϵ 1~3
@param TOOLNUM(in) ��������ϵ�� 1~8
@param USERNUM(in) �û�����ϵ�� 1~8
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int WriteUserVarRPY(int varID,RPY varRPY, float* exAxis, int coordinate, int TOOLNUM,int USERNUM,int ConnectID);

/**����λ�ñ�����RPY�е�mWord�������ã�
@param varRPY(in) λ�ñ����ṹ��
@param exAxis(in) RC�ⲿ�������� 
@param coordinate(in) ����ϵ 1~3
@param TOOLNUM(in) ��������ϵ�� 1~8
@param USERNUM(in) �û�����ϵ�� 1~8
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int WriteUserVarRPYS(int varID,RPY varRPY, float* exAxis, int coordinate, int TOOLNUM,int USERNUM,int ConnectID);

/**����ʵʱ��ƫ����
@param varRPY(in) λ�ñ����ṹ��
@param exAxis(in) RC�ⲿ�������� 
@param coordinate(in) ����ϵ���� 1~3
@param coordNum(in) ����ϵ�� 1~8
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendRectifyData(RPY varRPY, float* exAxis, int coordType, int coordNum,int ConnectID);

/***********************IO��ָ��**********************************************/

/**����Ҫʹ�õĹ��ߺ�*/
//ROBOTSDK_API  int SetTool(int index);
/**waitָ��.
@param IOMap (in) IO������
@param IOStatus (in) �ȴ���IO״̬
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Wait(int IoMap,BYTE IoStatus,int ConnectID);

/**IO���ָ��,�ڿ���������Ҫ���浽ָ��ִ�ж���.
@param IoMap (in) �û�IO������
@param IoStatus (in) IO״̬��1:ON��0:OFF
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API  int DO_Out(int IOMap,BYTE IOstatus,int ConnectID);

/***16λ��IO���ָ��,�ڿ���������Ҫ���浽ָ��ִ�ж���.
@param IOStatus (in)  16λIO״̬
@param Channel (in) IOͨ���� 1~64
@param IOGroupFlag (in) IO���ʶ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int DGO_Out(int IOStatus, int Channel,int ConnectID);

/***8λ��IO���ָ��,�ڿ���������Ҫ���浽ָ��ִ�ж���.
@param IOStatus (in)  8λIO״̬
@param Channel (in) IOͨ���� 1~8
@param IOGroupFlag (in) IO���ʶ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int DGO_Out8(int IOStatus, int Channel,int ConnectID);

/**�����û���IO���.
@brief �������յ������������ִ�У�������
@param IOStatus (in)  8λ����16λIO״̬
@param Channel (in) IOͨ���� 8λ��1~8 16λ��1~64
@param IOGroupFlag (in) IO���ʶ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int WriteGUO(int IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**���õ����û�IO���.
@brief �������յ������������ִ�У�������
@param IOMap (in) �û�IO������
@param IOStatus (in)   IO״̬��1:ON��0:OFF
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int WriteUO(int IOMap,BYTE IOStatus,int ConnectID);

/**�����û���IO����.
@brief �������յ������������ִ�У�������
@param IOStatus (in)  8λIO״̬
@param Channel (in) IOͨ���� 8λ��1~8 16λ��1~64
@param IOGroupFlag (in) IO���ʶ
@return ���ɹ�����0�����򷵻�-1
*/
ROBOTSDK_API int SimWriteGUI(int IOStatus,int Channel,int IOGroupFlag,int ConnectID);

/**�����û�IO����.
@param IOMap (in) �û�IO�����ţ����û�IO��
@param IOStatus (in)   IO״̬��1:ON��0:OFF
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SimWriteUI(int IOMap,BYTE IOStatus ,int ConnectID);

/****************************������ָ��**********************************/

/**�ӳ�ָ��.
@param DelayTime (in) �ӳ�ʱ�䣬��λ��S
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Delay(float DelayTime,int ConnectID);

/**������ҵ����ģʽ  add by tongyan 20150511.
@param JobRunMode (in) ��ҵ����ģʽ��1���Զ���2��һ�Σ�3������
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ChangeJobRunMode(BYTE JobRunMode,int ConnectID);

/*���õ�ǰ��ҵִ��״̬�����Ļص�����.
@param func (in) ����ָ�룬���û�ʵ��ִ��״̬�Ĵ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SetPlayMonitor(LPMONITOR_CALLBACK func,int ConnectID);
ROBOTSDK_API int SetSndstreamMonitor(LPMONITOR_CALLBACK func,int ConnectID);
ROBOTSDK_API int SetBackstreamMonitor(LPMONITOR_CALLBACK func,int ConnectID);


/**��ð汾��
*/
ROBOTSDK_API const char* GetSdkVersion();

/**���sdk���ɵ�ʱ��
*/
ROBOTSDK_API const char* GetBuildTime();

/****************************Ӧ����ָ��(����)**********************************/
/**Ĭ�Ϸ�ʽ��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ARCON(int ConnectID);
/**������ʽ��
@param VarI (in) �𻡵���
@param VarU (in) �𻡵�ѹ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ARCONSet(float varI, float varU,int ConnectID);
/**�����ļ���ʽ��
@param ASFNumberr (in) �����ļ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ARCONASF(short ASFNumber,int ConnectID);
/**Ĭ�Ϸ�ʽϢ��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ARCOFF(int ConnectID);
/**������ʽϢ��
@param VarI (in) �𻡵���
@param VarU (in) �𻡵�ѹ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ARCOFFSet(float varI, float varU,int ConnectID);
/**�����ļ���ʽ��
@param ASFNumberr (in) �����ļ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ARCOFFASF(short ASFNumber,int ConnectID);


/****************************Զ�̿�����ָ��**********************************/
// Add by ytj

/**����Զ�̿���״̬
//@param StrIP��in��Ҫ����Զ�̿���״̬�Ŀ�����IP��ַ
//@param RemoteON��in��true������Զ�̿��ƣ�false:�ر�Զ�̿���
//*/
//ROBOTSDK_API void RemoteControl(const char* StrIP, bool RemoteON);

/**���Զ��IO��������ҵ�򿪵�״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_MainJobOpen(int ConnectID);
/**���Զ��IO������ȫ�ŵ�״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_SafeDoor(int ConnectID);
/**���Զ��IO������·���ϵ�״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_OnPath(int ConnectID);
/**���Զ��IO����ԭ��λ��1��״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_Position1(int ConnectID);
/**���Զ��IO����ԭ��λ��2��״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_Position2(int ConnectID);
/**���Զ��IO���������е�״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_Warning(int ConnectID);
/**���Զ��IO����Զ��ģʽ��״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_Online(int ConnectID);
/**���Զ��IO���������е�״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_AutoRun(int ConnectID);
/**���Զ��IO�����ŷ��ϵ��״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_PowerOn(int ConnectID);
/**���Զ��IO����ִ��ģʽ��״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_Play(int ConnectID);
/**���Զ��IO��������ҵִ���е�״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_MainJobRun(int ConnectID);
/**���Զ��IO����ʾ��ģʽ��״̬
@param ConnectID��in����������ID
@return 1:ON,0:OFF;���򷵻ش�����
*/
ROBOTSDK_API int Read_Teach(int ConnectID);

/**����Զ��IO�������������
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/

ROBOTSDK_API int Send_Open(int ConnectID);
/**����Զ��IO����������λ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Send_Reset(int ConnectID);

/**����Զ��IO�����ⲿ����
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Send_Start(int ConnectID);
/**����Զ��IO�����ⲿ��ͣ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Send_Pause(int ConnectID);
/**����Զ��IO�����ⲿ��ͣ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Send_Stop(int ConnectID);



/**����Զ��IO�����ⲿ�ŷ��ϵ�
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Send_PowerOn(int ConnectID);

///**Զ��IO�����򿪰�ȫ��,add by tongyan 20160921
//@param ConnectID��in����������ID
//*/
//ROBOTSDK_API int Send_SafeDoorON(int ConnectID);
/**Զ��IO�����رհ�ȫ��,add by tongyan 20160921
@param ConnectID��in����������ID
*/
ROBOTSDK_API int Send_SafeDoorOFF(int ConnectID);

//
///**����Զ��IOֵ��add by tongyan20160927
//@param sysIO��in��IOֵ
//@param ConnectID��in����������ID
//@return ���ɹ��򷵻�0�����򷵻ش�����
//*/
//ROBOTSDK_API int Send_SysIO(int sysIO,int ConnectID);
//// Add end

//add by tongyan 20151119 

/**����RCָ��
@param RCInst��in�� RCָ��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Send_RCInst(INST RCInst,int ConnectID);

/**��ϵͳ������
@param axis_Num��out��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int Read_AxisNum(int& axis_Num,int ConnectID);

/**���ֽ����û�����
@param varID(in) �������
@param varBYTE(out) ����ֵ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadUserVarBYTE(int varID, BYTE& varBYTE,int ConnectID);

/**��32λ�����û�����
@param varID(in) �������
@param varINT(out) ����ֵ
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadUserVarINT(int varID, int& varINT,int ConnectID);

/**���������û�����
@param varID(in) �������
@param varFloat(out) ����ֵ
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadUserVarFLOAT(int varID, float& varFloat,int ConnectID);

/**��λ�ñ���
@param varRPY(out) λ�ñ����ṹ��
@param exAxis(out) RC�ⲿ�������� 
@param coordinate(out) ����ϵ 1~3
@param TOOLNUM(out)  ��������ϵ�� 1~8
@param USERNUM(out) �û�����ϵ�� 1~8
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadUserVarRPY(int varID,RPY* varRPY, float* exAxis, int& coordinate, int& TOOLNUM,int& USERNUM,int ConnectID);



/**��32λ����ϵͳ����
@param varID(in) �������
@param varINT(out) ����ֵ
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadSysVarINT(int varID, int& varINT,int ConnectID);

///**��������ϵͳ����
//@param varID(in) �������
//@param varFloat(out) ����ֵ
//@param ConnectID��in����������ID
//@return ���ɹ��򷵻�0�����򷵻ش�����
//*/
//ROBOTSDK_API int ReadSysVarFLOAT(int varID, float& varFloat,int ConnectID);
//add over


//add by tongyan 20160802 ���Ӧ��
/**��������Ʒ�������
@param fileNum(in) �ļ���
@param stackProData(in) ������ݽṹ��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendStackProData(short fileNum,PALL_FILE_PRO stackProData,int ConnectID);

/**����������
@param fileNum(in) �ļ���
@param stackData(int) �������ṹ��
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendStackCount(short fileNum,PALL_FILE_COUNTER stackCount,int ConnectID);

/**�������������(��һ��Ʒ)
@param fileNum(in) �ļ���
@param pointData(in) ���������
@param byteLen(in) ���ݳ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendStackPointData(short fileNum,BYTE* pointData,int byteLen,int ConnectID);

/**�������������(���ֲ�Ʒ)
@param fileNum(in) �ļ���
@param pointData(in) ���������
@param byteLen(in) ���ݳ���
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendStackPointData2(short fileNum,BYTE* pointData,int byteLen,int ConnectID);

//add over

//add by tongyan20160819
/**��ѯ��������ز���
@param dataStream(out) ������
@param streamLenth(out) ����������
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadRobAllData(BYTE* dataStream,int& streamLenth,int ConnectID);

/**��ѯ�������в���
@param dataStream(out) ������
@param streamLenth(out) ����������
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int ReadWeldAllData(BYTE* dataStream,int& streamLenth,int ConnectID);
//add over

//add by tongyan 20160919
/*���ü�ػ�������Ϣ�Ļص�����.
@param func (in) ����ָ�룬���û�ʵ��ִ��״̬�Ĵ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SetRobAllDataMonitor(RSMONITOR_CALLBACK func,int ConnectID);
//add over

//add by tongyan 20161026
/**��������־����
@param stackFlagData(in) ����־����
@param ConnectID��in����������ID
@return ���ɹ��򷵻�0�����򷵻ش�����
*/
ROBOTSDK_API int SendStackFlagData(PALL_FLAG_MSG stackFlagData,int ConnectID);
//add over

//add by tongyan 20161121
/**������ֵ̬��ùؽ�ֵ.
@param N (in) λ�˾���N����
@param O (in) λ�˾���O����
@param A (in) λ�˾���A����
@param P (in) λ�˾���P����,λ��.
@param jointNum��out���ؽڸ���
@param jointVal��out���ؽ�ֵ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadJointBaseNOAP(float *N,float *O,float *A,float *P,int jointNum,float *jointVal,int ConnectID);
//add over

//add by qgt 20170908
/**���ͻ������ղ���.
@param dataStream (in) �������ղ�������
@param streamLenth (in) ���ݳ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SendWeldCraftPara(BYTE* dataStream,int streamLenth,int ConnectID);
//add over

//add by tongyan 20171106
/**�����������.
@param fileNum (in) ��������ļ���
@param data (in) ��������ṹ�����
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SetAxisInsertData(int fileNum,AXIS_INTERF_DATA data,int ConnectID);

/**�������������.
@param fileNum (in) ����������ļ���
@param data (in) ����������ṹ�����
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SetCubeInsertData(int fileNum,CUBE_INTERF_DATA data,int ConnectID);
/**ƫ�ƿ���.
@param posNum (in) λ�ñ�����
@param corrdingNum (in) ����ϵ��
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Send_ShiftOnP(int posNum,int corrdingNum, int connectID);
/**ƫ�ƹر�.
@param connectID (in) ��������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Send_ShiftOnPOff( int connectID);


/**��ѯָ������ļ��ŵĵ�ǰ������
@param fileNum (in) ����ļ���
@param count (out) ��ǰ�������
@param connectID (in) ��������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadCurStacCount(short fileNum,int& count,int ConnectID);


/**��������ļ���
@param fileNum (in) ����ļ���
@param connectID (in) ��������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SendStackFileNum(short fileNum,int ConnectID);

/**���ù�������ϵ
@param coordNum (in) ����ϵ�ļ���
@param coordVal (in) ����ϵֵ
@param connectID (in) ��������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SetToolCoordinate(int coordNum, RPY coordVal, int connectID);

/**�����û�����ϵ
@param coordNum (in) ����ϵ�ļ���
@param coordVal (in) ����ϵֵ
@param connectID (in) ��������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int SetUserCoordinate(int coordNum, RPY coordVal, int connectID);


/**������ֵ̬(NOAP��ʽ)�ߵ���ؽ����˶�.
@param N (in) λ�˾���N����
@param O (in) λ�˾���O����
@param A (in) λ�˾���A����
@param P (in) λ�˾���P����,λ��.
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_P2P_NOAP(float* N, float* O, float* A, float* P, float* exAxis, int Tool, float Speed, int ConnectID);

/**������ֵ̬(NOAP��ʽ)�������ؽ����˶�.����õ�󲻼���
@param N (in) λ�˾���N����
@param O (in) λ�˾���O����
@param A (in) λ�˾���A����
@param P (in) λ�˾���P����,λ��.
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_CP_NOAP(float* N, float* O, float* A, float* P, float* exAxis, int Tool, float Speed, int ConnectID);

/**������ֵ̬(RPY��ʽ)�ߵ���ؽ����˶�.
@param RPY (in) λ�ñ����ṹ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_P2P_RPY(RPY *rpy, float* exAxis, int Tool, float Speed, int ConnectID);

/**������ֵ̬(RPY��ʽ)�������ؽ����˶�.����õ�󲻼���
@param RPY (in) λ�ñ����ṹ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_CP_RPY(RPY *rpy, float* exAxis, int Tool, float Speed, int ConnectID);

/**��ȡ�������ݣ�add by baidongni 20180410
@param Fx��out��x�������
@param Fy��out��y�������
@param Fz��out��z�������
@param Mx��out��x���������
@param My��out��y���������
@param Mz��out��z���������
@param checkout��out���Ƿ��ĵ���Ƭ��У��ֵ
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadForceControlData(double& Fx, double& Fy, double& Fz, double& Mx, double& My, double& Mz, int ConnectID);

/**��ȡ�������ݣ�add by baidongni 20180410
@param checkout��out���Ƿ��ĵ���Ƭ��У��ֵ
@param x��out�����ƽ������ֵx
@param y��out�����ƽ������ֵy
@param Rz��out��ƫ�ƽǶ�
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int ReadVisualSenseData(int& checkout, float& x, float& y, float& Rz, int ConnectID);


/**����ֱ�����˶�.(����ִ�з���)
@param N (in) λ�˾���N����
@param O (in) λ�˾���O����
@param A (in) λ�˾���A����
@param P (in) λ�˾���P����,λ��.
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movl_P2P_NoEndBack(float* N,float* O,float* A,float* P,float* exAxis ,int Tool,float Speed,int ConnectID);


/**����ֱ�����˶�(RPY)(����ִ�з���)
@param RPY (in) λ�ñ����ṹ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movl_P2P_RPY_NoEndBack(RPY *rpy,float* exAxis ,int Tool,float Speed,int ConnectID);


/**����ؽ����˶�.(����ִ�з���)
@param Joint (in) �ؽ�ֵ
@param JointNum (in) �ؽ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_P2P_NoEndBack(float* Joint, int Tool,float Speed,int ConnectID);


/**������ֵ̬(NOAP��ʽ)�ߵ���ؽ����˶�.(����ִ�з���)
@param N (in) λ�˾���N����
@param O (in) λ�˾���O����
@param A (in) λ�˾���A����
@param P (in) λ�˾���P����,λ��.
@param P (in) λ�˾���P����,λ��.
@param exAxis (in) �ⲿ��
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_P2P_NOAP_NoEndBack(float* N, float* O, float* A, float* P, float* exAxis, int Tool, float Speed, int ConnectID);



/**������ֵ̬(RPY��ʽ)�ߵ���ؽ����˶�.(����ִ�з���)
@param RPY (in) λ�ñ����ṹ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movj_P2P_RPY_NoEndBack(RPY *rpy, float* exAxis, int Tool, float Speed, int ConnectID);

/**������ֵ̬(NOAP��ʽ)�ߵ㵽��Բ���˶�
@param posAss (in) ������λ��
@param posTar (in) Ŀ���λ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param CircleSeg (in) �жϵ�ǰ���ڵ㴦��Բ��ǰ��λ��Ǻ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movc_P2P(ROB_POS posAss,ROB_POS posTar,int Tool,float Speed,int CircleSeg,int ConnectID);

/**������ֵ̬(NOAP��ʽ)������Բ���˶�
@param posAss (in) ������λ��
@param posTar (in) Ŀ���λ��
@param Tool (in) ʹ�õĹ��ߺ�
@param Speed (in) ����ĩ�˵�ִ���ٶȣ���λ��mm/s
@param CircleSeg (in) �жϵ�ǰ���ڵ㴦��Բ��ǰ��λ��Ǻ���
@param ConnectID��in����������ID
@return ���ɹ�����0�����򷵻ش�����
*/
ROBOTSDK_API int Movc_CP(ROB_POS posAss,ROB_POS posTar,int Tool,float Speed,int CircleSeg,int ConnectID);