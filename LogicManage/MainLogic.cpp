#include "MainLogic.h"
#include "../3rdParty/ReadWriteExcel/include/ReadWriteExcel.h"
#include "../CommonFile/CommonDefine.h"
#include <QElapsedTimer>


MainLogic::MainLogic(IMainClient *_main) :
	QObject(),
    ILogicInterface(_main)
{
	qRegisterMetaType<QMap<QString, QString>>("QMap<QString, QString>");
}

MainLogic::~MainLogic()
{
}

bool MainLogic::Start()
{
	return true;
}

void MainLogic::Stop()
{
}

void MainLogic::ImportData(QString qstrFilePath)
{
    ReadWriteExcel rdExcel;
	rdExcel.OpenExcel(qstrFilePath);
	QList<QList<QVariant>> rows = rdExcel.ReadAllData();
	if (0 == rows.size())
	{
		loge() << QStringLiteral("读取数据失败！");
		return;
	}
	rows.pop_front();		//去掉标题栏

    m_mapLotteryList.clear();
	for (QList<QVariant> row : rows)
	{
		QString qstrPeriod = row.at(1).toString();
		QString qstrNum = row.at(2).toString();
		m_mapLotteryList[qstrPeriod] = qstrNum;
	}

    emit signalLotteryListChanged(m_mapLotteryList);
}

void MainLogic::AddData(QString qstrPeriod, QString qstrNum)
{
	if (qstrPeriod.isEmpty() || qstrNum.isEmpty()) return;
	m_mapLotteryList[qstrPeriod] = qstrNum;
    emit signalLotteryListChanged(m_mapLotteryList);
}

const QMap<QString, QString> MainLogic::GetLotteryList()
{
	return m_mapLotteryList;
}
