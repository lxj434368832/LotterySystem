#include "FormImportWxLotteryData.h"
#include "ui_FormImportWxLotteryData.h"

FormImportWxLotteryData::FormImportWxLotteryData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormImportWxLotteryData)
{
    ui->setupUi(this);
    connect(ui->btnBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->btnBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

FormImportWxLotteryData::~FormImportWxLotteryData()
{
    delete ui;
}

QString FormImportWxLotteryData::GetLotteryNum()
{
    return ui->teLotteryNum->toPlainText();
}
