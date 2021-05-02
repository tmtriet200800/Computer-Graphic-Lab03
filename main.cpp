#include "includes/LineDrawer/LineDrawer.h"
#include "includes/OvalDrawer/OvalDrawer.h"
#include "includes/OvalDrawer/CircleDrawer.h"
#include "includes/TriangleDrawer/TriangleDrawer.h"
#include "includes/PolygonDrawer/HexagonDrawer.h"
#include "includes/PolygonDrawer/PentagonDrawer.h"
#include "includes/RectangleDrawer/RectangleDrawer.h"
#include "includes/RectangleDrawer/SquareDrawer.h"
#include "includes/OtherDrawer/StarDrawer.h"
#include "includes/OtherDrawer/ArrowDrawer.h"
#include "includes/MathDrawer/PlusDrawer.h"
#include "includes/MathDrawer/MultipleDrawer.h"
#include "includes/MathDrawer/MinusDrawer.h"
#include  "includes/MathDrawer/DividerDrawer.h"
#include "includes/Drawer.h"

#include "includes/Filler/FloodFiller.h"
#include "includes/Filler/ScanLineFiller.h"
#include "includes/Filler/BoundaryFiller.h"

#include "includes/AffineController/AffineController.h"

struct Shape{
  int type;
  int startX;
  int startY;
  int endX;
  int endY;
  int scaleX;
  int scaleY;
  vector<pair<double, double>> points;
  Color color;
};

vector<Shape> historyShape;

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
static int endX = -1;
static int endY = -1;
static int scaleX = 1;
static int scaleY = 1;

int vis[MAX_WIDTH][MAX_HEIGHT];


vector<pair<double, double>> points;
vector<pair<double, double>> customPolygon;

Color color;

bool drawing = false;

TriangleDrawer td;
OvalDrawer od;
CircleDrawer cd;
HexagonDrawer hexagonDrawer;
PentagonDrawer pentagonDrawer;
RectangleDrawer rd;
SquareDrawer sd;
StarDrawer stad;
ArrowDrawer ard;
PlusDrawer plusDrawer;
MinusDrawer minusDrawer;
MultipleDrawer multipleDrawer;
DividerDrawer dividerDrawer;
LineDrawer lineDrawer;
Drawer drawer;

FloodFiller floodFiller;
ScanLineFiller scanlineFiller;
BoundaryFiller boundaryFiller;
AffineController affineController;

void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    drawType = num;
  }
  glutPostRedisplay();
}

void drawByType(int drawType, int startX, int startY, int endX, int endY, int scaleX, int scaleY, vector<pair<double, double>> &points){
    switch(drawType){
      case -2:
        if(customPolygon.size() >= 2){
          for(int i = 0; i < customPolygon.size() - 1; i++){
            lineDrawer.drawByOpenGL(customPolygon[i].first, customPolygon[i].second, customPolygon[i + 1].first, customPolygon[i + 1].second);
          }
        }
        break;
      case -1:
        if(points.size() > 0){
          drawer.drawPoly(points);
        }
        break;
      case 1:
        // cout  << startX << " " << startY << " " << endX << " " << endY << endl;
        lineDrawer.drawByOpenGL(startX, startY, endX, endY);
        break;
      case 2:
        // cout << "Draw tam giac vuong can with scale: " << scaleY << endl;    
        points = td.drawRight(startX, startY, scaleY);
        break;
      
      case 3:
        // cout << "Draw tam giac vuong can with scale: " << scaleY << endl;    
        points = td.drawIsosceles(startX, startY, scaleY);
        break;

      case 4:
        // cout << "Draw rectangle with scaleX: " << scaleX << ", scaleY: " << scaleY << endl;
        points = rd.draw(startX, startY, scaleX, scaleY);
        break;

      case 5:
        // cout << "Draw square with scale: " << scaleY << endl;
        points = sd.draw(startX, startY, scaleY);
        break;

      case 6:
        // cout << "Draw circle with scaleY: " << scaleY << endl;
        points = cd.draw(startX, startY, scaleY);
        break;

      case 7:
        // cout << "Draw eclipse with scaleX: " << scaleX << ", scaleY: " << scaleY << endl;
        points = od.draw(startX, startY, scaleX, scaleY);
        break;

      case 8:
        // cout << "Draw start with scale: " << scaleY << endl;
        points = stad.draw(startX, startY, scaleY);
        break;

      case 9:
        // cout << "Draw arrow with scaleX: " << scaleX << ", scaleY: " << scaleY << endl;
        points = ard.draw(startX, startY, scaleX, scaleY);
        break;

      case 10:
        // cout << "Draw plus with scale: " << scaleY << endl;
        points = plusDrawer.draw(startX, startY, scaleY);
        break;

      case 11:
        // cout << "Draw minus with scale: " << scaleY << endl;
        points = minusDrawer.draw(startX, startY, scaleY);
        break;
      
      case 12:
        // cout << "Draw multiple with scale: " << scaleY << endl;
        points = multipleDrawer.draw(startX, startY, scaleY);
        break;    

      case 13:
        dividerDrawer.draw(startX, startY, scaleY);
        break;

      case 14:
        // cout << "Draw pentagon with scale: " << scaleY << endl;
        points = pentagonDrawer.draw(startX, startY, scaleY);
        break;    

      case 15:
        // cout << "Draw hexagon with scale: " << scaleY << endl;
        points = hexagonDrawer.draw(startX, startY, scaleY);
        break; 
    }
}

