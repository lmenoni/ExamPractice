#include "set.hpp"

set::set() {}

set::set(const set& other) {
    _bag = other._bag;
}

set::set (searchable_bag& bag) : _bag(0) {
    _bag = &bag;
}

set::~set() {}

set& set::operator=(const set& other) {

    if (this != &other) {
        this->_bag = other._bag;
    }
    return(*this);
}

void set::insert(int *a, int s) {
    _bag->insert(a, s);
}

void set::insert(int val) { 
    _bag->insert(val);
}

bool set::has (int val) const {
    return (_bag->has (val));
}

void set::print(void) { 
    _bag->print();
}

void set::clear( void ) {  
    _bag->clear();
}
searchable_bag& set::get_bag(void) {
    return (*_bag);
}
