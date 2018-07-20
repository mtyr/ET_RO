
/*	-----------------------------------------------------------------------	 */
/*	dcMotor_Output.h									     			   	 */
/*	モーター出力									             			 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/03	廖  振勛	 */
/*	000001	関数名修正								2018/07/04	廖  振勛	 */
/*	000002	コード修正								2018/07/09	廖  振勛	 */
/*	000003	コード修正								2018/07/20	廖  振勛	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */

#include "Motor.h"
#include "ev3api.h"
#include "app.h"
#include "common.h"


class dcMotor_Output{
	
	public:
	void MotorOutput(SINT getPwmLeft,SINT getPwmRight);
	
	private:


};

/*	-----------------------------------------------------------------------	 */