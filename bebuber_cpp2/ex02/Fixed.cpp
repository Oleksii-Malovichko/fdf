/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:36:35 by bebuber           #+#    #+#             */
/*   Updated: 2024/12/04 00:17:56 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors && Destructor
Fixed::Fixed() : rawBits(0) {}
Fixed::Fixed(const int raw) : rawBits(raw << fractionalBits) {}
Fixed::Fixed(const float raw) : rawBits(roundf(raw * (1 << fractionalBits))) {}
Fixed::Fixed(const Fixed& other) : rawBits(other.rawBits) {}
Fixed::~Fixed() {}

// Copy Member Operator
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

// Member Functions
int Fixed::getRawBits() const {	return rawBits; }
void Fixed::setRawBits(int const raw) {	rawBits = raw; }
float Fixed::toFloat() const { return (float)rawBits / (1 << fractionalBits); }
int Fixed::toInt() const { return rawBits >> fractionalBits; }

// 4* Arithmetic operators:
Fixed Fixed::operator+(const Fixed& other) const {return Fixed(this->toFloat() + other.toFloat());}
Fixed Fixed::operator-(const Fixed& other) const {return Fixed(this->toFloat() - other.toFloat());}
Fixed Fixed::operator*(const Fixed& other) const {return Fixed(this->toFloat() * other.toFloat());}
Fixed Fixed::operator/(const Fixed& other) const {return Fixed(this->toFloat() / other.toFloat());}

// 6* Comparison operators:
bool Fixed::operator>(const Fixed& other) const { return this->getRawBits() > other.getRawBits();}
bool Fixed::operator<(const Fixed& other) const { return this->getRawBits() < other.getRawBits();}
bool Fixed::operator>=(const Fixed& other) const { return this->getRawBits() >= other.getRawBits();}
bool Fixed::operator<=(const Fixed& other) const { return this->getRawBits() <= other.getRawBits();}
bool Fixed::operator==(const Fixed& other) const { return this->getRawBits() == other.getRawBits();}
bool Fixed::operator!=(const Fixed& other) const { return this->getRawBits() != other.getRawBits();}

// Pre-increment
Fixed& Fixed::operator++() {
	this->rawBits++;
	return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->rawBits++;
	return temp;
}

// Pre-decrement
Fixed& Fixed::operator--() {
	this->rawBits--;
	return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->rawBits--;
	return temp;
}

// 4 Overloaded functions
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }


// overload function to output as float
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
