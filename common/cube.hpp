#pragma once
#include <cstdint>
class Cube
{
    uint8_t data[54];
public:
    Cube(void); // solved cube
    Cube(const Cube&); // copy constructor
    Cube(uint8_t[54]);
    Cube(const char*);

    inline const uint8_t* get_data(void) const { return data; }
    
    // clockwise
    void R();
    void L();
    void U();
    void D();
    void F();
    void B();
    // anticlockwise
    void l();
    void r();
    void u();
    void d();
    void f();
    void b();
    // double
    void L2();
    void R2();
    void U2();
    void D2();
    void F2();
    void B2();
};