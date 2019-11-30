#include "FormWxLotteryStatistic.h"
#include "ui_FormWxLotteryStatistic.h"
#include "../../Controller/ControllerManage/ControllerManage.h"
#include "../../CommonFile/CommonDefine.h"
#include "FormLotteryNumber.h"
#include <QButtonGroup>
#include <QCloseEvent>
#include <QElapsedTimer>

FormWxLotteryStatistic::FormWxLotteryStatistic(ViewMediator *mdt, QWidget *parent) :
    QWidget(parent),
    ViewColleague (mdt),
    ui(new Ui::FormWxLotteryStatistic)
{
    ui->setupUi(this);

	//初始化统计列表窗体
	ui->twStatisticList->horizontalHeader()->setDefaultSectionSize(50);
	ui->twStatisticList->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    QStringList headers;
    headers.append(QString::fromLocal8Bit("期号"));
    headers.append(QString::fromLocal8Bit("开奖号"));
    headers.append("AVG");
    headers.append("0");
    headers.append("1");
    headers.append("2");
    headers.append("3");
    headers.append("4");
    headers.append("5");
    headers.append("6");
    headers.append("7");
    headers.append("8");
    headers.append("9");
	ui->twStatisticList->setColumnCount(headers.count());
    ui->twStatisticList->setColumnWidth(0, 65);
    ui->twStatisticList->setColumnWidth(1, 180);
	ui->twStatisticList->setColumnWidth(2, 50);
    ui->twStatisticList->setHorizontalHeaderLabels(headers);

    connect(m_mainLogic, SIGNAL(signalWxNumberChanged(QStringList)),
        SLOT(slotWxNumberChanged(QStringList)));

    m_iStatisticCount = ui->sbTatisticPeriod->value();
    m_iStatisticFigure = 5;

    ExecuteStatistic(m_mainLogic->GetWxNumberStatisticList());
}

FormWxLotteryStatistic::~FormWxLotteryStatistic()
{
    delete ui;
}

void FormWxLotteryStatistic::closeEvent(QCloseEvent *event)
{
    emit signalBackToTab(this, windowTitle());
    event->ignore();
}

void FormWxLotteryStatistic::on_sbTatisticPeriod_editingFinished()
{
    m_iStatisticCount = ui->sbTatisticPeriod->value();
    ExecuteStatistic(m_mainLogic->GetWxNumberStatisticList());
}

void FormWxLotteryStatistic::on_cbStatisticMode_currentIndexChanged(int index)
{
	index;
    ExecuteStatistic(m_mainLogic->GetWxNumberStatisticList());
}

void FormWxLotteryStatistic::slotWxNumberChanged(QStringList list)
{
    QElapsedTimer time;
    time.start();
    ExecuteStatistic(list);
    logm() << QStringLiteral("统计总共用时%1毫秒").arg(time.elapsed());
}

void FormWxLotteryStatistic::ExecuteStatistic(const QStringList listLottery)
{
    if(0 == ui->cbStatisticMode->currentIndex())
        StatisticHeat(listLottery);
    else
        StatisticMissing(listLottery);
}

void FormWxLotteryStatistic::StatisticHeat(const QStringList listLottery)
{
    double dAvg;
    int iCount = listLottery.size();
    if(0 == iCount) return;

    int iStatisticCount = m_iStatisticCount;
    if (iCount < iStatisticCount)
	{
        logm() << QString::fromLocal8Bit("统计期数为:%1, 总期数为:%2。统计期数高于总期数。")
                  .arg(iStatisticCount).arg(iCount);
        iStatisticCount = iCount;
    }
    ui->twStatisticList->setRowCount(iStatisticCount);
    ui->leTotalPeriod->setText(QString::number(iCount));
   ::memset(m_aHitCount,0,sizeof(m_aHitCount));
   QTableWidgetItem *item;
   int iRow = 0;
   int iStart = iCount - iStatisticCount;
   for (auto iter = listLottery.begin() + iStart; iter != listLottery.end(); iter++)
   {
       int iCol = 0;
       //添加期号
       item = new QTableWidgetItem(QString::number(iRow + 1));
	   item->setTextAlignment(Qt::AlignCenter);
       ui->twStatisticList->setItem(iRow, iCol++, item);

       //添加开奖号
       QString qstrNums = *iter;
       ui->twStatisticList->setItem(iRow,  iCol, new QTableWidgetItem);
        FormLotteryNumber   *form = new FormLotteryNumber();
		form->SetLotteryNumbers(qstrNums);
        ui->twStatisticList->setCellWidget(iRow, iCol++, form);

        //添加平均值
       dAvg = (iRow + 1) * m_iStatisticFigure / 10.0;
       item = new QTableWidgetItem(QString::number(dAvg, 'f' ,1));
	   item->setTextAlignment(Qt::AlignCenter);
       ui->twStatisticList->setItem(iRow,  iCol++,  item);

       //添加各个数字的热度
       StatisticOneHeat(qstrNums);
	   for (int i = 0; i < 10; i++)
	   {
		   item = new QTableWidgetItem(QString::number(m_aHitCount[i]));
		   item->setTextAlignment(Qt::AlignCenter);
		   ui->twStatisticList->setItem(iRow, iCol++, item);
	   }

	   iRow++;
   }

   HighlightFifthRow();
   ui->twStatisticList->scrollToBottom();

}

void FormWxLotteryStatistic::StatisticOneHeat(QString& qstrNums)
{
    for (QChar qstrNum : qstrNums)
	{
        int iNum = qstrNum.digitValue();
        m_aHitCount[iNum]++;
	}
}

void FormWxLotteryStatistic::HighlightFifthRow()
{
	QTableWidgetItem *item = nullptr;
	int iRowCount = ui->twStatisticList->rowCount();
	int iColCount = ui->twStatisticList->colorCount();
	for (int iRow = 4; iRow < iRowCount; iRow+= 5)
	{
		for (int iCol = 0; iCol < iColCount; iCol++)
		{
			item = ui->twStatisticList->item(iRow, iCol);
			if(item)
				item->setBackground(QColor("#deffde"));//#fda4a4
		}
	}
}

void FormWxLotteryStatistic::StatisticMissing(const QStringList listLottery)
{

}
