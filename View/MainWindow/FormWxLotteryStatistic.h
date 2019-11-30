#pragma once

#include <QWidget>
#include <QVector>
#include <QMap>
#include "../ViewManage/ViewColleague.h"

namespace Ui {
class FormWxLotteryStatistic;
}


class FormWxLotteryStatistic : public QWidget, public ViewColleague
{
    Q_OBJECT

public:
    explicit FormWxLotteryStatistic(ViewMediator *mdt, QWidget *parent = nullptr);
    ~FormWxLotteryStatistic();

signals:
    void signalBackToTab(QWidget*, QString qstrTitle);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_sbTatisticPeriod_editingFinished();

    void on_cbStatisticMode_currentIndexChanged(int index);

    void slotWxNumberChanged(QStringList list);

private:
    void ExecuteStatistic(const QStringList listLottery);
    void StatisticHeat(const QStringList listLottery);
    void StatisticMissing(const QStringList listLottery);

    void StatisticOneHeat(QString&);    //统计一个开奖号的热度
	void HighlightFifthRow();

private:
    Ui::FormWxLotteryStatistic *ui;
    int                           m_iStatisticCount;      //统计期数
    QVector<int>				  m_vctStatisticRank;     //需要统计的名次
	int							  m_iStatisticFigure;	  //统计位数
    int                           m_aHitCount[10];        //1--10命中的次数

};

