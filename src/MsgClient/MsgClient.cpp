// MsgClient.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MsgClient.h"


// ���ǵ���������һ��ʾ��
MSGCLIENT_API int nMsgClient=0;

// ���ǵ���������һ��ʾ����
MSGCLIENT_API int fnMsgClient(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MsgClient.h
CMsgClient::CMsgClient()
{
	return;
}
