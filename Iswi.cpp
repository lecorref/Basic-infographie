#include "Iswi.hpp"

std::vector<std::vector<Vertex> > &			Iswi::surface(std::vector<Vertex >  & control, int x, int y, int width, int height)
{
	std::vector<std::vector<Vertex> >		*res = new std::vector<std::vector<Vertex> >;
	std::vector<Vertex>						tmp;
	double									divx = static_cast<double>(width) / static_cast<double>(x);
	double									divy = static_cast<double>(height) / static_cast<double>(y);

	Iswi::_generate(control, x, y, width, height);
	for (int i = 0; i < x; i++)
	{
		tmp.clear();
		for (int j = 0; j < y; j++)
		{
			Vertex vtx = Vertex(i * divx, - (Iswi::_avg(control, i * divx, j * divy)), j * divy);
			tmp.push_back(vtx);
		}
		res->push_back(tmp);
	}
	return *res;
}

void										Iswi::_generate(std::vector<Vertex > & control, int x, int y, int width, int height)
{
	double									divx = static_cast<double>(width) / 50.0;
	double									divy = static_cast<double>(height) / 50.0;
	Vertex									vtx;
	Vertex									vtx2;

	for (int i = -1; i <= 50; i++)
	{
		vtx = Vertex(i * divx, -height / 4.0, 0);
		vtx2 = Vertex(i * divx, (y + 1) * (height / 4.0), 0);
		control.push_back(vtx);
		control.push_back(vtx2);
	}
	for (int j = 0; j < 50; j++)
	{
		vtx = Vertex(-width / 4.0, j * divy, 0);
		vtx2 = Vertex((x + 1) * (width / 4.0), j * divy, 0);
		control.push_back(vtx);
		control.push_back(vtx2);
	}
}
double										Iswi::_avg(const std::vector<Vertex > &control, double x, double y)
{
	double									z = 0;
	double									tmp;
	double									save = 0;
	std::vector<Vertex >::const_iterator	it;

	for (it = control.begin(); it != control.end(); ++it)
	{
		tmp = (std::pow(x - (*it).getX(), 2) + std::pow(y - (*it).getY(), 2));
		if (tmp == 0)
			return (*it).getZ();
	z += (*it).getZ() / tmp;
		save += 1.0 / tmp;
	}
	z /= save;
	return z;
}
