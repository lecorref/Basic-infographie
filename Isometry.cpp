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

std::vector<Triangle>			Isometry::toTriangles(std::vector<std::vector<Vertex> > const & surface)
{
	Vertex						a;
	Vertex						b;
	Vertex						c;
	std::vector<Triangle>		lst;
	int							width = surface.size();
	int							height = surface[0].size();

	for (int j = height - 1; j > 0; j--)
	{
		for (int i = 0; i < width - 1; i++)
		{
			a = surface[i][j];
			b = surface[i][j - 1];
			c = surface[i + 1][j - 1];
			lst.push_back(Triangle(a, b, c));
			a = surface[i + 1][j];
			b = surface[i][j];
			c = surface[i + 1][j - 1];
			lst.push_back(Triangle(a, b, c));
		}
	}
	return lst;
}
