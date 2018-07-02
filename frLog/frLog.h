#pragma once
/* ------------------------------------------------------------------------- */
/* Log.h																	 */
/* �q�n�R�R																	 */
/* ���O���𓝊�����N���X									 				 */
/*																			 */
/* ------------------------------------------------------------------------- */
/* 	�ԍ�	�X�V���e								�X�V��		���O		 */
/* ------------------------------------------------------------------------- */
/* 000000	�V�K�쐬								2018/06/22	����  ����	 */
/* 000001	�V���O���g���Ή�						2018/06/25	����  ����	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* include�t�@�C��															 */
/* ------------------------------------------------------------------------- */
#include "common.h"

/* ------------------------------------------------------------------------- */
/* �萔��`																	 */
/* ------------------------------------------------------------------------- */

/* ���O�h�c�ꗗ ------------------------------------------------------------ */
#define LOG_ID_MOTOR		( 0x00000001 )		/* ���[�^�[�֘A				 */
#define LOG_ID_TAIL			( 0x00000002 )		/* �����ۊ֘A				 */
#define LOG_ID_SONIC		( 0x00000004 )		/* �����g�֘A				 */
#define LOG_ID_BATTERY		( 0x00000008 )		/* �o�b�e���[�֘A			 */
#define LOG_ID_COLOR		( 0x00000010 )		/* �J���[�Z���T�[�֘A		 */
#define LOG_ID_GYRO			( 0x00000010 )		/* �W���C���Z���T�[�֘A		 */
#define LOG_ID_TRACE		( 0x20000000 )		/* �g���[�X�֘A				 */
#define LOG_ID_ERR			( 0x40000000 )		/* �G���[���O				 */
#define LOG_ID_TERMINATE	( 0x80000000 )		/* �I�[						 */

#define LOG_MAX_BUF			(        256 )		/* ���O�o�b�t�@�ő�l		 */

/* ���O�R�}���h�ꗗ -------------------------------------------------------- */
#define LOG_CMD_LOGON		"logon"				/* ���O�n�m�R�}���h			 */
#define LOG_CMD_LOGOFF		"logoff"			/* �ꕔ���O�n�e�e�R�}���h	 */
#define LOG_CMD_MOTOR		"motor"				/* ���[�^�[���ʃR�[�h		 */
#define LOG_CMD_TAIL		"tail"				/* �����ێ��ʃR�[�h			 */
#define LOG_CMD_GYRO		"gyro"				/* �W���C�����ʃR�[�h		 */
#define LOG_CMD_BATTERY		"battery"			/* �o�b�e���[���ʃR�[�h		 */
#define LOG_CMD_COLOR		"color"				/* �J���[�Z���T�[���ʃR�[�h	 */
#define LOG_CMD_SONIC		"sonic"				/* �����g�Z���T�[���ʃR�[�h	 */
#define LOG_CMD_TRACE		"trace"				/* �g���[�X���O���[�h		 */

/* ------------------------------------------------------------------------- */
/* �N���X��`																 */
/* ------------------------------------------------------------------------- */
class frLog{

public:
	void SetLog(SCHR code);
	void LOG(SINT id, const SCHR* log, ...);

	static frLog& GetInstance(void);

private:
	~frLog();
	frLog();
	frLog(const frLog &x) { };
	frLog&operator=(const frLog &) { return *this; };

	void CommandAnaryze( void );
	void FlgSet( const SINT flg, ULNG* log, SINT id );

	ULNG _logmode;
	SCHR _buf[LOG_MAX_BUF];
};



/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */



