#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

bool is_cycle_in_significant_cycles(int cycle)
{
    return cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140
    || cycle == 180 || cycle == 220;
}

//20th, 60th, 100th, 140th, 180th, and 220th cycles
int main()
{
    std::ifstream in("input");
    std::string line;
    int cycle{1};
    int x{1};
    int sig{0};
    std::string text{""};
    while(std::getline(in, line))
    {
        std::stringstream s{line};
        std::string tmp;
        s >> tmp;
        text += line + "\n";
        if(tmp == "noop")
        {
            cycle++;
        }
        else if(tmp == "addx")
        {
            cycle +=2;
        }
    }
    std::stringstream s{text};
    std::string tmp;
    bool adding{false};
    bool next{false};
    std::map<int, int> pixels;
    for(int i{0}; i < cycle; i++)
    {
        if(is_cycle_in_significant_cycles(i))
        {
            sig += x * i;
        }
        if(is_cycle_in_significant_cycles(i+20) && i != 0)
        {
            std::cout << std::endl;
        }
        
        if(next)
        {
            x += std::stoi(tmp);
            next = false;
        }
        if(x  == i % 40 || (x + 1)  == i % 40 || (x - 1) == i % 40)
        {
            std::cout << "#";
        }
        else
        {
            std::cout << ".";
        }
        s >> tmp;
        if(adding)
        {
            next = true;
            adding = false;
        }
        if(tmp == "addx")
        {
            adding = true;
        }
    }
    std::cout << std::endl;
    in.close();
    std::cout << "Suma de los ciclos: " << sig << std::endl;
}