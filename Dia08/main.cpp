#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

bool visible(int x, int y, std::vector<std::vector<int>> &trees)
{
    if(x == 0 || x == trees[0].size() -1 || y == 0 || y == trees.size()-1)
    {
        return true;
    }
    else 
    {
        bool dirs[4];
        for(auto &d : dirs)
        {
            d = true;
        }
        for(int i{x + 1}; i < trees[0].size(); i++)
        {
            if(trees[y][x] <= trees[y][i])
            {
                dirs[0] = false;
                break;
            }
        } 
        for(int i{x - 1}; i >= 0; i--)
        {
            if(trees[y][x] <= trees[y][i])
            {
                dirs[1] = false;
                break;
            }
        } 
        for(int i{y + 1}; i < trees.size(); i++)
        {
            if(trees[y][x] <= trees[i][x])
            {
                dirs[2] = false;
                break;
            }
        } 
        for(int i{y - 1}; i >= 0; i--)
        {
            if(trees[y][x] <= trees[i][x])
            {
                dirs[3] = false;
                break;
            }
        } 
        for(auto &d : dirs)
        {
            if(d == true)
            {
                return true;
            }
        }
        return false;
    }
}

int calculate_score(int x, int y, std::vector<std::vector<int>> &trees)
{
    int dirs[4] = {0,0,0,0};
   
    for(int i{x + 1}; i < trees[y].size(); i++)
    {
        dirs[0]++;
        if(trees[y][x] <= trees[y][i])
        {
            break;
        }
    } 
    for(int i{x - 1}; i >=0; i--)
    {
        dirs[1]++;
        if(trees[y][x] <= trees[y][i])
        {
            break;
        }
    } 
    for(int i{y + 1}; i < trees.size(); i++)
    {
        dirs[2]++;
        if(trees[y][x] <= trees[i][x])
        {
            break;
        }
    } 
    for(int i{y - 1}; i >=0; i--)
    {
        dirs[3]++;
        if(trees[y][x] <= trees[i][x])
        {
            break;
        }
    } 
    return dirs[0] * dirs[1] * dirs[2] * dirs[3];

}

int main()
{
    std::ifstream in("input");
    std::string line;
    std::vector<std::vector<int>> trees;
    int line_n{0};
    while(std::getline(in, line))
    {
        trees.push_back({});
        for(auto &c:line)
        {
            trees[line_n].push_back(c-48);
        }
        line_n++;
    }
    int visibletrees{0};
    std::vector<int> scores{};
    for(int y{0}; y < trees.size(); y++)
    {
        for(int x{0}; x < trees.size(); x++)
        {
            if(visible(x, y, trees))
            {
                visibletrees++;
            }
            scores.push_back(calculate_score(x, y, trees));
        }
    }
    std::cout << "Árboles visibles: " << visibletrees << std::endl;

    std::sort(scores.begin(), scores.end());

    std::cout << "Puntuación máxima: " << scores.back() << std::endl;

    in.close();
}