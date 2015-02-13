#include "Color.hpp"

Color::Color( void ) : _r(0), _g(0), _b(0)
{
//	std::cout << "r = " << this->_r << " g = " << this->_g << " b = " << this->_b << std::endl;
	return ;
}

Color::Color( unsigned int color ) : _r((color & 0xFF0000) >> 16), _g((color & 0x00FF00) >> 8), _b((color & 0x0000FF))
{
//	std::cout << "r = " << this->_r << " g = " << this->_g << " b = " << this->_b << std::endl;
	return ;
}

Color::Color( unsigned char r, unsigned char g, unsigned char b) : _r(r), _g(g), _b(b)
{
//	std::cout << "r = " << this->_r << " g = " << this->_g << " b = " << this->_b << std::endl;
	return ;
}

Color::Color(Color const & src)
{
//	std::cout << "[Color] created" << std::endl;
	*this = src;
//	std::cout << "r = " << this->_r << " g = " << this->_g << " b = " << this->_b << std::endl;
	return ;
}

Color::~Color( void )
{
//	std::cout << "[Color] destructed" << std::endl;
	return ;
}

unsigned char		Color::getRed() const
{
	return this->_r;
}

unsigned char		Color::getGreen() const
{
	return this->_g;
}

unsigned char		Color::getBlue() const
{
	return this->_b;
}

unsigned int		Color::getHex() const
{
	return (this->_r << 16) + (this->_g << 8) + this->_b;
}

Color				Color::operator*(double d)
{
	return	Color(static_cast<unsigned char>(this->_r * d),
			static_cast<unsigned char>(this->_g * d),
			static_cast<unsigned char>(this->_b * d));
}

Color				Color::operator-(Color const & rhs)
{
	return	Color(this->_r - rhs._r, this->_g - rhs._g, this->_b - rhs._b);
}

Color				Color::operator+(Color const & rhs)
{
	return	Color(this->_r + rhs._r, this->_g + rhs._g, this->_b + rhs._b);
}

Color &				Color::operator=(Color const & rhs)
{
	this->_r = rhs._r;
	this->_g = rhs._g;
	this->_b = rhs._b;
	return *this;
}

std::string			Color::toString() const
{
	std::stringstream sstr;

	sstr << "[Color : {" << static_cast<int>(this->_r) << ", " << static_cast<int>(this->_g) << ", " << static_cast<int>(this->_b) << "}]";
	return sstr.str();
}

std::ostream &		operator<<(std::ostream & o, Color const & rhs)
{
	o << rhs.toString();
	return o;
}
