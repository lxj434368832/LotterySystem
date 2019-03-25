#ifndef FORMSTATISTIC_H
#define FORMSTATISTIC_H

#include <QWidget>
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

private:
    Ui::FormStatistic *ui;
};

#endif // FORMSTATISTIC_H
