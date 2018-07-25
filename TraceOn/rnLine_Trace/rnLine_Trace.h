#include <stdio.h>

#define TRUE				(			1 )			/* true 				 */
#define FALSE				(			0 )			/* false				 */


class rnLine_Trace {
public:

	rnLine_Trace();										/* コンストラクタ	 */
	~rnLine_Trace();									/* デストラクタ		 */

	SINT LineTracing();									/* ライントレース	 */

private:

	SINT i_initialized;	/* 倒立走行に必要なものをリセットするか決める変数	 */
};