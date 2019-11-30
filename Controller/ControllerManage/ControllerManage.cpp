#include "ControllerManage.h"
#include "../../3rdParty/ReadWriteExcel/include/ReadWriteExcel.h"
#include "../../CommonFile/CommonDefine.h"
#include "../../CommonFile/EnumDefine.h"
#include "../../MainClient/IMainClient.h"
#include "../../Model/ModelManage/ModelManage.h"
#include <QElapsedTimer>


ControllerManage::ControllerManage(IMainClient *_main) :
	QObject(),
    IControllerManage(_main)
{
	qRegisterMetaType<QMap<QString, QString>>("QMap<QString, QString>");

    connect(this, SIGNAL(signalImportFiveMinuteRaceData(QString)),this, SLOT(slotImportFiveMinuteRaceData(QString)));
    connect(this, SIGNAL(signalImportThreePointsQuiklyData(QString)),this, SLOT(slotImportThreePointsQuiklyData(QString)));
    moveToThread(&m_thread);
    m_thread.start();
}

ControllerManage::~ControllerManage()
{
    m_thread.quit();
    m_thread.wait();
//    m_thread.terminate();
}

bool ControllerManage::Start()
{
    m_pModel = dynamic_cast<ModelManage*>(m_main->GetModelManage());
    if(nullptr == m_pModel)
    {
        loge()<<QStringLiteral("��ȡģ�͹���ʧ��!");
        return false;
    }
	return true;
}

void ControllerManage::Stop()
{
    m_pModel = nullptr;
}

void ControllerManage::slotImportFiveMinuteRaceData(QString qstrFilePath)
{
    ReadWriteExcel rdExcel;
    if(nullptr == m_pModel)  return;
	rdExcel.OpenExcel(qstrFilePath);
   m_pModel->SaveFiveMinuteRaceNumberList( rdExcel.ReadAllData());

   emit signalFiveMinuteRaceNumberChanged(m_pModel->GetFiveMinuteRaceNumberList());
}

void ControllerManage::slotImportThreePointsQuiklyData(QString qstrFilePath)
{
    ReadWriteExcel rdExcel;
    if(nullptr == m_pModel)  return;
    rdExcel.OpenExcel(qstrFilePath);
   m_pModel->SaveThreePointsQuiklyNumberList(rdExcel.ReadAllData());
}

void ControllerManage::AddFiveMinuteRaceData(QString qstrPeriod, QString qstrNum)
{
     if(nullptr == m_pModel)  return;
     m_pModel->AddFiveMinuteRaceNumberData(qstrPeriod, qstrNum);
}

void ControllerManage::AddThreePointsQuiklyData(QString qstrPeriod, QString qstrNum)
{
    if(nullptr == m_pModel)  return;
    m_pModel->AddThreePointsQuiklyNumberData(qstrPeriod, qstrNum);
}

const QMap<QString, QString> ControllerManage::GetFiveMinuteRaceNumberList()
{
     if(nullptr == m_pModel)
     {
         QMap<QString, QString> map;
         return map;
     }
     return m_pModel->GetFiveMinuteRaceNumberList();
}

const QMap<QString, QString> ControllerManage::GetThreePointsQuiklyNumberList()
{
    if(nullptr == m_pModel)
    {
        QMap<QString, QString> map;
        return map;
    }
    return m_pModel->GetThreePointsQuiklyNumberList();
}

void ControllerManage::AddWxStatisticData(QString strLotteryData)
{
    QStringList listNums;
    strLotteryData = strLotteryData.trimmed();
    int iNum = 1;
    QString strNum;
    for(QChar ch : strLotteryData)
    {
        if(false == ch.isNumber())
        {
            loge()<< QString::fromLocal8Bit("��ǰ�ַ�:%1��Ϊ���֡�").arg(ch);
            continue;
        }

        strNum.append(ch);
        if(0 == iNum++ % 5)
        {
            listNums.append(strNum);
            strNum.clear();
        }
    }

    m_pModel->SaveWxNumStatisticData(listNums);
    emit signalWxNumberChanged(listNums);
}

void ControllerManage::AddWxNumberData(QString strNum)
{
    logm()<<QString::fromLocal8Bit("��ǰ��ӵĺ���Ϊ:%1").arg(strNum);
    int iCount = strNum.count();
    if(5 != iCount)
    {
        QString qstrMsg = QString::fromLocal8Bit("����Ŀ�����Ϊ:%1,�䳤�Ȳ�Ϊ5�����������룡").arg(strNum);
        emit signalPopupShowMessage(ESMT_INFORMATION, "����", qstrMsg.toLocal8Bit().data());
        return;
    }

    for(QChar ch : strNum)
    {
        if(false == ch.isNumber())
        {
            QString qstrMsg = QString::fromLocal8Bit("��ǰ�ַ�:%1��Ϊ���֡�").arg(ch);
            emit signalPopupShowMessage(ESMT_INFORMATION, "����", qstrMsg.toLocal8Bit().data());
            return;
        }
    }
    QStringList listNum = m_pModel->AddWxNumberData(strNum);
    emit signalWxNumberChanged(listNum);
}

const QStringList ControllerManage::GetWxNumberStatisticList()
{
    return m_pModel->GetWxNumberList();
}
