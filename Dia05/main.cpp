#include <iostream>
#include <fstream>
#include <pthread.h>
#include <sstream>
#include "stack.hpp"
#include "parser.hpp"

int main()
{
    std::ifstream in("input");
    std::vector<Stack> stacks;
    std::vector<std::string> stack_lines;
    std::string line;
    for(int i{0}; i < 9; i++)
    {
        stacks.push_back(*new Stack());
        getline(in, line);
        stack_lines.push_back(line);
    }
    std::string toBeParsed{""};
    for(auto &p : stack_lines)
    {
        std::cout << p << std::endl;
        toBeParsed += p + "\n";
    }
    Parser p{toBeParsed};
    for(int i{0}; i < p.traspose().size(); i++)
    {
        auto v  = p.traspose()[i];
        for(auto &c : v)
        {
            stacks[i].push(c);
        }
    }
    std::getline(in, line);
    while(std::getline(in, line))
    {
        std::cout << line<<std::endl;
        std::stringstream s {line};
        std::string tmp;
        s >> tmp;
        s >> tmp;
        int times = std::stoi(tmp);
        s >> tmp;
        s >> tmp;
        int origin = std::stoi(tmp);
        s >> tmp;
        s >> tmp;
        int destination = std::stoi(tmp);
        std::cout << times << "  " << origin << "  " << destination << std::endl;
        for(int i{0}; i < times; i++)
        {
            auto p = stacks[origin-1].pop();
            std::cout << p << std::endl;
            stacks[destination-1].push(p);
        }
    }
    in.close();

    for(auto &o : stacks)
    {
        std::cout << "" <<o.pop() << "";
    }
    std::cout << std::endl;
}