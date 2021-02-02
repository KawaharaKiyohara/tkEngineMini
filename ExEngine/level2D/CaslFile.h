#pragma once
#include <list>
#include <vector>
#include <cstdlib>
#include <memory>
#include <map>

struct Level2DObject
{
public:

	std::unique_ptr<char[]> name;	//���O�B
	std::unique_ptr<char[]> fileName;	//�t�@�C���̃p�X�B
	Vector2 position = Vector2::Zero;
	int width = 0;
	int height = 0;
	int numberLayer = 0;
	Vector2 scale = Vector2::Zero;
};

class CaslFile
{
public:
	void Load(const char* filePath);
	Level2DObject* Find(const char* name);
	std::vector<Level2DObject*>& Finds(const char* name);
private:
	//1���������ǂݍ��ށA(,)��ǂݍ��ނ̂Ɏg���B
	void ReadOnlyOneCharacter(FILE* file);
	//������ǂݍ��ށB
	int ReadInteger(FILE* file);
	//float�^��ǂݍ��ށB
	float ReadDecimal(FILE* file);

	std::vector<std::unique_ptr<Level2DObject>> m_levelObjectList;
	std::vector<Level2DObject*> m_specificlevelObjectList;
	int m_numLevel = 0;
};

