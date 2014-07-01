/*
 * leg.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: yabgu
 */

#include "leg.h"
#include <math.h>

leg::leg(){
	radius = 20.0;
	length = 50.0;
	cylinder = gluNewQuadric();
}

leg::leg(double R , double L ){
	radius = R;
	length = L;
	cylinder = gluNewQuadric();
}

leg::leg(double R , double L , struct angle3d Angles ){
	radius = R;
	length = L;
    angles = Angles;
    cylinder = gluNewQuadric();
}
double leg::getRadius(void){
	return radius;
}
bool leg::setRadius(double R ){
	if(R > 0.0 && R <= 20.0){
		radius = R;
		return true;
	}
	else{
		radius = 20.0 ;
		return false;
	}
}
double leg::getLength(void){
	return length;
}
bool leg::setLength(double L ){
	if(L > 0.0 && L <= 50.0){
		length = L ;
		return true;
	}
	else{
		length = 50.0 ;
		return false;
	}
}
void leg::setColor(struct color3d Color )
{
	if(Color.red >= 0.0 && Color.red <= 1.0)
		color.red = Color.red;
	if(Color.green >= 0.0 && Color.green <= 1.0)
		color.green = Color.green;
	if(Color.blue >= 0.0 && Color.blue <= 1.0)
		color.blue = Color.blue;
}
void leg::setAngles(struct angle3d Angle)
{
	angles.x = fmod(Angle.x,360.0);
	angles.y = fmod(Angle.y,360.0);
	angles.z = fmod(Angle.z,360.0);
}

void leg::draw()
{
	glColor3d(color.red ,color.green , color.blue);
	glRotated(angles.x , 1.0 , 0.0 , 0.0);
	glRotated(angles.y , 0.0 , 1.0 , 0.0);
	glRotated(angles.z , 0.0 , 0.0 , 1.0);
	gluQuadricNormals(cylinder , GL_SMOOTH);
	gluCylinder( cylinder , radius , radius , length , 32 ,32 );
}
void leg::draw(struct angle3d Angles)
{
	glColor3d(color.red ,color.green , color.blue);
	glRotated(Angles.x , 1.0 ,0.0 , 0.0);
	glRotated(Angles.y , 0.0 ,1.0 , 0.0);
	glRotated(Angles.z , 0.0 ,0.0 , 1.0);
	gluQuadricNormals(cylinder , GL_SMOOTH);
	gluCylinder( cylinder , radius, radius , length , 32 ,32 );
}
