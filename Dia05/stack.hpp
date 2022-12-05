#include <iostream>
#include <vector>
class Stack
{
    public:
        Stack()
        {

        }
        void push(char crate)
        {
            crates.push_back(crate);
        }
        char pop()
        {
            char ret;
            if(crates.size()> 0)
                crates.pop_back();
            return ret;
        }
    private:
        std::vector<char> crates;
};