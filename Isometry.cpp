
#include "Isometry.hpp"

std::vector<std::vector<Vertex> > Isometry::toIso(std::vector<std::vector<Vertex> > const & surface)
{
	Matrix								rot = RotationMatrixX(deg2rad(35.264)) * RotationMatrixY(deg2rad(45.0));
	std::vector<std::vector<Vertex> >	ret;
	std::vector<Vertex>					row;

	std::cout << rot.toString() << std::endl;
	ret.reserve(surface.size());
	for (unsigned int i = 0; i < surface.size(); i++)
	{
		row.clear();
		row.reserve(surface[i].size());
		for (int j = surface[i].size() - 1; j >= 0; j--)
		{
			Vertex tmp = (rot * surface[i][j]);
			tmp.setZ(surface[i][j].getY());
			tmp.setX(tmp.getX() + 100);
			tmp.setY(tmp.getY() + 480);
			row.push_back(tmp);
		}
		ret.push_back(row);
	}






	return ret;
}
