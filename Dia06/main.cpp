#include <iostream>
#include <fstream>

int number_of_times(std::string str, char c)
{
    int r{0};
    for(auto &p : str)
    {
        if(p == c)
            r++;
    }
    return r;
}

int main()
{
    std::ifstream in("input");
    std::string line;
    std::string chars;
    std::string chars2;
    int index{0};
    int index2{0};
    bool found[4] = {false, false, false, false};
    bool found_message_marker[14];
    bool continue_t_m = true;
    std::getline(in, line);
    
    for(int i{0}; i < line.size(); i++)
    {
        //Part 1 code
        if(continue_t_m)
        {
            for(auto &b : found)
            {
                b = false;
            }
            std::string p{""};
            p += line[i];
            p += line[i+1];
            p += line[i+2];
            p += line[i+3];
            for(int i{0}; i < p.size(); i++)
            {
                char s = p[i];
                if(number_of_times(p, s) == 1)
                {
                    found[i] = true;
                }
            }
            if(found[0] == true && found[1] == true && found[2] == true && found[3] == true)
            {
                chars = p;
                index = line.find(p)+4;
                continue_t_m = false;
            } 
        }
        //Part 2 code
        for(auto &b : found_message_marker)
        {
            b = false;
        }
        
        std::string m{""};
        
        for(int j{0}; j < 14; j++)
        {
            m += line[j + i];
        }
        
        
        for(int j{0}; j < m.size(); j++)
        {
            char c = m[j];
            if(number_of_times(m, c) == 1)
            {
                found_message_marker[j] = true;
            }
        }
        if(found_message_marker[0] == true && 
            found_message_marker[1] == true &&
            found_message_marker[2] == true &&
            found_message_marker[3] == true &&
            found_message_marker[4] == true &&
            found_message_marker[5] == true &&
            found_message_marker[6] == true &&
            found_message_marker[7] == true &&
            found_message_marker[8] == true &&
            found_message_marker[9] == true &&
            found_message_marker[10] == true &&
            found_message_marker[11] == true &&
            found_message_marker[12] == true &&
            found_message_marker[13] == true)
        {
            chars2 = m;
            index2 = line.find(m) + 14;
            //I did this on the basis that it will be later in the string that I find the message header
            //than the transmission header
            break;
        }
        
    }
    //Part 1
    std::cout << "[HEADER DE TRANSMISIÓN]: " << chars << std::endl;
    std::cout << "[CARACTERES PROCESADOS]: " << index << std::endl;

    //Part 2
    std::cout << "[HEADER DE MENSAJE]: " << chars2 << std::endl;
    std::cout << "[CARACTERES PROCESADOS]: " << index2 << std::endl;
    in.close();
}