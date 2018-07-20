#ifndef CR_DRIVING_ORDER
#define CR_DRIVING_ORDER
/*	-----------------------------------------------------------------------	 */
/*	crDriving_Order.h														 */
/*	走行指示クラス															 */
/*	走行開始を支持するクラス												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴							日付		氏名	         */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成							2018/07/03	宇都宮　正章     */
/*	-----------------------------------------------------------------------	 */

/*	----------------------------------------------------------------------	 */
/*	includeファイル														 	 */
/*	----------------------------------------------------------------------	 */
#include "common.h"

/*	----------------------------------------------------------------------	 */
/*	クラス宣言															 	 */
/*	----------------------------------------------------------------------	 */
class crDriving_Order{							/*	走行指示クラス			 */
public:											/*	パブリック-------------	 */
	crDriving_Order();							/*	コンストラクタ			 */
	~crDriving_Order();							/*	デストラクタ			 */
	void RunWayDecision();					    /*  走行方法決定			 */

private:										/*	プライベート-----------	 */
	void Difficulty();                          /*  難所攻略                 */  
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif