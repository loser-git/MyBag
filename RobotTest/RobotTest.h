
// RobotTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRobotTestApp: 
// �йش����ʵ�֣������ RobotTest.cpp
//

class CRobotTestApp : public CWinApp
{
public:
	CRobotTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRobotTestApp theApp;