#pragma once

#define MESSAGE_RESOURCE_COUNT 100

//服务器类型，客户端的UserKey就使用此枚举变量
enum EServerType
{
	EST_UNKNOWN,
	EST_CMD_SERVER,
	EST_DATA_SERVER,
	EST_SERVER_COUNT = 1000
};

//显示消息类型
enum EShowMsgType
{
    ESMT_UNKNOWN,
    ESMT_INFORMATION,   //信息
    ESMT_WARNING,           //告警
    ESMT_CRITICAL,           //严重
    ESMT_QUESTION          //问询
};
