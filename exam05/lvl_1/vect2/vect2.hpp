#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
private:
    int _x;
    int _y;

public:
    // COSTRUTTORI E DISTRUTTORE
    vect2() : _x(0), _y(0) {}
    vect2(int x, int y) : _x(x), _y(y) {}
    vect2(const vect2& other) : _x(other._x), _y(other._y) {}
    vect2& operator=(const vect2& other) {
        if (this != &other) {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }
    ~vect2() {}

    // GETTER
    int getX() const;
    int getY() const;

    // SOMMA E INCREMENTO
    vect2 operator+(const vect2& add) const;  // nuovo oggetto (v = v + v)
    vect2& operator+=(const vect2& add);      // modifica this (v += v)
    vect2 operator++(int);                    // post-incremento (ritorna copia prima di incrementare)
    vect2& operator++();                      // pre-incremento (ritorna this incrementato)

    // SOTTRAZIONE E DECREMENTO
    vect2 operator-(const vect2& add) const;  // nuovo oggetto (v = v - v)
    vect2& operator-=(const vect2& add);      // modifica this (v -= v)
    vect2 operator--(int);                    // post-decremento
    vect2& operator--();                      // pre-decremento
    vect2 operator-() const;                  // unary minus (-v)

    // MOLTIPLICAZIONE
    vect2 operator*(int val) const;           // nuovo oggetto (v = v * int)
    vect2& operator*=(int val);               // modifica this (v *= int)

    // ACCESSO PER INDICE
    int& operator[](int idx);                 // riferimento modificabile (v[0] = n)
    const int& operator[](int idx) const;     // riferimento costante (solo lettura)
};

// OPERATORI ESTERNI
vect2 operator*(int val, const vect2& v);     // overload esterno (v = int * v)
std::ostream& operator<<(std::ostream& os, const vect2& v); // stampa su stream

bool operator==(const vect2& v1, const vect2& v2);
bool operator!=(const vect2& v1, const vect2& v2);

#endif
