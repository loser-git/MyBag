#ifndef CROBOTSDK_H
#define CROBOTSDK_H
#endif

#include "afxcmn.h"
#include "afxwin.h"
#include <map>
#include <vector>

using namespace std;

class CRobotSDK
{
public:
	CRobotSDK();
    ~CRobotSDK();
	CString GetErrorMessage(int ErrorCode);
	map<CString,int> GetFunctionMap();
	vector<CString> SendAPI(CString apiName, CString Param1, CString Param2,CString Param3, CString Param4,CString Param5,CString Param6,CString Param7,CString Param8,CString Param9,CString Param10,CString Param11);
	int ConnectIP(CString strIP, short sPort);
	int ConnectUdp(CString strIP, short sPort);
	int DisconnectIP();
	bool GetConnectStatus();
private:
	void LoadFunction();
	char* CStringToChar(CString stringIN);
	int CRobotSDK::GetParams( LPCTSTR Str,float* Param,int len );
private:
	map<CString,int> m_FunctionMap;
	int connectID;
	bool m_bConnected;
};