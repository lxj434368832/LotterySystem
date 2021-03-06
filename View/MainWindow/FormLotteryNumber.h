#pragma once

#include <QWidget>
#include <QVector>

namespace Ui {
class FormLotteryNumber;
}

class FormLotteryNumber : public QWidget
{
    Q_OBJECT

public:
    explicit FormLotteryNumber(QWidget *parent = 0);
    ~FormLotteryNumber();
    void SetLotteryNumbers(QString qstrNums);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::FormLotteryNumber *ui;

    QVector<QString>     m_listNumBgColor;
    int                  m_iSpacing;
	QString				 m_strLotteryNums;
};

