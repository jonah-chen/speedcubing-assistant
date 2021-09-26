#include "cube.hpp"
#include <cstring>

/*
Constructs an empty cube
*/
Cube::Cube()
{
    memset(data,    0x00, 9);
    memset(data+ 9, 0x01, 9);
    memset(data+18, 0x02, 9);
    memset(data+27, 0x03, 9);
    memset(data+36, 0x04, 9);
    memset(data+45, 0x05, 9);
}

Cube::Cube(const Cube& other)
{
    memcpy(data, other.data, 54);
}

Cube::Cube(uint8_t data[54])
{
    memcpy(this->data, data, 54);
}