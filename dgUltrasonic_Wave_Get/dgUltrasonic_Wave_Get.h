#ifndef __SONIC__
#define __SONIC__
/*	-----------------------------------------------------------------------	 */
/*	dgUltrasonic_Wave_Get.h												   	 */
/*	£ξρζΎ															 */
/*	-----------------------------------------------------------------------	 */
/*	Τ	XVπ								ϊt		Ό		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	VKμ¬								2018/07/13	ϋόͺ ΘΎ	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	t@C														 */
/*	-----------------------------------------------------------------------	 */
#include "common.h"								/* typedefιΎ			 */
#include "ev3api.h"								/* ev3apiCu[		 */
/* NXιΎ--------------------------------------------------------------- */
class dgUltrasonic_Wave_Get{

public:
	/* public\bh */
	static dgUltrasonic_Wave_Get& GetInstance(void);	/* ΐΜμ¬\bh	 */
	int16_t DistanceGet();							/* Fξρψ«n΅\bh	 */
	void DistanceUpdate(void);					/* £ξρXV\bh		 */
private:
	/* private\bh------------------------------------------------------ */
	dgUltrasonic_Wave_Get();						/* RXgN^		 */
	~dgUltrasonic_Wave_Get();						/* fXgN^			 */
	/* VOgΙKvΘz */
	dgUltrasonic_Wave_Get(const dgUltrasonic_Wave_Get &x) { };
	dgUltrasonic_Wave_Get&operator=(const dgUltrasonic_Wave_Get &) { return *this; };
	/* privateΟ---------------------------------------------------------- */
	int16_t i_distance_info;						/* ζΎ΅½£ξρ		 */
};
#endif