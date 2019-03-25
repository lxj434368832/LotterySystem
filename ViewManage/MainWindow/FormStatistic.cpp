#include "FormStatistic.h"
#include "ui_FormStatistic.h"

FormStatistic::FormStatistic(ViewMediator *mdt, QWidget *parent) :
    QWidget(parent),
    ViewColleague (mdt),
    ui(new Ui::FormStatistic)
{
    ui->setupUi(this);
}

FormStatistic::~FormStatistic()
{
    delete ui;
}

void FormStatistic::on_sbTatisticPeriod_editingFinished()
{

}

void FormStatistic::on_cbStatisticMode_currentIndexChanged(int index)
{

}
