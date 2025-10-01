#include "bigint.hpp"

bigint& bigint::operator>>=(const bigint& big) {
    *this = *this >> big;
    return (*this);
}

bigint bigint::operator>>(const bigint& big) {
    std::vector<int> copy = this->getValue();
    std::vector<int> res;
    int amount = big.getIntValue();

    if (copy.size() - amount <= 0)
        return (bigint(0));
    for (size_t i = 0; i < copy.size() - amount; i++) {
        res.push_back(copy[i]);
    }
    return (bigint(res));
}

bigint& bigint::operator<<=(const bigint& big) {
    *this = *this << big;
    return (*this);
}

bigint bigint::operator<<(const bigint& big) {
    std::vector<int> copy = this->getValue();
    int amount = big.getIntValue();
    for (int i = 0; i < amount; i++)
        copy.push_back(0);
    return (bigint(copy));
}

bigint& bigint::operator>>=(int val) {
    *this = *this >> val;
    return (*this);
}
bigint bigint::operator>>(int val) {
    std::vector<int> copy = this->getValue();
    std::vector<int> res;

    if (copy.size() - val <= 0)
        return (bigint(0));
    for (size_t i = 0; i < copy.size() - val; i++) {
        res.push_back(copy[i]);
    }
    return (bigint(res));
}

bigint& bigint::operator<<=(int val) {
    *this = *this << val;
    return (*this);
}

bigint bigint::operator<<(int val) {
    std::vector<int> copy = _value;

    for (int i = 0; i < val; i++) {
        copy.push_back(0);
    }
    return (bigint(copy));
}

bigint&  bigint::operator++() {
    *this = *this + bigint(1);
    return (*this);
} //pre

bigint  bigint::operator++(int) {
    bigint copy = *this;
    *this = *this + bigint(1);
    return (copy);
} //post

bigint  bigint::operator+(int val) {
    return (*this + bigint(val));
}

bigint& bigint::operator+=(const bigint& big) {
   *this = *this + big;
   return (*this);
}

bigint  operator+(const bigint& n1, const bigint& n2) {
    int carry = 0;
    std::vector<int> v1 = n1.getValue();
    std::vector<int> v2 = n2.getValue();
    std::vector<int> res;
    size_t i;
    size_t j;

    i = v1.size();
    j = v2.size();
    while (i > 0 || j > 0) {
        int d1 = 0;
        int d2 = 0;
        if  (i > 0)
            d1 = v1[i - 1];
        if (j > 0)
            d2 = v2[j - 1];
        int d3 = d1 + d2 + carry;
        res.insert(res.begin(), d3 % 10);
        carry = d3 / 10;
        if (i > 0)
            i--;
        if (j > 0)
            j--;
    }
    if (carry > 0)
        res.insert(res.begin(), carry);
    return (bigint(res));
}

std::ostream& bigint::stream(std::ostream& os) const {
    for (size_t i = 0; i < _value.size();  i++) {
        os << _value[i];
    }
    return (os);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
    return (obj.stream(os));
}

bool    operator<(const bigint& big1, const bigint& big2) {
    std::vector<int> vec1 = big1.getValue();
    std::vector<int> vec2 = big2.getValue();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (size1 > size2)
        return (false);
    if (size1 < size2)
        return (true);
    size_t i = 0;
    while (i < size1) {
        if (vec1[i] != vec2[i])
            break;
        i++;
    }
    if (i == size1)
        return(false);
    return (vec1[i] < vec2[i]);
}

bool    operator>(const bigint& big1, const bigint& big2) {
    std::vector<int> vec1 = big1.getValue();
    std::vector<int> vec2 = big2.getValue();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (size1 > size2)
        return (true);
    if (size1 < size2)
        return (false);
    size_t i = 0;
    while (i < size1) {
        if (vec1[i] != vec2[i])
            break;
        i++;
    }
    if (i == size1)
        return(false);
    return (vec1[i] > vec2[i]);
}

bool    operator==(const bigint& big1, const bigint& big2) {
    std::vector<int> vec1 = big1.getValue();
    std::vector<int> vec2 = big2.getValue();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (size1 != size2)
        return (false);
    size_t i = 0;
    while (i < size1) {
        if (vec1[i] != vec2[i])
            return (false);
        i++;
    }
    return(true);
}
bool    operator!=(const bigint& big1, const bigint& big2) {
    std::vector<int> vec1 = big1.getValue();
    std::vector<int> vec2 = big2.getValue();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (size1 != size2)
        return (true);
    size_t i = 0;
    while (i < size1) {
        if (vec1[i] != vec2[i])
            return (true);
        i++;
    }
    return(false);
}

bool    operator<=(const bigint& big1, const bigint& big2) {
    std::vector<int> vec1 = big1.getValue();
    std::vector<int> vec2 = big2.getValue();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (size1 > size2)
        return (false);
    if (size1 < size2)
        return (true);
    size_t i = 0;
    while (i < size1) {
        if (vec1[i] != vec2[i])
            break;
        i++;
    }
    if (i == size1)
        return(true);
    return (vec1[i] < vec2[i]);
}

bool    operator>=(const bigint& big1, const bigint& big2) {
    std::vector<int> vec1 = big1.getValue();
    std::vector<int> vec2 = big2.getValue();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    if (size1 > size2)
        return (true);
    if (size1 < size2)
        return (false);
    size_t i = 0;
    while (i < size1) {
        if (vec1[i] != vec2[i])
            break;
        i++;
    }
    if (i == size1)
        return(true);
    return (vec1[i] > vec2[i]);
}