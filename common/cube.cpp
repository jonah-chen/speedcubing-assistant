/*
Basic definitions for the cube class. 

Contains:
    - Constructors
    - Debug print operator
*/

#include "cube.hpp"

/*
Constructs an solved cube
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

std::ostream& operator<<(std::ostream& os, const Cube& cube)
{
    for (uint8_t i = 0; i < 3; ++i) // print the top face
        os << "      " << 
        COLOR_H(cube.data[3*i  ]) << " " <<
        COLOR_H(cube.data[3*i+1]) << " " << 
        COLOR_H(cube.data[3*i+2]) << " " << std::endl;
    
    for(uint8_t j = 0; j < 9; j+=3) // print the faces in the middle
    {
        for (uint8_t i =  9+j; i < 12+j; ++i)
            os << COLOR_H(cube.data[i]) << " ";
        os << "\b|";
        for (uint8_t i = 18+j; i < 21+j; ++i)
            os << COLOR_H(cube.data[i]) << " ";
        os << "\b|";
        for (uint8_t i = 36+j; i < 39+j; ++i)
            os << COLOR_H(cube.data[i]) << " ";
        os << "\b|";
        for (uint8_t i = 45+j; i < 48+j; ++i)
            os << COLOR_H(cube.data[i]) << " ";
        
        os << std::endl;
    }

    for (uint8_t i = 9; i < 12; ++i) // print the bottom face
        os << "      " << 
        COLOR_H(cube.data[3*i  ]) << " " <<
        COLOR_H(cube.data[3*i+1]) << " " << 
        COLOR_H(cube.data[3*i+2]) << " " << std::endl;
    
    return os;
}
