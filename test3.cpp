#include <includes/LineDrawer/LineDrawer.h>

LineDrawer lineDrawer;

float startX = 150.0f;
float startY = 150.0f;
float endX = 400.0f;
float endY = 400.0f;

void display(){
    lineDrawer.drawByOpenGL(startX, startY, endX, endY);
    glFlush();
}


void onMouseClick(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON){
    if(state == GLUT_DOWN){ 
    }
    else{
    }
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(MAX_WIDTH, MAX_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Lab02");

  glutMouseFunc(onMouseClick);

  glutDisplayFunc(display);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, MAX_WIDTH, MAX_HEIGHT, 0.0);
  glutMainLoop();

  return 0;
}