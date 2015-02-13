#ifndef BEZIER_HPP
# define BEZIER_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <vector>
# include "Vertex.hpp"

class Bezier
{
	public:
		static std::vector<std::vector<Vertex> > *	surface(std::vector<std::vector<Vertex> > & vec, double m, double n, double u, double v);

	private:
		Bezier( void );
		Bezier(Bezier const & src);
		~Bezier( void );
		Bezier &	operator=(Bezier const & rhs);
		static Vertex					_casteljau(std::vector<Vertex> &control, double r, int i, double t);
		static	std::vector<Vertex> *	_courbe(std::vector<Vertex> &control, double n, double t);
};


#endif /* BEZIER_HPP */
