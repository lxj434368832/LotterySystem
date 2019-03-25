#include "MainClient.h"
#include "..\ViewManage\MainView\MainView.h"
#include "..\LogicManage\MainLogic.h"
#include "..\ModelManage\MainModel.h"
#include "..\Component\CommunicationModule\MainCommunication.h"
//#include "..\Component\MessageModule\MessageModule.h"
#include "../CommonFile/CommonDefine.h"
#include "../3rdParty/MConfigManage/include/MConfigManage.h"
#include <QApplication>
#include <QDir>
#include <stdio.h>

MainClient::MainClient()
{
	m_pLogic = new MainLogic(this);
	m_pModel = new MainModel(this);
	m_pCommunication = new MainCommunication(this);
	//	m_pMessage = new MessageModule(this);

	m_pView = new MainView(this);
}

MainClient::~MainClient()
{
	RELEASE(m_pView);
	RELEASE(m_pLogic);
	RELEASE(m_pModel);
	RELEASE(m_pCommunication);
//    RELEASE(m_pMessage);
}

ClientConfig * MainClient::GetClientConfig()
{
	return &m_clConfig;
}

IViewInterface * MainClient::GetViewInterface()
{
	return m_pView;
}

ILogicInterface * MainClient::GetLogicInterface()
{
	return m_pLogic;
}

IModelInterface * MainClient::GetModelInterface()
{
	return m_pModel;
}

ICommunication * MainClient::GetMainCommunication()
{
	return m_pCommunication;
}

IMessage * MainClient::GetMessageModule()
{
	return m_pMessage;
}

bool MainClient::Start()
{
//	if (false == ReadConfigFile()) return false;
	if (false == m_pLogic->Start()) return false;
	if (false == m_pModel->Start()) return false;
	if (false == m_pCommunication->Start()) return false;
//	if (false == m_pMessage->Start()) return false;

	if (false == m_pView->Start()) return false;
	return true;
}

void MainClient::Stop()
{
	m_pView->Stop();
	m_pLogic->Stop();
	m_pModel->Stop();
	m_pCommunication->Stop();
//	m_pMessage->Stop();
}

bool MainClient::ReadConfigFile()
{
    MConfigManage config(QApplication::applicationDirPath() +"\\config\\ClientConfig.ini" );
    m_clConfig.uMessageThreadCount = config.value("Client", "MessageThreadCount", "0").toUInt();
    m_clConfig.uIOCPThreadCount =  config.value("Client", "IOCPThreadCount", "0").toUInt();
    m_clConfig.uHeartbeatTime = config.value("Client", "HeartbeatTime", "0").toUInt();
    m_clConfig.strServerIP =  config.value("Connect", "ServerIP", "").toString().toLocal8Bit().data();
    m_clConfig.usServerPort =  config.value("Connect", "ServerPort", "0").toUInt();

    if (false == m_clConfig.CheckValid())
    {
        loge() << QStringLiteral("读取配置文件发生错误，请检查配置文件！");
        //return false;
    }

	return true;
}
