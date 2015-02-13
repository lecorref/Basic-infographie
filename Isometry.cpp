
#include "Isometry.hpp"

std::vector<std::vector<Vertex> > Isometry::toIso(std::vector<std::vector<Vertex> > const & surface)
{
	std::vector<std::vector<Vertex> >	ret;
	double								tab[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	Matrix								mat(tab);
	Matrix								rot = RotationMatrixX(deg2rad(35.264)) * RotationMatrixY(deg2rad(45.0));
	std::vector<Vertex> row;

	ret.reserve(surface.size());
	for (unsigned int i = 0; i < surface.size(); i++)
	{
		row.clear();
		row.reserve(surface[i].size());
		for (int j = surface[i].size() - 1; j >= 0; j--)
		{
			Vertex tmp = mat * (rot * surface[i][j]);
			tmp.setZ(surface[i][j].getZ());
			row.push_back(tmp);
		}
		ret.push_back(row);
	}
	return ret;
}
