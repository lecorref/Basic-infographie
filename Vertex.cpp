#include "Vertex.hpp"

Vertex::Vertex( void ) : _x(0.0), _y(0.0), _z(0.0)
{
	return ;
}

Vertex::Vertex( double x, double y, double z) : _x(x), _y(y), _z(z)
{
	return ;
}

Vertex::Vertex(Vertex const & src)
{
	*this = src;
	return ;
}

Vertex::~Vertex( void )
{
	return ;
}

double						Vertex::getX() const
{
	return this->_x;
}

double						Vertex::getY() const
{
	return this->_y;
}

double						Vertex::getZ() const
{
	return this->_z;
}

void						Vertex::setX(double x)
{
	this->_x = x;
	return ;
}

void						Vertex::setY(double y)
{
	this->_y = y;
	return ;
}

void						Vertex::setZ(double z)
{
	this->_z = z;
	return ;
}

Vertex &					Vertex::operator=(Vertex const & rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_z = rhs._z;
	return *this;
}

Vertex						Vertex::operator+(Vertex const & rhs)
{
	return Vertex(this->_x + rhs._x, this->_y + rhs._y, this->_z + rhs._z);
}

Vertex	&					Vertex::operator+=(Vertex const & rhs)
{
	Vertex	vtx = Vertex(*this + rhs);
	*this = vtx;
	return *this;
}

Vertex						Vertex::operator*(double const rhs)
{
	return Vertex(this->_x * rhs, this->_y * rhs, this->_z * rhs);
}

std::string					Vertex::toString() const
{
	std::stringstream sstr;

	sstr << "[Vertex : {" << this->_x << ", " << this->_y << ", " << this->_z
		<< "}]";
	return sstr.str();
}

std::ostream &				operator<<(std::ostream & o, Vertex const & rhs)
{
	o << rhs.toString();
	return o;
}
