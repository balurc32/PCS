#include <iostream>
#include <numeric>
#include <concepts>
#pragma once

template<typename I> requires std::integral<I>
class rational
{
	
private:
I num_;
I den_;

void semplifica()
{
	if (den_==0) return;
	
	if (den_ <0) {
		num_=-num_;
		den_=-den_;
	}
	
	I comune= std::gcd(num_, den_);
	num_ = num_ / comune;
	den_ = den_ / comune;
}

	
public:
rational() : num_(I{0}), den_(I{1}) // costruttore di default
{}

rational(const I& p_num, const I& p_den) // costruttore user-defined
: num_(p_num), den_(p_den)
{
	if (den_ ==0) {
		if (num_ ==0) {    // caso NaN
			num_=0;
			den_=0;
			}
			else {
				num_ = (num_ > 0) ? I{1} : I{-1};   // caso inf
				den_ = 0;
			}
	}
	else {
		semplifica();

		}
	
}

I num() const { return num_; }
I den() const { return den_; }

bool is_nan() const { return (num_==0 && den_==0); }
bool is_inf() const { return (num_ !=0 && den_==0); }

// Operatore += 
rational& operator+=(const rational& other) {
	if (this->is_nan() || other.is_nan()) {
		num_=0;
		den_= 0;
	}
	else if (this->is_inf() || other.is_inf()) {
		num_=1;
		den_=0;
	}
	else {
		num_= num_ * other.den_ + other.num_ * den_;
		den_=den_* other.den_;
		semplifica();
	}
	return *this;
}


// Operatore +
rational operator+(const rational& other) const {
	rational res = *this;
	res += other;
	return res;	
}

// Operatore -=
rational& operator-=(const rational& other) {
	return *this += rational(-other.num(), other.den());
}

// Operatore -
rational operator-(const rational& other) const {
	rational res= *this;
	res-= other;
	return res;
}

// Operatore *=
rational& operator*=(const rational& other) {
	if (this->is_nan() || other.is_nan()) {
		num_=0;
		den_=0;
		}
		else {
			num_ *= other.num_;
			den_ *= other.den_;
			if (den_ != 0) semplifica();
			else {
				num_= (num_==0) ? 0 : (num_ > 0 ? 1 : -1);
			}
		}
		return *this;	
}

// Operatore *
rational operator*(const rational& other) const {
	rational res= *this;
	res *= other;
	return res;
}

// Operatore /=
rational& operator/=(const rational& other) {
	return *this *= rational(other.den(), other.num());
}

// Operatore /
rational operator/(const rational& other) const {
	rational res = *this;
	res /= other;
	return res;
}

};


// overload operatore <<
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
	if (r.is_nan()) os <<"NaN";
	else if (r.is_inf()) os << (r.num() > 0 ? "+inf" : "-inf");
	else os << r.num() << "/" << r.den();
	return os;
}
