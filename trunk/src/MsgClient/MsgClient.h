// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MSGCLIENT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MSGCLIENT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MSGCLIENT_EXPORTS
#define MSGCLIENT_API __declspec(dllexport)
#else
#define MSGCLIENT_API __declspec(dllimport)
#endif

// �����Ǵ� MsgClient.dll ������
class MSGCLIENT_API CMsgClient {
public:
	CMsgClient(void);
	// TODO: �ڴ�������ķ�����
};

extern MSGCLIENT_API int nMsgClient;

MSGCLIENT_API int fnMsgClient(void);
