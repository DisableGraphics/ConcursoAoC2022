#include "rope.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

class LongRope
{
    public:
        LongRope()
        {
            for(int i = 0; i < 10; i++)
            {
                knots.push_back(std::make_pair(0,0));
            }
            tail_positions.insert(std::make_pair(0,0));
        }
        void move(Direction dir, int number)
        {
            switch(dir)
            {
                case UP:
                    for(int i{0}; i < number; i++)
                    {
                        knots[0] = std::make_pair(knots[0].first, knots[0].second + 1);
                        for(int i = 1; i < 10; i++)
                        {
                            calculate_tail_position(knots[i-1], knots[i]);
                        }
                        tail_positions.insert(knots[9]);
                    }
                    break;
            
                case DOWN:
                    for(int i{0}; i < number; i++)
                    {
                        knots[0] = std::make_pair(knots[0].first, knots[0].second - 1);
                        for(int i = 1; i < 10; i++)
                        {
                            calculate_tail_position(knots[i-1], knots[i]);
                        }
                        tail_positions.insert(knots[9]);
                    }
                    break;
            
                case RIGHT:
                    for(int i{0}; i < number; i++)
                    {
                        knots[0] = std::make_pair(knots[0].first + 1, knots[0].second);
                        for(int i = 1; i < 10; i++)
                        {
                            calculate_tail_position(knots[i-1], knots[i]);
                        }
                        tail_positions.insert(knots[9]);
                    }
                    break;
                case LEFT:
                    for(int i{0}; i < number; i++)
                    {
                        knots[0] = std::make_pair(knots[0].first - 1, knots[0].second);
                        for(int i = 1; i < 10; i++)
                        {
                            calculate_tail_position(knots[i-1], knots[i]);
                        }
                        tail_positions.insert(knots[9]);
                    }
                    break;
            }
        }

        void calculate_tail_position(std::pair<int, int>&head, std::pair<int, int> &tail)
        {
            if(head == tail)
            {
                //Si no pongo un return en estos casos aparentemente aislados
                //Se me va a colar en otros casos que no quiero
                //Y me va a contar mal los movimientos de la cola
                return;
            }
            else if(head.first == tail.first && abs(head.second - tail.second) == 1)
            {
                return;
            }
            else if(head.second == tail.second && abs(head.first - tail.first) == 1)
            {
                return;
            }
            else if(head.first == tail.first)
            {
                if(tail.second > head.second)
                {
                    tail = std::make_pair(tail.first, tail.second - 1);
                }
                else 
                {
                    tail = std::make_pair(tail.first, tail.second + 1);
                }
            }
            else if(head.second == tail.second)
            {
                if(tail.first > head.first)
                {
                    tail = std::make_pair(tail.first - 1, tail.second);
                }
                else
                {
                    tail = std::make_pair(tail.first + 1, tail.second);
                }
            }
            else if(abs(head.first - tail.first) == 1 && abs(head.second - tail.second) == 1)
            {
                return;
            }
            else if(abs(head.first - tail.first) == 1)
            {
                if(tail.second > head.second)
                {
                    tail = std::make_pair(head.first, tail.second - 1);
                }
                else
                {
                    tail = std::make_pair(head.first, tail.second + 1);
                }
            }
            else if(abs(head.second - tail.second) == 1)
            {
                if(tail.first > head.first)
                {
                    tail = std::make_pair(tail.first - 1, head.second);
                }
                else
                {
                    tail = std::make_pair(tail.first + 1, head.second);
                }
            }
            else 
            {
                int dx[4] = {1,1,-1,-1};
                int dy[4] = {1,-1,1,-1};
                for(int i{0}; i < 4; i++)
                {
                    if(abs(tail.first + dx[i] - head.first) == 1 && abs(tail.second + dy[i] - head.second) == 1)
                    {
                        tail = std::make_pair(tail.first + dx[i], tail.second + dy[i]);
                        break;
                    }
                }
            }
        }
        int get_tail_positions()
        {
            return tail_positions.size();
        }
    private:
        std::set<std::pair<int, int>> tail_positions;
        std::vector<std::pair<int, int>> knots;
};