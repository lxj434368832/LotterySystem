#include "ViewManage.h"
#include "ViewMediator.h"
#include "../MainWindow/MMainWindow.h"
#include "..\..\CommonFile\EnumDefine.h"
#include "..\..\CommonFile\CommonDefine.h"
#include "../../MainClient/IMainClient.h"
#include "../../Controller/ControllerManage/ControllerManage.h"
#include <QMessageBox>


ViewManage::ViewManage(IMainClient *_main)
    :QObject()
    ,IViewManage(_main)
{
	m_viewMdt = new ViewMediator(m_main);
    ControllerManage* pCtrlMng = dynamic_cast<ControllerManage*>
            (m_main->GetControllerManage());
    connect(pCtrlMng, SIGNAL(signalPopupShowMessage(uint,std::string,std::string)),
            this, SLOT(slotPopupShowMessage(uint,std::string,std::string)));
}

ViewManage::~ViewManage()
{
    delete m_viewMdt;
    m_viewMdt = nullptr;
}

bool ViewManage::Start()
{
	m_mainWnd = new MMainWindow(m_viewMdt);
    m_mainWnd->show();
    m_mainWnd->raise();
    m_mainWnd->activateWindow();
    m_mainWnd->move(0,0);
	return true;
}

void ViewManage::Stop()
{
    delete m_mainWnd;
    m_mainWnd = nullptr;
}

unsigned ViewManage::PopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg)
{
    QString qstrMsg = QString("<font size='12' color='red'>%1</font>").arg(QString::fromLocal8Bit(strMsg.c_str()));
     int iRet = 0;
     switch (uType)
     {
     case EShowMsgType::ESMT_INFORMATION:
         logm() << QString::fromLocal8Bit(strMsg.data());
         iRet = QMessageBox::information(nullptr, QString::fromLocal8Bit(strTitle.c_str()), qstrMsg
             , QString::fromLocal8Bit("确定"));
         break;
     case EShowMsgType::ESMT_WARNING:
         logw() << QString::fromLocal8Bit(strMsg.data());
         iRet = QMessageBox::warning(nullptr, QString::fromLocal8Bit(strTitle.c_str()), qstrMsg
             , QString::fromLocal8Bit("确定"));
         break;
     case EShowMsgType::ESMT_CRITICAL:
         loge() << QString::fromLocal8Bit(strMsg.data());
         iRet = QMessageBox::critical(nullptr, QString::fromLocal8Bit(strTitle.c_str()), qstrMsg
             , QString::fromLocal8Bit("确定"));
         break;
     case EShowMsgType::ESMT_QUESTION:
         logm() << QString::fromLocal8Bit(strMsg.data());
         iRet = QMessageBox::question(nullptr, QString::fromLocal8Bit(strTitle.c_str()), qstrMsg
             , QString::fromLocal8Bit("确定"), QString::fromLocal8Bit("取消"));
         break;
     default:
         loge() << QString::fromLocal8Bit("未知显示消息类型！");
         break;
     }
     return iRet;
}

void ViewManage::slotPopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg)
{
    PopupShowMessage(uType, strTitle, strMsg);
}
