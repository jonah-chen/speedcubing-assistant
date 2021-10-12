/*
Move sequence or scrambler is a easy way to input moves (either human moves or scrambles)
using various formats like:
    - human readable scrambles
    - lists of sequence of moves (that often comes from search)
in a unified and convenient manner to be stored or processed or visualized.
*/

#pragma once
#include "cube.hpp"
#include "turning.hpp"

#include <list>   // means of storage
#include <string> // c style strings are a little unstable

class MoveSequence
{
public:
    MoveSequence() : moves() {}                                     // construct empty moveseq
    MoveSequence(const std::list<int16_t>& moves) : moves(moves) {} // construct from list
    MoveSequence(const std::string&);                               // construct from string (or scramble)
    MoveSequence(const MoveSequence& other) : moves(other.moves) {} // copy constructor

    // prints out the sequence in human readable form
    friend std::ostream& operator<<(std::ostream&, const MoveSequence&);

    // adds one turn to the back of the sequence
    inline void push_back(int16_t i) { moves.push_back(i); }

    // joins another sequence to the back of the sequence
    inline void concat(const MoveSequence& after) 
    { 
        moves.insert(moves.end(), 
                    after.moves.begin(), 
                    after.moves.end()
                    ); 
    }
    
    // returns the length of the sequence
    inline size_t len() { return moves.size(); }

    // executes the moves onto a cube.
    Cube execute(const Cube&) const;
    void execute_inplace(Cube&) const;

private:
    std::list<int16_t> moves; // stores moves as list. not array.
};