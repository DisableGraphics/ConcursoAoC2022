#include <iostream>
#include <fstream>
/*
    A: Rock
    B: Paper
    C: Scissors

    X:  Rock
    Y:  Paper
    Z:  Scissors
*/

/*
    6 si gano yo
    0 si gana el oponente
    3 si hay empate
*/
int whowon(std::string opponent, char me)
{
    if(opponent == "A")
    {
        if(me == 'X')
        {
            return 3;
        }
        else if(me == 'Y')
        {
            return 6;
        }
        else 
        {
            return 0;
        }
    }
    else if(opponent == "B")
    {
        if(me == 'X')
        {
            return 0;
        }
        else if(me == 'Y')
        {
            return 3;
        }
        else 
        {
            return 6;
        }
    }
    else if(opponent == "C")
    {
        if(me == 'X')
        {
            return 6;
        }
        else if(me == 'Y')
        {
            return 0;
        }
        else 
        {
            return 3;
        }
    }
    //No quiero warnings
    return 0;
}

int my_selection(char me)
{
    int ret{0};
    if(me == 'X')
    {
        ret = 1;
    }
    else if(me == 'Y')
    {
        ret = 2;
    }
    else if(me == 'Z')
    {
        ret = 3;
    }
    return ret;
}

char selected(char me, char opponent)
{
    switch(me)
    {
        case 'X':
            std::cout << "PERDER" << std::endl;
            switch(opponent)
            {
                case 'A':
                    return 'Z';
                case 'B':
                    return 'X';
                case 'C':
                    return 'Y';
            }
            break;
        case 'Y':
            std::cout << "EMPATAR" << std::endl;
            return opponent + ('X' - 'A');
            break;
        case 'Z':
            std::cout << "GANAR" << std::endl;
            switch(opponent)
            {
                case 'A':
                    return 'Y';
                case 'B':
                    return 'Z';
                case 'C':
                    return 'X';
            }
            break;
    }
    //Fuera warnings
    return '\0';
}

int main()
{
    //Parte 1
    std::ifstream in{"input"};

    std::string input;
    std::string abc;
    std::string xyz;
    bool abc_or_xyz{true};
    int outcome{0};
    int outcome_p2{0};
    while(in >> input)
    {
        
        if(abc_or_xyz)
        {
            abc_or_xyz = false;
            abc = input;
            
        }
        else 
        {
            abc_or_xyz = true;
            xyz = input;
            
            outcome += my_selection(xyz[0]) + whowon(abc, xyz[0]);
            //Parte 2
            char selec = selected(xyz[0], abc[0]);
            outcome_p2 += my_selection(selec) +  whowon(abc, selec);
        }
        
    }
    std::cout << outcome << std::endl;
    std::cout << outcome_p2 << std::endl;

    in.close();
}