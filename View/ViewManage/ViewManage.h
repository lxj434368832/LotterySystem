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
    * function: ��ʾ������Ϣ
    * param uType:��Ϣ����
    * param strMsg:��ʾ����
    * return:   1=YES 0=NO
    *************************************************************************/
    unsigned PopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg);

private slots:

    void slotPopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg);

private:
    ViewMediator    *m_viewMdt;        //��ͼ�н���
    MMainWindow     *m_mainWnd;        //������
};

