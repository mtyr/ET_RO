/* ------------------------------------------------------------------------- */
/* List.cpp																	 */
/* List�\���쐬																 */
/* List�\�����쐬���܂�														 */
/* ------------------------------------------------------------------------- */
/*	�ԍ�	�X�V����								���t		����		 */
/* ------------------------------------------------------------------------- */
/*	000000	�V�K�쐬								2018/06/12	���� �ȑ�	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* include�t�@�C��															 */
/* ------------------------------------------------------------------------- */
#include"List.h"								/* List�w�b�_�[				 */

/*---------------------------------------------------------------------------*/
/* �֐���		:main														 */
/* �@�\��		:���C��														 */
/* �@�\�T�v		:�@�\�̐����A�e�֐��̌Ăяo��								 */
/* ����			:����														 */
/* �߂�l		:int			:0				:�v���O�����I��				 */
/* �쐬��		:2018/06/12		�����ȑ�		�V�K�쐬					 */
/* ------------------------------------------------------------------------- */
void main(void) {
	/* �ϐ��錾------------------------------------------------------------- */
	struct List* pFirstList = NULL;				/* ����List�\���̃|�C���^�[	 */
	struct List* pNowList	= NULL;				/* ����List�|�C���^�[		 */
	UINT		 uiCount	= 0;				/* �f�[�^�i�[�p�ϐ�			 */
	UINT		 uimainFlg  = 1;				/* ���C�����[�v����			 */
	UINT		 uierrorFlg	= 0;				/* error����				 */
	UCHR		 uiSelect	= 0;				/* �������					 */
	SCHR		*ucNextA= (SCHR*)malloc(100);	/* �V��������				 */
	SCHR		*ucNextQ= (SCHR*)malloc(100);	/* �V��������				 */
	UINT		uifirstcount = 0;				/* �t�@�[�X�g���X�g�ɖ߂�flg */
	FILE* fp;
	/* �t�@�C���ǂݍ��� */
	fp=fopen("List.txt", "r+");
	if (fp != NULL) {
		fread(pFirstList, sizeof(List), 1, fp);
		pNowList = pFirstList;
		while (pFirstList->pNextPointerB->tansaku == 1 || pNowList == pFirstList) {
			if (pNowList->pNextPointerA != NULL || pNowList->tansaku == 0) {
				pNowList->pNextPointerA = create();
				pNowList = pNowList->pNextPointerA;
				fread(pNowList, sizeof(pNowList->cA), 1, fp);
				fread(pNowList, sizeof(pNowList->cQ), 1, fp);
			}
			else if (pNowList->pNextPointerB != NULL || pNowList->tansaku == 0) {
				pNowList->pNextPointerB = create();
				pNowList = pNowList->pNextPointerB;
				fread(pNowList, sizeof(pNowList->cA), 1, fp);
				fread(pNowList, sizeof(pNowList->cQ), 1, fp);
			}
			else if (pNowList->tansaku == 1 || pNowList->tansaku == 1) {
				pNowList = pNowList->pPreviewPointer;
			}
		}
		fclose(fp);
	}
	/* List�ǉ�------------------------------------------------------------- */
	while (uimainFlg==1) {
		/* �t�@�[�X�g�|�C���^��NULL�Ȃ�쐬 */
		if (pFirstList == NULL) {
			pFirstList = create();
			strcpy(pFirstList->cQ,"�Ԃ��H");
			pFirstList->pNextPointerA = create();
			pFirstList->pNextPointerB = create();
			strcpy(pFirstList->pNextPointerA->cA, "���");
			strcpy(pFirstList->pNextPointerB->cA, "�o�i�i");
			/* ��O���L�� */
			pFirstList->pNextPointerA->pPreviewPointer = create();
			pFirstList->pNextPointerB->pPreviewPointer = create();
			pFirstList->pNextPointerA->pPreviewPointer = pFirstList;
			pFirstList->pNextPointerB->pPreviewPointer = pFirstList;
		}
		/* 2��ڈȍ~��List��ǉ� */
		else {
			/*�l�N�X�g�|�C���^�[�쐬*/
			pNowList->pNextPointerA = create();
			pNowList->pNextPointerB = create();
			/* ��O���L�� */
			pNowList->pNextPointerA->pPreviewPointer = create();
			pNowList->pNextPointerB->pPreviewPointer = create();
			pNowList->pNextPointerA->pPreviewPointer = pNowList;
			pNowList->pNextPointerB->pPreviewPointer = pNowList;
			/* ���̃C�G�X��V���������Ă���������̂ɂ��� */
			pNowList->pNextPointerA->cA=ucNextA;
			/* ���̃m�[��O��̍Ō�̃A���T�[�� */
			strcpy(pNowList->pNextPointerB->cA, pNowList->cA);
			/* �����Ă�������Ⴂ������� */
			strcpy(pNowList->cQ, ucNextQ);
			uiCount++;
			pNowList->pNextPointerA->uiData = uiCount;
			uiCount++;
			pNowList->pNextPointerB->uiData = uiCount;
		}
		/* Now���t�@�[�X�g�� */
		pNowList = pFirstList;
		/*�@����֐��Ăяo��*/
		pNowList=question(pNowList);

		/*�������킹*/
		if (pNowList != pFirstList) {
			printf("�����%s�ł����H\n", pNowList->cA);
			printf("����I��\nYES:Y,NO:N-->");
			rewind(stdin);
			scanf("%c", &uiSelect);
			if (uiSelect != 'Y' && uiSelect != 'N') {
				printf("Y��N�œ��͂��Ă��������B\n");
			}
			else {
				uierrorFlg = 1;
			}
			if (uiSelect == 'Y') {
				printf("����\n");
				break;
			}
			else if (uiSelect == 'N') {
				printf("����͉��ł����H\n");
				scanf("%s", ucNextA);
				printf("�����%s�Ƃǂ��Ⴂ�܂����H\n", pNowList->cA);
				scanf("%s", ucNextQ);
				printf("%s�ł��ˁA�L�����܂����B\n",ucNextA);
			}
		}
	}
	/* �t�@�C���������� */
	fp = fopen("List.txt", "w+");
	fwrite(pFirstList->cA,1, 1, fp);
	fwrite(pFirstList->cQ, sizeof(pFirstList->cQ), 1, fp);
	pNowList = pFirstList;
	while (pFirstList->pNextPointerB->tansaku == 1 || pNowList == pFirstList) {
		if (pNowList->pNextPointerA != NULL || pNowList->tansaku == 0) {
			pNowList = pNowList->pNextPointerA;
			fwrite(pNowList->cA, sizeof(pNowList->cA), 1, fp);
			fwrite(pNowList->cQ, sizeof(pNowList->cQ), 1, fp);
		}
		else if (pNowList->pNextPointerB != NULL || pNowList->tansaku == 0) {
			pNowList = pNowList->pNextPointerB;
			fwrite(pNowList->cA, sizeof(pNowList->cA), 1, fp);
			fwrite(pNowList->cQ, sizeof(pNowList->cQ), 1, fp);
		}
		else if (pNowList->tansaku == 1 || pNowList->tansaku == 1) {
			pNowList = pNowList->pPreviewPointer;
		}
	}
	fclose(fp);
	uifirstcount = 0;
	/* �t�@�[�X�g���X�g�܂ł��ׂ�free--------------------------------------- */
	while (pNowList!=pFirstList) {
		/* �t�@�[�X�g���X�g�ɖ߂� */
		if (uifirstcount == 0) {
			pNowList = pFirstList;
		}
		uifirstcount = 1;
		/* �l�N�X�gA������Γ��� */
		if (pNowList->pNextPointerA != NULL) {
			pNowList=pNowList->pNextPointerA;
			/* ��ԉ��܂ŗ�����t���[ */
			if (pNowList->pNextPointerA == NULL
				&& pNowList->pNextPointerB == NULL) {
				pNowList->pPreviewPointer->pNextPointerA = NULL;
				free(pNowList);
				printf("a");
				uifirstcount = 0;
			}
		}
		/* A���Ȃ��Ă��l�N�X�gB������Γ��� */
		else if (pNowList->pNextPointerB != NULL) {
			pNowList = pNowList->pNextPointerB;
			/* ��ԉ��܂ŗ�����t���[ */
			if (pNowList->pNextPointerA == NULL
				&& pNowList->pNextPointerB == NULL) {
				pNowList->pPreviewPointer->pNextPointerB = NULL;
				free(pNowList);
				printf("a");
				uifirstcount = 0;
			}
		}
	}
	free(ucNextA);
	free(ucNextQ);
	free(pFirstList);
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright	HAL	College	of	Technology	&	Design			 */
/*	-----------------------------------------------------------------------	 */