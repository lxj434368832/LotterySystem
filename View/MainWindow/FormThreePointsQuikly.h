#ifndef FORMTHREEPOINTSQUIKLY_H
#define FORMTHREEPOINTSQUIKLY_H

#include <QWidget>

namespace Ui {
class FormThreePointsQuikly;
}

class FormThreePointsQuikly : public QWidget
{
    Q_OBJECT

public:
    explicit FormThreePointsQuikly(QWidget *parent = nullptr);
    ~FormThreePointsQuikly();

private slots:
    void on_sbTatisticPeriod_editingFinished();

private:
    Ui::FormThreePointsQuikly *ui;
};

#endif // FORMTHREEPOINTSQUIKLY_H
