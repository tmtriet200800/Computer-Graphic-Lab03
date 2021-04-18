#include "includes/LineDrawer.h"
#include "includes/CircleDrawer.h"
#include "includes/EclipseDrawer.h"
#include "includes/HyperbolaDrawer.h"
#include "includes/ParabolaDrawer.h"
#include "includes/FloodFiller.h"
#include "includes/ScanLineFiller.h"

using namespace std;

string input_filename = "testcase3.txt";

vector<pair<int, int>> temp;
// vector<pair<float, float>> temp;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(1.0);

  LineDrawer lineDrawer;
  CircleDrawer circleDrawer;
  HyperbolaDrawer hyperbolaDrawer;
  EclipseDrawer eclipseDrawer;
  ParabolaDrawer parabolaDrawer;

  string line;
  ifstream myfile(input_filename);

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      size_t pos = 0;
      string delimiter = " ";
      vector<int> inputArr;

      while ((pos = line.find(delimiter)) != string::npos) {
        string token = line.substr(0, pos);
        inputArr.push_back(stoi(token));
        line.erase(0, pos + delimiter.length());
      }

      inputArr.push_back(stoi(line));

      if (inputArr[0] == 0) {
        cout << "DDA Line" << endl;
        cout << "Input: " << inputArr[1] << " " << inputArr[2] << " "
             << inputArr[3] << " " << inputArr[4] << endl;

        const clock_t begin_time = clock();
        lineDrawer.drawByDDA(inputArr[1], inputArr[2], inputArr[3], inputArr[4]);

        cout << "Time complexity implemented: "
             << float(clock() - begin_time) / CLOCKS_PER_SEC << endl
             << endl;
          
        const clock_t begin_time_opengl = clock();
        lineDrawer.drawByOpenGL(1, 0, 0, inputArr[1], inputArr[2] + 50, inputArr[3], inputArr[4] + 50);

        cout << "Time complexity OpenGL: "
             << float(clock() - begin_time) / CLOCKS_PER_SEC << endl
             << endl;
      }

      if (inputArr[0] == 1) {
        cout << "Bresenham Line" << endl;
        cout << "Input: " << inputArr[1] << " " << inputArr[2] << " "
             << inputArr[3] << " " << inputArr[4] << endl;

        const clock_t begin_time = clock();
        lineDrawer.drawByBresenham(inputArr[1], inputArr[2], inputArr[3],
                              inputArr[4]);

        cout << "Time complexity: "
             << float(clock() - begin_time) / CLOCKS_PER_SEC << endl
             << endl;

        const clock_t begin_time_opengl = clock();
        lineDrawer.drawByOpenGL(1, 0, 0, inputArr[1], inputArr[2] + 50, inputArr[3], inputArr[4] + 50);

        cout << "Time complexity OpenGL: "
             << float(clock() - begin_time) / CLOCKS_PER_SEC << endl
             << endl;
      }


      if (inputArr[0] == 2) {
        // cout << "Midpoint Circle" << endl;
        // cout << "Input: " << inputArr[1] << " " << inputArr[2] << " "
        //      << inputArr[3] << endl;

        const clock_t begin_time = clock();
        temp = circleDrawer.drawByMidpoint(inputArr[1], inputArr[2], inputArr[3]);

        cout << "Time complexity: "
             << float(clock() - begin_time) / CLOCKS_PER_SEC << endl
             << endl;

        // const clock_t begin_time_opengl = clock();
        // circleDrawer.drawByOpenGL(inputArr[1] + 50, inputArr[2] + 50, inputArr[3], 1, 0,1, temp);

        // cout << "Time complexity OpenGL: " << float(clock() - begin_time) / CLOCKS_PER_SEC << endl << endl;
      }



      if (inputArr[0] == 3) {
        cout << "Midpoint Ellipse" << endl;
        cout << "Input: " << inputArr[1] << " " << inputArr[2] << " "
             << inputArr[3] << inputArr[4] << endl;

        const clock_t begin_time = clock();
        eclipseDrawer.drawByMidPoint(inputArr[1], inputArr[2], inputArr[3],
                                    inputArr[4]);
        cout << "Time complexity: " << float(clock() - begin_time) / CLOCKS_PER_SEC << endl << endl;

        const clock_t begin_time_opengl = clock();
        eclipseDrawer.drawByOpenGL(inputArr[1] + 50, inputArr[2] + 50, inputArr[3],  inputArr[4], 1, 0, 1);
        cout << "Time complexity OpenGL: " << float(clock() - begin_time_opengl) / CLOCKS_PER_SEC << endl << endl;
      }

      if (inputArr[0] == 4) {
        cout << "Midpoint Parapola" << endl;
        cout << "Input: " << inputArr[1] << " " << inputArr[2] << " "
             << inputArr[3] << endl;

        const clock_t begin_time = clock();
        parabolaDrawer.drawByMidPoint(inputArr[1], inputArr[2], inputArr[3]);

        cout << "Time complexity: " << float(clock() - begin_time) / CLOCKS_PER_SEC << endl << endl;

        const clock_t begin_time_opengl = clock();
        parabolaDrawer.drawByOpenGL(inputArr[1] + 50, inputArr[2] + 50, inputArr[3]);

        cout << "Time complexity OpenGL: " << float(clock() - begin_time_opengl) / CLOCKS_PER_SEC << endl << endl;
      }

      if (inputArr[0] == 5) {
        cout << "Midpoint HyperParapola" << endl;
        cout << "Input: " << inputArr[1] << " " << inputArr[2] << " "
             << inputArr[3] << endl;

        const clock_t begin_time = clock();
        hyperbolaDrawer.drawByMidPoint(inputArr[1], inputArr[2], inputArr[3],
                              inputArr[4]);
        cout << "Time complexity: " << float(clock() - begin_time) / CLOCKS_PER_SEC << endl << endl;

        const clock_t begin_time_opengl = clock();
        hyperbolaDrawer.drawByOpenGL(inputArr[1] + 50, inputArr[2] + 50, inputArr[3], inputArr[4]);

        cout << "Time complexity OpenGL: " << float(clock() - begin_time_opengl) / CLOCKS_PER_SEC << endl << endl;
      }

      glutSwapBuffers();
    }

    myfile.close();
  }

  glFlush();
}

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {0.0f, 0.0f, 0.0f};

  // FloodFiller fl;
  ScanLineFiller sl;

  cout << x << " " << y << endl;
  // cout << float(x) / 640 << " " << float(y) / 480 << endl;

  // cout << temp[0].first << " " << temp[0].second << endl;
  // cout << temp[1].first << " " << temp[1].second << endl;

  cout << temp.size() << endl;

  for(int i = 0; i < temp.size(); i = i + 2){
    sl.storeEdgeInTable(temp[i].first, temp[i].second, temp[i + 1].first, temp[i + 1].second);
  }

  // fl.fill(x, y, oldColor, newColor);
  sl.fill();

  cout << "ENDDDD" << endl;
}


int main(int argc, char **argv) {

  // cout << "Enter input filename: ";

  // cin >> input_filename;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Lab02");

  glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 480, 0.0);
  glutMainLoop();

  return 0;
}