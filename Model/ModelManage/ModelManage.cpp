#include "ModelManage.h"



ModelManage::ModelManage(IMainClient *_main)
	:IModelManage(_main)
{
}


ModelManage::~ModelManage()
{
}

bool ModelManage::Start()
{
	return true;
}

void ModelManage::Stop()
{
}
