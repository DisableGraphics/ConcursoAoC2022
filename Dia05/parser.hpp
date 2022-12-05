#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "stack.hpp"
class Parser 
{
    public:
        Parser(std::vector<std::string> toParse)
        {
            parsed = toParse;

            for(auto &p : parsed)
            {
                std::cout << p << std::endl;
            }
            std::cout << "-----------------------------\n";
            
            reverse_lines();
            for(auto &p : parsed)
            {
                std::cout << p << std::endl;
            }
        }
        void reverse_lines()
        {
            std::reverse(parsed.begin(), parsed.end());
        }
        void traspose(std::vector<Stack> &stacks)
        {
            std::cout << "Parsing\n------------------------------------\n";
            for(int j{0}; j < parsed.size(); j++)
            {
                for(int i{0}; i < parsed[j].size(); i++)
                {
                    if(parsed[j][i] != ' ' && parsed[j][i] != '[' && parsed[j][i] != ']')
                    {
                        stacks[(i - 1) / 4].push(parsed[j][i]);
                    }
                }
            }
            for(auto &s: stacks)
            {
                s.print();
            }
        }
        
    private:
        std::vector<std::string> parsed = {};
};