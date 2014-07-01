/*
 * motion.h
 *
 *  Created on: Jun 12, 2014
 *      Author: yabgu
 */

#ifndef MOTION_H_
#define MOTION_H_

#include "../gen_def.h"

class motion
{
private :
	// limits for the motion , use this(these) as a boundaries of random number generator
	struct motion3d limits;
	// random motion
	struct motion3d randMotion;

	// generate random number
	double generateRandomNumber(void);
	// assign new values to randMotion variable
	void generateRandomMotion(void);

	public:
	motion();
	motion(struct motion3d);
	virtual ~motion();

	// return randMotion variable
	struct motion3d getRandomMotion(void);
	void setLimits(struct motion3d );
	void printRandomMotion(void);
};

#endif /* MOTION_H_ */
