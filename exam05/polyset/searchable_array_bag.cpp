#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::~searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& other ) : array_bag(other) {}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other ) {
    this->clear();
    this->data = new int[other.size];
    for (int i = 0; i < other.size; i++)
        this->data[i] = other.data[i];
    this->size = other.size;
    return *this;
}

bool searchable_array_bag::has(int val) const {
    for (int i = 0; i < size; i++) {
        if (data[i]== val)
            return (true);
    }
    return (false);
}