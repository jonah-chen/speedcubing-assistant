/*
common/common.hpp contains the common resources shared within the entire project. 
The common files for specific parts of the project are stored in common.hpp in their specific location. 
*/


#pragma once
#include <cstdint> // fixed width int types
/*
representation of the colors stored in arrays
*/
#define WHITE 0
#define YELLOW 3
#define ORANGE 1
#define RED 4
#define GREEN 2
#define BLUE 5

/*
Human Readable Macros
*/
#define COLOR_H(COLOR) ((COLOR)==WHITE?"W":(\
                        (COLOR)==BLUE?"B":(\
                        (COLOR)==YELLOW?"Y":(\
                        (COLOR)==GREEN?"G":(\
                        (COLOR)==RED?"R":(\
                        (COLOR)==ORANGE?"O":\
                        "X"))))))


