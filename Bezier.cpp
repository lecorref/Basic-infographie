
#include "Bezier.hpp"

std::vector<std::vector<Vertex> > *		Bezier::surface(std::vector<std::vector<Vertex> > & vec, double m, double n, double u, double v)
{
	std::vector<std::vector<Vertex>	>	*ret = new std::vector<std::vector<Vertex> >;
	std::vector<Vertex>					tmp;
	std::vector<std::vector<Vertex> >	curves;
	std::vector<std::vector<Vertex> >::iterator		it;

	for (it = vec.begin(); it != vec.end(); ++it)
	{
		curves.push_back(*Bezier::_courbe(*it, n, v));
	}
	for (int i = 0 ; i < v ; i++)
	{
		tmp.clear();
		for (int j = 0 ; j <= m ; j++)
			tmp.push_back(curves[j][i]);
		ret->push_back(*Bezier::_courbe(tmp, m, u));
	}
	return ret;
}

std::vector<Vertex> *			Bezier::_courbe(std::vector<Vertex> &control, double n, double t)
{
	std::vector<Vertex> *vec = new std::vector<Vertex>;
	double				d = 0;
	double				dv = 1 / t;

	while (d <= 1.0)
	{
		Vertex vtx = Bezier::_casteljau(control, n, 0, d);
		vec->push_back(vtx);
		d += dv;
	}
	return vec;
}

Vertex					Bezier::_casteljau(std::vector<Vertex> &control, double r, int i, double t)
{
	if (r == 1)
		return control[i] * (1.0 - t) + control[i + 1] * t;
	return Bezier::_casteljau(control, r - 1, i, t) * (1.0 - t) + Bezier::_casteljau(control, r - 1, i + 1, t) * t;
}

