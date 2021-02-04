#pragma once
#include <list>
#include <vector>

//2D�̃��x���I�u�W�F�N�g�B
struct CaslData
{
public:

	std::unique_ptr<char[]> name;	//���O�B
	std::unique_ptr<char[]> fileName;	//�t�@�C���̃p�X�B
	std::unique_ptr<char[]> ddsFileName;	//dds�t�@�C���̃p�X�B
	Vector2 position = Vector2::Zero;	//���W�B
	int width = 0;		//�����B
	int height = 0;		//�c���B
	int numberLayer = 0;		//���C���[�D��x�B
	Vector2 scale = Vector2::Zero;		//�傫���B
};

//Casl�t�@�C����ǂݍ��ށB
class CaslFile
{
public:
	/// <summary>
	/// casl�t�@�C����ǂݍ��ށB
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X�B</param>
	void Load(const char* filePath);
	int GetNumCaslData()
	{
		return m_caslDataList.size();
	}
	CaslData* GetCaslData(int number)
	{
		return m_caslDataList[number].get();
	}
private:
	//1���������ǂݍ��ށA(,)��ǂݍ��ނ̂Ɏg���B
	void ReadOnlyOneCharacter(FILE* file);
	//������ǂݍ��ށB
	int ReadInteger(FILE* file);
	//float�^��ǂݍ��ށB
	float ReadDecimal(FILE* file);

	std::vector<std::unique_ptr<CaslData>> m_caslDataList;
	int m_numLevel = 0;
};

