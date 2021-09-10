#pragma once

class Cube
{
    unsigned char data[54];

public:
    Cube(); // solved cube
    Cube(const Cube& other);
    Cube(const char* moves);
    
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