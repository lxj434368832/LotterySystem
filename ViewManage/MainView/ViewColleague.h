#ifndef VIEWCOLLEAGUE_H
#define VIEWCOLLEAGUE_H

class ViewMediator;
class IMainClient;
class MainLogic;

class ViewColleague
{
public:
    ViewColleague(ViewMediator* mdt);
    ~ViewColleague();

protected:
    ViewMediator        *m_mediator;
    IMainClient         *m_mainClient; 
	MainLogic			*m_mainLogic;
};

#endif // VIEWCOLLEAGUE_H
