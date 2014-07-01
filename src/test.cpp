

#include  "gen_def.h"
// GLUquadricObj to draw sphere
	GLUquadricObj *sphere;

// GLUquadricObj to draw sphere
	GLUquadricObj *cylinder;

void drawSphere(double radius , color3d color )
{
	glColor3d(color.red , color.green , color.blue );
	gluQuadricNormals(sphere , GL_SMOOTH);
	gluSphere(sphere , radius , 32 , 32 );
}



void drawCylinder( double  radius , double length , color3d color)
{
	glColor3d(color.red , color.green , color.blue );
	gluQuadricNormals(cylinder , GL_SMOOTH);
	gluCylinder( cylinder , radius , radius , length , 32 ,32 );
}


void draw3dRect(size3d size , color3d color)
{
	// draw bottom
		glBegin(GL_POLYGON);
		glColor3d(color.red , color.green, color.blue);
		//glColor3d(0.9 , 0.5, 0.5);
		glVertex3d(-size.width/2 , -size.height/2 ,  0);
		glVertex3d(-size.width/2 ,  size.height/2 ,  0);
		glVertex3d( size.width/2 ,  size.height/2 ,  0);
		glVertex3d( size.width/2 , -size.height/2 ,  0);
		glEnd();
		// draw left
		glBegin(GL_POLYGON);
		//glColor3d(color.red , color.green, color.blue);
		glVertex3d(-size.width/2 , -size.depth/2 ,  0);
		glVertex3d(-size.width/2 ,  size.depth/2 ,  0);
		glVertex3d(-size.width/2 ,  size.depth/2 ,  0+ size.depth );
		glVertex3d(-size.width/2 , -size.depth/2 ,  0+ size.depth );
		glEnd();
		//
		glBegin(GL_POLYGON);
		//glColor3d(color.red , color.green, color.blue);
		glVertex3d(-size.width/2 ,  size.height/2 ,  0);
		glVertex3d( size.width/2 ,  size.height/2 ,  0);
		glVertex3d( size.width/2 ,  size.height/2 ,  0+ size.depth );
		glVertex3d(-size.width/2 ,  size.height/2 ,  0+ size.depth );
		glEnd();
		// draw right side
		glBegin(GL_POLYGON);
		//glColor3d(color.red , color.green, color.blue);
		//glNormal3d(0.0 ,1.0 ,1.0);
		glVertex3d( size.width/2 ,  size.height/2 ,  0);
		glVertex3d( size.width/2 , -size.height/2 ,  0);
		glVertex3d( size.width/2 , -size.height/2 ,  0+ size.depth );
		glVertex3d( size.width/2 ,  size.height/2 ,  0+ size.depth );
		glEnd();
		// draw back side
		glBegin(GL_POLYGON);
		//glColor3d(color.red , color.green, color.blue);
		glNormal3d(-1.0 ,0.0 ,0.0);
		glVertex3d(-size.width/2 , -size.height/2 ,  0);
		glVertex3d(-size.width/2 ,  size.height/2 ,  0);
		glVertex3d(-size.width/2 ,  size.height/2 ,  0+ size.depth );
		glVertex3d(-size.width/2 , -size.height/2 ,  0+ size.depth );
		glEnd();
		// draw up side
		glBegin(GL_POLYGON);
		//glColor3d(color.red , color.green, color.blue);
		glNormal3d(0.0 ,0.0 ,1.0);
		glVertex3d(-size.width/2 , -size.height/2 ,  0+ size.depth );
		glVertex3d(-size.width/2 ,  size.height/2 ,  0+ size.depth );
		glVertex3d( size.width/2 ,  size.height/2 ,  0+ size.depth );
		glVertex3d( size.width/2 , -size.height/2 ,  0+ size.depth );
		glEnd();




}

