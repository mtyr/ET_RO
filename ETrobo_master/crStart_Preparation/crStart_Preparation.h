#ifndef CR_START_PREPARATION
#define CR_START_PREPARATION
/*	-----------------------------------------------------------------------	 */
/*	crStart_Preparation.h													 */
/*	スタート準備クラス														 */
/*	スタートする際に必要な初期化と順番										 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成									2018/07/02	小西 巧  */
/*	000001	文字コードと改行コードの変更				2018/07/20	小西 巧	 */
/*	-----------------------------------------------------------------------	 */

/*	----------------------------------------------------------------------	 */
/*	includeファイル														 	 */
/*	----------------------------------------------------------------------	 */
#include "ev3api.h"
#include "..\common\common.h"

/*	----------------------------------------------------------------------	 */
/*	クラス宣言															 	 */
/*	----------------------------------------------------------------------	 */
class crStart_Preparation{						/*	スタート準備クラス		 */
public:											/*	パブリック-------------	 */
  	crStart_Preparation();						/*	コンストラクタ			 */
	~crStart_Preparation();						/*	デストラクタ			 */
	
	void StartPreparation(void);				/*	スタート準備メソッド	 */

private:										/*	プライベート-----------	 */
	
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif