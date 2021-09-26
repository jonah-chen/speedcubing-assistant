#include "cube.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Cube a;
    for (int i = 0; i < 54; ++i)
        std::cout << (int)a.get_data()[i];
    return 0;
}