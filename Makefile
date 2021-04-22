
build:
	g++ -o main.o main.cpp includes/*.cpp includes/*/*.cpp -lglut -lGLU -lGL
test:
	g++ test.cpp includes/Drawer.cpp includes/RectangleDrawer/RectangleDrawer.cpp -o test.o -lglut -lGLU -lGL

build_win:
	x86_64-w64-mingw32-gcc -o main64.exe main.cpp includes/*.cpp -lglut -lGLU -lGL

convert:
	g++ -o main.exe main.o

.PHONY: build, convert