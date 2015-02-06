
#include "Camera.hpp"

Camera::Camera(Vertex const & origin, Matrix const & direction, double far, double near, double height,
		double width, double fov ) : _origin(origin), _direction(direction),
	_far(far), _near(near), _height(height), _width(width), _viewMatrix(this->_initializeView(origin, direction)),
	_projection(this->_initializeProjection(fov, width, height, near, far))
{
	return ;
}

Camera::Camera(Camera const & src)
{
	*this = src;
	return ;
}

Camera::~Camera( void )
{
}

Matrix		Camera::_initializeView(Vector const & origin, Matrix const & direction)
{
	Vector				vct(origin);
	Matrix				rot = direction.inverse();
	TranslationMatrix	tlt(-vct);
	return (rot * tlt);
}

Matrix		Camera::_initializeProjection(double const fov, double const width,
				double const height, double const near, double const far)
{
	return ProjectionMatrix(fov, width/height, near, far);
}

void		Camera::setOrigin(Vertex const & vtx)
{
	this->_origin = vtx;
}

void		Camera::setDirection(Matrix	const & mtx)
{
	this->_direction = mtx;
}

Vertex	Camera::getOrigin(void) const
{
	return this->_origin;
}

Matrix	Camera::getDirection(void) const
{
	return this->_direction;
}

Matrix	Camera::getProjection(void) const
{
	return this->_projection;
}

Vertex		Camera::watchVertex(Vertex vertex)
{
	Vertex tmp = this->_viewMatrix.transformVertex(vertex);
	Vertex nvtx = this->_projection.transformVertex(tmp);
	nvtx.setX((nvtx.getX() / nvtx.getW()) * (this->_width / 2) + (this->_width / 2));
	nvtx.setY((nvtx.getY() / nvtx.getW()) * (this->_height / 2) + (this->_height / 2));
	nvtx.setZ((nvtx.getZ() / nvtx.getW()) * ((this->_width - this->_height)/ 2) + ((this->_far + this->_near) / 2));
	return nvtx;
}

Triangle	Camera::watchtriangle(Triangle tri)
{
	Vertex A = this->watchVertex(tri.getA());
	Vertex B = this->watchVertex(tri.getB());
	Vertex C = this->watchVertex(tri.getC());
	return (Triangle(A, B, C));
}

Camera &	Camera::operator=(Camera const & rhs)
{
	this->_origin = rhs._origin;
	this->_direction = rhs._direction;
	this->_viewMatrix = rhs._viewMatrix;
	this->_near = rhs._near;
	this->_far = rhs._far;
	this->_width = rhs._width;
	this->_height = rhs._height;
	this->_projection = rhs._projection;
	return *this;
}

