#include <iostream>
#include <sstream>
#include <vector>
class Parser 
{
    public:
        Parser(std::string toParse)
        {
            parsed = toParse;
            //reverse(parsed);
            std::cout << parsed << std::endl;
            create_matrix();

        }
        std::vector<std::string> traspose()
        {
            std::vector<std::string> lines;
            for(int j{0}; j < 9; j++)
            {
                lines.push_back("");
            }
            for(int i{0}; i < matrix.size() - 1; i++)
            {
                
                std::string tmp;
                std::cout << "|";
                for(int j{0}; j < matrix[i].size(); j++)
                {
                    if(matrix[i][j] != ']' && matrix[i][j] != '[' && matrix[i][j] != ' ')
                        std::cout << matrix[i][j] << ": ->" << j << ", ";
                    if((j-1) % 4 == 0)
                        lines[(j-1)/4] += matrix[i][j];
                }
                std::cout << "|\n";

            }
            for(auto &p:lines)
            {
                std::cout << p << std::endl;
            }
            return lines;
        }
    private:
        std::string parsed;
        std::vector<std::string> matrix;
        void reverse(std::string &string)
        {
            std::string reversed{""};
            std::string copy = string;
            for(unsigned long i{copy.size() - 1}; i > 0; i--)
            {
                reversed += copy[i];
            }
            string = reversed;
        }
        std::string get_line_elements(int line)
        {
            //std::cout << "-----------------------------\n";
            std::string tmp;
            std::stringstream p{parsed};
            std::string l;
            for(int i{0}; i <= line; i++)
            {
                getline(p, tmp);
                l += tmp;
            }
            //std::cout << l << std::endl;
            //remove_useless_characters(tmp);
            //std::cout << l;
            return tmp;
        }
        void remove_useless_characters(std::string &str)
        {
            for(auto &p : str)
            {
                if(p == ']' || p == '[' || p == ' ')
                {
                    p = '\0';
                }
            }
        }
        
        void create_matrix()
        {
            for(int i{1}; i < 9; i++)
            {
                std::string line = get_line_elements(i); //- get_line_elements(i - 1);
                matrix.push_back(line);
            }
            for(auto &p: matrix)
            {
                std::cout << p << std::endl;
            }
            traspose();
            
        }
        void get_crates_in_line(int line)
        {

        }
};