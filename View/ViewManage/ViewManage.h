#pragma once
#include "IViewManage.h"
#include <string>
#include <QObject>

class ViewMediator;
class MMainWindow;

class ViewManage : public QObject, public IViewManage
{
    Q_OBJECT
public:
	ViewManage(IMainClient *_main = nullptr);
    ~ViewManage() override;

	bool Start() override;
	void Stop() override;

    /*************************************************************************
    * function: 显示弹窗消息
    * param uType:消息类型
    * param strMsg:显示内容
    * return:   1=YES 0=NO
    *************************************************************************/
    unsigned PopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg);

private slots:

    void slotPopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg);

private:
    ViewMediator    *m_viewMdt;        //视图中介者
    MMainWindow     *m_mainWnd;        //主窗体
};

