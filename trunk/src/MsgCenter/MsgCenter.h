// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MSGCENTER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MSGCENTER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MSGCENTER_EXPORTS
#define MSGCENTER_API __declspec(dllexport)
#else
#define MSGCENTER_API __declspec(dllimport)
#endif

// �����Ǵ� MsgCenter.dll ������
class MSGCENTER_API CMsgCenter {
public:
	CMsgCenter(void);
	// TODO: �ڴ�������ķ�����
};

extern MSGCENTER_API int nMsgCenter;

MSGCENTER_API int fnMsgCenter(void);
