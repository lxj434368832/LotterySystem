#pragma once
#include <QMap>
#include <QObject>
#include "ILogicInterface.h"

class MainLogic : public QObject, public ILogicInterface
{
    Q_OBJECT
public:
	MainLogic(IMainClient *_main = nullptr);
    ~MainLogic() override;

	bool Start() override;
	void Stop() override;

    /*************************************************************************
    * function:从本地文件中导入数据
    * param qstrFilePath: 文件路径
    * return:
    *************************************************************************/
    void ImportData(QString qstrFilePath);

    /*************************************************************************
    * function:增加一行数据到列表中
    * param qstrPeriod:期数
    * param qstrNum:   开奖号
    * return:
    *************************************************************************/
    void AddData(QString qstrPeriod, QString qstrNum);

	const QMap<QString, QString>& GetLotteryList();


signals:
    void signalLotteryListChanged(QMap<QString, QString>*);

private:
    QMap<QString, QString>        m_mapLotteryList;     //期数，开奖号
};

