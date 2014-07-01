/*
 * motion.cpp
 *
 *  Created on: Jun 12, 2014
 *      Author: yabgu
 */

#include "motion.h"

/************************     PRIVATE   *******************/
double motion::generateRandomNumber(void)
{
	double random;
	random = ((double)rand() / (double)(RAND_MAX));
	return random;

}

void motion::generateRandomMotion(void)
{
	randMotion.Angle.x = generateRandomNumber()*limits.Angle.x;
	randMotion.Angle.y = generateRandomNumber()*limits.Angle.y;
	randMotion.Angle.z = generateRandomNumber()*limits.Angle.z;
	randMotion.Translate.x = generateRandomNumber()*limits.Translate.x;
	randMotion.Translate.y = generateRandomNumber()*limits.Translate.y;
	randMotion.Translate.z = generateRandomNumber()*limits.Translate.z;
}

/************************      PUBLIC   *******************/
motion::motion()
{
	limits.Angle = { 30.0 , 30.0 , 30.0 };
	limits.Translate = {1.0 , 1.0 , 1.0 };
}
motion::motion(struct motion3d Limit)
{
	limits= Limit;
}


motion::~motion()
{
	// Auto-generated destructor stub
}

struct motion3d motion::getRandomMotion()
{
	generateRandomMotion();
	return randMotion;
}

void motion::setLimits(struct motion3d Limit)
{
	limits = Limit;
}

void motion::printRandomMotion()
{
	cout << "motion angles : " << randMotion.Angle.x << "  " << randMotion.Angle.y << "  " << randMotion.Angle.z << endl;
	cout << "motion translations : " << randMotion.Translate.x << "  " << randMotion.Translate.y << "  " << randMotion.Translate.z << endl;
}
