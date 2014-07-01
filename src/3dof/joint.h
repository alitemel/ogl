/*
 * joint.h
 *
 *  Created on: Jun 6, 2014
 *      Author: yabgu
 */

#ifndef JOINT_H_
#define JOINT_H_

#include "../gen_def.h"

class joint
{
private:
	double radius;
	struct color3d color = {1.0 , 1.0, 1.0} ;

	// GLUquadricObj to draw sphere
	GLUquadricObj *sphere;
public:
	joint();
	joint(double);
	virtual ~joint();

	double getRadius(void);
	bool setRadius(double);
	void setColor(struct color3d );
	void draw( void );
};

#endif /* JOINT_H_ */
