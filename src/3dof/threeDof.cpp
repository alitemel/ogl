/*
 * threeDof.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: yabgu
 */

#include "threeDof.h"

/**************  PRIVATE  ************************************/


// calculate joint points as a corners of virtual equilateral triangle
// http://stackoverflow.com/questions/11449856/draw-a-equilateral-triangle-given-the-center
triPoint3d threeDof::assignJointPoints(size3d paneSize)
{
	double gap = 3*legRadius; // gap for joints
	double cx , cy; // center of equilateral triangle
    double r ; // distance from center to corners
	double Ax , Ay , Bx , By , Cx , Cy;  // bottom left (A) , bottom right (B) , top (C)
	triPoint3d jointPoints;
	//obtain center of triangle
	if(paneSize.width >= paneSize.height )
	{
		cx = 0.0;
		cy = (paneSize.height - gap * 3.0) / 3.0 + gap - paneSize.height / 2.0 ;
		r = ((paneSize.height - gap * 3.0) / 3.0 * 2.0);
		Cx = cx;
		Cy = cy + r ;
		Bx = r * sin(120.0 / 180.0 * myPI) ;
		By = gap - paneSize.height/2.0;
		Ax = r * sin(240.0 / 180.0 * myPI) ;
		Ay = gap - paneSize.height /2.0 ;
	}
	else
	{
		cx = 0.0;
		cy = (paneSize.width - gap*3.0)/3.0 + gap - paneSize.width/2.0 ;
		r = ((paneSize.width- gap*3.0)/3.0*2.0);
		Cx = cx;
		Cy = cy + r ;
		Bx = r * sin(120.0 / 180.0 * myPI) ;
		By = gap - paneSize.width/2.0 ;
		Ax = r * sin(240.0 / 180.0 * myPI) ;
		Ay = gap - paneSize.width/2.0 ;
	}
	// z values should be assigned in main program
	jointPoints.A= {Ax , Ay , 0.0 };
	jointPoints.B= {Bx , By , 0.0 };
	jointPoints.C= {Cx , Cy , 0.0 };

	struct point3d center;
	center.x = (jointPoints.A.x + jointPoints.B.x + jointPoints.C.x)/3.0;
	center.y = (jointPoints.A.y + jointPoints.B.y + jointPoints.C.y)/3.0;
	center.z = (jointPoints.A.z + jointPoints.B.z + jointPoints.C.z)/3.0;

	jointPoints.A.x -= center.x;
	jointPoints.A.y -= center.y;
	jointPoints.A.z -= center.z;

	jointPoints.B.x -= center.x;
	jointPoints.B.y -= center.y;
	jointPoints.B.z -= center.z;

	jointPoints.C.x -= center.x;
	jointPoints.C.y -= center.y;
	jointPoints.C.z -= center.z;

	return jointPoints;
}

// Calculate joint points ,  define objects such as pane , leg ...
void threeDof::initialize()
{
	lowerPaneJointPoints.A.z = lowerPaneSize.depth + lowerLegRadius/2.0 ;
	lowerPaneJointPoints.B.z = lowerPaneSize.depth + lowerLegRadius/2.0 ;
	lowerPaneJointPoints.C.z = lowerPaneSize.depth + lowerLegRadius/2.0 ;

	upperPaneJointPoints.A.z = lowerPaneSize.depth + maxHeight + legRadius/2.0;
	upperPaneJointPoints.B.z = lowerPaneSize.depth + maxHeight + legRadius/2.0;
	upperPaneJointPoints.C.z = lowerPaneSize.depth + maxHeight + legRadius/2.0;

	bottomPane.setPaneSize(lowerPaneSize );
	bottomPane.setCenter({0.0 , 0.0 , 0.0 } );

	topPane.setPaneSize(upperPaneSize);
	topPane.setCenter({0.0 , 0.0 , 0.0});

	topJoint1.setRadius(upperLegRadius);
	topJoint1.setColor(jointColor);
	topJoint2.setRadius(upperLegRadius);
	topJoint2.setColor(jointColor);
	topJoint3.setRadius(upperLegRadius);
	topJoint3.setColor(jointColor);

	bottomJoint1.setRadius(lowerLegRadius);
	bottomJoint1.setColor(jointColor);
	bottomJoint2.setRadius(lowerLegRadius);
	bottomJoint2.setColor(jointColor);
	bottomJoint3.setRadius(lowerLegRadius);
	bottomJoint3.setColor(jointColor);

	bottomLeg1.setRadius(lowerLegRadius);
	bottomLeg1.setLength(lowerLegLength);
	bottomLeg1.setColor(lowerLegColor);

	bottomLeg2.setRadius(lowerLegRadius);
	bottomLeg2.setLength(lowerLegLength);
	bottomLeg2.setColor(lowerLegColor);

	bottomLeg3.setRadius(lowerLegRadius);
	bottomLeg3.setLength(lowerLegLength);
	bottomLeg3.setColor(lowerLegColor);

	topLeg1.setRadius(upperLegRadius);
	topLeg1.setLength(upperLegLength);
	topLeg1.setColor(upperLegColor);

	topLeg2.setRadius(upperLegRadius);
	topLeg2.setLength(upperLegLength);
	topLeg2.setColor(upperLegColor);

	topLeg3.setRadius(upperLegRadius);
	topLeg3.setLength(upperLegLength);
	topLeg3.setColor(upperLegColor);
}


