/*
 * calcPosition.cpp
 *
 *  Created on: Jun 13, 2014
 *      Author: yabgu
 */

#include "calcPosition.h"

/************************     PRIVATE   *******************/
struct point3d calcPosition::findCenterPoint( struct triPoint3d Points )
{
	struct point3d center;
	center.x = (Points.A.x + Points.B.x + Points.C.x)/3.0;
	center.y = (Points.A.y + Points.B.y + Points.C.y)/3.0;
	center.z = (Points.A.z + Points.B.z + Points.C.z)/3.0;
	return center;
}



/************************      PUBLIC   *******************/
calcPosition::calcPosition()
{
	jointPoints = { {0,0,0} , {0,0,0} , {0,0,0} };
	centerPoint = findCenterPoint(jointPoints);
}

calcPosition::calcPosition(struct triPoint3d Points)
{
	jointPoints = Points;
	centerPoint = findCenterPoint(jointPoints);
}

calcPosition::~calcPosition()
{
	// TODO Auto-generated destructor stub
}

struct triPoint3d calcPosition::calcNewJointPoints(struct motion3d Motion)
{
	jointPoints.A = rotatePoint(jointPoints.A , p3d2t3d(centerPoint) , Motion.Angle.x , 1.0 , 0.0, 0.0);
	jointPoints.A = rotatePoint(jointPoints.A , p3d2t3d(centerPoint) , Motion.Angle.y , 0.0 , 1.0, 0.0);
	jointPoints.A = rotatePoint(jointPoints.A , p3d2t3d(centerPoint) , Motion.Angle.z , 0.0 , 0.0, 1.0);
	jointPoints.A = translatePoint(jointPoints.A , Motion.Translate  );

	jointPoints.B = rotatePoint(jointPoints.B , p3d2t3d(centerPoint) , Motion.Angle.x , 1.0 , 0.0, 0.0);
	jointPoints.B = rotatePoint(jointPoints.B , p3d2t3d(centerPoint) , Motion.Angle.y , 0.0 , 1.0, 0.0);
	jointPoints.B = rotatePoint(jointPoints.B , p3d2t3d(centerPoint) , Motion.Angle.z , 0.0 , 0.0, 1.0);
	jointPoints.B = translatePoint(jointPoints.B , Motion.Translate  );

	jointPoints.C = rotatePoint(jointPoints.C , p3d2t3d(centerPoint) , Motion.Angle.x , 1.0 , 0.0, 0.0);
	jointPoints.C = rotatePoint(jointPoints.C , p3d2t3d(centerPoint) , Motion.Angle.y , 0.0 , 1.0, 0.0);
	jointPoints.C = rotatePoint(jointPoints.C , p3d2t3d(centerPoint) , Motion.Angle.z , 0.0 , 0.0, 1.0);
	jointPoints.C = translatePoint(jointPoints.C , Motion.Translate );
	return jointPoints;
}

void calcPosition::setPosition(struct triPoint3d Points )
{
	jointPoints = Points;
	centerPoint = findCenterPoint(jointPoints);
}

void calcPosition::printJointPoints(void)
{
	cout << "point 1 : " << jointPoints.A.x << "  " << jointPoints.A.y << "  " << jointPoints.A.z << endl;
	cout << "point 2 : " << jointPoints.B.x << "  " << jointPoints.B.y << "  " << jointPoints.B.z << endl;
	cout << "point 3 : " << jointPoints.C.x << "  " << jointPoints.C.y << "  " << jointPoints.C.z << endl;
}
