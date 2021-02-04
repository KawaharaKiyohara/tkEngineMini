/*!
 *@brief	���x���B
 */

#include "stdafx.h"
#include "ExEngine.h"
#include "Level2D.h"
#include "CaslFile.h"
#include "MapChipRender2D.h"



Level2D::~Level2D()
{
	for (auto render : m_mapChipRender2DList)
	{
		DeleteGO(render);
	}
}

void Level2D::AddMapChipRender2D(CaslData* caslData)
{
	MapChipRender2D* mapChipRender2D = NewGO<MapChipRender2D>(0);
	mapChipRender2D->Init(caslData);
	m_mapChipRender2DList.push_back(mapChipRender2D);
}

void Level2D::Init(
	const char* filePath,
	std::function<bool(Level2DObjectData & objData)> hookFunc
)
{
	//Casl�t�@�C�������[�h����B
	CaslFile casl;
	casl.Load(filePath);

	//�\�z�\�z�B
	for (int i = 0; i < casl.GetNumCaslData(); i++)
	{
		auto caslData = casl.GetCaslData(i);
		Level2DObjectData objData;
		objData.scale.x = caslData->scale.x;
		objData.scale.y = caslData->scale.y;
		objData.position.x = caslData->position.x;
		objData.position.y = caslData->position.y;
		objData.width = caslData->width;
		objData.height = caslData->height;
		objData.name = caslData->name.get();
		auto isHook = false;
		if (hookFunc != nullptr) {
			//hook�֐����w�肳��Ă���̂�hook�֐����Ăяo���B
			isHook = hookFunc(objData);
			if (!isHook)
			{
				AddMapChipRender2D(caslData);
			}
		}
		else
		{
			AddMapChipRender2D(caslData);
		}
	}

}
