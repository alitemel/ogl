/*
 * calcJointAngles.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: yabgu
 */

#include "calcJointAngles.h"


/************************     PRIVATE   *******************/

///  http://stackoverflow.com/questions/12229950/the-x-angle-between-two-3d-vectors
struct angle3d calcJointAngles::calcAnglesBetween2Points(struct point3d bottomJointPoint , struct point3d topJointPoint )
{
	struct angle3d angles;
	struct point3d temp;
	temp.x = topJointPoint.x -bottomJointPoint.x;
	temp.y = topJointPoint.y -bottomJointPoint.y;
	temp.z = topJointPoint.z -bottomJointPoint.z;
	double mag = sqrt( pow(temp.x ,2) + pow(temp.y ,2)  + pow(temp.z ,2) );
/*
	angles.x = -90 + (acos(temp.x/mag)*180/myPI);
	angles.y = -90 + (acos(temp.y/mag)*180/myPI);
	angles.z = acos(temp.z/mag)*180/myPI;
*/
	angles.x =  -90+( atan2( sqrt(pow(temp.y,2)+pow(temp.z ,2)) , temp.x) )*180/myPI;
	angles.y =  -90+( atan2( sqrt(pow(temp.x,2)+pow(temp.z ,2)) , temp.y) )*180/myPI;
	angles.z =  ( atan2( sqrt(pow(temp.y,2)+pow(temp.x ,2)) , temp.z) )*180/myPI;

	return angles;
}

/************************      PUBLIC   *******************/
calcJointAngles::calcJointAngles()
{
	// TODO Auto-generated constructor stub

}

calcJointAngles::~calcJointAngles()
{
	// TODO Auto-generated destructor stub
}

struct triAngle3d calcJointAngles::calcNewJointAngles(struct triPoint3d bottomPaneJointPos , struct triPoint3d topPaneJointPos )
{
	jointAngles.A = calcAnglesBetween2Points(bottomPaneJointPos.A , topPaneJointPos.A);
	jointAngles.B = calcAnglesBetween2Points(bottomPaneJointPos.B , topPaneJointPos.B);
	jointAngles.C = calcAnglesBetween2Points(bottomPaneJointPos.C , topPaneJointPos.C);
	return jointAngles;
}

void calcJointAngles::printNewAngles()
{
	cout << "leg 1 angles: " << jointAngles.A.x << "  " << jointAngles.A.y << "  " << jointAngles.A.z << endl;
	cout << "leg 2 angles: " << jointAngles.B.x << "  " << jointAngles.B.y << "  " << jointAngles.B.z << endl;
	cout << "leg 3 angles: " << jointAngles.C.x << "  " << jointAngles.C.y << "  " << jointAngles.C.z << endl;
}
