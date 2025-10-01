#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

class bigint {
private:

    std::vector<int>    _value;

public:

    std::vector<int>   getValue( void ) const { return (_value); }
    int getIntValue() const {
        int result = 0;
        for (size_t i = 0; i < _value.size(); ++i) {
            result = result * 10 + _value[i];
        }
        return result;
    }

    std::ostream& stream(std::ostream& os) const;

    bigint&  operator++(); //pre
    bigint  operator++(int); //post
    bigint  operator+(int val);
    bigint& operator+=(const bigint& big);

    bigint operator<<(int val);
    bigint& operator<<=(int val);
    bigint operator<<(const bigint& big);
    bigint& operator<<=(const bigint& big);

    bigint operator>>(int val);
    bigint& operator>>=(int val);
    bigint operator>>(const bigint& big);
    bigint& operator>>=(const bigint& big);

    bigint( void ) {
       _value.push_back(0);
    }
    bigint( unsigned int val ) {
        if (val == 0)
            _value.push_back(0);
        else {
            while (val > 0) {
                unsigned int digit;
                digit = val % 10;
                _value.insert(_value.begin(), digit);
                val /= 10;
            }
        }
    }
    bigint( const std::vector<int>& vec ) {
        _value = vec;
    }
    bigint( const bigint& other) {
        *this = other;
    }
    bigint& operator=( const bigint& other ) {
        if (this != &other)
            _value = other._value;
        return (*this);
    }
    ~bigint() {}
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);
bigint  operator+(const bigint& n1, const bigint& n2);
bool    operator<(const bigint& big1, const bigint& big2);
bool    operator>(const bigint& big1, const bigint& big2);
bool    operator==(const bigint& big1, const bigint& big2);
bool    operator!=(const bigint& big1, const bigint& big2);
bool    operator<=(const bigint& big1, const bigint& big2);
bool    operator>=(const bigint& big1, const bigint& big2);



#endif