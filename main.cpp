#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "Tic Tac Toe.h"
using namespace std;

int main()
{
    srand(time(NULL));
    game obj;
    obj.start();
    return 0;
}
