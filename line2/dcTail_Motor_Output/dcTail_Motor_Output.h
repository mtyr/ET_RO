
/*	-----------------------------------------------------------------------	 */
/*	dcTail_Motor_Output.h									     			 */
/*	尻尾モーター出力									                 	 */
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

#include "Motor.h"
#include "ev3api.h"
#include "..\common\common.h"


class dcTail_Motor_Output{
	
	public:
	void TailMotorOutput(SINT degree);
	
	private:

};

/*	-----------------------------------------------------------------------	 */