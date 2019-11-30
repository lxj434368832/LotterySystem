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

    //�ⲿ���õĺ���
public:
    /*************************************************************************
    * function:����һ�����ݵ��б���
    * param qstrPeriod:����
    * param qstrNum:   ������
    * return:
    *************************************************************************/
    void AddFiveMinuteRaceData(QString qstrPeriod, QString qstrNum);

    /*************************************************************************
    * function:����һ�����ֿ������ݵ��б���
    * param qstrPeriod:����
    * param qstrNum:   ������
    * return:
    *************************************************************************/
    void AddThreePointsQuiklyData(QString qstrPeriod, QString qstrNum);
    const QMap<QString, QString> GetFiveMinuteRaceNumberList();

    const QMap<QString, QString> GetThreePointsQuiklyNumberList();

    //���΢�ſ�������
    void AddWxStatisticData(QString strLotteryData);
    //���һ�ڿ�������
    void AddWxNumberData(QString strNum);
    //��ȡ΢�ſ�������
    const QStringList GetWxNumberStatisticList();

    //���ⲿ֪ͨ���źź���
signals:

    //������ʾ��Ϣ
    void signalPopupShowMessage(unsigned uType, std::string strTitle, std::string strMsg);
    void signalFiveMinuteRaceNumberChanged(QMap<QString, QString>);
    void signalThreePointsQuiklyNumberChanged(QMap<QString, QString>);
    void signalWxNumberChanged(QStringList);

    //�ⲿ���õ��ź�
signals:
    /*************************************************************************
    * function:�ӱ����ļ��е�������
    * param qstrFilePath: �ļ�·��
    * return:
    *************************************************************************/
    void signalImportFiveMinuteRaceData(QString qstrFilePath);

    /*************************************************************************
    * function:�ӱ����ļ��е������ֿ�������
    * param qstrFilePath: �ļ�·��
    * return:
    *************************************************************************/
    void signalImportThreePointsQuiklyData(QString qstrFilePath);

private slots:
    //�ⲿ�����źŵ�ʵ�ֺ���
    void slotImportFiveMinuteRaceData(QString qstrFilePath);
    void slotImportThreePointsQuiklyData(QString qstrFilePath);

private:
    QThread                                     m_thread;                   //�첽�߳�
    ModelManage                                 *m_pModel;                  //ģ�͹���
};

