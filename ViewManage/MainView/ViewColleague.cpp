#include "ViewColleague.h"
#include "ViewMediator.h"
#include "../../MainClient/IMainClient.h"
#include "../../LogicManage/MainLogic.h"

ViewColleague::ViewColleague(ViewMediator* mdt){
    m_mediator = mdt;
    m_mainClient = mdt->GetMainClient();
	m_mainLogic = dynamic_cast<MainLogic*>(m_mainClient->GetLogicInterface());
}

ViewColleague::~ViewColleague()
{
    m_mediator = nullptr;
    m_mainClient = nullptr;
	m_mainLogic = nullptr;
}

