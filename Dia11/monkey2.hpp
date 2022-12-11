#include <iostream>
#include <vector>
#include <sstream>

class Monkey2
{
    public:
        Monkey2(int pos, std::string text)
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
        void set_vector(std::vector<Monkey2> * monkeys)
        {
            this->monkeys = monkeys;
        }
        void push(unsigned long worry)
        {
            items.push_back(worry);
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
        }
        void give()
        {
            
            for(int i{0}; i < items.size(); i++)
            {
                compute(i);
                int new_worry = items[i] % superresto;
                if(items[i] % test != 0)
                {
                    monkeys->at(monkeys_to_give[1]).push(new_worry);
                }
                else 
                {
                    monkeys->at(monkeys_to_give[0]).push(new_worry);
                }
                
            }
            examination_count += items.size();
            items.clear();            
        }
        unsigned long get_examination_count()
        {
            return examination_count;
        }
        int get_item_size()
        {
            return items.size();
        }
        int get_test()
        {
            return test;
        }
        void set_superresto(int new_s)
        {
            superresto = new_s;
        }
    private:
        std::vector<Monkey2> * monkeys;
        std::vector<unsigned long> items{};
        unsigned long examination_count{0};
        char operation;
        int number;
        int monkeys_to_give[2];
        int test;
        int superresto;
        
        void remove_commas(std::string &t)
        {
            if(t[t.size()-1] == ',')
            {
                t.pop_back();
            }
        }
};