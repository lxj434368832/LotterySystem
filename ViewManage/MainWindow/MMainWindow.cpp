#include "MMainWindow.h"
#include "ui_MMainWindow.h"
#include "FormStatistic.h"
#include "..\..\LogicManage\MainLogic.h"
#include "formAddData.h"
#include "..\..\CommonFile\CommonDefine.h"
#include <QFileDialog>
#include <QElapsedTimer>

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

void MMainWindow::on_btnImportData_clicked()
{
    QString qstrFilePath = QFileDialog::getOpenFileName(nullptr, QString::fromLocal8Bit("请选择要导入的Excel文件"),
		"", QString::fromLocal8Bit("Excel 工作薄(*.xlsx *.xls)"));

	if (qstrFilePath.isEmpty()) return;
	if (false == QFile::exists(qstrFilePath)) return;
	m_mainLogic->ImportData(QDir::toNativeSeparators(qstrFilePath));
}

void MMainWindow::on_btnAddData_clicked()
{
	QString qstrPeriod;
	QString qstrNum;
	formAddData	dlg;
	const QMap<QString, QString> lotteryList = m_mainLogic->GetLotteryList();
	if (false == lotteryList.isEmpty())
	{
		qstrPeriod = lotteryList.lastKey();
	}
    dlg.SetLastPeriod(qstrPeriod);
    if(QDialog::Rejected == dlg.exec()) return;
    dlg.GetData(qstrPeriod, qstrNum);
    m_mainLogic->AddData(qstrPeriod, qstrNum);
}

void MMainWindow::on_btnAddStatistic_clicked()
{
    int iItemCount = ui->tabStatistic->count();
    FormStatistic *form = new FormStatistic(m_mediator);

    ui->tabStatistic->addTab(form, QString::fromLocal8Bit("统计项%1").arg(iItemCount + 1));
    ui->tabStatistic->setCurrentIndex(iItemCount);
}
