#ifndef RNINVERTED_CONTROL
#define RNINVERTED_CONTROL
/*	-----------------------------------------------------------------------	 */
/*	rnInverted_Control.h													 */
/*	倒立振子のライブラリのラッピングヘッダ									 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/25	小西 巧	 	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "..\common\common.h"
#include "ev3api.h"

/*	-----------------------------------------------------------------------	 */
/*	クラス定義																 */
/*	-----------------------------------------------------------------------	 */
class rnInverted_Control{
public:											/*	パブリック-------------	 */
	
	void BalanceControl(void);				/*	バランスの制御			 */
	void BalanceInit(void);					/*	倒立ライブラリの初期化	 */
	void DriviParame(FLOT,FLOT);			/*	走行と旋回の値			 */
	
	static rnInverted_Control& GetInstance(void);/*	クラス生成用			 */

private:								/*	プライベート-----------	 */
	rnInverted_Control();				/*	コンストラクタ			 */
	~rnInverted_Control();				/*	デストラクタ			 */
	
	signed char pwm_L;					/*	左モーターPWM出力前回	 */
	signed char pwm_R; 					/*	右モーターPWM出力前回	 */
	
	FLOT f_forward;
	FLOT f_turn;
	
	void BacklashCancel(signed char, signed char,
						int32_t*, 	 int32_t*	 );
	
	/*	シングルトン作成用-------------------------------------------------	 */
	rnInverted_Control(const rnInverted_Control &x){ };
	rnInverted_Control&operator=(const rnInverted_Control&){return *this;};
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif
