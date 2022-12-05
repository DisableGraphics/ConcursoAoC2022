#pragma once
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

class Stack
{
    public:
        Stack()
        {

        }
        void push(char crate)
        {
            crates.push_back(crate);
        }
        void push_multiple(std::string crat)
        {
            crates += crat;
        }
        char pop()
        {
            char ret = crates.back();
            
            crates.pop_back();
            return ret;
        }
        void remove_useless_characters()
        {
            for (int i{0}; i < crates.size(); i++)
            {
                if(crates[i] == ']' || crates[i] == '[' || crates[i] == ' ')
                {
                    crates.erase(crates.begin() + i);
                }
            }
        }
        void print()
        {
            for(auto &c : crates)
            {
                std::cout << c;
            }
            std::cout << std::endl;
        }
        bool contains(char c)
        {
            for(auto &p : crates)
            {
                if(p == c)
                    return true;
            }
            return false;
        }
        std::string get_crates(int n)
        {
            
            std::string ret{""};
            
            for(auto i{0}; i < n; i++)
            {
                ret += crates.back();
                crates.pop_back();
            }
            std::reverse(ret.begin(), ret.end());
            return ret;
        }
    private:
        std::string crates = "";
};