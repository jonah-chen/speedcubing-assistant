/*
Implements helpers and methods for the move sequence class
*/

#include "moveseq.hpp"
#include <sstream> // stringstream

// helper function to find the id of a particular move
static int16_t find_id_by_str(std::string str)
{
    for (int16_t i=0; i<TURN_OPTIONS; ++i)
        if (! strcmp(Turning::STRS[i], str.c_str()))
            return i;
    std::cout << str << " is not a valid turn string\n";
    return -1;
}

// helper function to parse a list of moves from a scramble
static std::list<int16_t> parse_string(const std::string& str)
{
    std::list<int16_t> moves;
    std::stringstream ss(str);
    std::string turn;
    while (std::getline(ss, turn, ' '))
        moves.push_back(find_id_by_str(turn));
    return moves;
}

// constructor from scramble
MoveSequence::MoveSequence(const std::string& str)
    : moves(parse_string(str)) {}

// debug print operator
std::ostream& operator<<(std::ostream& os, const MoveSequence& moves)
{
    for (int16_t move : moves.moves)
        os << Turning::STRS[move] << " ";
    os << std::endl;
    return os;
}

Cube MoveSequence::execute(const Cube& start_state) const
{
    Cube c(start_state);
    execute_inplace(c);
    return c;
}

void MoveSequence::execute_inplace(Cube& cube) const
{
    Turning& turner = Turning::init();
    for (int16_t move : moves)
        (cube.*turner[move])();
}