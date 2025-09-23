#include "vect2.hpp"

// GETTER
int vect2::getX() const { return _x; }
int vect2::getY() const { return _y; }

// STREAM OPERATOR
std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v.getX() << "," << v.getY() << "}";
    return os;
}

// SOMMA E INCREMENTO
vect2 vect2::operator+(const vect2& add) const {
    return vect2(_x + add._x, _y + add._y);
}

vect2& vect2::operator+=(const vect2& add) {
    _x += add._x;
    _y += add._y;
    return *this;
}

vect2 vect2::operator++(int) { // post-incremento
    vect2 copy = *this;
    ++(*this);
    return copy;
}

vect2& vect2::operator++() { // pre-incremento
    ++_x;
    ++_y;
    return *this;
}

// SOTTRAZIONE E DECREMENTO
vect2 vect2::operator-(const vect2& add) const {
    return vect2(_x - add._x, _y - add._y);
}

vect2& vect2::operator-=(const vect2& add) {
    _x -= add._x;
    _y -= add._y;
    return *this;
}

vect2 vect2::operator--(int) { // post-decremento
    vect2 copy = *this;
    --(*this);
    return copy;
}

vect2& vect2::operator--() { // pre-decremento
    --_x;
    --_y;
    return *this;
}

vect2 vect2::operator-() const { // unary minus
    return vect2(-_x, -_y);
}

// MOLTIPLICAZIONE
vect2 vect2::operator*(int val) const {
    return vect2(_x * val, _y * val);
}

vect2& vect2::operator*=(int val) {
    _x *= val;
    _y *= val;
    return *this;
}

vect2 operator*(int val, const vect2& v) {
    return v * val;
}

// ACCESSO PER INDICE
int& vect2::operator[](int idx) {
    if (idx == 0) return _x;
    if (idx == 1) return _y;
    return _x; // fallback
}

const int& vect2::operator[](int idx) const {
    if (idx == 0) return _x;
    if (idx == 1) return _y;
    return _x; // fallback
}

// COMPARAZIONI
bool operator==(const vect2& v1, const vect2& v2) {
    return (v1.getX() == v2.getX() && v1.getY() == v2.getY());
}

bool operator!=(const vect2& v1, const vect2& v2) {
    return !(v1 == v2);
}
