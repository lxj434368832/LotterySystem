#pragma once
/*************************************************************************
* function�������ͨѶ����Ľӿڣ����е�ͨѶ���ڴ�ģ���й���
* author :	������
* datetime��2017-12-14
* company:
*************************************************************************/


class IMainClient;
class ServerConnect;

class ITCPCommunication
{
public:
    ITCPCommunication(IMainClient *main = nullptr):m_main(main){}
    virtual ~ITCPCommunication() { m_main = nullptr; }
	inline IMainClient* GetMainClient(){ return m_main; }
	virtual ServerConnect* GetServerConnect() = 0;

	virtual bool Start() = 0;
	virtual void Stop() = 0;

	/*************************************************************************
	* function�� ��������
	* param key: �û�id
	* param data:��Ҫ���͵�����
	* return:	 ��
	*************************************************************************/
//	virtual void SendData(UserKey uUserKey, const char* data, unsigned uLength) = 0;

protected:
	IMainClient *m_main;
};