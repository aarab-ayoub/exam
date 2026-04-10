#pragma once


#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag &bag;
    public :
        set(searchable_bag& obj);
        set( const set &obj);

        ~set();

        void insert(int);
        void insert(int *, int) ;
        void print() const;
        void clear();

        bool has(int) const;

        const searchable_bag& get_bag() const;
};