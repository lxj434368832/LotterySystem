#pragma once

#include "../CommonFile/TypeDefine.h"
#include "IMainClient.h"

class MainClient : public IMainClient
{
public:
	MainClient();
    ~MainClient() override;
	virtual ClientConfig* GetClientConfig() override;
	virtual IViewManage* GetViewManage() override;
	virtual IControllerManage* GetControllerManage() override;
	virtual IModelManage* GetModelManage() override;

//	virtual ITCPCommunication* GetMainCommunication() override;
//	virtual IMessage*	GetMessageModule() override;

	bool Start() override;
	void Stop() override;

private:
	bool ReadConfigFile();

private:
	ClientConfig		m_clConfig;	//�ͻ���������
	IViewManage*		m_pView;
    IControllerManage*	m_pController;
	IModelManage*	m_pModel;

//	ITCPCommunication*		m_pCommunication;
//    IMessage*                          m_pMessage;
};

