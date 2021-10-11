/*
Cube class. Representation of the Rubik's cube as a 54 byte object. 

Methods:
    - Constructors
    - Moving the cubes
    - Getter for const data pointer
    - Comparision
    - Solved or not
    - Hash functions (not implemented yet)

*/

#pragma once
#include "common.hpp"
#include <iostream> // std::ostream
#include <cstring>  // memcmp, memset, memcpy

class Cube
{
public:
    Cube(void);        // solved cube
    Cube(const Cube&); // copy constructor
    Cube(uint8_t[54]); // initialize from array
    Cube(const char*); // some random stuff

    // get the data of the member
    inline const uint8_t* get_data(void) const { return data; }

    // check if two cubes are exactly the same
    inline bool operator==(const Cube& other) const { return ! (bool)memcmp(data, other.data, 54); };

    // currently assumes that the orientation of the cube is fixed.
//#### needs to change if X, Y, Z, moves are allowed in the future.
    inline bool solved(void) const { return *this == Cube(); }

    // print out the cube with the 6 sides into console
    friend std::ostream& operator<<(std::ostream&, const Cube&);

    // hash functions used in hashtables
    uint64_t hash() const;
    uint64_t fasthash() const;

    // Modifying the cube in place. 
    // If you want to create a new cube after the turn and keep the original one in tact, use the method in the Turning class (turning.hpp)
      
    // clockwise
    void L ();
    void R ();
    void U ();
    void D ();
    void F ();
    void B ();
    // anticlockwise
    void L_();
    void R_();
    void U_();
    void D_();
    void F_();
    void B_();
    // half turns
    void L2();
    void R2();
    void U2();
    void D2();
    void F2();
    void B2();
private: 
    uint8_t data[54];
};

#ifdef CUBEMOVE_SWAP // some macros for swapping "stickers"
// swap 2
#define SWAP2(A,B,TMP) TMP=A;A=B;B=TMP
// swap 2 in array
#define SWAPA2(ARR,A,B,TMP) SWAP2(ARR[A],ARR[B],TMP)

// swap 4
#define SWAP4(A,B,C,D,TMP) TMP=D;D=C;C=B;B=A;A=TMP
// swap 4 in array
#define SWAPA4(ARR,A,B,C,D,TMP) SWAP4(ARR[A],ARR[B],ARR[C],ARR[D],TMP)
// swap 4 in reverse order
#define SWAPR4(ARR,A,B,C,D,TMP) SWAPA4(ARR,D,C,B,A,TMP)
#endif
