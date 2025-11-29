#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
  Fixed ( void );
  ~Fixed ( void );
  Fixed ( Fixed const & src );
  Fixed & operator= ( Fixed const & rhs );
  int getRawBits( void ) const;
  void setRawBits( int const raw );

private:
  int _integer;
  static const int _frac = 8;
};

#endif
