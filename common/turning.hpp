#pragma once
#include "cube.hpp"

class Turning
{
public:
    using Turn = void (Cube::*)(); // make code easier to read
    
    // iterator for for_each loops or pythonic for loops
    using iterator = TurnIterator; 

    // get the instance of the singleton class
    static Turning& init() { return instance; }

    // returns function pointer to the requested turning function
    inline Turn operator[](size_t index) { return _TURNS[index]; }
    
    // Creates new cube and turns it out of place
    Cube& operator()(size_t, const Cube&);
    Cube& operator()(Turn,  const Cube&);

    iterator begin()
    {
    }
private:
    Turning();
    static Turning& instance;
    static constexpr Turn _TURNS[18] = {
        Cube::L , Cube::R , Cube::U , Cube::D , Cube::F , Cube::B ,
        Cube::L_, Cube::R_, Cube::U_, Cube::D_, Cube::F_, Cube::B_,
        Cube::L2, Cube::R2, Cube::U2, Cube::D2, Cube::F2, Cube::B2
    };
};

class TurnIterator
{
public:
    using value_t = Turning::Turn;
    using ptr_t = value_t*;
    using ref_t = value_t&;

    TurnIterator(ptr_t ptr);
};