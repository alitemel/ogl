/*
 * pane.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: yabgu
 */

#include "pane.h"


pane::pane(){
	size.width  = 100.0;
	size.height = 100.0;
	size.depth  = 10.0 ;
	color.red   = 1.0;
}
pane::pane(struct size3d Size , struct point3d center){
	size.width  = Size.width	;
	size.height = Size.height;
	size.depth  = Size.depth ;
	centerOf = center;
}

struct size3d pane::getTableSize(void)
{
	return size;
}
void pane::setPaneSize(struct size3d Size )
{
	if(Size.width <= 100.0 && Size.width >= 0.0){
		size.width = Size.width;
	}
	else{
		size.width = 100.0;
	}
	if(Size.height <= 100.0 && Size.height >= 0.0){
		size.height = Size.height;
	}
	else{
		size.height = 100.0;
	}
	if(Size.depth <= 10.0 && Size.depth >= 0.0){
		size.depth = Size.depth ;
	}
	else{
		size.depth = 10.0;
	}
}

void pane::setCenter(struct point3d Center)
{
	centerOf = Center;
}
void pane::setColor(struct color3d Color )
{
	if(Color.red >= 0.0 && Color.red <= 1.0)
		color.red = Color.red;
	if(Color.green >= 0.0 && Color.green <= 1.0)
		color.green = Color.green;
	if(Color.blue >= 0.0 && Color.blue <= 1.0)
		color.blue = Color.blue;
}
void pane::setAngles(struct angle3d Angle)
{
	angles.x = fmod(Angle.x,360.0);
	angles.y = fmod(Angle.y,360.0);
	angles.z = fmod(Angle.z,360.0);
}

void pane::draw()
{
	// draw bottom
	glBegin(GL_POLYGON);
	glColor3d(color.red , color.green, color.blue);
	//glColor3d(0.9 , 0.5, 0.5);
	glVertex3d(-size.width/2 , -size.height/2 ,  centerOf.z );
	glVertex3d(-size.width/2 ,  size.height/2 ,  centerOf.z );
	glVertex3d( size.width/2 ,  size.height/2 ,  centerOf.z );
	glVertex3d( size.width/2 , -size.height/2 ,  centerOf.z );
	glEnd();
	// draw left
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glVertex3d(-size.width/2 , -size.depth/2 ,  centerOf.z );
	glVertex3d(-size.width/2 ,  size.depth/2 ,  centerOf.z );
	glVertex3d(-size.width/2 ,  size.depth/2 ,  centerOf.z + size.depth );
	glVertex3d(-size.width/2 , -size.depth/2 ,  centerOf.z + size.depth );
	glEnd();
	//
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glVertex3d(-size.width/2 ,  size.height/2 ,  centerOf.z );
	glVertex3d( size.width/2 ,  size.height/2 ,  centerOf.z );
	glVertex3d( size.width/2 ,  size.height/2 ,  centerOf.z + size.depth );
	glVertex3d(-size.width/2 ,  size.height/2 ,  centerOf.z + size.depth );
	glEnd();
	// draw right side
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	//glNormal3d(0.0 ,1.0 ,1.0);
	glVertex3d( size.width/2 ,  size.height/2 ,  centerOf.z );
	glVertex3d( size.width/2 , -size.height/2 ,  centerOf.z );
	glVertex3d( size.width/2 , -size.height/2 ,  centerOf.z + size.depth );
	glVertex3d( size.width/2 ,  size.height/2 ,  centerOf.z + size.depth );
	glEnd();
	// draw back side
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glNormal3d(-1.0 ,0.0 ,0.0);
	glVertex3d(-size.width/2 , -size.height/2 ,  centerOf.z );
	glVertex3d(-size.width/2 ,  size.height/2 ,  centerOf.z );
	glVertex3d(-size.width/2 ,  size.height/2 ,  centerOf.z + size.depth );
	glVertex3d(-size.width/2 , -size.height/2 ,  centerOf.z + size.depth );
	glEnd();
	// draw up side
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glNormal3d(0.0 ,0.0 ,1.0);
	glVertex3d(-size.width/2 , -size.height/2 ,  centerOf.z + size.depth );
	glVertex3d(-size.width/2 ,  size.height/2 ,  centerOf.z + size.depth );
	glVertex3d( size.width/2 ,  size.height/2 ,  centerOf.z + size.depth );
	glVertex3d( size.width/2 , -size.height/2 ,  centerOf.z + size.depth );
	glEnd();

}


void pane::draw( int )
{
	// draw bottom
	glBegin(GL_POLYGON);
	glColor3d(color.red , color.green, color.blue);
	//glColor3d(0.9 , 0.5, 0.5);
	glVertex3d(-size.width/2 , -size.height/2 , 0 );
	glVertex3d(-size.width/2 ,  size.height/2 ,  0 );
	glVertex3d( size.width/2 ,  size.height/2 ,  0 );
	glVertex3d( size.width/2 , -size.height/2 ,  0 );
	glEnd();
	// draw left
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glVertex3d(-size.width/2 , -size.depth/2 ,  0 );
	glVertex3d(-size.width/2 ,  size.depth/2 ,  0 );
	glVertex3d(-size.width/2 ,  size.depth/2 ,  0 + size.depth );
	glVertex3d(-size.width/2 , -size.depth/2 ,  0 + size.depth );
	glEnd();
	//
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glVertex3d(-size.width/2 ,  size.height/2 ,  0 );
	glVertex3d( size.width/2 ,  size.height/2 ,  0 );
	glVertex3d( size.width/2 ,  size.height/2 ,  0 + size.depth );
	glVertex3d(-size.width/2 ,  size.height/2 ,  0 + size.depth );
	glEnd();
	// draw right side
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	//glNormal3d(0.0 ,1.0 ,1.0);
	glVertex3d( size.width/2 ,  size.height/2 ,  0 );
	glVertex3d( size.width/2 , -size.height/2 ,  0 );
	glVertex3d( size.width/2 , -size.height/2 ,  0 + size.depth );
	glVertex3d( size.width/2 ,  size.height/2 ,  0 + size.depth );
	glEnd();
	// draw back side
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glNormal3d(-1.0 ,0.0 ,0.0);
	glVertex3d(-size.width/2 , -size.height/2 ,  0 );
	glVertex3d(-size.width/2 ,  size.height/2 ,  0 );
	glVertex3d(-size.width/2 ,  size.height/2 ,  0 + size.depth );
	glVertex3d(-size.width/2 , -size.height/2 ,  0 + size.depth );
	glEnd();
	// draw up side
	glBegin(GL_POLYGON);
	//glColor3d(color.red , color.green, color.blue);
	glNormal3d(0.0 ,0.0 ,1.0);
	glVertex3d(-size.width/2 , -size.height/2 ,  0 + size.depth );
	glVertex3d(-size.width/2 ,  size.height/2 ,  0 + size.depth );
	glVertex3d( size.width/2 ,  size.height/2 ,  0 + size.depth );
	glVertex3d( size.width/2 , -size.height/2 ,  0 + size.depth );
	glEnd();

}
