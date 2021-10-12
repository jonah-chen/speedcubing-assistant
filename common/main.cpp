#include "cube.hpp"
#include "turning.hpp"
#include "moveseq.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Cube a;
    MoveSequence ms("D2 U\' R\' F D U B F\' D R\' B2 F\' U\' L B\' F\' D2 L\' R2 D\' R\' U2 R2 F\' L\' D2 U B2 L2 D2");
    std::cout << ms.len() << std::endl;
    std::cout << ms.execute(a) << std::endl;

    return 0;
}
