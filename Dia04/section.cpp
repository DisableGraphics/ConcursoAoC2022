#include "section.h"

section::section(int start, int end)
{
    this->start = start;
    this->end = end;
    this->lenght = end - start;
}
//Este operador comprueba solapamiento a secas
bool section::operator<(const section &other) const
{
    if(*this <= other)
    {
        return true;
    }
    else 
    {
        if(other.start <= start && other.end <= end && other.end >= start)
        {
            return true;
        }
        else if(other.start >= start && other.end >= end && other.start <= end)
        {
            return true;
        }
    }
    return false;
}
//Este operador comprueba solapamiento total
bool section::operator<=(const section &other) const
{
    return other.start <= start && other.end >= end;
}

void section::new_pair(int start, int end)
{
    this->start = start;
    this->end = end;
    this->lenght = end - start;
}
int section::get_start()
{
    return start;
}
int section::get_end()
{
    return end;
}