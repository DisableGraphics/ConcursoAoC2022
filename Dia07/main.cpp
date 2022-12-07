#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "directory.hpp"

int main()
{
    std::ifstream in("inputt");
    std::string line;
    std::string current_directory{""};
    std::map<std::string, Directory> directories; 
    bool parsing_dir_contents{false};
    int dir_size_count{0};
    while(std::getline(in, line))
    {
        //It is a command
        if(line.find("$") != std::string::npos)
        {
            
        }
        else 
        {
           
        }
        std::cout << line << std::endl;
    }
    
    in.close();
}