#ifndef __CURSES
#define __CURSES

#include <cstdlib>
#include <curses.h>
#include <time.h>
#include <iostream>

 
#define BLACKONYELLOW	1
#define WHITEONBLACK	2
#define WHITEONBLUE     3
#define BLACKONWHITE    4
#define BLACKONBLUE     5
#define BLACKONGREEN    6
#define BLACKONCYAN     7
#define BLACKONRED      8
#define BLACKONMAGENTA  9  


using namespace std;

void myExit();
void initialize();

#endif
