#ifndef ISWI_HPP
# define ISWI_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <cmath>
# include <vector>
# include "Vertex.hpp"

class Iswi
{
	public:
		static	std::vector<std::vector<Vertex> > & surface(const std::vector<Vertex >  & control, int x, int y, int width, int height);

	private:
		static	double			_avg(const std::vector<Vertex > &control, double x, double y);
		Iswi( void );
		Iswi(Iswi const & src);
		~Iswi( void );
		Iswi &	operator=(Iswi const & rhs);
};
#endif /* ISWI_HPP */
