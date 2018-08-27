#ifndef LCD
#define LCD
/*	-----------------------------------------------------------------------	 */
/*	Lcd.h																	 */
/*	EV3デバイスのLCDの制御													 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成									2018/07/31	小西 巧  */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "..\common\common.h"					/*	コーディング規約		 */

/*	-----------------------------------------------------------------------	 */
/*	define定義																 */
/*	-----------------------------------------------------------------------	 */
//#define 	EV3_LCD_WIDTH    ( 178 )			/*	LCD画面の幅 			 */
//#define 	EV3_LCD_HEIGHT   ( 128 )			/*	LCD画面の高さ 			 */

/*	-----------------------------------------------------------------------	 */
/*	クラス定義																 */
/*	-----------------------------------------------------------------------	 */
class Lcd{
public:											/*	パブリック-------------	 */
	Lcd();										/*	コンストラクタ			 */
	
	void LcdPrint(const char *str);				/*	LCDに文字列を表示		 */
	
private:										/*	プライベート-----------	 */
};

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif
