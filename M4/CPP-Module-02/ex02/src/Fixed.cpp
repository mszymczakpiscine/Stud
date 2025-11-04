/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:10:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/11/04 18:10:09 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int input)
{
    //std::cout << "Int constructor called" << std::endl;
    fixedPointValue = input << fractionalBits;
}

Fixed::Fixed(const float input)
{
    //std::cout <<"Float constructor called" << std::endl;
    fixedPointValue = roundf(input * (1 << fractionalBits));
}
Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    ++fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++fixedPointValue;
    return temp;
}

Fixed &Fixed::operator--()
{
    --fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --fixedPointValue;
    return temp;
}

int Fixed::getRawBits(void) const
{
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return fixedPointValue >> fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
