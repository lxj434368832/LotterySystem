#include "FormStatistic.h"
#include "ui_FormStatistic.h"
#include "../../LogicManage/MainLogic.h"
#include <QButtonGroup>
#include <WinBase.h>

FormStatistic::FormStatistic(ViewMediator *mdt, QWidget *parent) :
    QWidget(parent),
    ViewColleague (mdt),
    ui(new Ui::FormStatistic)
{
    ui->setupUi(this);

    int index = 0;
    QButtonGroup *btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->cbrOne, index++);
    btnGroup->addButton(ui->cbrTwo, index++);
    btnGroup->addButton(ui->cbrThree, index++);
    btnGroup->addButton(ui->cbrFour, index++);
    btnGroup->addButton(ui->cbrFive, index++);
    btnGroup->addButton(ui->cbrSix, index++);
    btnGroup->addButton(ui->cbrSeven, index++);
    btnGroup->addButton(ui->cbrEight, index++);
    btnGroup->addButton(ui->cbrNine, index++);
    btnGroup->addButton(ui->cbrTen, index++);
    connect(btnGroup,SIGNAL(buttonToggled(int,bool)),this, SLOT(slotGroupButtonToggled(int,bool)));

    //初始化统计列表窗体
    QStringList headers;
    headers.append(QString::fromLocal8Bit("期号"));
    headers.append(QString::fromLocal8Bit("开奖号"));
    headers.append(QString::fromLocal8Bit("AVG"));
    headers.append("1");
    headers.append("2");
    headers.append("3");
    headers.append("4");
    headers.append("5");
    headers.append("6");
    headers.append("7");
    headers.append("8");
    headers.append("8");
    headers.append("10");
    ui->twStatisticList->setColumnCount(headers.count());
    ui->twStatisticList->setHorizontalHeaderLabels(headers);
    ui->twStatisticList->setColumnWidth(0,60);
    ui->twStatisticList->setColumnWidth(1,100);
    ui->twStatisticList->setColumnWidth(2,50);

    connect(m_mainLogic,SIGNAL(signalLotteryListChanged(QMap<QString,QString>)),
            this,SLOT(slotLotteryListChanged(QMap<QString,QString>)));

    m_iStatisticCount = ui->sbTatisticPeriod->value();
    m_vctStatisticRank = {0,0,1,1,1,1,1,1,0,0};
    ExecuteStatistic(m_mainLogic->GetLotteryList());
}

FormStatistic::~FormStatistic()
{
    delete ui;
}

void FormStatistic::on_sbTatisticPeriod_editingFinished()
{
    m_iStatisticCount = ui->sbTatisticPeriod->value();
    ExecuteStatistic(m_mainLogic->GetLotteryList());
}

void FormStatistic::on_cbStatisticMode_currentIndexChanged(int index)
{
    ExecuteStatistic(m_mainLogic->GetLotteryList());
}

void FormStatistic::slotGroupButtonToggled(int id, bool checked)
{
    m_vctStatisticRank[id] = checked ? 1 : 0;
    ExecuteStatistic(m_mainLogic->GetLotteryList());
}

void FormStatistic::slotLotteryListChanged(QMap<QString, QString> mapLotteryList)
{
    ExecuteStatistic(mapLotteryList);
}

void FormStatistic::ExecuteStatistic(const QMap<QString, QString> mapLotteryList)
{
    if(0 == ui->cbStatisticMode->currentIndex())
        StatisticHeat(mapLotteryList);
    else
        StatisticMissing(mapLotteryList);
}

void FormStatistic::StatisticHeat(const QMap<QString, QString> mapLotteryList)
{
    double dAvg;
    int iCount = mapLotteryList.size();
    ui->leTotalPeriod->setText(QString::number(iCount));
   ::ZeroMemory(m_aHitCount, sizeof(m_aHitCount));

}

void FormStatistic::StatisticMissing(const QMap<QString, QString> mapLotteryList)
{

}
