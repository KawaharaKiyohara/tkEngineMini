#include "stdafx.h"
//#include "../../GameTemplate/Game/stdafx.h"
#include "CaslFile.h"
#include <string>

void CaslFile::Load(const char* filePath)
{
	auto fp = fopen(filePath, "rb");
	//�t�@�C���ǂݍ��߂Ȃ�������B
	if (fp == nullptr) {
		return;
	}
	//�摜�̐����擾�B
	m_numLevel = ReadInteger(fp);
	for (int i = 0; i < m_numLevel; i++)
	{

		auto levelObject = std::make_unique<Level2DObject>();
		//std::unique_ptr<Level2DObject> levelObject;
		//���x���t�@�C���ɕۑ����Ă���̂�
		//�ȉ��S��char�^�ŕۑ����Ă���A����(,)�ŋ�؂肪���Ă���B
		//���O�̒���(int)�A���O(char)
		//�t�@�C���p�X�̒���(int)�A�t�@�C���p�X(char)
		//���Wx,y(float)
		//�摜�̑傫��x,y(int)
		//���C���[�D��xx,y(int)
		//�X�P�[���{��x,y(float)
		//�摜�̖��O�̒������擾�B
		int nameCount = ReadInteger(fp);
		//�摜�̖��O���擾
		levelObject.get()->name = std::make_unique<char[]>(nameCount + 1);
		fread(levelObject.get()->name.get(), nameCount, 1, fp);
		ReadOnlyOneCharacter(fp);

		int fileNameCount = ReadInteger(fp);
		//�摜�̖��O���擾
		levelObject.get()->fileName = std::make_unique<char[]>(fileNameCount + 1);
		fread(levelObject.get()->fileName.get(), fileNameCount, 1, fp);
		ReadOnlyOneCharacter(fp);

		//���W���擾�B
		levelObject.get()->position.x = ReadDecimal(fp);
		levelObject.get()->position.y = ReadDecimal(fp);

		//���ƍ������擾�B
		levelObject.get()->width = ReadInteger(fp);
		levelObject.get()->height = ReadInteger(fp);

		//���C���[�D��x���擾�B
		levelObject.get()->numberLayer = ReadInteger(fp);

		//�傫���̔{�����擾�B
		levelObject.get()->scale.x = ReadDecimal(fp);
		levelObject.get()->scale.y = ReadDecimal(fp);

		m_levelObjectList.push_back(std::move(levelObject));
	}
	int a = 0;

}

void CaslFile::ReadOnlyOneCharacter(FILE* file)
{
	char a;
	fread(&a, 1, 1, file);
}

int CaslFile::ReadInteger(FILE* file)
{
	std::string number;
	while (true)
	{
		char c;
		fread(&c, 1, 1, file);
		if (c != ',' && c != '\n')
		{
			number += c;
		}
		else {
			break;
		}
	}
	//string�^��int�^�ɕϊ�����B
	return atoi(number.c_str());
}

float CaslFile::ReadDecimal(FILE* file)
{
	std::string number;
	while (true)
	{
		char c;
		fread(&c, 1, 1, file);
		if (c != ',' && c != '\n')
		{
			number += c;
		}
		else {
			break;
		}
	}
	//string�^��float�^�ɕϊ�����B
	return atof(number.c_str());
}

Level2DObject* CaslFile::Find(const char* name)
{
	int number = m_levelObjectList.size();
	for (int i = 0; i < number; i++)
	{
		if (strncmp(name, m_levelObjectList[i].get()->name.get(), strlen(m_levelObjectList[i].get()->name.get())) == 0)
		{
			return m_levelObjectList[i].get();
		}
	}
	return nullptr;
}

std::vector<Level2DObject*>& CaslFile::Finds(const char* name)
{
	int number = m_levelObjectList.size();
	m_specificlevelObjectList.clear();
	for (int i = 0; i < number; i++)
	{
		if (strncmp(name, m_levelObjectList[i].get()->name.get(), strlen(m_levelObjectList[i].get()->name.get())) == 0)
		{
			m_specificlevelObjectList.push_back(m_levelObjectList[i].get());
		}
	}
	return m_specificlevelObjectList;
}
