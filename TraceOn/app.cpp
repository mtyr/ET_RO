// tag::tracer_def[]
#include "app.h"
#include "common\common.h"
#include "rnLine_Trace\rnLine_Trace.h"
#include <string.h>
//using namespace ev3api;

// end::tracer_def[]
// tag::main_task[]

/*	-----------------------------------------------------------------------	 */
/*	メインタスク															 */
/*	-----------------------------------------------------------------------	 */
void main_task(intptr_t unused) {	
/*	クラス宣言-------------------------------------------------------------	 */
	class rnLine_Trace LineTrace;
	LineTrace.LineTracing();
	
	while(1){ }
	
  ext_tsk();
}

// end::main_task[]
