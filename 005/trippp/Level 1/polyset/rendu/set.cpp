#include "set.hpp"

set::set(searchable_bag& obj): bag(obj){};
set::set( const set &obj) : bag(obj.bag){};
set::~set(){};
void set::insert(int value)
{
    if(!bag.has(value))
        bag.insert(value);
};
void set::insert(int *data, int size) 
{
    for (int i = 0; i < size; i++)
    {
        if(!bag.has(data[i]))
            bag.insert(data[i]);
    }
    
};
void set::print() const
{
    bag.print();
};
void set::clear()
{
    bag.clear();
};
bool set::has(int value) const
{
    return(bag.has(value));
};
const searchable_bag& set::get_bag() const
{
    return (bag);
};