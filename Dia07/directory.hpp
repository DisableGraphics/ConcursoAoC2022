#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

class Directory 
{
    public:
        Directory(std::string path)
        {
            this->path = path; 
            
        } 
        void add_element(std::string element)
        {
            std::stringstream s{element};
            std::string tmp;
            s >> tmp;
            if(tmp == "dir")
            {
                s >> tmp;
                children_directories.push_back(path + tmp + "/");
            }
            else 
            {
                int size = std::stoi(tmp);
                s >> tmp;
                children_files[size] = tmp;
            }
        }
        unsigned long calculate_size()
        {
            unsigned long size;
            for(auto &p : children_files)
            {
                size += p.first;
            }
            /*for(auto &d : children_directories)
            {
                size += d->calculate_size();
            }*/
            return size;
        }

    private:
        std::string path;
        std::map<int, std::string> children_files;
        std::vector<std::string> children_directories;
};