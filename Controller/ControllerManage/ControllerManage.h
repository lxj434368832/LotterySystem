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

//֪ͨ���źź���
signals:
    void signalFiveMinuteRaceNumberChanged(QMap<QString, QString>);
    void signalThreePointsQuiklyNumberChanged(QMap<QString, QString>);

private slots:
    void slotImportFiveMinuteRaceData(QString qstrFilePath);
    void slotImportThreePointsQuiklyData(QString qstrFilePath);

private:
    QThread                                     m_thread;                   //�첽�߳�
    ModelManage                           *m_model;                  //ģ�͹���
};

