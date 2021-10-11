#include "cube.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Cube a;
    for (uint8_t _ = 0; _ < 6; ++_)
    {
        a.L2();
        std::cout << a;
    }
    return 0;
}