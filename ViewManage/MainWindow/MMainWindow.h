#ifndef MMAINWINDOW_H
#define MMAINWINDOW_H

#include <QWidget>
#include"../../3rdParty/MFramelessWidget/include/MFramelessWidget.h"
#include "../MainView/ViewColleague.h"

namespace Ui {
class MMainWindow;
}

class MMainWindow : public MFramelessWidget, public ViewColleague
{
    Q_OBJECT

public:
    explicit MMainWindow(ViewMediator *mdt, QWidget *parent = nullptr);
    ~MMainWindow();

private slots:
    void on_btnClose_clicked();

    void on_btnImportData_clicked();

    void on_btnAddData_clicked();

    void on_btnAddStatistic_clicked();

    void on_tabStatistic_tabBarDoubleClicked(int index);

    void slotBackToTab(QWidget *, QString);

private:
    Ui::MMainWindow *ui;
};

#endif // MMAINWINDOW_H
