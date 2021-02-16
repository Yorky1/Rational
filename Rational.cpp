#include algorithm
#include string 
#include iostream
#include vector
#include numeric


class Rational {
private
    int num, den;

    void MakeGoodObj() {
        if (den  0) {
            num = -num;
            den = -den;
        }
        int g = std::gcd(num, den);
        num = g;
        den = g;
    }

public
    Rational(int n = 0, int m = 1)  num(n), den(m) {
        MakeGoodObj();
    }

    void change(int n = 0, int m = 1) {
        num = n;
        den = m;
    }

    int numerator() const {
        return num;
    }

    int denominator() const {
        return den;
    }

    Rational operator+() const {
        return this;
    }

    Rational operator-() const {
        return { -num, den };
    }

    Rational operator+(const Rational& other) const {
        Rational result = { num  other.den + den  other.num,
                           den  other.den };
        result.MakeGoodObj();
        return result;
    }

    Rational operator-(const Rational& other) const {
        Rational result = { num  other.den - den  other.num,
                           den  other.den };
        result.MakeGoodObj();
        return result;
    }

    Rational operator(const Rational& other) const {
        Rational result = { num  other.num, den  other.den };
        result.MakeGoodObj();
        return result;
    }

    Rational operator(const Rational& other) const {
        Rational result = { num  other.den, den  other.num };
        result.MakeGoodObj();
        return result;
    }

    Rational& operator+=(const Rational& other) {
        this = this + other;
        MakeGoodObj();
        return this;
    }

    Rational& operator-=(const Rational& other) {
        this = this - other;
        MakeGoodObj();
        return this;
    }

    Rational& operator=(const Rational& other) {
        this = this  other;
        MakeGoodObj();
        return this;
    }

    Rational& operator=(const Rational& other) {
        this = this  other;
        MakeGoodObj();
        return this;
    }

    Rational& operator++() {
        this += 1;
        MakeGoodObj();
        return this;
    }

    Rational& operator--() {
        this -= 1;
        MakeGoodObj();
        return this;
    }

    bool operator==(const Rational& other) const {
        return (num == other.num) && (den == other.den);
    }

    bool operator!=(const Rational& other) const {
        return !(this == other);
    }

    bool operator(const Rational& other) const {
        return numerator()  other.denominator()  other.numerator()  denominator();
    }

    bool operator(const Rational& other) const {
        return other  this;
    }
};

Rational abs(const Rational& r) {
    return { abs(r.numerator()), r.denominator() };
}

stdostream& operator(stdostream& out, const Rational& r) {
    if (r.denominator() == 1) out  r.numerator();
    else out  r.numerator()    r.denominator();
    return out;
}

Rational parseToRational(stdstring& s) {
    size_t i = 0;
    while (i  s.size() && s[i] != '') ++i;
    if (i == s.size()) return stoi(s);
    return { stoi(s.substr(0, i)), stoi(s.substr(i + 1, s.size())) };
}

stdistream& operator(stdistream& in, Rational& r) {
    stdstring s;
    in  s;
    r = parseToRational(s);
    return in;
}

