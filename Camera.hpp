#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "ProjectionMatrix.hpp"
# include "TranslationMatrix.hpp"
# include "Matrix.hpp"
# include "Vertex.hpp"
# include "Vector.hpp"
# include "Triangle.hpp"

class Camera
{
	public:
		Camera(Vertex const & origin, Matrix const & direction, double far, double near,
				double height, double width, double fov );
		Camera(Camera const & src );
		~Camera( void );

		void		setOrigin(Vertex const * vtx);
		void		setDirection(Matrix	const * mtx);

		Vertex const	getOrigin(void) const;
		Matrix const	getDirection(void) const;
		Matrix const	getProjection(void) const;

		Vertex		watchVertex(Vertex vertex);
		Triangle	watchtriangle(Triangle tri);
		Camera &	operator=( Camera const & rhs );
	private:
		Camera( void );

		Vertex const *		_origin;
		Matrix const *		_direction;
		double				_far;
		double				_near;
		double				_height;
		double				_width;
		double				_fov;
		Matrix const *		_viewMatrix;
		Matrix const *		_projection;
};

#endif /* CAMERA_HPP */
