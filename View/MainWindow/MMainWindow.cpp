#include "MMainWindow.h"
#include "ui_MMainWindow.h"
#include "FormFiveMinuteRaceStatistic.h"
#include "..\..\Controller\ControllerManage\ControllerManage.h"
#include "formAddData.h"
#include "..\..\CommonFile\CommonDefine.h"
#include "FormImportWxLotteryData.h"
#include <QFileDialog>
#include <QElapsedTimer>
#include "FormWxLotteryStatistic.h"

MMainWindow::MMainWindow(ViewMediator *mdt, QWidget *parent) :
    MFramelessWidget(parent),
    ViewColleague (mdt),
    ui(new Ui::MMainWindow)
{
    ui->setupUi(this);
//    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    ui->frameStatusBar->setVisible(false);
    on_btnAddStatistic_clicked();
}

MMainWindow::~MMainWindow()
{
    delete ui;
}

void MMainWindow::on_btnClose_clicked()
{
    close();
}

void MMainWindow::on_leLotteryNum_returnPressed()
{
    QString qstrNum = ui->leLotteryNum->text();
    m_mainLogic->AddWxNumberData(qstrNum);
    ui->leLotteryNum->clear();
}

void MMainWindow::on_btnImportData_clicked()
{
    /*QString qstrFilePath = QFileDialog::getOpenFileName(nullptr, QString::fromLocal8Bit("请选择要导入的Excel文件"),
		"", QString::fromLocal8Bit("Excel 工作薄(*.xlsx *.xls)"));

	if (qstrFilePath.isEmpty()) return;
	if (false == QFile::exists(qstrFilePath)) return;
    emit m_mainLogic->signalImportFiveMinuteRaceData(QDir::toNativeSeparators(qstrFilePath));*/
    FormImportWxLotteryData form(this);
    if(QDialog::Accepted == form.exec())
    {
        QString strText = form.GetLotteryNum();
        m_mainLogic->AddWxStatisticData(strText);
    }

}

void MMainWindow::on_btnAddStatistic_clicked()
{
    int iItemCount = ui->tabStatistic->count();
	FormWxLotteryStatistic *form = new FormWxLotteryStatistic(m_mediator);
    connect(form, SIGNAL(signalBackToTab(QWidget*, QString)), this, SLOT(slotBackToTab(QWidget*, QString)));

    ui->tabStatistic->addTab(form, QString::fromLocal8Bit("统计项%1").arg(iItemCount + 1));
    ui->tabStatistic->setCurrentIndex(iItemCount);
}

void MMainWindow::on_tabStatistic_tabBarDoubleClicked(int index)
{
    QWidget *widget = ui->tabStatistic->widget(index);
    widget->setWindowTitle(ui->tabStatistic->tabText(index));
    ui->tabStatistic->removeTab(index);
    widget->setWindowFlags(Qt::Window);
    widget->show();
    widget->raise();
    widget->activateWindow();
	widget->move(50, 50);
}

void MMainWindow::slotBackToTab(QWidget* widget, QString qstrTitle)
{
    widget->setWindowFlags(Qt::Widget);
    ui->tabStatistic->addTab(widget, qstrTitle);
}

void MMainWindow::on_btnMinimum_clicked()
{
    showMinimized();
}

void MMainWindow::on_btnMaximum_clicked()
{
    if(isMaximized())
        showNormal();
    else
        showMaximized();
}
