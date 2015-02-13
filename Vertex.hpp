#ifndef VERTEX_HPP
# define VERTEX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Color.hpp"

class Vertex
{
	public:
		Vertex( void );
		Vertex( double x, double y, double z, double w, Color color);
		Vertex( double x, double y, double z, double w, unsigned int color);
		Vertex( double x, double y, double z, Color color);
		Vertex( double x, double y, double z, unsigned int color);
		Vertex(Vertex const & src);
		~Vertex( void );
		double		getX() const;
		double		getY() const;
		double		getZ() const;
		double		getW() const;
		Color		getColor() const;
		void		setX(double x);
		void		setY(double y);
		void		setZ(double z);
		void		setW(double w);
		void		setColor(Color color);
		Vertex &	operator=(Vertex const & rhs);
		Vertex		operator+(Vertex const & rhs);
		Vertex &	operator+=(Vertex const & rhs);
		Vertex		operator*(double const rhs);
		std::string	toString() const;

	private:
		double		_x;
		double		_y;
		double		_z;
		double		_w;
		Color		_color;
};

std::ostream &		operator<<(std::ostream & o, Vertex const & rhs);

#endif /* VERTEX_HPP */
