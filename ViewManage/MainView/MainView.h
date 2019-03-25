#pragma once
#include "IViewInterface.h"

class ViewMediator;
class MMainWindow;

class MainView : public IViewInterface
{
public:
	MainView(IMainClient *_main = nullptr);
    ~MainView() override;

	bool Start() override;
	void Stop() override;

private:
    ViewMediator    *m_viewMdt;        //��ͼ�н���
    MMainWindow     *m_mainWnd;        //������
};

