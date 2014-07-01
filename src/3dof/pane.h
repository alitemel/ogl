/*
 * pane.h
 *
 *  Created on: Jun 5, 2014
 *      Author: yabgu
 */

#ifndef TABLE_H_
#define TABLE_H_

#include "../gen_def.h"

class pane
{
private:
	struct size3d  size   = {100.0 , 100.0 , 5.0 };
	struct color3d color  = {1.0   , 0.0   , 0.0 };
	struct angle3d angles = {0.0   , 0.0   , 0.0 };
	struct point3d centerOf = {0.0   , 0.0   , 0.0 };
public:
	pane();
	pane(struct size3d , struct point3d );
	struct size3d getTableSize(void);
	void setPaneSize(struct size3d);
	void setCenter(struct point3d);
	void setColor(struct color3d );
	void setAngles(struct angle3d );
	void draw( void );
	void draw( int );

};

#endif /* TABLE_H_ */
