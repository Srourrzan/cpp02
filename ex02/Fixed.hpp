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
  int toInt( void ) const;
  Fixed ( Fixed const & src );
  float toFloat( void ) const;
  int getRawBits( void ) const;
  void setRawBits( int const raw );
  Fixed & operator= ( Fixed const & rhs );
  Fixed operator+ ( Fixed const & rhs );
  Fixed operator- ( Fixed const & rhs );
  Fixed operator* ( Fixed const & rhs );
  Fixed operator/ ( Fixed const & rhs );
  bool operator< ( Fixed const & rhs );
  bool operator> ( Fixed const & rhs );
  bool operator>= ( Fixed const & rhs );
  bool operator<= ( Fixed const & rhs );
  bool operator== ( Fixed const & rhs );
  bool operator!= ( Fixed const & rhs );
  Fixed & operator++ ( );
  Fixed operator++ ( int );
  Fixed & operator-- ( );
  Fixed operator-- ( int );
  //  static Fixed & operatormin;
  static Fixed & mix (Fixed const & lhs, Fixed const & rhs);
  static Fixed & max (Fixed const & lhs, Fixed const & rhs);
  static Fixed & mix (Fixed & lhs, Fixed & rhs);
  static Fixed & max (Fixed & lhs, Fixed & rhs);

private:
  int _integer;
  static const int _frac = 8;
  
};

std::ostream & operator<<( std::ostream & o, Fixed const & i);

#endif
