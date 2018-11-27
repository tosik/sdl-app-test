all:
	clang++ main.cpp -o test.app/Contents/MacOS/test -I/usr/local/include -L/usr/local/lib -lSDL2

