//
// Created by Elias on 29.09.16.
//

#ifndef UEBUNG2_FRACTION_H
#define UEBUNG2_FRACTION_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

inline void check_char(std::istream &is, char ch) {
    char c; is >> c; if(c!=ch) { is.putback(c); is.setstate(ios::badbit); }
}

template <class T>
T gcf(T a, T b) {
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a, b);
    while (b!=0) { a=a-b; if (a<b) swap(a, b); }
    return a;
}

template <class T>
inline T lcm(T a, T b) {
    return (a/gcf(a, b))*b;
}

class fraction { // type definition
private:
    int c; int d;
public:
    fraction(int cntr=0, int denom=1) : c(cntr) {
        assert(denom != 0);
        d = denom;
    }
    int getNumerator() { return c; }
    int getDenominator() { return d; }
    fraction operator*(fraction b) {
        int f1=gcf(c, b.d), f2=gcf(b.c, d);
        return fraction((c/f1)*(b.c/f2), (d/f2)*(b.d/f1));
    }
    fraction operator/(fraction b) {
        return (*this)*fraction(b.d, b.c);
    }
    fraction operator+(fraction b) {
        int num = c*b.d + b.c*d;
        int den = d*b.d;
        int gc = gcf(num, den);
        return fraction((double)num/gc, (double)den/gc);
    }
    fraction operator-(fraction b) {
        int num = c*b.d - b.c*d;
        int den = d*b.d;
        int gc = gcf(num, den);
        return fraction((double)num/gc, (double)den/gc);
    }
    friend istream &operator>>(istream &is, fraction &f) {
        fraction g;
        check_char(is, '('); is >> g.c;
        check_char(is, '/');
        int denom;
        is >> denom;
        assert(denom != 0);
        g.d = denom;
        check_char(is, ')'); if(is) f=g;
        return is;
    }
    friend ostream &operator<<(ostream &os, fraction f) {
        os << '(' << f.c << '/' << f.d << ')';
        return os;
    }
    string to_string() {
        return std::to_string((double)c / (double)d);
    }
};


#endif //UEBUNG2_FRACTION_H
