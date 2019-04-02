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
        loge() << QStringLiteral("��������ʧ�ܣ�����Ϊ0��");
        return 0;
    }
    rows.pop_front();		//ȥ��������

    if(10 != rows[0].at(2).toString().split(','))
    {
        loge()<<QString::fromLocal8Bit("��ȡ�������������󣬺��������Ϊ10!");
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
        loge()<<QString::fromLocal8Bit("��ӿ�����������ʧ��! period:%1 number:%2").arg(qstrPeriod).arg(qstrNum);
        return;
    }

    int icount = qstrNum.split(',').size();
    if(10 != icount)
    {
        loge()<<QString::fromLocal8Bit("��ӵĿ����������󣬸�����Ϊ10��number:%1  ����:%2").arg(qstrNum).arg(icount);
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
        loge() << QStringLiteral("��������ʧ�ܣ�����Ϊ0��");
        return 0;
    }
    rows.pop_front();		//ȥ��������

    if(3 != rows[0].at(2).toString().split(','))
    {
        loge()<<QString::fromLocal8Bit("��ȡ���ֿ���������󣬺��������Ϊ10!");
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
        loge()<<QString::fromLocal8Bit("��ӿ�����������ʧ��! period:%1 number:%2").arg(qstrPeriod).arg(qstrNum);
        return;
    }

    int icount = qstrNum.split(',').size();
    if(3 != icount)
    {
        loge()<<QString::fromLocal8Bit("��ӵĿ����������󣬸�����Ϊ3��number:%1  ����:%2").arg(qstrNum).arg(icount);
        return;
    }

    m_mapThreePointsQuiklyNumberList[qstrPeriod] = qstrNum;
}

const QMap<QString, QString> ModelManage::GetThreePointsQuiklyNumberList()
{\
    return m_mapThreePointsQuiklyNumberList;
}
