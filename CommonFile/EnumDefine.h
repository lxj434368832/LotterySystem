#pragma once

#define MESSAGE_RESOURCE_COUNT 100

//���������ͣ��ͻ��˵�UserKey��ʹ�ô�ö�ٱ���
enum EServerType
{
	EST_UNKNOWN,
	EST_CMD_SERVER,
	EST_DATA_SERVER,
	EST_SERVER_COUNT = 1000
};

//��ʾ��Ϣ����
enum EShowMsgType
{
    ESMT_UNKNOWN,
    ESMT_INFORMATION,   //��Ϣ
    ESMT_WARNING,           //�澯
    ESMT_CRITICAL,           //����
    ESMT_QUESTION          //��ѯ
};
