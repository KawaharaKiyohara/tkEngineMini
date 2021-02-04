/*!
 *@brief	���x���B
 */


#pragma once

struct CaslData;
class MapChipRender2D;
/*!
* @brief	�I�u�W�F�N�g���B
*/
struct Level2DObjectData {
	Vector3 position = Vector3::Zero;		//<���W�B
	Quaternion rotation = Quaternion::Identity;	//!<��]�B
	Vector3 scale = Vector3::One;			//!<�g�嗦�B
	int width = 0;		//!<�����B
	int height = 0;		//!<�c���B
	const char* name;	//!<���O�B
	/*!
	* @brief	�����œn�����I�u�W�F�N�g���̃I�u�W�F�N�g�����ׂ�B
	*@param[in]	objName		���ׂ閼�O�B
	*@return	���O�������ꍇ��true��Ԃ��܂��B
	*/
	bool EqualObjectName(const char* objName)
	{
		return strcmp(objName, name) == 0;
	}
	/*!
	* @brief	���O���O����v���邩���ׂ�B
	*/
	bool ForwardMatchName(const char* n)
	{
		auto len = strlen(n);
		auto namelen = strlen(name);
		if (len > namelen) {
			//���O�������B�s��v�B
			return false;
		}
		return strncmp(n, name, len) == 0;
	}
};
/*!
*@brief	���x���B
	*/
class Level2D {
public:
	~Level2D();
	/*!
	 * @brief	���x�����������B
	 *@param[in]	filePath		casl�t�@�C���̃t�@�C���p�X�B
	 *@param[in] hookFunc				�I�u�W�F�N�g���쐬���鎞�̏������t�b�N���邽�߂̊֐��I�u�W�F�N�g�B
	 *   �t�b�N���Ȃ��Ȃ�nullptr���w�肷��΂悢�A
	 * ���̊֐��I�u�W�F�N�g��false��Ԃ��ƁA�I�u�W�F�N�g�̏�񂩂�A
	 * �ÓI�I�u�W�F�N�g��MapChip2D�N���X�̃C���X�^���X����������܂��B
	 * �I�u�W�F�N�g�̖��O�ȂǂŁA�v���C���[��HP�o�[�Ȃǂ̓���ȃN���X�̃C���X�^���X�𐶐������Ƃ��ɁA
	 * �f�t�H���g�ō쐬�����MapChip�N���X�̃C���X�^���X���s�v�ȏꍇ��true��Ԃ��Ă��������B
	 * �Ⴆ�΁A�t�b�N�֐��̒��ŁA�n���ꂽ�I�u�W�F�N�g�f�[�^�̖��O�̃X�v���C�g��`�悷��N���X�̃C���X�^���X��
	 * ���������Ƃ��ɁAfalse��Ԃ��Ă��܂��ƁA�����X�v���C�g����`�悳��邱�ƂɂȂ�܂��B
	 */
	void Init(const char* filePath, std::function<bool(Level2DObjectData & objData)> hookFunc);
private:
	/// <summary>
	/// �}�b�v�`�b�v�����_���[2D��ǉ�����B
	/// </summary>
	/// <param name="caslData">Casl�f�[�^</param>
	void AddMapChipRender2D(CaslData* caslData);
private:
	std::vector<MapChipRender2D*> m_mapChipRender2DList;		//�}�b�v�`�b�v�����_���[�B
};
