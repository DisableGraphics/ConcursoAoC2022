#include <iostream>
#include <fstream>
#include <pthread.h>
#include <sstream>
#include <string>
#include "stack.hpp"
#include "parser.hpp"

int main()
{
    std::ifstream in("input");
    std::vector<Stack> stacks;
    std::vector<Stack> stacks2;
    std::vector<std::string> stack_lines;
    std::string line;
    int counter{0};
    for(int i{0}; i < 9; i++)
    {
        stacks.push_back(*new Stack());
    }
    while(std::getline(in, line))
    {
        if(counter >= 8)
        {
            break;
        }
        stack_lines.push_back(line);
        counter++;
    }
    Parser p{stack_lines};
    p.traspose(stacks);
    stacks2 = stacks;

    std::getline(in, line);
    while(std::getline(in, line))
    {
        std::cout << "------------------------------\n";
        std::cout << line <<std::endl;
        std::stringstream s{line};
        std::string tmp;
        int origin, destination, quantity; 
        s >> tmp;
        s >> tmp;
        quantity = std::stoi(tmp);
        s >> tmp;
        s >> tmp;
        origin = std::stoi(tmp);
        s >> tmp;
        s >> tmp;
        destination = std::stoi(tmp);
        std::cout << "[ORIGIN] ";
        stacks2[origin-1].print();
        std::cout << "[DESTINATION] ";
        stacks2[destination-1].print();
        stacks2[destination-1].push_multiple(stacks2[origin-1].get_crates(quantity));
        for(int i{0}; i < quantity; i++)
        {
            stacks[destination-1].push(stacks[origin-1].pop());
        }
        std::cout << "[ORIGIN] ";
        stacks2[origin-1].print();
        std::cout << "[DESTINATION] ";
        stacks2[destination-1].print();

    }


    //Part 1
    for(auto &s : stacks)
    {
        std::cout << s.pop();
    }
    std::cout << std::endl;
    //Part 2
    for(auto &s : stacks2)
    {
        std::cout << s.pop();
    }
    std::cout << std::endl;
    in.close();
}