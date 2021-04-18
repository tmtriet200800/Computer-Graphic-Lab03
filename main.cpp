#include "includes/OvalDrawer/OvalDrawer.h"
#include "includes/OvalDrawer/CircleDrawer.h"
#include "includes/TriangleDrawer.h"
#include "includes/PolygonDrawer.h"
#include "includes/RectangleDrawer/RectangleDrawer.h"
#include "includes/RectangleDrawer/SquareDrawer.h"
#include "includes/OtherDrawer/StarDrawer.h"

static int window;
static int menu_id;
static int triganle_menu_id;
static int rectangle_menu_id;
static int oval_menu_id;
static int polygon_menu_id;
static int other_menu_id;
static int math_menu_id;
static int color_menu_id;

static int value = 0;
static int drawType = -1;
static int startX = -1;
static int startY = -1;
static int scaleX = 1;
static int scaleY = 1;

bool drawing = false;

TriangleDrawer td;
OvalDrawer od;
CircleDrawer cd;
PolygonDrawer pd;
RectangleDrawer rd;
SquareDrawer sd;
StarDrawer stad;

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    drawType = num;
  }
  glutPostRedisplay();
} 


void createMenu(void){     
    triganle_menu_id = glutCreateMenu(menu);
    
    glutAddMenuEntry("Vuong can", 2);
    glutAddMenuEntry("Deu", 3);

    rectangle_menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh chu nhat", 4);
    glutAddMenuEntry("Hinh vuong", 5);

    oval_menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh tron", 6);
    glutAddMenuEntry("Hinh eclipse", 7);

    other_menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh ngoi sao", 8);
    glutAddMenuEntry("Hinh mui ten", 9);
    
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Duong thang", 1); 
    glutAddSubMenu("Tam giac", triganle_menu_id);
    glutAddSubMenu("Tu giac", rectangle_menu_id);  
    glutAddSubMenu("Oval", oval_menu_id);  
    glutAddSubMenu("Hinh khac", other_menu_id);          
    glutAddMenuEntry("Quit", 0);     
    glutAttachMenu(GLUT_RIGHT_BUTTON);
} 

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);

    cout << drawing << " " << drawType << endl;

    if(drawing == true){
      switch(drawType){
        case 2:
          cout << "Draw tam giac vuong can with scale: " << scaleY << endl;    
          td.drawRight(startX, startY, 1, 0, 0, scaleY);
          break;
        
        case 3:
          cout << "Draw tam giac vuong can with scale: " << scaleY << endl;    
          td.drawIsosceles(startX, startY, 1, 0, 0, scaleY);
          break;

        case 4:
          cout << "Draw rectangle with scaleX: " << scaleX << ", scaleY: " << scaleY << endl;
          rd.draw(startX, startY, scaleX, scaleY);
          break;

        case 5:
          cout << "Draw square with scale: " << scaleY << endl;
          sd.draw(startX, startY, scaleY);
          break;

        case 6:
          cout << "Draw circle with scaleY: " << scaleY << endl;
          cd.draw(startX, startY, scaleY);
          break;

        case 7:
          cout << "Draw eclipse with scaleX: " << scaleX << ", scaleY: " << scaleY << endl;
          od.draw(startX, startY, scaleX, scaleY);
          break;

        case 8:
          cout << "Draw start with scale: " << scaleY << endl;
          stad.draw(startX, startY, scaleY);
          break;

        default:
          break;
      }
    }

    glFlush();
}


void drag (int x, int y)
{
  if(drawing == true){
    // cout << x << " " << y << endl;
    scaleY = abs(y - startY);
    scaleX = abs(x - startX);
    display();
  }
}

void onMouseClick(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON){
    if(state == GLUT_DOWN){
        cout << "Start drawing" << endl;
        drawing = true;
        startX = x;
        startY = y;
    }
    else{
      cout << "End drawing" << endl;
      drawing = false;
    }
  }
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Lab02");

  glutMotionFunc(drag);
  glutMouseFunc(onMouseClick);


  glutDisplayFunc(display);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  createMenu();
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 480, 0.0);
  glutMainLoop();

  return 0;
}