#include <iostream>
#include <fstream>


int get_maximum_levels(const std::string &arr)
{
    int max{0};
    int current_level{0};
    for(int i{0}; i < arr.size(); i++)
    {
        if(arr[i] == '[')
        {
            current_level++;
        }
        else if(arr[i] == ']')
        {
            current_level--;
        }
        if(current_level > max)
        {
            max = current_level;
        }
    }
    return max;
}

//A level begins with a "[" and ends with the corresponding "]".
//There can be nested levels within a level, so the number of "[" and "]" will always be the same.
//The first level contains all the elements between the first [ and the first ], but not recursively.
//That is, the first level contains all the elements between the first [ and the first ] that are not themselves enclosed in another pair of brackets.
//And every element in the same level is separated by a comma.
int number_of_elements(const std::string &arr, int level = 0)
{
    int return_number{0};
    int current_level{0};
    for(int i{0}; i < arr.size(); i++)
    {
        if(arr[i] == '[')
        {
            current_level++;
        }
        else if(arr[i] == ']')
        {
            current_level--;
        }
        else if((arr[i] != ',' || arr[i] == ',' && arr[i+1] == '[' )&& current_level == level)
        {
            return_number++;
        }
    }
    
    return return_number;
}


bool is_in_correct_order(const std::string &pair1, const std::string &pair2)
{
    int depthlevel1{0};
    int depthlevel2{0};
    std::cout << number_of_elements(pair1, 2) << " " << number_of_elements(pair2, 2);
    std::cout << " Max_levels: " << get_maximum_levels(pair1) << " " << get_maximum_levels(pair2) << std::endl;
    /*for(int i{0}; i < pair1.size(); i++)
    {
        if(pair1[i] != pair2[i])
        {
            try 
            {
                std::string test{pair1[i]};
                int n1 = std::stoi(test);
                test = pair2[i];
                int n2 = std::stoi(test);
                if(n1 > n2)
                {
                    return false;
                }
                else if(n1 < n2)
                {
                    return true;
                }

            } catch (std::exception &e) 
            {
                std::cout << "Distinto\n";
            }   
        }
    }*/
}

int main()
{
    std::ifstream in("inputt");
    std::string line;
    std::string pair1;
    std::string pair2;
    std::string pair3;
    bool pair1_gen{true};
    while(std::getline(in, line))
    {
        if(line == "")
        {
            is_in_correct_order(pair1, pair2);
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