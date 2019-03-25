#include "MainView.h"
#include "ViewMediator.h"
#include "../MainWindow/MMainWindow.h"



MainView::MainView(IMainClient *_main)
	:IViewInterface(_main)
{
	m_viewMdt = new ViewMediator(m_main);
}

MainView::~MainView()
{
    delete m_mainWnd;
    m_mainWnd = nullptr;

    delete m_viewMdt;
    m_viewMdt = nullptr;
}

bool MainView::Start()
{
	m_mainWnd = new MMainWindow(m_viewMdt);
    m_mainWnd->show();
    m_mainWnd->raise();
    m_mainWnd->activateWindow();
	return true;
}

void MainView::Stop()
{
}
