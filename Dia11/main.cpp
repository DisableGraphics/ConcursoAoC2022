#include <iostream>
#include <fstream>
#include <string>
#include "monkey.hpp"
#include "monkey2.hpp"
#include <vector>
#include <algorithm>

int main()
{
    std::vector<Monkey> monkeys;
    std::vector<Monkey2> monkeys2;
    std::ifstream in("input");
    std::string line;
    std::string text{""};
    int pos{0};
    while(std::getline(in, line))
    {
        if(line == "")
        {
            monkeys.push_back(Monkey(pos, text));
            monkeys2.push_back(Monkey2(pos, text));
            pos++;
            text = "";
        }
        else 
        {
            text += line + "\n";
        }
    }
    for(auto &m : monkeys)
    {
        m.set_vector(&monkeys);
    }
    int superresto{1};
    for(auto &m : monkeys2)
    {
        m.set_vector(&monkeys2);
        superresto *= m.get_test();
    }
    for(auto &m : monkeys2)
    {
        m.set_superresto(superresto);
    }
    for(int i{0}; i < 20; i++)
    {
        for(int i{0}; i < monkeys.size(); i++)
        {
            monkeys[i].give();
        }
    }
    for(int i{0}; i < 10000; i++)
    {
        for(int i{0}; i < monkeys2.size(); i++)
        {
            monkeys2[i].give();
        } 
    }
    std::vector<unsigned long> p2{};
    std::vector<int> p1{};
    for(auto &m : monkeys)
    {
        p1.push_back(m.get_examination_count());
    }
    for(auto &m : monkeys2)
    {
        p2.push_back(m.get_examination_count());
    }
    std::sort(p1.begin(), p1.end());
    std::sort(p2.begin(), p2.end());

    std::cout << "[PARTE 1]: " << p1[p1.size()-1] * p1[p1.size() -2] << std::endl;
    std::cout << "[PARTE 2]: " << p2[p2.size()-1] * p2[p2.size()- 2] << std::endl;
    
    
    in.close();
}