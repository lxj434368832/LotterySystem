#include "ControllerManage.h"
#include "../../3rdParty/ReadWriteExcel/include/ReadWriteExcel.h"
#include "../../CommonFile/CommonDefine.h"
#include "../../MainClient/IMainClient.h"
#include "../../Model/ModelManage/ModelManage.h"
#include <QElapsedTimer>


ControllerManage::ControllerManage(IMainClient *_main) :
	QObject(),
    IControllerManage(_main)
{
	qRegisterMetaType<QMap<QString, QString>>("QMap<QString, QString>");

    connect(this, SIGNAL(signalImportData(QString)),this, SLOT(slotImportData(QString)));
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
    m_model = dynamic_cast<ModelManage*>(m_main->GetModelInterface());
    if(nullptr == m_model)
    {
        loge()<<QStringLiteral("获取模型管理失败!");
        return false;
    }
	return true;
}

void ControllerManage::Stop()
{
    m_model = nullptr;
}

void ControllerManage::slotImportData(QString qstrFilePath)
{
    ReadWriteExcel rdExcel;
    if(nullptr == m_model)  return;
	rdExcel.OpenExcel(qstrFilePath);
   m_model->SaveLotteryNumberList( rdExcel.ReadAllData());

    emit signalLotteryListChanged(m_model->GetLotteryList());
}

void ControllerManage::AddData(QString qstrPeriod, QString qstrNum)
{
     if(nullptr == m_model)  return;
    m_model->AddLotteryNumberData(qstrPeriod, qstrNum);
}

const QMap<QString, QString> ControllerManage::GetLotteryList()
{
     if(nullptr == m_model)
     {
         QMap<QString, QString> map;
         return map;
     }
    return m_model->GetLotteryList();
}
