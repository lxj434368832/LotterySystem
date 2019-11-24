#include "FormThreePointsQuikly.h"
#include "ui_FormThreePointsQuikly.h"

FormThreePointsQuikly::FormThreePointsQuikly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormThreePointsQuikly)
{
    ui->setupUi(this);
}

FormThreePointsQuikly::~FormThreePointsQuikly()
{
    delete ui;
}

void FormThreePointsQuikly::on_sbTatisticPeriod_editingFinished()
{

}
