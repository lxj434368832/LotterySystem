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
    * function:�ӱ����ļ��е�������
    * param qstrFilePath: �ļ�·��
    * return:
    *************************************************************************/
    void ImportData(QString qstrFilePath);

    /*************************************************************************
    * function:����һ�����ݵ��б���
    * param qstrPeriod:����
    * param qstrNum:   ������
    * return:
    *************************************************************************/
    void AddData(QString qstrPeriod, QString qstrNum);

	const QMap<QString, QString>& GetLotteryList();


signals:
    void signalLotteryListChanged(QMap<QString, QString>*);

private:
    QMap<QString, QString>        m_mapLotteryList;     //������������
};

