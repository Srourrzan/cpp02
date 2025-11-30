#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _integer(0)
{
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::~Fixed( void )
{
  std::cout << "Destructor called" << std::endl;
  return;
}

Fixed::Fixed( Fixed const & src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

Fixed::Fixed(int const n)
{
  std::cout << "Int constructor called" << std::endl;
  this->_integer = n << _frac;
  return;
}

Fixed::Fixed(float const f)
{
  std::cout << "float constructor called" << std::endl;
  Fixed::_integer = static_cast<int>(roundf(f * (1 << _frac)));
  return;  
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
	this->_integer = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits( void ) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return this->_integer;
}

void Fixed::setRawBits( int const raw )
{
  std::cout << "setRawBits member function called" << std::endl;
  this->_integer = raw;
}

float Fixed::toFloat( void ) const
{
  return ((float)(this->_integer) / (1 << _frac));
}

int Fixed::toInt( void ) const
{
  return (this->_integer >> this->_frac);
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ){
  o << i.getRawBits();

  return (o);
}
