#include <iostream>
#include <fstream>
#include <sstream>
#include "rope.hpp"
#include "longrope.hpp"

int main()
{
    std::ifstream in("input");
    std::string line;
    Rope r;
    LongRope longy;
    
    int numerodemovimientos{0};
    while(std::getline(in, line))
    {
        std::stringstream s{line};
        std::string instruction, times;
        s >> instruction;
        s >> times;
        Direction d;
        if(instruction == "R")
        {
            d = RIGHT;
        }
        else if(instruction == "L")
        {
            d = LEFT;
        }
        else if(instruction == "U")
        {
            d = UP;
        }
        else if(instruction == "D")
        {
            d = DOWN;
        }
        int times_c = std::stoi(times);
        r.move(d, times_c);
        longy.move(d, times_c);
    }
    std::cout << "Movimientos de la cola de la soga corta: " << r.get_tail_positions() << std::endl;
    std::cout << "Movimientos de la cola de la soga larga: " << longy.get_tail_positions() << std::endl;
    in.close();
}