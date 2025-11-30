#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
  Fixed ( void );
  ~Fixed ( void );
  Fixed ( int const n );
  Fixed (float const f);
  Fixed ( Fixed const & src );
  int getRawBits( void ) const;
  void setRawBits( int const raw );
  Fixed & operator= ( Fixed const & rhs );
  float toFloat( void ) const;
  int toInt( void ) const;

private:
  int _integer;
  static const int _frac = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i);

#endif
