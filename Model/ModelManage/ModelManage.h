#pragma once

#include <QMap>
#include <QList>
#include <QVariant>
#include "IModelManage.h"

class ModelManage : public IModelManage
{
public:
    ModelManage(IMainClient *_main = nullptr);
    ~ModelManage();

	bool Start() override;
	void Stop() override;

    int SaveFiveMinuteRaceNumberList(QList<QList<QVariant>>);
    void AddFiveMinuteRaceNumberData(QString qstrPeriod, QString qstrNum);
    const QMap<QString, QString> GetFiveMinuteRaceNumberList();

    int SaveThreePointsQuiklyNumberList(QList<QList<QVariant>>);
    void AddThreePointsQuiklyNumberData(QString qstrPeriod, QString qstrNum);

    const QMap<QString, QString> GetThreePointsQuiklyNumberList();

    void SaveWxNumStatisticData(QStringList list);
    QStringList AddWxNumberData(QString strNum);
    QStringList GetWxNumberList();

private:

    QMap<QString, QString>        m_mapFiveMinuteRaceNumberList;     //期数，开奖号
    QMap<QString, QString>        m_mapThreePointsQuiklyNumberList;   //期数，开奖号

    QStringList                   m_listWxNumList;
};

