/*
Define the method bodies for the Turning class and its iterators
*/
#include "turning.hpp"

using iter_t = Turning::Iterator; // I type pretty slow

// instantiate static variables
Turning Turning::instance; 
constexpr Turning::Turn Turning::TURNS[TURN_OPTIONS];
constexpr const char* Turning::STRS[TURN_OPTIONS];

Cube Turning::operator()(size_t index, const Cube& cube) const
{
    Cube c(cube); // use the copy constructor
    (c.*TURNS[index])();
    return c;
}

Cube Turning::operator()(Turn turn, const Cube& cube) const
{
    Cube c(cube);
    (c.*turn)();
    return c;
}

int16_t Turning::find(Turn turn) const
{
    for (int16_t i = 0; i < TURN_OPTIONS; ++i)
        if (turn == TURNS[i])
            return i;
    return -1;
}

iter_t& iter_t::operator++() noexcept
{
    ++cur_ptr;
    return *this;
}

iter_t iter_t::operator++(int) noexcept
{
    Iterator tmp = *this; 
    ++cur_ptr;
    return tmp;
}

