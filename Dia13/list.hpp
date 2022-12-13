#include <initializer_list>
#include <iostream>
#include <vector>

class List
{
    public:
        List();
        void add_number(int n)
        {
            child_numbers.push_back(n);
        }
        void add_list(List * list)
        {
            child_lists.push_back(list);
        }
        void * get_child_at_pos(int pos)
        {
        }
        int size()
        {
            return child_numbers.size() + child_lists.size();
        }
    private:
        std::vector<int> child_numbers{};
        std::vector<List *> child_lists{};
};