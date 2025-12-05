#include <iostream>

class Integer {
public:
  Integer( int const n);
  ~Integer( void );

  int getValue( void ) const;

  Integer & operator=( Integer const & rhs );
  Integer operator+( Integer const & rhs) const;

private:
  int _n;
};

std::ostream & operator<<( std::ostream & o, Integer const & rhs);

Integer::Integer( int const n) : _n(n) {
  std::cout << "Constructor called with value" << n << std::endl;
  return;
}

Integer::~Integer( void ) {
  std::cout << "Destructor called with value " << this->_n << std::endl;
  return ;
	}

int Integer::getValue( void ) const {
  return this->_n;
}

Integer & Integer::operator=( Integer const & rhs ){
  std::cout << "Assigning operator called from " << std::endl;
  std::cout << " to " << rhs.getValue() << std::endl;

  this->_n = rhs.getValue();
  return *this;
}

Integer Integer::operator+( Integer const & rhs ) const {
  std::cout << "Addition operator called with " << this->_n; 
  std::cout << " and " << rhs.getValue() << std::endl;

  return (Integer( this->_n + rhs.getValue() ));
}


std::ostream & operator<<( std::ostream & o, Integer const & rhs)
{
  o << rhs.getValue();
  return o;
}

int main()
{
  Integer x( 30 );
  Integer y( 10 );
  Integer z( 0 );

  std::cout << "Value of x : " << x << std::endl;
  std::cout << "Value of y : " << y << std::endl;
  y = Integer ( 12 );
  std::cout << "Value of y : " << y << std::endl;
  std::cout << "Value of z : " << z << std::endl;
  z = x + y;
  std::cout << "Value of z : " << z << std::endl;
  return (0);
}
