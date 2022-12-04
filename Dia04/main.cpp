#include <iostream>
#include <fstream>
#include <string>
#include "section.h"



Vector2D parse_section(std::string part)
{
    int posguion = part.find("-");
    
    std::string part1 = part.substr(0, posguion);
    std::string part2 = part.substr(posguion + 1, part.size());
    return {std::stoi(part1), std::stoi(part2)};
}

int main()
{
    std::ifstream in("input");
    std::string line;
    section pair1{0, 0};
    section pair2{0,0};
    std::string beforecomma;
    std::string aftercomma;
    int overlap_count{0};
    int overlap_simple_count{0};

    while(std::getline(in, line))
    {
        int commapos = line.find(",");
        beforecomma = line.substr(0, commapos);
        aftercomma = line.substr(commapos+1);
        std::cout << beforecomma << " " << aftercomma << std::endl;
        auto pair1c = parse_section(beforecomma);
        auto pair2c = parse_section(aftercomma);
        pair1.new_pair(pair1c.x, pair1c.y);
        pair2.new_pair(pair2c.x, pair2c.y);
        if(pair1 <= pair2 || pair2 <= pair1)
        {
            overlap_count++;
        }
        
        if(pair1 < pair2 || pair2 < pair1)
        {
            overlap_simple_count++;
            std::cout << R"(
  ^
  |
MATCH
)";
        }
    }
    in.close();
    std::cout << "Solapamiento total: " << overlap_count << std::endl;
    std::cout << "Solapamiento: " << overlap_simple_count << std::endl;
}