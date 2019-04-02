#ifndef FORMSTATISTIC_H
#define FORMSTATISTIC_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include "../ViewManage/ViewColleague.h"

namespace Ui {
class FormFiveMinuteRaceStatistic;
}


class FormFiveMinuteRaceStatistic : public QWidget, public ViewColleague
{
    Q_OBJECT

public:
    explicit FormFiveMinuteRaceStatistic(ViewMediator *mdt, QWidget *parent = nullptr);
    ~FormFiveMinuteRaceStatistic();

signals:
    void signalBackToTab(QWidget*, QString qstrTitle);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_sbTatisticPeriod_editingFinished();

    void on_cbStatisticMode_currentIndexChanged(int index);

    void slotGroupButtonToggled(int id, bool checked);

    void slotFiveMinuteRaceNumberChanged(QMap<QString,QString>);

private:
    void ExecuteStatistic(const QMap<QString, QString>);
    void StatisticHeat(const QMap<QString, QString>);
    void StatisticMissing(const QMap<QString, QString>);

	void StatisticOneHeat(QString&);
	void HighlightFifthRow();

private:
    Ui::FormFiveMinuteRaceStatistic *ui;
    int                           m_iStatisticCount;      //ͳ������
    QVector<int>				  m_vctStatisticRank;     //��Ҫͳ�Ƶ�����
	int							  m_iStatisticFigure;	  //ͳ��λ��
    int                           m_aHitCount[10];        //1--10���еĴ���

};

#endif // FORMSTATISTIC_H
