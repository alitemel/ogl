/*
 * joint.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: yabgu
 */

#include "joint.h"

joint::joint()
{
	radius = 20.0;
	sphere = gluNewQuadric();
}

joint::joint(double R){
	radius = R;
	sphere = gluNewQuadric();
}

joint::~joint()
{

}

double joint::getRadius(void){
	return radius;
}

bool joint::setRadius(double R ){
	if(R > 0.0 && R <= 16.0){
		radius = R;
		return true;
	}
	else{
		radius = 20.0 ;
		return false;
	}
}

void joint::setColor(struct color3d Color )
{
	if(Color.red >= 0.0 && Color.red <= 1.0)
		color.red = Color.red;
	if(Color.green >= 0.0 && Color.green <= 1.0)
		color.green = Color.green;
	if(Color.blue >= 0.0 && Color.blue <= 1.0)
		color.blue = Color.blue;
}

void joint::draw()
{
	glColor3d(color.red , color.green , color.blue );
	gluQuadricNormals(sphere , GL_SMOOTH);
	gluSphere(sphere , radius , 32 , 32 );

}




