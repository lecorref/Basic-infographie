#ifndef ISOMETRY_HPP
# define ISOMETRY_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <cmath>
# include <vector>
# include "Vertex.hpp"
# include "RotationMatrixZ.hpp"
# include "RotationMatrixY.hpp"
# include "RotationMatrixX.hpp"
# define deg2rad(angle) angle / 180 * M_PI

class Isometry
{
	public:
		static std::vector<std::vector<Vertex> >	toIso(std::vector<std::vector<Vertex> > const & surface);
		static std::vector<Triangle>				toTriangles(std::vector<std::vector<Vertex> > const & surface);
	private:
		Isometry( void );
		Isometry(Isometry const & src);
		~Isometry( void );
		Isometry &	operator=(Isometry const & rhs);
};
#endif /* ISOMETRY_HPP */
