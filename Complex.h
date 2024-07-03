#pragma once
#include <iostream>

class Complex
{
private:
	double re;
	double im;
public:
	Complex()
	{
		this->re = 0;
		this->im = 0;
	}
	Complex(double re, double im)
	{
		this->re = re;
		this->im = im;
	}
	Complex(const Complex& other)
	{
		this->re = other.re;
		this->im = other.im;
	}
	Complex operator+(const Complex& other) const
	{
		Complex result(*this);
		result.re += other.re;
		result.im += other.im;
		return result;
	}
	Complex operator-(const Complex& other) const
	{
		Complex result(*this);
		result.re -= other.re;
		result.im -= other.im;
		return result;
	}
	Complex operator*(const Complex& other) const
	{
		Complex result;
		result.re = this->re * other.re - this->im * other.im;
		result.im = this->re * other.im + this->im * other.re;
		return result;
	}
	Complex operator/(const Complex& other) const
	{
		Complex result;
		result.re = (this->re * other.re + this->im * other.im) / (other.re * other.re + other.im * other.im);
		result.im = (this->im * other.re - this->re * other.im) / (other.re * other.re + other.im * other.im);
		return result;
	}
	bool operator ==(const Complex& other) const
	{
		if (this->re == other.re && this->im == other.im)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend std::ostream& operator << (std::ostream& os, const Complex& other)
	{
		os << other.re << " + " << other.im << "i";
		return os;
	}
	friend std::istream& operator >> (std::istream& is, Complex& other)
	{
		std::cout << "re = ";
		is >> other.re;
		std::cout << "\nim = ";
		is >> other.im;
		return is;
	}
};