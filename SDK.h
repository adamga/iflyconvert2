#ifndef _737MAXSDK_H_
#define _737MAXSDK_H_

#pragma pack(push) 
#pragma pack(8)

#include "SDK_Defines.h"


//**********************************************************************************************************
//
// Panel Message System
//
static UINT iFly737MAX_MSG=NULL;
#define iFly737MAX_MSG_GAU  "iFly737MAX_MSG_GAU"



//For P3D, call iFly737MAX_Init_SendMessage(VER_P3D_V5)
//For MSFS, call iFly737MAX_Init_SendMessage(VER_MSFS2020)
static void iFly737MAX_Init_SendMessage(int VER=VER_P3D_V5)
{
	Version=VER;
	if(Version<VER_MSFS2020)
		FS_main_window=::FindWindowEx(NULL, NULL,"FS98MAIN", NULL);
	else if(Version==VER_MSFS2020)
		FS_main_window=::FindWindowEx(NULL, NULL, NULL, "iFly Plugin");
	else if(Version==VER_MSFS2024)
		FS_main_window=::FindWindowEx(NULL, NULL, NULL, "iFly Plugin - MSFS2024");
	else
		FS_main_window=NULL;

	if(FS_main_window!=NULL && iFly737MAX_MSG==NULL)
		iFly737MAX_MSG = RegisterWindowMessage(iFly737MAX_MSG_GAU);
}

static void iFly737MAX_SendMessage(int Command, double Value1, double Value2, double Value3)
{
	iFly737MAX_Message message;
	message.Command=Command;
	message.Value1=Value1;
	message.Value2=Value2;
	message.Value3=Value3;

	if(Version<VER_MSFS2020)
		FS_main_window=::FindWindowEx(NULL, NULL,"FS98MAIN", NULL);
	else if(Version==VER_MSFS2020)
		FS_main_window=::FindWindowEx(NULL, NULL, NULL, "iFly Plugin");
	else if(Version==VER_MSFS2024)
		FS_main_window=::FindWindowEx(NULL, NULL, NULL, "iFly Plugin - MSFS2024");
	else
		FS_main_window=NULL;

	if(FS_main_window!=NULL && iFly737MAX_MSG) 
	{
		COPYDATASTRUCT cpdata;
		cpdata.dwData=iFly737MAX_MSG;
		cpdata.cbData = sizeof(message)+2;
		cpdata.lpData = &message;
		::SendMessage(FS_main_window,WM_COPYDATA,0,(LPARAM)&cpdata);
	}
}

#pragma pack(pop)

#endif
