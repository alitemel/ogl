
#ifndef GEN_DEF_H_
#define GEN_DEF_H_

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include <unistd.h>

using namespace std;

#define myPI  3.1415926


struct angle3d{
	double x;
	double y;
	double z;
};

struct color3d{
	double red;
	double green;
	double blue;
};

struct size3d{
	double width;
	double height;
	double depth;
};

struct point3d {
	double x;
	double y;
	double z;
};

struct triPoint3d {
	struct point3d A;
	struct point3d B;
	struct point3d C;
};

struct translate3d{
	double x;
	double y;
	double z;
};

struct motion3d{
	struct angle3d Angle;
	struct translate3d Translate;
};

struct triAngle3d{
	struct angle3d A;
	struct angle3d B;
	struct angle3d C;
};



#endif
