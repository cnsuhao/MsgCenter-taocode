// MsgCenter.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "MsgCenter.h"


// ���ǵ���������һ��ʾ��
MSGCENTER_API int nMsgCenter=0;

// ���ǵ���������һ��ʾ����
MSGCENTER_API int fnMsgCenter(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� MsgCenter.h
CMsgCenter::CMsgCenter()
{
	return;
}
