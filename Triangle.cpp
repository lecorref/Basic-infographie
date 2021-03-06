
#include "Triangle.hpp"

Triangle::Triangle( void )
{
	this->_initNormalVector();
	return ;
}

Triangle::Triangle( Vertex const & a, Vertex const & b, Vertex const & c ) : _a(a), _b(b), _c(c)
{
	this->_initNormalVector();
	return ;
}

Triangle::Triangle(Triangle const & src)
{
	*this = src;
	return ;
}

Triangle::~Triangle( void )
{
	return ;
}

Triangle &	Triangle::operator=(Triangle const & rhs)
{
	this->_a = rhs._a;
	this->_b = rhs._b;
	this->_c = rhs._c;
	return *this;
}

Vertex		Triangle::getA() const
{
	return this->_a;
}

Vertex		Triangle::getB() const
{
	return this->_b;
}

Vertex		Triangle::getC() const
{
	return this->_c;
}

void		Triangle::_initNormalVector()
{
	Vector	ab(this->_a, this->_b);
	Vector	ac(this->_a, this->_c);

	this->_normal = ab ^ ac;
}

std::string	Triangle::toString() const
{
	std::stringstream sstr;

	sstr << "[Triangle : {" << this->_a << ", " << this->_b << ", " << this->_c
		<< "}]";
	return sstr.str();
}

std::ostream &		operator<<(std::ostream & o, Triangle const & rhs)
{
	o << rhs.toString();
	return o;
}

