#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "directory.hpp"

std::string go_up(std::string directory)
{
    directory.pop_back();
    auto last_slash_pos = directory.find_first_of("/");
    return directory.substr(0, last_slash_pos-1);
}

std::string go_to_dir(std::string current_dir, std::string dir)
{
    if(dir == "/")
        return "/";
    return current_dir + dir + "/";
}

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
            if(line.find("cd") != std::string::npos)
            {
                if(line.find("..") != std::string::npos)
                {
                    current_directory = go_up(current_directory);
                }
                else
                {
                    
                }
            }
        }
        else 
        {
           
        }
        std::cout << line << std::endl;
    }
    
    in.close();
}