#include "ModelManage.h"
#include "../../CommonFile/CommonDefine.h"



ModelManage::ModelManage(IMainClient *_main)
	:IModelManage(_main)
{
}


ModelManage::~ModelManage()
{
}

bool ModelManage::Start()
{
	return true;
}

void ModelManage::Stop()
{
}

int ModelManage::SaveFiveMinuteRaceNumberList(QList<QList<QVariant> > rows)
{
    if (rows.size() < 2)
    {
        loge() << QStringLiteral("保存数据失败，长度为0！");
        return 0;
    }
    rows.pop_front();		//去掉标题栏

    if(10 != rows[0].at(2).toString().split(','))
    {
        loge()<<QString::fromLocal8Bit("读取五分赛车号码错误，号码个数不为10!");
        return 0;
    }

    m_mapFiveMinuteRaceNumberList.clear();
    for (QList<QVariant> row : rows)
    {
        QString qstrPeriod = row.at(1).toString();
        QString qstrNum = row.at(2).toString();
        m_mapFiveMinuteRaceNumberList[qstrPeriod] = qstrNum;
    }
    return m_mapFiveMinuteRaceNumberList.size();
}

void ModelManage::AddFiveMinuteRaceNumberData(QString qstrPeriod, QString qstrNum)
{
    if (qstrPeriod.isEmpty() || qstrNum.isEmpty())
    {
        loge()<<QString::fromLocal8Bit("添加开奖号码数据失败! period:%1 number:%2").arg(qstrPeriod).arg(qstrNum);
        return;
    }

    int icount = qstrNum.split(',').size();
    if(10 != icount)
    {
        loge()<<QString::fromLocal8Bit("添加的开奖号码有误，个数不为10。number:%1  个数:%2").arg(qstrNum).arg(icount);
        return;
    }

    m_mapFiveMinuteRaceNumberList[qstrPeriod] = qstrNum;
}

const QMap<QString, QString> ModelManage::GetFiveMinuteRaceNumberList()
{
    return m_mapFiveMinuteRaceNumberList;
}

int ModelManage::SaveThreePointsQuiklyNumberList(QList<QList<QVariant> > rows)
{
    if (rows.size() < 2)
    {
        loge() << QStringLiteral("保存数据失败，长度为0！");
        return 0;
    }
    rows.pop_front();		//去掉标题栏

    if(3 != rows[0].at(2).toString().split(','))
    {
        loge()<<QString::fromLocal8Bit("读取三分快三号码错误，号码个数不为10!");
        return 0;
    }

    m_mapThreePointsQuiklyNumberList.clear();
    for (QList<QVariant> row : rows)
    {
        QString qstrPeriod = row.at(1).toString();
        QString qstrNum = row.at(2).toString();
        m_mapThreePointsQuiklyNumberList[qstrPeriod] = qstrNum;
    }
    return m_mapThreePointsQuiklyNumberList.size();
}

void ModelManage::AddThreePointsQuiklyNumberData(QString qstrPeriod, QString qstrNum)
{
    if (qstrPeriod.isEmpty() || qstrNum.isEmpty())
    {
        loge()<<QString::fromLocal8Bit("添加开奖号码数据失败! period:%1 number:%2").arg(qstrPeriod).arg(qstrNum);
        return;
    }

    int icount = qstrNum.split(',').size();
    if(3 != icount)
    {
        loge()<<QString::fromLocal8Bit("添加的开奖号码有误，个数不为3。number:%1  个数:%2").arg(qstrNum).arg(icount);
        return;
    }

    m_mapThreePointsQuiklyNumberList[qstrPeriod] = qstrNum;
}

const QMap<QString, QString> ModelManage::GetThreePointsQuiklyNumberList()
{\
    return m_mapThreePointsQuiklyNumberList;
}
