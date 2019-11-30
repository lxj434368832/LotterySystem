#pragma once

#include <QDialog>
#include <QPushButton>

namespace Ui {
class FormImportWxLotteryData;
}

class FormImportWxLotteryData : public QDialog
{
    Q_OBJECT

public:
    explicit FormImportWxLotteryData(QWidget *parent = 0);
    ~FormImportWxLotteryData();
    QString GetLotteryNum();

private:
    Ui::FormImportWxLotteryData *ui;
};

