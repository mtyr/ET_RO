/* ------------------------------------------------------------------------- */
/* List.cpp																	 */
/* List構造作成																 */
/* List構造を作成します														 */
/* ------------------------------------------------------------------------- */
/*	番号	更新履歴								日付		氏名		 */
/* ------------------------------------------------------------------------- */
/*	000000	新規作成								2018/06/12	髙岡 諒太	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* includeファイル															 */
/* ------------------------------------------------------------------------- */
#include"List.h"								/* Listヘッダー				 */

/*---------------------------------------------------------------------------*/
/* 関数名		:main														 */
/* 機能名		:メイン														 */
/* 機能概要		:機能の説明、各関数の呼び出し								 */
/* 引数			:無し														 */
/* 戻り値		:int			:0				:プログラム終了				 */
/* 作成日		:2018/06/12		髙岡諒太		新規作成					 */
/* ------------------------------------------------------------------------- */
void main(void) {
	/* 変数宣言------------------------------------------------------------- */
	struct List* pFirstList = NULL;				/* 初期List構造体ポインター	 */
	struct List* pNowList	= NULL;				/* 現在Listポインター		 */
	UINT		 uiCount	= 0;				/* データ格納用変数			 */
	UINT		 uimainFlg  = 1;				/* メインループ条件			 */
	UINT		 uierrorFlg	= 0;				/* error条件				 */
	UCHR		 uiSelect	= 0;				/* 分岐条件					 */
	SCHR		*ucNextA= (SCHR*)malloc(100);	/* 新しい答え				 */
	SCHR		*ucNextQ= (SCHR*)malloc(100);	/* 新しい質問				 */
	UINT		uifirstcount = 0;				/* ファーストリストに戻すflg */
	FILE* fp;
	/* ファイル読み込み */
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
	/* List追加------------------------------------------------------------- */
	while (uimainFlg==1) {
		/* ファーストポインタがNULLなら作成 */
		if (pFirstList == NULL) {
			pFirstList = create();
			strcpy(pFirstList->cQ,"赤い？");
			pFirstList->pNextPointerA = create();
			pFirstList->pNextPointerB = create();
			strcpy(pFirstList->pNextPointerA->cA, "りんご");
			strcpy(pFirstList->pNextPointerB->cA, "バナナ");
			/* 一つ前を記憶 */
			pFirstList->pNextPointerA->pPreviewPointer = create();
			pFirstList->pNextPointerB->pPreviewPointer = create();
			pFirstList->pNextPointerA->pPreviewPointer = pFirstList;
			pFirstList->pNextPointerB->pPreviewPointer = pFirstList;
		}
		/* 2回目以降はListを追加 */
		else {
			/*ネクストポインター作成*/
			pNowList->pNextPointerA = create();
			pNowList->pNextPointerB = create();
			/* 一つ前を記憶 */
			pNowList->pNextPointerA->pPreviewPointer = create();
			pNowList->pNextPointerB->pPreviewPointer = create();
			pNowList->pNextPointerA->pPreviewPointer = pNowList;
			pNowList->pNextPointerB->pPreviewPointer = pNowList;
			/* 次のイエスを新しく教えてもらったものにする */
			pNowList->pNextPointerA->cA=ucNextA;
			/* 次のノーを前回の最後のアンサーに */
			strcpy(pNowList->pNextPointerB->cA, pNowList->cA);
			/* 教えてもらった違いを質問に */
			strcpy(pNowList->cQ, ucNextQ);
			uiCount++;
			pNowList->pNextPointerA->uiData = uiCount;
			uiCount++;
			pNowList->pNextPointerB->uiData = uiCount;
		}
		/* Nowをファーストに */
		pNowList = pFirstList;
		/*　質問関数呼び出し*/
		pNowList=question(pNowList);

		/*答え合わせ*/
		if (pNowList != pFirstList) {
			printf("それは%sですか？\n", pNowList->cA);
			printf("分岐選択\nYES:Y,NO:N-->");
			rewind(stdin);
			scanf("%c", &uiSelect);
			if (uiSelect != 'Y' && uiSelect != 'N') {
				printf("YかNで入力してください。\n");
			}
			else {
				uierrorFlg = 1;
			}
			if (uiSelect == 'Y') {
				printf("正解\n");
				break;
			}
			else if (uiSelect == 'N') {
				printf("それは何ですか？\n");
				scanf("%s", ucNextA);
				printf("それは%sとどう違いますか？\n", pNowList->cA);
				scanf("%s", ucNextQ);
				printf("%sですね、記憶しました。\n",ucNextA);
			}
		}
	}
	/* ファイル書き込み */
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
	/* ファーストリストまですべてfree--------------------------------------- */
	while (pNowList!=pFirstList) {
		/* ファーストリストに戻す */
		if (uifirstcount == 0) {
			pNowList = pFirstList;
		}
		uifirstcount = 1;
		/* ネクストAがあれば入る */
		if (pNowList->pNextPointerA != NULL) {
			pNowList=pNowList->pNextPointerA;
			/* 一番奥まで来たらフリー */
			if (pNowList->pNextPointerA == NULL
				&& pNowList->pNextPointerB == NULL) {
				pNowList->pPreviewPointer->pNextPointerA = NULL;
				free(pNowList);
				printf("a");
				uifirstcount = 0;
			}
		}
		/* AがなくてもネクストBがあれば入る */
		else if (pNowList->pNextPointerB != NULL) {
			pNowList = pNowList->pNextPointerB;
			/* 一番奥まで来たらフリー */
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