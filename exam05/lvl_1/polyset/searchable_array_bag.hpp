#ifndef SEARCHABLE_ARRAY_BAG_H
#define SEARCHABLE_ARRAY_BAG_H

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag: virtual public array_bag, public searchable_bag {
public:

    searchable_array_bag();
    ~searchable_array_bag();
    searchable_array_bag(const searchable_array_bag& other );
    searchable_array_bag& operator=(const searchable_array_bag& other );
    bool has (int val) const;

    int *get_data( void ) const;
    int get_size( void ) const;

};

#endif