#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::~searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other ) : array_bag(other) {}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other) {
    if (this != &other)
        array_bag::operator=(other);
    return *this;
}

bool searchable_array_bag::has(int val) const {
    for (int i = 0; i < size; i++) {
        if (data[i]== val)
            return (true);
    }
    return (false);
}

int *searchable_array_bag::get_data( void ) const {
    return (data);
}

int searchable_array_bag::get_size( void ) const {
    return (size);
}