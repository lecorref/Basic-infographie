#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <cmath>
# include "Vertex.hpp"

class Vector
{
	public:
		Vector( void );
		Vector( Vertex const & dest );
		Vector( Vertex const & ori, Vertex const & dest);
		Vector( double const x, double const y, double const z );
		Vector(Vector const & src);
		~Vector( void );
		Vector		operator-() const;
		Vector		operator-(Vector const & rhs) const;
		Vector		operator+(Vector const & rhs) const;
		double		operator*(Vector const & rhs) const;
		Vector		operator*(double const k) const;
		Vector		operator^(Vector const & rhs) const;
		Vector &	operator=(Vector const & rhs);
		double		getX() const;
		double		getY() const;
		double		getZ() const;
		double		magnitude() const;
		Vector		normalize() const;
		double		cos(Vector const & rhs) const;
		std::string	toString() const;

	private:
		double		_x;
		double		_y;
		double		_z;
};

std::ostream &		operator<<(std::ostream & o, Vector const & rhs);

#endif /* VECTOR_HPP */
