
#include "Vector.hpp"

Vector::Vector( void ) : _x(0), _y(0), _z(0)
{
	return ;
}

Vector::Vector( Vertex const & dest ) : _x(dest.getX()), _y(dest.getY()), _z(dest.getZ())
{
	return ;
}

Vector::Vector( Vertex const & ori, Vertex const & dest) : _x(dest.getX() - ori.getX()), _y(dest.getY() - ori.getY()), _z(dest.getZ() - ori.getZ())
{
	return ;
}

Vector::Vector( double const x, double const y, double const z ) : _x(x), _y(y), _z(z)
{
	return ;
}

Vector::Vector(Vector const & src)
{
	*this = src;
	return ;
}

Vector::~Vector( void )
{
	return ;
}

Vector		Vector::operator-() const
{
	return Vector(-this->_x, -this->_y, -this->_z);
}

Vector		Vector::operator-(Vector const & rhs) const
{
	return Vector(this->_x - rhs._x, this->_y - rhs._y, this->_z - rhs._z);
}

Vector		Vector::operator+(Vector const & rhs) const
{
	return Vector(this->_x + rhs._x, this->_y + rhs._y, this->_z + rhs._z);
}

double		Vector::operator*(Vector const & rhs) const
{
	return (this->_x * rhs._x + this->_y * rhs._y + this->_z * rhs._z);
}

Vector		Vector::operator*(double const k) const
{
	return Vector(this->_x * k, this->_y * k, this->_z * k);
}

Vector		Vector::operator^(Vector const & rhs) const
{
	double	x = (this->_y * rhs._z) - (this->_z * rhs._y);
	double	y = (this->_z * rhs._x) - (this->_x * rhs._z);
	double	z = (this->_x * rhs._y) - (this->_y * rhs._x);
	return Vector(x, y, z);
}

Vector &	Vector::operator=(Vector const & rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_z = rhs._z;
	return *this;
}

double		Vector::getX() const
{
	return this->_x;
}

double		Vector::getY() const
{
	return this->_y;
}

double		Vector::getZ() const
{
	return this->_z;
}

double		Vector::magnitude() const
{
	return std::sqrt(std::pow(this->_x, 2) + std::pow(this->_y, 2) + std::pow(this->_z, 2));
}

Vector		Vector::normalize() const
{
	double	norm = this->magnitude();
	double	x = this->_x / norm;
	double	y = this->_y / norm;
	double	z = this->_z / norm;
	return Vector(x, y, z);
}

double		Vector::cos(Vector const & rhs) const
{
	return (*this * rhs / (this->magnitude() * rhs.magnitude()));
}

std::string	Vector::toString() const
{
	std::stringstream sstr;

	sstr << "[Vector : {" << this->_x << ", " << this->_y << ", " << this->_z << "}]";
	return sstr.str();
}

std::ostream &		operator<<(std::ostream & o, Vector const & rhs)
{
	o << rhs.toString();
	return o;
}
