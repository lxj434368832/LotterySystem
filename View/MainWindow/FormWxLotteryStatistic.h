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

    void StatisticOneHeat(QString&);    //ͳ��һ�������ŵ��ȶ�
	void HighlightFifthRow();

private:
    Ui::FormWxLotteryStatistic *ui;
    int                           m_iStatisticCount;      //ͳ������
    QVector<int>				  m_vctStatisticRank;     //��Ҫͳ�Ƶ�����
	int							  m_iStatisticFigure;	  //ͳ��λ��
    int                           m_aHitCount[10];        //1--10���еĴ���

};

