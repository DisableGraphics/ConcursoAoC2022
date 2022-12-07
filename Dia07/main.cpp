#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <algorithm>
#include "directory.hpp"

/*
    Este programa está dedicado
    a mi profesor de programación,
    por suspenderme la práctica porque no añadí
    7000 funciones auxiliares y la hice
    limpiamente con un sólo bucle.

    Hay que fastidiarse.
    (El programa funcionaba perfectamente)
*/

std::string go_up(std::string directory)
{
    if(directory == "/")
    {
        return "/";
    }
    unsigned long slashpos{0};
    for(auto i{directory.size()-2}; i > 0; i--)
    {
        if(directory[i] == '/')
        {
            slashpos = i;
            break;
        }
    }
    std::string ret{""};
    for(unsigned long i{0}; i <= slashpos; i++)
    {
        ret += directory[i];
    }
    if(ret == "")
    {
        return "/";
    }
    return ret;
}

std::string go_to_dir(std::string current_dir, std::string dir)
{
    if(dir == "/")
        return "/";
    return current_dir + dir + "/";
}

int main()
{
    std::ifstream in("input");
    std::string line;
    std::string current_directory{""};
    std::map<std::string, std::unique_ptr<Directory>> directories; 
    bool parsing_dir_contents{false};
    unsigned long dir_size_count{0};
    unsigned long total_size{70000000};
    int line_n{0};
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
                    std::stringstream s{line};
                    std::string tmp;
                    s >> tmp;
                    s >> tmp;
                    s >> tmp;
                    current_directory = go_to_dir(current_directory, tmp);

                }
            }
            if(line.find("ls") != std::string::npos)
            {
                directories[current_directory] = std::make_unique<Directory>(*new Directory(current_directory));
                if(current_directory != "/")
                {
                    auto dir_check = current_directory;
                    if(current_directory != "/")
                    {
                        while(directories.find(go_up(dir_check)) != directories.end())
                        {
                            directories[go_up(dir_check)]->add_children_directory(current_directory);
                            if(dir_check != "/")
                            {
                                dir_check = go_up(dir_check);
                            }
                            else 
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
        else 
        {
            
            directories[current_directory]->add_element(line);
            
        }
        line_n++;
    }

    for(auto &p : directories)
    {
        for(auto &y : p.second->get_child_directories())
        {
            p.second->add_extra_size(directories[y]->calculate_size());
            
        }
        if(p.second->get_size() <= 100000)
        {
            dir_size_count += p.second->get_size();
        }
    }
    //Part 1
    std::cout << dir_size_count << std::endl;

    auto freespace = total_size - directories["/"]->get_size();
    std::vector<std::pair<unsigned long, std::string>> directories_for_sort{};
    for(auto &direc : directories)
    {
        //directories_for_sort[direc.second->get_size()] = direc.first;
        directories_for_sort.push_back(std::make_pair(direc.second->get_size(), direc.first));
    }
    std::sort(directories_for_sort.begin(), directories_for_sort.end());
    //std::reverse(directories_for_sort.begin(), directories_for_sort.end());

    unsigned long selected_dir;
    for(auto & dir : directories_for_sort)
    {
        if((freespace + dir.first) >= 30000000)
        {
            selected_dir = dir.first;
            break;
        }
    }
    //Part 2
    std::cout << selected_dir << std::endl;
    
    in.close();
}