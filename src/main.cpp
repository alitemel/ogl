#include "3dof/threeDof.h"
#include "motion/motion.h"
#include "motion/calcPosition.h"
#include "motion/calcJointAngles.h"

#define window_width  640
#define window_height 480


void Keyboard(unsigned char key, int x, int y);

// global 3dof
threeDof my3dof;
motion randMotion;
calcPosition upperPaneJointsPositions;
calcJointAngles legAngles;
double angleX = -90.0 , angleY , angleZ;

// Main loop

void main_loop_function() {

	upperPaneJointsPositions.setPosition(my3dof.getUpperPaneJointPoints());
	upperPaneJointsPositions.printJointPoints();
	struct motion3d m;
	m.Angle = {10,10,10};
	m.Translate = {0.1,0.1,0.05};
	randMotion.setLimits(m);
	struct motion3d instantMotion = randMotion.getRandomMotion();
	instantMotion = randMotion.getRandomMotion();
	instantMotion = {{10,0,30}, {0.0,0.0,0.0}};
	//instantMotion = randMotion.getRandomMotion();
	randMotion.printRandomMotion();
	struct triPoint3d newUpperJoints = upperPaneJointsPositions.calcNewJointPoints(instantMotion);
	upperPaneJointsPositions.printJointPoints();
	struct triAngle3d jointAngles = legAngles.calcNewJointAngles(my3dof.getLowerPaneJointPoints() , newUpperJoints );
	legAngles.printNewAngles();
	// Clear color (screen)
    // And depth (used internally to block obstructed objects)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Load identity matrix
    glLoadIdentity();
    // Multiply in translation matrix
    glTranslatef(0, 0, -5);
    // Multiply in rotation matrix
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    glRotatef(angleZ, 0, 0, 1);

    //my3dof.draw();
    my3dof.draw(my3dof.getLowerPaneJointPoints() ,newUpperJoints , jointAngles ,instantMotion);


    //test



    usleep(300000);
    // Swap buffers (color buffers, makes previous render visible)
    glutSwapBuffers();


}

// Initialze OpenGL perspective matrix
void GL_Setup(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    gluPerspective(60 , (float) width / height, .1, 7);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);
}

// Initialize GLUT and start main loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(window_width, window_height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("GLUT Example!!!");
    //					lps				ups				mh	   lr		lpc					upc				llc					ulc					jc
    threeDof m3dof({2.0 ,2.0 , 0.1},{2.0 ,2.0 , 0.1} , 1.0 , 0.1 , {1.0 , 0.0 , 0.0}, {1.0 , 0.0 , 0.0}, {1.0 , 1.0 , 0.0}, {1.0 , 0.0 , 1.0}, {0.0 , 0.0 , 1.0});
    my3dof = m3dof;
    /*
    double angle =0 ;
    angle = sqrt(pow(my3dof.getMaxHeight(),2.0) , pow( sqrt(pow(my3dof.getUpperPaneJointPoints().A.x - my3dof.getUpperPaneJointPoints().B.x ,2.0 ) +
    		pow(my3dof.getUpperPaneJointPoints().A.y - my3dof.getUpperPaneJointPoints().B.y , 2.0 )+ pow(my3dof.getUpperPaneJointPoints().A.z - my3dof.getUpperPaneJointPoints().B.z , 2.0 )),2.0));
     */
    upperPaneJointsPositions.setPosition(my3dof.getUpperPaneJointPoints());
    upperPaneJointsPositions.printJointPoints();
    struct motion3d m;
    m.Angle = {10,10,10};
    m.Translate = {0.1,0.1,0.05};
    randMotion.setLimits(m);
    struct motion3d instantMotion = randMotion.getRandomMotion();
    instantMotion = randMotion.getRandomMotion();
    instantMotion = randMotion.getRandomMotion();
    randMotion.printRandomMotion();
    struct triPoint3d newUpperJoints = upperPaneJointsPositions.calcNewJointPoints(instantMotion);
    upperPaneJointsPositions.printJointPoints();
    struct triAngle3d jointAngles = legAngles.calcNewJointAngles(my3dof.getLowerPaneJointPoints() , newUpperJoints );
    legAngles.printNewAngles();
    glutKeyboardFunc (Keyboard);
    glutIdleFunc(main_loop_function);
    GL_Setup(window_width, window_height);

    glutMainLoop();
}


void Keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:             // ESCAPE key
	  exit (0);
	  break;
  case 'w':
	  angleX += 1.0;
	  break;
  case 's':
	  angleX -= 1.0;
	  break;
  case 'r':
	  angleY += 1.0;
	  break;
  case 'f':
	  angleY -= 1.0;
  	  break;
  case 'y':
	  angleZ += 1.0;
  	  break;
  case 'h':
	  angleZ -= 1.0;
  	  break;

  }
}
