/*
Transformations (moves) on the cube.

Contains:
    - Quarter CW & CCW turns for the 6 faces
    - Half turns for the 6 faces.
*/

#define CUBEMOVE_SWAP
#include "cube.hpp"

/*
Use 4-cycles to do single turns
*/
void Cube::L ()
{
    uint8_t tmp;
    
    SWAPA4(data, 9,11,17,15,tmp);
    SWAPA4(data,10,14,16,12,tmp);

    SWAPA4(data, 0,18,27,53,tmp);
    SWAPA4(data, 3,21,30,50,tmp);
    SWAPA4(data, 6,24,33,47,tmp);
}

void Cube::L_()
{
    uint8_t tmp;
    
    SWAPR4(data, 9,11,17,15,tmp);
    SWAPR4(data,10,14,16,12,tmp);

    SWAPR4(data, 0,18,27,53,tmp);
    SWAPR4(data, 3,21,30,50,tmp);
    SWAPR4(data, 6,24,33,47,tmp);
}


void Cube::R ()
{
    uint8_t tmp;
    
    SWAPA4(data,36,38,44,42,tmp);
    SWAPA4(data,37,41,43,39,tmp);

    SWAPA4(data, 2,51,29,20,tmp);
    SWAPA4(data, 5,48,32,23,tmp);
    SWAPA4(data, 8,45,35,26,tmp);
}

void Cube::R_()
{
    uint8_t tmp;
    
    SWAPR4(data,36,38,44,42,tmp);
    SWAPR4(data,37,41,43,39,tmp);

    SWAPR4(data, 2,51,29,20,tmp);
    SWAPR4(data, 5,48,32,23,tmp);
    SWAPR4(data, 8,45,35,26,tmp);
}


void Cube::U ()
{
    uint8_t tmp;
    
    SWAPA4(data, 2, 8, 6, 0,tmp);
    SWAPA4(data, 5, 7, 3, 1,tmp);

    SWAPA4(data,45,36,18, 9,tmp);
    SWAPA4(data,46,37,19,10,tmp);
    SWAPA4(data,47,38,20,11,tmp);
}

void Cube::U_()
{
    uint8_t tmp;
    
    SWAPR4(data, 2, 8, 6, 0,tmp);
    SWAPR4(data, 5, 7, 3, 1,tmp);

    SWAPR4(data,45,36,18, 9,tmp);
    SWAPR4(data,46,37,19,10,tmp);
    SWAPR4(data,47,38,20,11,tmp);
}


void Cube::D ()
{
    uint8_t tmp;
    
    SWAPA4(data,27,29,35,33,tmp);
    SWAPA4(data,28,32,34,30,tmp);

    SWAPA4(data,15,24,42,51,tmp);
    SWAPA4(data,16,25,43,52,tmp);
    SWAPA4(data,17,26,44,53,tmp);
}

void Cube::D_()
{
    uint8_t tmp;
    
    SWAPR4(data,27,29,35,33,tmp);
    SWAPR4(data,28,32,34,30,tmp);

    SWAPR4(data,15,24,42,51,tmp);
    SWAPR4(data,16,25,43,52,tmp);
    SWAPR4(data,17,26,44,53,tmp);
}


void Cube::F ()
{
    uint8_t tmp;
    
    SWAPA4(data,18,20,26,24,tmp);
    SWAPA4(data,19,23,25,21,tmp);

    SWAPA4(data, 6,36,29,17,tmp);
    SWAPA4(data, 7,39,28,14,tmp);
    SWAPA4(data, 8,42,27,11,tmp);
}

void Cube::F_()
{
    uint8_t tmp;
    
    SWAPR4(data,18,20,26,24,tmp);
    SWAPR4(data,19,23,25,21,tmp);

    SWAPR4(data, 6,36,29,17,tmp);
    SWAPR4(data, 7,39,28,14,tmp);
    SWAPR4(data, 8,42,27,11,tmp);
}


