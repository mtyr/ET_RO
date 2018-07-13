#ifndef __COMMON__
#define __COMMON__
/*	-----------------------------------------------------------------------	 */
/*	common.h																 */
/*	���{�b�g�w���R�[�f�B���O�K��											 */
/*	�^����typedef�錾�̏W�܂�												 */
/*	-----------------------------------------------------------------------	 */
/*	�ԍ�	�X�V����								���t		����		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	�V�K�쐬								2018/06/05	���Y�Ж�	 */
/*	-----------------------------------------------------------------------	 */

#include "cstdint"

#define FUNC_OK			(                 1 )	/*  �֐�����I��			 */
#define FUNC_ERR		(                -1 )	/*  �֐��ُ�I��			 */
#define SYS_ERR			(                -2 )	/*  �V�X�e���s��G���[	 */
#define PARAM_ERR		(                -3 )	/*  �����G���[				 */
#define HW_ERR			(                -4 )	/*  �n�[�h�E�F�A�G���[		 */
#define RETRY_ERR		(                -5 )	/*  �Ď擾�G���[			 */

/*	-----------------------------------------------------------------------	 */
/*	typedef�錾																 */
/*	-----------------------------------------------------------------------	 */
typedef char			SCHR;					/*	char�^					 */
typedef unsigned char	UCHR;					/*	unsigned char�^			 */
typedef short			SSHT;					/*	short�^					 */
typedef unsigned short	USHT;					/*	unsigned short�^		 */
typedef long			SLNG;					/*	long�^					 */
typedef unsigned long	ULNG;					/*	unsigned long�^			 */
typedef int				SINT;					/*	int�^					 */
typedef unsigned int	UINT;					/*	unsigned int�^			 */
typedef	float			FLOT;					/*	float�^					 */
typedef	double			DBLE;					/*	double�^				 */
typedef bool            BOOL;                   /*  bool�^                   */
typedef int8_t          I08T;                   /*  int8_t�^                 */
typedef int16_t         I16T;                   /*  int16_t�^                */
typedef int32_t         I32T;                   /*  int32_t�^                */

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif

