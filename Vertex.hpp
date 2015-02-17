#ifndef VERTEX_HPP
# define VERTEX_HPP
# include <string>
# include <sstream>
# include <iostream>

class Vertex
{
	public:
		Vertex( void );
		Vertex( double x, double y, double z);
		Vertex(Vertex const & src);
		~Vertex( void );
		double		getX() const;
		double		getY() const;
		double		getZ() const;
		void		setX(double x);
		void		setY(double y);
		void		setZ(double z);
		Vertex &	operator=(Vertex const & rhs);
		Vertex		operator+(Vertex const & rhs);
		Vertex &	operator+=(Vertex const & rhs);
		Vertex		operator*(double const rhs);
		std::string	toString() const;

	private:
		double		_x;
		double		_y;
		double		_z;
};

std::ostream &		operator<<(std::ostream & o, Vertex const & rhs);

#endif /* VERTEX_HPP */
