
/*	-----------------------------------------------------------------------	 */
/*	dcTail_Motor_Output.h									     			 */
/*	尻尾モーター制御									                 	 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/13	廖  振勛	 */
/*	000001	関数名修正								2018/07/14	廖  振勛	 */
/*	000002	コード修正								2018/07/18	廖  振勛	 */
/*	000003	コード修正								2018/07/20	廖  振勛	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "ev3api.h"
#include "..\common.h"

/*	-----------------------------------------------------------------------	 */
/*	define定義																 */
/*	-----------------------------------------------------------------------	 */
#define TAIL_UP		( 1 )							/*	走行体の安定時		 */
#define TAIL_DOWN	( 2 )							/*	走行体の発進時		 */


/*	-----------------------------------------------------------------------	 */
/*	クラス宣言																 */
/*	-----------------------------------------------------------------------	 */
class dcTail_Motor_Output{
	
public:											/*	パブリック-------------	 */
	dcTail_Motor_Output();						/*	コンストラクト			 */
	void TailMotorOutput(SINT);					/*	尻尾モーターの出力		 */
	void TailStart(SINT);						/*	尻尾を下す				 */

private:										/*	プライベート-----------	 */

};

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
