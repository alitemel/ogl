#include "myMath.h"

double rotationMatrix[4][4];
double inputMatrix[4][1] = {0.0, 0.0, 0.0, 0.0};
double outputMatrix[4][1] = {0.0, 0.0, 0.0, 0.0};


// typeCast :))
translate3d p3d2t3d(point3d points)
{
	return {points.x , points.y , points.z } ;
}

void multiplyMatrix()
{
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 1; j++){
            outputMatrix[i][j] = 0;
            for(int k = 0; k < 4; k++){
                outputMatrix[i][j] += rotationMatrix[i][k] * inputMatrix[k][j];
            }
        }
    }
}
void setUpRotationMatrix(double angle, double u, double v, double w)
{
    float L = (u*u + v * v + w * w);
    angle = angle * M_PI / 180.0; //converting to radian value
    float u2 = u * u;
    float v2 = v * v;
    float w2 = w * w;

    rotationMatrix[0][0] = (u2 + (v2 + w2) * cos(angle)) / L;
    rotationMatrix[0][1] = (u * v * (1 - cos(angle)) - w * sqrt(L) * sin(angle)) / L;
    rotationMatrix[0][2] = (u * w * (1 - cos(angle)) + v * sqrt(L) * sin(angle)) / L;
    rotationMatrix[0][3] = 0.0;

    rotationMatrix[1][0] = (u * v * (1 - cos(angle)) + w * sqrt(L) * sin(angle)) / L;
    rotationMatrix[1][1] = (v2 + (u2 + w2) * cos(angle)) / L;
    rotationMatrix[1][2] = (v * w * (1 - cos(angle)) - u * sqrt(L) * sin(angle)) / L;
    rotationMatrix[1][3] = 0.0;

    rotationMatrix[2][0] = (u * w * (1 - cos(angle)) - v * sqrt(L) * sin(angle)) / L;
    rotationMatrix[2][1] = (v * w * (1 - cos(angle)) + u * sqrt(L) * sin(angle)) / L;
    rotationMatrix[2][2] = (w2 + (u2 + v2) * cos(angle)) / L;
    rotationMatrix[2][3] = 0.0;

    rotationMatrix[3][0] = 0.0;
    rotationMatrix[3][1] = 0.0;
    rotationMatrix[3][2] = 0.0;
    rotationMatrix[3][3] = 1.0;
}

struct point3d rotatePoint(struct point3d point , struct translate3d centerPoint , double angle , double x ,double y , double z)
{
	// carry around origin
	point = translateCenterToOrigin(point , centerPoint);
	// calculate rotation
	inputMatrix[0][0] = point.x;
	inputMatrix[1][0] = point.y;
	inputMatrix[2][0] = point.z;
	inputMatrix[3][0] = 1.0;
	setUpRotationMatrix(angle, x ,y ,z);
	multiplyMatrix();
	point.x = outputMatrix[0][0] ;
	point.y = outputMatrix[1][0] ;
	point.z = outputMatrix[2][0] ;
	// go back
	point = translatePoint(point , centerPoint );

	return point;
}

struct point3d translatePoint(struct point3d points , struct translate3d translation )
{
	struct point3d retPoint;
	retPoint.x = points.x + translation.x;
	retPoint.y = points.y + translation.y;
	retPoint.z = points.z + translation.z;
	return retPoint;
}

struct point3d translateCenterToOrigin(struct point3d points , struct translate3d translation )
{
	struct point3d retPoint;
	retPoint.x = points.x - translation.x;
	retPoint.y = points.y - translation.y;
	retPoint.z = points.z - translation.z;
	return retPoint;
}

