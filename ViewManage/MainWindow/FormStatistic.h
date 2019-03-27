#ifndef FORMSTATISTIC_H
#define FORMSTATISTIC_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include "../MainView/ViewColleague.h"

namespace Ui {
class FormStatistic;
}


class FormStatistic : public QWidget, public ViewColleague
{
    Q_OBJECT

public:
    explicit FormStatistic(ViewMediator *mdt, QWidget *parent = nullptr);
    ~FormStatistic();

signals:
    signalBackToTab(QWidget*, QString qstrTitle);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_sbTatisticPeriod_editingFinished();

    void on_cbStatisticMode_currentIndexChanged(int index);

    void slotGroupButtonToggled(int id, bool checked);

    void slotLotteryListChanged(QMap<QString,QString>);

private:
    void ExecuteStatistic(const QMap<QString, QString>);
    void StatisticHeat(const QMap<QString, QString>);
    void StatisticMissing(const QMap<QString, QString>);

	void StatisticOneHeat(QString&);
	void HighlightFifthRow();

private:
    Ui::FormStatistic *ui;
    int                           m_iStatisticCount;      //统计期数
    QVector<int>				  m_vctStatisticRank;     //需要统计的名次
	int							  m_iStatisticFigure;	  //统计位数
    int                           m_aHitCount[10];        //1--10命中的次数

};

#endif // FORMSTATISTIC_H
