#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    // Part 1
    std::ifstream in{"input"};
    std::string line;
    std::vector<int> calories;
    int calories_sum{0};
    while(std::getline(in, line))
    {
        if(line != "")
        {
            calories_sum += std::stoi(line);
        }
        else
        {
            calories.push_back(calories_sum);
            calories_sum = 0;
        }
    }
    std::sort(calories.begin(), calories.end()); 
    std::cout << "Calorías máximas: " << calories.back() << std::endl;
    // Part 2
    std::cout << "Los 3 elfos con más calorías tienen " << calories[calories.size() -1] + calories[calories.size() -2] + calories[calories.size() - 3] << " calorías entre ellos" << std::endl; 
}