#include <iostream>
#include <fstream>
#include <sstream>
#include <type_traits>
#include <vector>
#include "matrix.hpp"
#include "shortest_path.hpp"

bool can_be_connected(char a, char b)
{
    if(a == 'S')
        a = 'a';
    else if(b == 'S')
        b = 'a';
    else if(a == 'E')
        a = 'z';
    else if(b == 'E')
        b = 'z';
    return a + 1 >= b;
}

void populate_matrix(Matrix& adyacence_matrix, const std::string &map, int rowlength, int rows)
{
    for(int i{0}; i < map.size(); i++)
    {
        //Test all possible options with the can_be_connected function
        //Also: Depending on the position, the possible neighbours are different
        //      (e.g. the first row has no top neighbour)
        if(i % rowlength != 0 && can_be_connected(map[i], map[i - 1]))
            adyacence_matrix(i, i - 1) = 1;
        if(i % rowlength != rowlength - 1 && can_be_connected(map[i], map[i + 1]))
            adyacence_matrix(i, i + 1) = 1;
        if(i >= rowlength && can_be_connected(map[i], map[i - rowlength]))
            adyacence_matrix(i, i - rowlength) = 1;
        if(i < map.size() - rowlength && can_be_connected(map[i], map[i + rowlength]))
            adyacence_matrix(i, i + rowlength) = 1;
    }
}

void populate_matrix_p2(Matrix& adyacence_matrix, const std::string &map, int rowlength, int rows)
{
    for(int i{0}; i < map.size(); i++)
    {
        //Test all possible options with the can_be_connected function
        //Also: Depending on the position, the possible neighbours are different
        //      (e.g. the first row has no top neighbour)
        if(i % rowlength != 0 && can_be_connected(map[i - 1], map[i]))
            adyacence_matrix(i, i-1) = 1;
        if(i % rowlength != rowlength - 1 && can_be_connected(map[i + 1], map[i]))
            adyacence_matrix(i, i +1) = 1;
        if(i >= rowlength && can_be_connected(map[i - rowlength], map[i]))
            adyacence_matrix(i, i - rowlength) = 1;
        if(i < map.size() - rowlength && can_be_connected(map[i + rowlength], map[i]))
            adyacence_matrix(i, i + rowlength) = 1;
    }
}

int main()
{
    std::ifstream in("input");
    std::string line;
    std::string map{""};
    int s, e;
    int rowlength{0};
    int rows{0};
    
    while(std::getline(in, line))
    {
        map += line;
        rowlength = line.size();
        rows++;
        for(int i{0}; i < line.size(); i++)
        {
            if(line[i] == 'S')
                s = i + rowlength * (rows - 1);
            else if(line[i] == 'E')
                e = i + rowlength * (rows - 1);
        }
    }
    std::cout << e << std::endl;
    Matrix adyacence_matrix(rows * rowlength, rowlength * rows);
    Matrix adyacence_matrix_p2(rows * rowlength, rowlength * rows);
    populate_matrix(adyacence_matrix, map, rowlength, rows);
    populate_matrix_p2(adyacence_matrix_p2, map, rowlength, rows);
    dijkstra(adyacence_matrix, s);
    dijkstra(adyacence_matrix_p2, e, map);
    
    in.close();
}