/**************  PUBLIC   ************************************/

// constructors
threeDof::threeDof()
{
	maxHeight =100.0;
	lowerLegLength = maxHeight/1.4;
	upperLegLength = maxHeight/1.4;
	lowerPaneSize  = {100.0, 100.0, 5.0};
	upperPaneSize  = {100.0, 100.0, 5.0};
	legRadius 	   = 10.0;
	lowerLegRadius = legRadius;
	upperLegRadius = legRadius - 0.001;

	lowerPaneColor = {0.4 , 0.4 , 0.4};  // dark gray
	upperPaneColor = {0.8 , 0.8 , 0.8};  // light gray
	lowerLegColor  = {0.0 , 0.0 , 1.0};
	upperLegColor  = {1.0 , 0.0 , 0.0};
	jointColor     = {0.9 , 0.9 , 0.15}; //yellow

	lowerPaneJointPoints = assignJointPoints(lowerPaneSize);
	upperPaneJointPoints = assignJointPoints(upperPaneSize);

	initialize();

}
// lower pane size , upper pane size , max height , leg radius , lower pane color ,
// upper pane color , lower leg color , upper leg color , joint color
threeDof::threeDof(struct size3d lps, struct size3d ups , double mh , double lr ,struct color3d lpc, struct color3d upc, struct color3d llc, struct color3d ulc, struct color3d jc)
{
	maxHeight = mh;
	lowerLegLength = maxHeight/1.4;
	upperLegLength = maxHeight/1.4;
	lowerPaneSize  = lps;
	upperPaneSize  = ups;
	legRadius 	   = lr;
	lowerLegRadius = legRadius;
	upperLegRadius = legRadius - 0.001;

	lowerPaneColor = lpc;
	upperPaneColor = upc;
	lowerLegColor  = llc;
	upperLegColor  = ulc;
	jointColor     = jc;

	lowerPaneJointPoints = assignJointPoints(lowerPaneSize);
	upperPaneJointPoints = assignJointPoints(upperPaneSize);

	initialize();
}

// height of platform
double threeDof::getMaxHeight()
{
	return maxHeight;
}

void threeDof::setMaxHeight(double mh)
{
	if(mh > 0.0 && mh <=100 )
		maxHeight = mh ;
}

// radius of leg(s)
double threeDof::getLegRadius()
{
	return legRadius;
}

void threeDof::setLegRadius(double lr)
{
	if(lr > 0.0 && lr <=100 )
		legRadius = lr ;
}

double threeDof::getLowerLegRadius()
{
	return lowerLegRadius;
}

double threeDof::getUpperLegRadius()
{
	return upperLegRadius;
}

// size of panes
struct size3d threeDof::getLowerPaneSize()
{
	return lowerPaneSize;
}

void threeDof::setLowerPaneSize(struct size3d Size)
{
	if(Size.width > 0.0 && Size.width <= 100.0 )
		lowerPaneSize.width = Size.width ;
	if(Size.height> 0.0 && Size.height<= 100.0 )
		lowerPaneSize.height= Size.height ;
	if(Size.depth> 0.0 && Size.depth<= 10.0 )
			lowerPaneSize.depth= Size.depth ;
}

struct size3d threeDof::getUpperPaneSize()
{
	return lowerPaneSize;
}

void threeDof::setUpperPaneSize(struct size3d Size)
{
	if(Size.width > 0.0 && Size.width <= 100.0 )
		lowerPaneSize.width = Size.width ;
	if(Size.height> 0.0 && Size.height<= 100.0 )
		lowerPaneSize.height= Size.height ;
	if(Size.depth> 0.0 && Size.depth<= 10.0 )
			lowerPaneSize.depth= Size.depth ;
}

