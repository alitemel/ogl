/*
 * calcPosition.h
 *
 *  Created on: Jun 13, 2014
 *      Author: yabgu
 */

#ifndef CALCPOSITION_H_
#define CALCPOSITION_H_

#include "../gen_def.h"
#include "../myMath.h"
class calcPosition
{
private:
	struct triPoint3d jointPoints;
	struct point3d centerPoint;

	struct point3d findCenterPoint(struct triPoint3d );

public:
	// constructos
	calcPosition();
	calcPosition(struct triPoint3d );
	// destructor
	virtual ~calcPosition();

	struct triPoint3d calcNewJointPoints(struct motion3d);
	void setPosition(struct triPoint3d);
	void printJointPoints( );

};

#endif /* CALCPOSITION_H_ */
