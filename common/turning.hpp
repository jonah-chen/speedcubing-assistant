/*
Turning class is a singleton class that organizes the for turning the cube (defined in cube.hpp) 
in a way that is convenient to iterate through to perform searches.

Usage:
    - To get the object use Turning::init()
    - Turn the cube while making a new cube 
    - Iterate through the different turns using foreach loop
*/

#pragma once
#include "cube.hpp"

#define TURN_OPTIONS 18

class Turning
{
public:
    Turning(const Turning&) = delete; // delete copy constructor
    Turning& operator=(const Turning&) = delete; // delete assignment operator

    using Turn = void (Cube::*)(); // make code easier to read

    // get the instance of the singleton class
    static inline Turning& init() { return instance; }

    // returns function pointer to the requested turning function
    // primarily used for debugging purposes
    // for regular use, use the iterator
    inline Turn operator[](size_t index) { return TURNS[index]; }
    
    // Creates new cube and turns it out of place
    Cube operator()(size_t, const Cube&) const;
    Cube operator()(Turn,  const Cube&) const;

    // Finding the index of the turn
    int16_t find(Turn) const;

    // Finding the string from index
    inline const char* str(int16_t id) { return STRS[id]; };

    // finding string from turn
    inline const char* str(Turn turn) { return str(find(turn)); }



    // iterator for for_each loops or pythonic for loops
    class Iterator
    {
    public:
        using value_t = Turning::Turn;
        using ptr_t = value_t*;

        Iterator(ptr_t ptr) noexcept : cur_ptr(ptr) {}

        Iterator& operator++() noexcept;
        Iterator operator++(int) noexcept;

        inline bool operator!=(const Iterator& other) const noexcept { return cur_ptr != other.cur_ptr; };

        inline value_t operator*() const noexcept { return *cur_ptr; }
    private:
        ptr_t cur_ptr;
    };

    // iterator begin and end
    inline Iterator begin() const noexcept 
    { 
        return Iterator(
            const_cast<Iterator::ptr_t>(TURNS)
            ); 
    }
    inline Iterator end() const noexcept
    { 
        return Iterator(
            const_cast<Turn*>(TURNS+TURN_OPTIONS)
            ); 
    }

    // array of all the cube turns
    static constexpr Turn TURNS[TURN_OPTIONS] = {
        &Cube::L ,&Cube::R ,&Cube::U ,&Cube::D ,&Cube::F ,&Cube::B ,
        &Cube::L_,&Cube::R_,&Cube::U_,&Cube::D_,&Cube::F_,&Cube::B_,
        &Cube::L2,&Cube::R2,&Cube::U2,&Cube::D2,&Cube::F2,&Cube::B2
    };

    // human readable strings for moves
    static constexpr const char* STRS[TURN_OPTIONS] = {
        "L"  ,"R"  ,"U"  ,"D"  ,"F"  ,"B"  ,
        "L\'","R\'","U\'","D\'","F\'","B\'",
        "L2" ,"R2" ,"U2" ,"D2" ,"F2" ,"B2" 
    };

private:
    Turning() {} // make default constructor private

    static Turning instance; // the singleton instance
};