void Cube::B ()
{
    uint8_t tmp;
    
    SWAPA4(data,45,47,53,51,tmp);
    SWAPA4(data,46,50,52,48,tmp);

    SWAPA4(data, 2, 9,33,44,tmp);
    SWAPA4(data, 1,12,34,41,tmp);
    SWAPA4(data, 0,15,35,38,tmp);
}

void Cube::B_()
{
    uint8_t tmp;
    
    SWAPR4(data,45,47,53,51,tmp);
    SWAPR4(data,46,50,52,48,tmp);

    SWAPR4(data, 2, 9,33,44,tmp);
    SWAPR4(data, 1,12,34,41,tmp);
    SWAPR4(data, 0,15,35,38,tmp);
}

/*
Use 2 cycles to do double turns
*/
void Cube::L2()
{
    uint8_t tmp;
    // the + x swap
    SWAPA2(data, 9,17,tmp);
    SWAPA2(data,11,15,tmp);
    SWAPA2(data,10,16,tmp);
    SWAPA2(data,12,14,tmp);

    SWAPA2(data, 0,27,tmp);
    SWAPA2(data, 3,30,tmp);
    SWAPA2(data, 6,33,tmp);

    SWAPA2(data,18,53,tmp);
    SWAPA2(data,21,50,tmp);
    SWAPA2(data,24,47,tmp);
}

void Cube::R2()
{
    uint8_t tmp;

    SWAPA2(data,36,44,tmp);
    SWAPA2(data,38,42,tmp);
    SWAPA2(data,37,43,tmp);
    SWAPA2(data,39,41,tmp);

    SWAPA2(data, 2,29,tmp);
    SWAPA2(data, 5,32,tmp);
    SWAPA2(data, 8,35,tmp);

    SWAPA2(data,20,51,tmp);
    SWAPA2(data,23,48,tmp);
    SWAPA2(data,26,45,tmp);
}

void Cube::U2()
{
    uint8_t tmp;

    SWAPA2(data, 0, 8,tmp);
    SWAPA2(data, 2, 6,tmp);
    SWAPA2(data, 1, 7,tmp);
    SWAPA2(data, 3, 5,tmp);

    SWAPA2(data, 9,36,tmp);
    SWAPA2(data,10,37,tmp);
    SWAPA2(data,11,38,tmp);

    SWAPA2(data,18,45,tmp);
    SWAPA2(data,19,46,tmp);
    SWAPA2(data,20,47,tmp);
}

void Cube::D2()
{
    uint8_t tmp;

    SWAPA2(data,27,35,tmp);
    SWAPA2(data,29,33,tmp);
    SWAPA2(data,28,34,tmp);
    SWAPA2(data,30,32,tmp);

    SWAPA2(data,15,42,tmp);
    SWAPA2(data,16,43,tmp);
    SWAPA2(data,17,44,tmp);

    SWAPA2(data,24,51,tmp);
    SWAPA2(data,25,52,tmp);
    SWAPA2(data,26,53,tmp);
}

void Cube::F2()
{
    uint8_t tmp;

    SWAPA2(data,18,26,tmp);
    SWAPA2(data,20,24,tmp);
    SWAPA2(data,19,25,tmp);
    SWAPA2(data,21,23,tmp);

    SWAPA2(data, 6,29,tmp);
    SWAPA2(data, 7,28,tmp);
    SWAPA2(data, 8,27,tmp);

    SWAPA2(data,11,42,tmp);
    SWAPA2(data,14,39,tmp);
    SWAPA2(data,17,36,tmp);
}

void Cube::B2()
{
    uint8_t tmp;

    SWAPA2(data,45,53,tmp);
    SWAPA2(data,47,51,tmp);
    SWAPA2(data,46,52,tmp);
    SWAPA2(data,48,50,tmp);

    SWAPA2(data, 2,33,tmp);
    SWAPA2(data, 1,34,tmp);
    SWAPA2(data, 0,35,tmp);

    SWAPA2(data,15,38,tmp);
    SWAPA2(data,12,41,tmp);
    SWAPA2(data, 9,44,tmp);
}

#undef CUBEMOVE_SWAP