#include <iostream>
#include <fstream>
#include <string>

int get_priority(const std::string &duplicates)
{
    int ret{0};
    if(duplicates.size() != 0)
    {
        auto d = duplicates[0];
        if(d >= 'A' && d <= 'Z')
        {
            ret += (d - 38);
        }
        else
        {
            ret += (d - 96);
        }
    }
        
    
    return ret;
}

std::string get_duplicates(const std::string &firstHalf, const std::string &secondHalf)
{
    std::string ret{""};
    for(auto &p : firstHalf)
    {
        if(secondHalf.find(p) != std::string::npos)
        {
            ret += p;
        }
    }
    return ret;
}

std::string get_badge(const std::string&firstLine, const std::string&secondLine, const std::string&thirdLine)
{
    std::string first = get_duplicates(firstLine, secondLine);
    std::string second = get_duplicates(secondLine, thirdLine);
    return get_duplicates(first, second);
}

int main()
{
    std::ifstream in("input");
    std::string line;
    std::string firstHalf;
    std::string secondHalf;
    int priorities{0};
    
    while(std::getline(in, line))
    {
        firstHalf = line.substr(0, line.size()/2);
        secondHalf = line.substr((line.size()/2), line.size());
        std::string dups = get_duplicates(firstHalf, secondHalf);
        priorities += get_priority(dups);
    }
    std::cout << "Prioridad total: " << priorities << std::endl;
    in.close();
    in.open("input");
    priorities = 0;
    int count{0};
    std::string firstLine;
    std::string secondLine;
    std::string thirdLine;
    while(std::getline(in, line))
    {
        switch(count)
        {
            case 0:
                firstLine = line;

                
                break;
            case 1:
                secondLine = line;
                break;
            case 2:
                thirdLine = line;
                priorities += get_priority(get_badge(firstLine, secondLine, thirdLine));
                count = -1;
                break;
        }
        count++;
        
    }
    std::cout << "Prioridad total de las insignias: " << priorities << std::endl;
}