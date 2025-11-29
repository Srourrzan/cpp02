#include <iostream>

class Sample {
public:
  Sample( void );   //conon
  Sample ( int const n );
  Sample ( Sample const & src ); //conon
  ~Sample ( void );  //conon

  Sample & operator=( Sample const & rhs ); //conon
  int getFoo( void ) const;

private:
  int _foo;
};

std::ostream & operator<<( std::ostream & o, Sample const & i);

Sample::Sample( void ) : _foo( 0 ) {
  std::cout << "Default Constructor called" << std::endl;

  return ;
}

Sample::Sample( int const n ) : _foo( n ) {
  std::cout << "Parametric Constructor called" << std::endl;
  return ;
}

Sample::Sample( Sample const & src ) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;

  return ;
}

Sample::~Sample( void ) {
  std::cout << "Destructor called" << std::endl;
  return;
}

int Sample::getFoo( void ) const {
  return this->_foo;
}

Sample & Sample::operator=( Sample const & rhs ) {
  std::cout << "Assignment operator called" << std::endl;

  if (this != &rhs)
	this->_foo = rhs.getFoo();
  return *this;
}

std::ostream & operator<<( std::ostream & o, Sample const & i ){
  o << "The value of _foo is : " << i.getFoo();

  return (o);
}

int main() {
  Sample instance1;
  Sample instance2( 42 );
  Sample instance3( instance1 );

  std::cout << instance1 << std::endl;
  std::cout << instance2 << std::endl;
  std::cout << instance3 << std::endl;

  instance3 = instance2;
  std::cout << instance3 << std::endl;

  return (0);
}
