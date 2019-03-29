#pragma once

#include "IModelManage.h"

class ModelManage : public IModelManage
{
public:
    ModelManage(IMainClient *_main = nullptr);
    ~ModelManage();

	bool Start() override;
	void Stop() override;

};

