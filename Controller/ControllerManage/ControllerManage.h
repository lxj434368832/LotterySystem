#pragma once
#include <QObject>
#include <QThread>
#include <QMap>
#include "IControllerManage.h"

class ControllerManage : public QObject, public IControllerManage
{
    Q_OBJECT
public:
    ControllerManage(IMainClient *_main = nullptr);
    ~ControllerManage() override;

    bool Start() override;
    void Stop() override;

    //外部调用的函数
public:
    /*************************************************************************
    * function:增加一行数据到列表中
    * param qstrPeriod:期数
    * param qstrNum:   开奖号
    * return:
    *************************************************************************/
    void AddFiveMinuteRaceData(QString qstrPeriod, QString qstrNum);

    /*************************************************************************
    * function:增加一行三分快三数据到列表中
    * param qstrPeriod:期数
    * param qstrNum:   开奖号
    * return:
    *************************************************************************/
    void AddThreePointsQuiklyData(QString qstrPeriod, QString qstrNum);
    const QMap<QString, QString> GetFiveMinuteRaceNumberList();

    const QMap<QString, QString> GetThreePointsQuiklyNumberList();

    //添加微信开奖数据
    void AddWxStatisticData(QString strLotteryData);
    //添加一期开奖号码
    void AddWxNumberData(QString strNum);
    //获取微信开奖数据
    const QStringList GetWxNumberStatisticList();

    //对外部通知的信号函数
signals:

    //弹窗显示消息
    void signalPopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg);
    void signalFiveMinuteRaceNumberChanged(QMap<QString, QString>);
    void signalThreePointsQuiklyNumberChanged(QMap<QString, QString>);
    void signalWxNumberChanged(QStringList);

    //外部调用的信号
signals:
    /*************************************************************************
    * function:从本地文件中导入数据
    * param qstrFilePath: 文件路径
    * return:
    *************************************************************************/
    void signalImportFiveMinuteRaceData(QString qstrFilePath);

    /*************************************************************************
    * function:从本地文件中导入三分快三数据
    * param qstrFilePath: 文件路径
    * return:
    *************************************************************************/
    void signalImportThreePointsQuiklyData(QString qstrFilePath);

private slots:
    //外部调用信号的实现函数
    void slotImportFiveMinuteRaceData(QString qstrFilePath);
    void slotImportThreePointsQuiklyData(QString qstrFilePath);

private:
    QThread                                     m_thread;                   //异步线程
    ModelManage                                 *m_pModel;                  //模型管理
};