void redraw(){
  // cout << historyShape.size() << endl;

  for(auto shape : historyShape){
    drawByType(shape.type, shape.startX, shape.startY, shape.endX, shape.endY, shape.scaleX, shape.scaleY, shape.points);
  }
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

    math_menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Dau cong", 10);
    glutAddMenuEntry("Dau tru", 11);
    glutAddMenuEntry("Dau nhan", 12);
    glutAddMenuEntry("Dau chia", 13);

    polygon_menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngu giac deu", 14);
    glutAddMenuEntry("Luc giac deu", 15);

    color_menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Do", 16);
    glutAddMenuEntry("Xanh", 17);
    glutAddMenuEntry("Vang", 18);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Duong thang", 1); 
    glutAddSubMenu("Tam giac", triganle_menu_id);
    glutAddSubMenu("Tu giac", rectangle_menu_id);  
    glutAddSubMenu("Oval", oval_menu_id);  
    glutAddSubMenu("Hinh khac", other_menu_id); 
    glutAddSubMenu("Dau", math_menu_id);
    glutAddSubMenu("Da giac deu", polygon_menu_id);
    glutAddSubMenu("To mau", color_menu_id);         
    glutAddMenuEntry("Quit", 0);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);
} 

void display(){
    cout << drawing << " " << drawType << " " << startX << " " << startY << endl;

    // if(drawing == true){
      if(drawType < 16){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(1.0);

        redraw();
      }

      drawByType(drawType, startX, startY, endX, endY, scaleX, scaleY, points);      
    // }

    glFlush();
}


void drag (int x, int y)
{
  if(drawing == true){
    scaleY = abs(y - startY);
    scaleX = abs(x - startX);
    endX = x;
    endY = y;

    display();
  }
  else{
    customPolygon.push_back(make_pair(x, y));
    drawType = -2;
    display();
  }
}

void onMouseClick(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON){
    if(state == GLUT_DOWN){ 
        if(drawType > 0){
          if(drawType < 16){
            cout << "Start drawing" << endl;
            drawing = true;
          }
          else{
            switch(drawType){
              case 16:
                boundaryFiller.fill(x, y, Color{1,0,0}, Color{1,1,0}, vis);
                break;
              case 17:
                scanlineFiller.fill(0, 1, 0, points);
                break;
              case 18:
                floodFiller.fill(x, y, Color{0,0,0}, Color{1,1,0}, vis);
                break;
            }
          }
        }

        startX = x;
        startY = y;
        customPolygon[0].first = x;
        customPolygon[0].second = y;
    }
    else{
      if(drawing && drawType != -1){
        cout << "End drawing" << endl;
        Shape curShape = {drawType, startX, startY, x, y, scaleX, scaleY, points, color};
        // historyShape.push_back(curShape);
        drawing = false;
        drawType = -1;
      }
    }
  }
  
  if(button == GLUT_RIGHT_BUTTON){
    if(state == GLUT_DOWN){
      cout << "CLICKK RIGHT" << endl;

      if(drawType == -2){
        cout << "COMPLETE" << endl;

        customPolygon.push_back(make_pair(customPolygon[0].first, customPolygon[0].second));
        points = customPolygon;

        display();
        drawType = -1;
      }
    }
  }
}


void keyboardHandler(unsigned char Key, int x, int y){
  cout << Key << endl;

  cout << points[2].first << endl;

  switch (Key)
  {
    case '+':
      // affineController.scale(1.2, historyShape[historyShape.size() - 1].points);
      affineController.scale(1.2, points);

      break;
    
    case '-':
      affineController.scale(0.8,points);
      break;

    case 'l':
    case 'L':
      affineController.rotate(3.14/6, points);
      break;

    case 'r':
    case 'R':
      affineController.rotate(-3.14/6, points);
      break;

    default:
      break;
  }

  display();
}

void SpecialKeys(int key, int x, int y)
{
  switch (key)
  {
    case GLUT_KEY_LEFT:
      affineController.translate(-10,0, points);
      break;
    case GLUT_KEY_RIGHT:
      affineController.translate(10,0, points);
      break;
    case GLUT_KEY_UP:
      affineController.translate(0,-10, points); 
      break;
    case GLUT_KEY_DOWN:
      affineController.translate(0,10, points);
      break;
  }

  display();
}

int main(int argc, char **argv) {

  customPolygon.push_back(make_pair(startX, startY));


  for(int i=0;i<MAX_WIDTH;i++){
    for(int j=0;j<MAX_HEIGHT;j++){
      vis[i][j]=0;
    }
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(MAX_WIDTH, MAX_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Lab02");

  glutMotionFunc(drag);
  glutMouseFunc(onMouseClick);
  glutKeyboardFunc(keyboardHandler);
  glutSpecialFunc(SpecialKeys);



  // glutDisplayFunc(display);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  createMenu();
  glLoadIdentity();
  gluOrtho2D(0.0, MAX_WIDTH, MAX_HEIGHT, 0.0);
  glutMainLoop();

  return 0;
}