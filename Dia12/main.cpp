#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "shortest_path.hpp"

typedef struct
{
    int x, y;
} vector2d;

bool nodes_connected(char n1, char n2)
{
    if(n1 +1 >= n2)
    {
        return true;
    }
    return false;
}

std::vector<vector2d> get_permitted_nodes(const std::string &map, unsigned long position)
{
    int rows = map.size() / 160;
    int columns = 160;

    //Necesitamos 4 nodos del grafo, los cuales representan cada uno:
    //  El de arriba
    //  El de abajo
    //  El de la izquierda
    //  El de la derecha
    //Y, además, si y sólo si se pueden obtener (Si estoy en un borde no puedo obtener el que
    //estaría "más allá" del borde en cuestión)


} 

std::vector<std::vector<int>> generate_adyacence_matrix(const std::string &map)
{
    //Pasos:
    //  1 - Empezamos con una matriz nula
    //  2 - Por cada arista que une a dos nodos, 
    //      se suma 1 al valor que hay actualmente
    //      en la ubicación correspondiente de la matriz.
    //      (Copiaos de wikipedia)
    std::vector<std::vector<int>> matrix;
    for(int i{0}; i < map.size(); i++)
    {
        matrix.push_back({});
        for(int j{0}; j < map.size(); j++)
        {
            matrix[i].push_back(0);
        }
    }
    

    return matrix;
}


int main()
{
    std::ifstream in("input");
    std::string line;
    std::string map{""};
    std::vector<std::vector<int>> adyacence_matrix;
    while(std::getline(in, line))
    {
        map += line;
    }
    adyacence_matrix = generate_adyacence_matrix(map);
    for(auto & row : adyacence_matrix)
    {
        std::cout << "|" << std::endl;
        for(auto & item_in_row : row)
        {
            std::cout << item_in_row << " ";
        }
        std::cout << "|\n";
    }
    in.close();
}