#include <iostream>
#include <vector>
#include <sstream>

class Monkey
{
    public:
        Monkey(int pos, std::string text)
        {
            std::string tmp;
            std::stringstream s{text};
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> tmp;
            while(tmp != "Operation:")
            {
                
                s >> tmp;
                remove_commas(tmp);
                try
                {
                    items.push_back(std::stoi(tmp));
                }
                catch(std::exception &e)
                {

                }
            }
            
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> operation;
            s >> tmp;
            try
            {
                number = std::stoi(tmp);
            }
            //Nota: aquí es cuando encuentra "old"
            catch(std::exception &e)
            {
                //Como no hay números negativos en la operación...
                number = -1;
            }
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> test;
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> monkeys_to_give[0];
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> tmp;
            s >> monkeys_to_give[1];

        }
        void set_vector(std::vector<Monkey> * monkeys)
        {
            this->monkeys = monkeys;
        }
        void push(int worry)
        {
            items.push_back(worry);
        }
        int round(double t)
        {
            if(t / (int)t >= 0.5)
            {
                return (int)(t + 1);
            }
            else
            {
                return (int)t;
            }
        }
        void compute(int index)
        {
            if(number == -1)
            {
                if(operation == '*')
                {
                    items[index] *= items[index];
                }
                else 
                {
                    items[index] += items[index];
                }
            }
            else 
            {
                if(operation == '*')
                {
                    items[index] *= number;
                }
                else 
                {
                    items[index] += number;
                }
            }
            double division{(double)items[index] / 3};
            items[index] /=3; 
            
        }
        void give()
        {
            
            for(int i{0}; i < items.size(); i++)
            {
                
                compute(i);
                if(items[i] % test != 0)
                {
                    monkeys->at(monkeys_to_give[1]).push(items[i]);
                }
                else 
                {
                    monkeys->at(monkeys_to_give[0]).push(items[i]);
                }
                
            }
            examination_count += items.size();
            items.clear();            
        }
        unsigned int get_examination_count()
        {
            return examination_count;
        }
        int get_item_size()
        {
            return items.size();
        }
    private:
        std::vector<Monkey> * monkeys;
        std::vector<int> items{};
        unsigned int examination_count{0};
        char operation;
        int number;
        int monkeys_to_give[2];
        int test;
        void remove_commas(std::string &t)
        {
            if(t[t.size()-1] == ',')
            {
                t.pop_back();
            }
        }
};