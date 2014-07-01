/*
 * calcJointAngles.h
 *
 *  Created on: Jun 16, 2014
 *      Author: yabgu
 */

#ifndef CALCJOINTANGLES_H_
#define CALCJOINTANGLES_H_

#include "../gen_def.h"

class calcJointAngles
{
 	struct triAngle3d jointAngles;

 	struct angle3d calcAnglesBetween2Points(struct point3d , struct point3d);
public:
	calcJointAngles();
	virtual ~calcJointAngles();

	struct triAngle3d calcNewJointAngles(struct triPoint3d ,struct triPoint3d );

	void printNewAngles(void);
};

#endif /* CALCJOINTANGLES_H_ */
