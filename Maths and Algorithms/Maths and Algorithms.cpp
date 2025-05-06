#include <iostream>

#include "Algorithms.h"
#include "DataStructures.h"
#include "Maths.h"
#include "Matrix.h"
#include "Vector.h"

#include <math.h>
#include <algorithm>


int main()
{
    std::cout << "Hello World!\n";
    //vector
    //add
    //subtract

    float a = MathUtils::toRad(45.0f);
    if (a == 0.785398f)
        std::cout << "it works" << std::endl;
    else
    {
        std::cout << "it broken" << std::endl;
        std::cout << a << std::endl;
    }

    float b = MathUtils::toDeg(2.0f);
    if (b == 114.592f)
        std::cout << "it works" << std::endl;
    else
    {
        std::cout << "it broken" << std::endl;
        std::cout << b << std::endl;
    }

    float c = MathUtils::Pythagoras(45 , 45);
    if (c == 63.6396)
        std::cout << "it works" << std::endl;
    else
    {
        std::cout << "it broken" << std::endl;
        std::cout << c << std::endl;
    }




    //stack
   /*  Stack<int>*  mystack = new Stack<int>();
     mystack->Pop();*/

}


