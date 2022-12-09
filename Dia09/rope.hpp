#pragma once
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <array>


enum Direction
{
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3
};

typedef struct {
    int x;
    int y;
}vector2d;

class Rope
{
    public:
        Rope()
        {
        }
        bool in_grid()
        {
            return (head.x == tail.x && head.y == tail.y + 1)
                || (head.x == tail.x && head.y == tail.y)
                || (head.x == tail.x && head.y == tail.y - 1)
                || (head.x == tail.x-1 && head.y == tail.y + 1)
                || (head.x == tail.x-1 && head.y == tail.y)
                || (head.x == tail.x-1 && head.y == tail.y - 1)
                || (head.x == tail.x+1 && head.y == tail.y + 1)
                || (head.x == tail.x+1 && head.y == tail.y)
                || (head.x == tail.x+1 && head.y == tail.y - 1);
            
        }
        bool in_same_column()
        {
            return (head.x == tail.x);
        }
        bool in_same_row()
        {
            return (head.y == tail.y);
        }
        bool is_in_tails_pos(vector2d position)
        {
            for(auto &p : tail_positions)
            {
                if(p.x == position.x && p.y == position.y)
                {
                    return true;
                }
            }
            return false;
        }
        vector2d compute_tail_position(Direction dir)
        {
            if(!in_grid())
            {
                switch(dir)
                {
                    case UP:
                        if(in_same_column())
                        {
                            while(!in_grid())
                            {
                                tail.y++;
                            }
                        }
                        else
                        {
                            if(tail.x < head.x)
                            {
                                tail.x++;
                                while(!in_grid())
                                {
                                    tail.y++;
                                }
                            }
                            else if(tail.x > head.x)
                            {
                                tail.x--;
                                while(!in_grid())
                                {
                                    tail.y++;
                                }
                            }
                        }
                        break;
                    case DOWN:
                        if(in_same_column())
                        {
                            while(!in_grid())
                            {
                                tail.y--;
                            }
                        }
                        else
                        {
                            if(tail.x < head.x)
                            {
                                tail.x++;
                                while(!in_grid())
                                {
                                    tail.y--;
                                }
                            }
                            else if(tail.x > head.x)
                            {
                                tail.x--;
                                while(!in_grid())
                                {
                                    tail.y--;
                                }
                            }
                        }
                        break;
                    case LEFT:
                        if(in_same_row())
                        {
                            while(!in_grid())
                            {
                                tail.x--;
                            }
                        }
                        else
                        {
                            if(tail.y < head.y)
                            {
                                tail.y++;
                                while(!in_grid())
                                {
                                    tail.x--;
                                }
                            }
                            else if(tail.y > head.y)
                            {
                                tail.y--;
                                while(!in_grid())
                                {
                                    tail.x--;
                                }
                            }
                        }
                        break;
                    case RIGHT:
                        if(in_same_row())
                        {
                            while(!in_grid())
                            {
                                tail.x++;
                            }
                        }
                        else
                        {
                            if(tail.y < head.y)
                            {
                                tail.y++;
                                while(!in_grid())
                                {
                                    tail.x++;
                                }
                            }
                            else if(tail.y > head.y)
                            {
                                tail.y--;
                                while(!in_grid())
                                {
                                    tail.x++;
                                }
                            }
                        }
                        break;
                }  
                if(!is_in_tails_pos(tail))
                {
                    tail_positions.push_back(tail); 
                }
            }
            return {tail.x, tail.y};
        }
        void move(Direction dir, int number)
        {
            for(int i{0}; i < number; i++)
            {
                switch(dir)
                {
                    case UP:
                        head.y++;
                        compute_tail_position(dir);
                        break;
                    case DOWN:
                        head.y--;
                        compute_tail_position(dir);
                        break;
                    case RIGHT:
                        head.x++;
                        compute_tail_position(dir);
                        break;
                    case LEFT:
                        head.x--;
                        compute_tail_position(dir);
                        break;
                }
            }
        }
        int get_tail_positions()
        {
            return tail_positions.size();
        }
    private:
        vector2d head{0,0};
        vector2d tail{0,0};
        std::vector<vector2d> tail_positions;
};