/*
 * threeDof.h
 *
 *  Created on: Jun 6, 2014
 *      Author: yabgu
 */

#ifndef THREEDOF_H_
#define THREEDOF_H_

#include "pane.h"
#include "leg.h"
#include "joint.h"
#include "../gen_def.h"

class threeDof
{
private:
	// maximum height of platform , related with length of legs
	double maxHeight;

	// leg lengths
	double lowerLegLength;
	double upperLegLength;

	// size of upper and lower panes
	struct size3d lowerPaneSize;
	struct size3d upperPaneSize;

	// radius of legs
	double legRadius;

	// points of joints that are mounted an panes
	struct triPoint3d lowerPaneJointPoints ;
	struct triPoint3d upperPaneJointPoints ;

	//
	double lowerLegRadius;
	double upperLegRadius;

	// color parts of 3dof
	struct color3d lowerPaneColor;
	struct color3d upperPaneColor;
	struct color3d lowerLegColor;
	struct color3d upperLegColor;
	struct color3d jointColor;

	// declare panes
	pane bottomPane;
	pane topPane;

	// declare lower joints
	joint bottomJoint1 , bottomJoint2, bottomJoint3;

	// declare upper joints
	joint topJoint1 , topJoint2, topJoint3;

	// declare bottom legs
	leg bottomLeg1, bottomLeg2 , bottomLeg3;

	// declare bottom legs
	leg topLeg1, topLeg2 , topLeg3;

	// Assign joint points as corners of equilateral triangle - assume center of pane is (0,0,*)
	triPoint3d assignJointPoints(struct size3d );

	// Initialize 3dof , call this function in the constructor
	void initialize(void);

public:
	threeDof();
	threeDof(struct size3d , struct size3d , double , double , struct color3d , struct color3d , struct color3d , struct color3d , struct color3d);

	double getMaxHeight(void);
	void setMaxHeight(double);

	struct size3d getLowerPaneSize(void);
	void setLowerPaneSize(struct size3d);

	struct size3d getUpperPaneSize(void);
	void setUpperPaneSize(struct size3d);

	double getLegRadius(void);
	void setLegRadius(double);

	double getLowerLegRadius(void);
	double getUpperLegRadius(void);

	struct triPoint3d getLowerPaneJointPoints(void);
	struct triPoint3d getUpperPaneJointPoints(void);

	struct color3d getLowerPaneColor(void);
	void setLowerPaneColor(struct color3d);

	struct color3d getUpperPaneColor(void);
	void setUpperPaneColor(struct color3d);

	struct color3d getLowerLegColor(void);
	void setLowerLegColor(struct color3d);

	struct color3d getUpperLegColor(void);
	void setUpperLegColor(struct color3d);

	struct color3d getJointColor(void);
	void setJointColor(struct color3d);

	void draw( void );
	void draw( struct triPoint3d , struct triPoint3d , struct triAngle3d , struct motion3d );
	// debug
	void print(void);
};

#endif /* THREEDOF_H_ */
