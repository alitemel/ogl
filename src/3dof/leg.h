/*
 * leg.h
 *
 *  Created on: Jun 5, 2014
 *      Author: yabgu
 */

#ifndef LEG_H_
#define LEG_H_

#include "../gen_def.h"

class leg
{
private:
	double radius;
	double length;
	struct color3d color  = {0.0   , 1.0   , 0.0 };
	struct angle3d angles = {0.0   , 0.0   , 0.0 };

	// GLUquadricObj to draw cylinder
	GLUquadricObj *cylinder;
public:
	leg();
	leg(double radius , double length );
	leg(double radius , double length , struct angle3d );
	//virtual ~leg();

	double getRadius(void);
	bool setRadius(double);
	double getLength(void);
	bool setLength(double);
	void setColor(struct color3d );
	void setAngles(struct angle3d );

	void draw(void);
	void draw(struct angle3d );
};

#endif /* LEG_H_ */
