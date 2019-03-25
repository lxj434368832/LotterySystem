#ifndef FORMSTATISTIC_H
#define FORMSTATISTIC_H

#include <QWidget>
#include <QVector>
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

private slots:
    void on_sbTatisticPeriod_editingFinished();

    void on_cbStatisticMode_currentIndexChanged(int index);

    void slotGroupButtonToggled(int id, bool checked);

    void slotLotteryListChanged(QMap<QString, QString>);

private:
    void ExecuteStatistic(const QMap<QString, QString>);
    void StatisticHeat(const QMap<QString, QString>);
    void StatisticMissing(const QMap<QString, QString>);

private:
    Ui::FormStatistic *ui;
    int                           m_iStatisticCount;       //统计期数
    QVector<int>        m_vctStatisticRank;     //统计名次
    int                           m_aHitCount[10];         //1--10命中的次数

};

#endif // FORMSTATISTIC_H
