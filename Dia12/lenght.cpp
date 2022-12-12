#include <fstream>
#include <iostream>

int main()
{
    int y{0};
    int x{0};
    int total{0};
    std::ifstream in("input");
    std::string line;
    while(std::getline(in, line))
    {
        y++;
        x = line.size();
        total += line.size();
    }
    std::cout << "(" << x << ", " << y << ", " << total << std::endl;
}