// joint points
struct triPoint3d threeDof::getLowerPaneJointPoints()
{
	return lowerPaneJointPoints;
}

struct triPoint3d threeDof::getUpperPaneJointPoints()
{
	return upperPaneJointPoints;
}

// colors
struct color3d threeDof::getLowerPaneColor()
{
	return lowerPaneColor;
}
void threeDof::setLowerPaneColor(struct color3d Color)
{
	if( Color.red >= 0.0 && Color.red <= 1.0 )
		lowerPaneColor.red = Color.red ;
	if( Color.green >= 0.0 && Color.green <= 1.0 )
		lowerPaneColor.green = Color.green ;
	if( Color.blue >= 0.0 && Color.blue <= 1.0 )
		lowerPaneColor.blue = Color.blue ;
}

struct color3d threeDof::getUpperPaneColor()
{
	return upperPaneColor;
}
void threeDof::setUpperPaneColor(struct color3d Color)
{
	if( Color.red >= 0.0 && Color.red <= 1.0 )
		upperPaneColor.red = Color.red ;
	if( Color.green >= 0.0 && Color.green <= 1.0 )
		upperPaneColor.green = Color.green ;
	if( Color.blue >= 0.0 && Color.blue <= 1.0 )
		upperPaneColor.blue = Color.blue ;
}

struct color3d threeDof::getLowerLegColor()
{
	return lowerLegColor;
}
void threeDof::setLowerLegColor(struct color3d Color)
{
	if( Color.red >= 0.0 && Color.red <= 1.0 )
		lowerLegColor.red = Color.red ;
	if( Color.green >= 0.0 && Color.green <= 1.0 )
		lowerLegColor.green = Color.green ;
	if( Color.blue >= 0.0 && Color.blue <= 1.0 )
		lowerLegColor.blue = Color.blue ;
}

struct color3d threeDof::getUpperLegColor()
{
	return upperLegColor;
}
void threeDof::setUpperLegColor(struct color3d Color)
{
	if( Color.red >= 0.0 && Color.red <= 1.0 )
		upperLegColor.red = Color.red ;
	if( Color.green >= 0.0 && Color.green <= 1.0 )
		upperLegColor.green = Color.green ;
	if( Color.blue >= 0.0 && Color.blue <= 1.0 )
		upperLegColor.blue = Color.blue ;
}

struct color3d threeDof::getJointColor()
{
	return jointColor;
}
void threeDof::setJointColor(struct color3d Color)
{
	if( Color.red >= 0.0 && Color.red <= 1.0 )
		jointColor.red = Color.red ;
	if( Color.green >= 0.0 && Color.green <= 1.0 )
		jointColor.green = Color.green ;
	if( Color.blue >= 0.0 && Color.blue <= 1.0 )
		jointColor.blue = Color.blue ;
}


//  print class variables for debugging
void threeDof::print()
{
	cout << "Max Height : " << maxHeight << endl;
	cout << "Lower Leg Length : " << lowerLegLength << endl;
	cout << "Upper Leg Length : " << upperLegLength  << endl;
	cout << "Lower Pane Size : " <<  lowerPaneSize.width << " - "<< lowerPaneSize.height << " - "<< lowerPaneSize.depth << endl;
	cout << "Upper Pane Size : " <<  upperPaneSize.width << " - "<<  upperPaneSize.height << " - "<< upperPaneSize.depth << endl;
	cout << "Leg Radius : " << legRadius << endl;
	cout << "Lower Leg Radius : " << lowerLegRadius << endl;
	cout << "Upper Leg Radius : " << upperLegRadius << endl;
	cout << "Lower Pane Color : " << lowerPaneColor.red << " - "<< lowerPaneColor.green << " - "<< lowerPaneColor.blue  << endl;
	cout << "Upper Pane Color : " << upperPaneColor.red << " - "<< upperPaneColor.green << " - "<< upperPaneColor.blue  << endl;
	cout << "Upper Pane Joint Point 1 : " << upperPaneJointPoints.A.x << " - " << upperPaneJointPoints.A.y << " - " << upperPaneJointPoints.A.z << endl;
	cout << "Upper Pane Joint Point 2 : " << upperPaneJointPoints.B.x << " - " << upperPaneJointPoints.B.y << " - " << upperPaneJointPoints.B.z << endl;
	cout << "Upper Pane Joint Point 3 : " << upperPaneJointPoints.C.x << " - " << upperPaneJointPoints.C.y << " - " << upperPaneJointPoints.C.z << endl;

}

