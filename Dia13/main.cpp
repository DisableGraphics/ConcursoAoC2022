#include <iostream>
#include <fstream>
#include "list.hpp"

bool is_in_correct_order(List &l1, List &l2)
{

}

int main()
{
    std::ifstream in("input");
    std::string line;
    std::string pair1;
    std::string pair2;
    bool pair1_gen{true};
    while(std::getline(in, line))
    {
        if(line == "")
        {

        }
        else 
        {
            if(pair1_gen)
            {
                pair1 = line;
                pair1_gen = false;
            }   
            else 
            {
                pair2 = line;
                pair1_gen = true;
            }
        }
    }
    in.close();
}