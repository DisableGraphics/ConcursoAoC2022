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
        void add_children_directory(std::string dir)
        {
            if(!dir_exists_in_children(dir))
            {
                children_directories.push_back(dir);
            }
        }
        std::vector<std::string> get_child_directories()
        {
            return children_directories;
        }
        unsigned long calculate_size()
        {
            size = 0;
            for(auto &p : children_files)
            {
                size += p.first;
            }
            return size;
        }
        void add_extra_size(unsigned long i)
        {
            size += i;
        }
        unsigned long get_size()
        {
            return size;
        }
        std::string get_path()
        {
            return path;
        }

    private:
        unsigned long size{0};
        std::string path;
        std::map<int, std::string> children_files;
        std::vector<std::string> children_directories;
        bool dir_exists_in_children(std::string dir)
        {
            for(auto &d : children_directories)
            {
                if(dir == d)
                    return true;
            }
            return false;
        }
};