void threeDof::draw()
{
	// draw bottom pane
	bottomPane.draw();
	/*
	 * Draw bottom joints
	 */
	// draw joint 1 on bottom pane
	glPushMatrix();
	glTranslated(lowerPaneJointPoints.A.x , lowerPaneJointPoints.A.y , lowerPaneJointPoints.A.z);
	bottomJoint1.draw();
	glPopMatrix();
	// draw joint 2 on bottom pane
	glPushMatrix();
	glTranslated(lowerPaneJointPoints.B.x , lowerPaneJointPoints.B.y , lowerPaneJointPoints.B.z);
	bottomJoint2.draw();
	glPopMatrix();
	// draw joint 3 on bottom pane
	glPushMatrix();
	glTranslated(lowerPaneJointPoints.C.x , lowerPaneJointPoints.C.y , lowerPaneJointPoints.C.z);
	bottomJoint3.draw();
	glPopMatrix();

	/*
	 *  Draw bottom legs
	 */
	glPushMatrix();
	glTranslated(lowerPaneJointPoints.A.x , lowerPaneJointPoints.A.y , lowerPaneJointPoints.A.z);
	bottomLeg1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(lowerPaneJointPoints.B.x , lowerPaneJointPoints.B.y , lowerPaneJointPoints.B.z);
	bottomLeg2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(lowerPaneJointPoints.C.x , lowerPaneJointPoints.C.y , lowerPaneJointPoints.C.z);
	bottomLeg3.draw();
	glPopMatrix();

	/*
	 *  Draw top legs
	 */
	glPushMatrix();
	//glRotated( 180 ,0 , 0 , 0);
	glPushMatrix();
	glTranslated(upperPaneJointPoints.A.x , upperPaneJointPoints.A.y , upperPaneJointPoints.A.z);
	glPushMatrix();
	glRotated( 180 ,0 , 1 , 0);
	topLeg1.draw();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(upperPaneJointPoints.B.x , upperPaneJointPoints.B.y , upperPaneJointPoints.B.z);
	glPushMatrix();
	glRotated( 180 ,0 , 1 , 0);
	topLeg2.draw();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(upperPaneJointPoints.C.x , upperPaneJointPoints.C.y , upperPaneJointPoints.C.z);
	glPushMatrix();
	glRotated( 180 ,0 , 1 , 0);
	topLeg3.draw();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// translate base point
	glPushMatrix();
	//glTranslated(0.0 , 0.0 , bottomPane.getTableSize().depth + legRadius + maxHeight );
	/*
	 * Draw top joints
	 */
	//
	// draw joint 1 on top pane
	glPushMatrix();
	glTranslated(upperPaneJointPoints.A.x , upperPaneJointPoints.A.y , upperPaneJointPoints.A.z);
	topJoint1.draw();
	glPopMatrix();
	// draw joint 2 on top pane
	glPushMatrix();
	glTranslated(upperPaneJointPoints.B.x , upperPaneJointPoints.B.y , upperPaneJointPoints.B.z);
	topJoint2.draw();
	glPopMatrix();
	// draw joint 3 on top pane
	glPushMatrix();
	glTranslated(upperPaneJointPoints.C.x , upperPaneJointPoints.C.y , upperPaneJointPoints.C.z);
	topJoint3.draw();
	glPopMatrix();

	// draw top pane
	glPushMatrix();
	glTranslated(0.0, 0.0 , upperLegRadius);
	topPane.draw();
	glPopMatrix();
	glPopMatrix();
}

