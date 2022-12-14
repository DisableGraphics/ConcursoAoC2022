#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef struct 
{
    int x;
    int y;
} vector2d;

int main()
{
    std::ifstream in("input");
    std::string line;
    std::vector<vector2d> rock_points{};
    while(std::getline(in, line))
    {
        //std::cout << line << std::endl;
        int previous{0};
        vector2d r{0,0};
        bool n1{true};
        int y{0};
        std::vector<vector2d> rock_points2{};
        for(int i{0}; i < line.size(); i++)
        {
            
            //Numbers separated with commas and every pair of numbers is separated with this exact string " -> "
            //and an extra pair exists at the end of the line
            if(line[i] == ',' || line[i] == ' ' || line[i] == '-' || line[i] == '>' || i == line.size() - 1)
            {
                std::string number{line.substr(previous, i - previous)};
                if(i == line.size() - 1)
                    number += line[i];
                previous = i + 1;
                if(number != "")
                {
                    int n = std::stoi(number);
                    if(n1)
                    {
                        r.x = n;
                        n1 = false;
                    }
                    else
                    {
                        r.y = n;
                        n1 = true;
                        if(rock_points2.size() != 0)
                        {
                            if(r.x != rock_points2.back().x)
                            {
                                bool bigger = r.x > rock_points2.back().x;
                                if(bigger)
                                {
                                    for(int i{rock_points2.back().x + 1}; i < r.x; i++)
                                    {
                                        vector2d v{i, rock_points2.back().y};
                                        rock_points2.push_back(v);
                                    }
                                }
                                else
                                {
                                    for(int i{rock_points2.back().x - 1}; i > r.x; i--)
                                    {
                                        vector2d v{i, rock_points2.back().y};
                                        rock_points2.push_back(v);
                                    }
                                }
                            }
                            else if(r.y != rock_points2.back().y)
                            {
                                bool bigger = r.y > rock_points2.back().y;
                                if(bigger)
                                {
                                    for(int i{rock_points2.back().y + 1}; i < r.y; i++)
                                    {
                                        vector2d v{rock_points2.back().x, i};
                                        rock_points2.push_back(v);
                                    }
                                }
                                else
                                {
                                    for(int i{rock_points2.back().y - 1}; i > r.y; i--)
                                    {
                                        vector2d v{rock_points2.back().x, i};
                                        rock_points2.push_back(v);
                                    }
                                }
                            }
                        }
                        rock_points2.push_back(r);
                    }
                }
            }
        }
        for(auto &v : rock_points2)
        {
            rock_points.push_back(v);
        }
        
    }
    int max_y{0};
    for(auto &v : rock_points)
    {
        if(v.y > max_y)
            max_y = v.y;
    }
    
    std::sort(rock_points.begin(), rock_points.end(), [](vector2d &v1, vector2d &v2) -> bool
    {
        if(v1.x == v2.x)
        {
            return v1.y < v2.y;
        }
        return v1.x < v2.x;
    });
    
    for(int i{0}; i <= max_y; i++)
    {
        for(int j{rock_points[0].x}; j <= rock_points.back().x; j++)
        {
            if(i == 0 && j == 500)
            {
                std::cout << "+";
                continue;
            }
            bool found{false};
            for(auto &v : rock_points)
            {
                if(v.x == j && v.y == i)
                {
                    std::cout << "#";
                    found = true;
                    break;
                }
            }
            if(!found)
                std::cout << " ";
        }
        std::cout << std::endl; 
    }
    
    std::vector<vector2d> sands{};
    bool to_the_end{false};
    while(!to_the_end)
    {
        vector2d sand{500, 0};
        bool dor{true};
        while(dor)
        {
            sand.y++;
            if(sand.y > max_y)
            {
                to_the_end = true;
                break;
            }
            //Rules for the sand:
            //1. If the sand is over a rock or another sand, it stops unless:
            //  1.1 It can move one step down to the left
            //  1.2 It can move one step down to the right
            // That is in order (That means, if it can move one step down to the left, it will do it, with preference to the left)
            //2. If the sand is over a space, it will move one step down

            //Check if the sand is over a rock or another sand
            bool over_rock{false};
            bool over_sand{false};
            for(auto &v : rock_points)
            {
                if(v.x == sand.x && v.y == sand.y + 1)
                {
                    over_rock = true;
                    break;
                }
            }
            for(auto &v : sands)
            {
                if(v.x == sand.x && v.y == sand.y + 1)
                {
                    over_sand = true;
                    break;
                }
            }
            if(over_rock || over_sand)
            {
                //Check if the sand can move one step down to the left
                bool can_move_left{true};
                
                for(auto &v : sands)
                {
                    if(v.x == sand.x - 1 && v.y == sand.y + 1)
                    {
                        can_move_left = false;
                        break;
                    }
                }
                if(can_move_left)
                {
                    for(auto &v : rock_points)
                    {
                        if(v.x == sand.x - 1 && v.y == sand.y + 1)
                        {
                            can_move_left = false;
                            break;
                        }
                    }
                }
                if(can_move_left)
                {
                    sand.x--;
                    continue;
                }
                //Check if the sand can move one step down to the right
                bool can_move_right{true};
                
                for(auto &v : sands)
                {
                    if(v.x == sand.x + 1 && v.y == sand.y + 1)
                    {
                        can_move_right = false;
                        break;
                    }
                }
                if(can_move_right)
                {
                    for(auto &v : rock_points)
                    {
                        if(v.x == sand.x + 1 && v.y == sand.y + 1)
                        {
                            can_move_right = false;
                            break;
                        }
                    }
                }
                if(can_move_right)
                {
                    sand.x++;
                    continue;
                }
                //If it can't move one step down to the left or to the right, it stops
                dor = false;
                sands.push_back(sand);
                break;
            }
        }
    }
    std::vector<vector2d> sands2{};
    bool to_the_end2{false};
    std::cout << max_y << std::endl;
    /*
        The idea for the second part is to create a triangle of sand and eliminate the sand that 
        can't appear due to the sand falling rules
    */
    
    std::cout << "[PARTE 1]: " << sands.size() << std::endl;
    std::cout << "[PARTE 2]: " << sands2.size() << std::endl;
    in.close();
}