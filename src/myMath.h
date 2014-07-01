#ifndef MYMATH_H_
#define MYMATH_H_


#include "gen_def.h"

struct translate3d p3d2t3d(struct point3d points);
struct point3d rotatePoint(struct point3d point , struct translate3d centerPoint , double angle , double x , double y , double z);
void multiplyMatrix(void);
void setUpRotationMatrix(double angle, double u, double v, double w);
struct point3d translatePoint(struct point3d points , struct translate3d translation );
struct point3d translateCenterToOrigin(struct point3d points , struct translate3d translation );


#endif