void threeDof::draw(struct triPoint3d lowerPaneJointPoints , struct triPoint3d upperPaneJointPoints , struct triAngle3d legAngles , struct motion3d motion )
{
	// draw bottom pane
	bottomPane.draw();
	/*
	 * Draw bottom joints
	 */
	// draw joint 1 on bottom pane
	glPushMatrix();
		glTranslated(lowerPaneJointPoints.A.x , lowerPaneJointPoints.A.y , lowerPaneJointPoints.A.z);
		bottomJoint1.draw();
	glPopMatrix();
	// draw joint 2 on bottom pane
	glPushMatrix();
		glTranslated(lowerPaneJointPoints.B.x , lowerPaneJointPoints.B.y , lowerPaneJointPoints.B.z);
		bottomJoint2.draw();
	glPopMatrix();
	// draw joint 3 on bottom pane
	glPushMatrix();
		glTranslated(lowerPaneJointPoints.C.x , lowerPaneJointPoints.C.y , lowerPaneJointPoints.C.z);
		bottomJoint3.draw();
	glPopMatrix();

	/*
	 *  Draw bottom legs
	 */
	glPushMatrix();
	glTranslated(lowerPaneJointPoints.A.x , lowerPaneJointPoints.A.y , lowerPaneJointPoints.A.z);
		glPushMatrix();
		glRotated(legAngles.A.x , 1,0,0);
		glRotated(legAngles.A.y , 0,1,0);
		glRotated(legAngles.A.z , 0,0,1);
		bottomLeg1.draw();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(lowerPaneJointPoints.B.x , lowerPaneJointPoints.B.y , lowerPaneJointPoints.B.z);
		glPushMatrix();
		glRotated(legAngles.B.x , 1,0,0);
		glRotated(legAngles.B.y , 0,1,0);
		glRotated(legAngles.B.z , 0,0,1);
		bottomLeg2.draw();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(lowerPaneJointPoints.C.x , lowerPaneJointPoints.C.y , lowerPaneJointPoints.C.z);
		glPushMatrix();
		glRotated(legAngles.B.x , 1,0,0);
		glRotated(legAngles.B.y , 0,1,0);
		glRotated(legAngles.B.z , 0,0,1);
		bottomLeg3.draw();
		glPopMatrix();
	glPopMatrix();

	/*
	 *  Draw top legs
	 */
	glPushMatrix();
	//glRotated( 180 ,0 , 0 , 0);
		glPushMatrix();
		glTranslated(upperPaneJointPoints.A.x , upperPaneJointPoints.A.y , upperPaneJointPoints.A.z);
			glPushMatrix();
			glRotated(180+legAngles.A.x , 1,0,0);
			glRotated(legAngles.A.y , 0,1,0);
			glRotated(180+legAngles.A.z , 0,0,1);
			topLeg1.draw();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(upperPaneJointPoints.B.x , upperPaneJointPoints.B.y , upperPaneJointPoints.B.z);
			glPushMatrix();
			glRotated(180+legAngles.A.x , 1,0,0);
			glRotated(legAngles.A.y , 0,1,0);
			glRotated(180+legAngles.A.z , 0,0,1);
			topLeg2.draw();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(upperPaneJointPoints.C.x , upperPaneJointPoints.C.y , upperPaneJointPoints.C.z);
			glPushMatrix();
			glRotated(180+legAngles.A.x , 1,0,0);
			glRotated(legAngles.A.y     , 0,1,0);
			glRotated(180+legAngles.A.z , 0,0,1);
			topLeg3.draw();
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();


	/*
	 * Draw top joints
	 */
	//
	// draw joint 1 on top pane

	struct point3d center;
	center.x = (upperPaneJointPoints.A.x + upperPaneJointPoints.B.x + upperPaneJointPoints.C.x)/3.0;
	center.y = (upperPaneJointPoints.A.y + upperPaneJointPoints.B.y + upperPaneJointPoints.C.y)/3.0;
	center.z = (upperPaneJointPoints.A.z + upperPaneJointPoints.B.z + upperPaneJointPoints.C.z)/3.0;
	// translate base point
	topJoint1.draw();
	glPushMatrix();
		glRotated(motion.Angle.x , 1,0,0);
		glRotated(motion.Angle.y , 0,1,0);
		glRotated(motion.Angle.z , 0,0,1);
		glTranslated(motion.Translate.x, motion.Translate.y , motion.Translate.z);

		// draw top pane
		glPushMatrix();
			glTranslated(center.x ,center.y ,center.z + upperLegRadius/2);

			topPane.draw(3);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	/*
	 * Draw top joints
	 */
	// draw joint 1 on top pane
	glPushMatrix();
		glTranslated(upperPaneJointPoints.A.x , upperPaneJointPoints.A.y , upperPaneJointPoints.A.z);
		bottomJoint1.draw();
	glPopMatrix();
	// draw joint 2 on bottom pane
	glPushMatrix();
		glTranslated(upperPaneJointPoints.B.x , upperPaneJointPoints.B.y , upperPaneJointPoints.B.z);
		bottomJoint2.draw();
	glPopMatrix();
	// draw joint 3 on bottom pane
	glPushMatrix();
		glTranslated(upperPaneJointPoints.C.x , upperPaneJointPoints.C.y , upperPaneJointPoints.C.z);
		bottomJoint3.draw();
	glPopMatrix();
	//glPopMatrix();


}
