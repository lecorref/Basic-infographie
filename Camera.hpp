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

		void		setOrigin(Vertex const & vtx);
		void		setDirection(Matrix	const & mtx);

		Vertex		getOrigin(void) const;
		Matrix 		getDirection(void) const;
		Matrix 		getProjection(void) const;

		Vertex		watchVertex(Vertex vertex);
		Triangle	watchtriangle(Triangle tri);
		Camera &	operator=( Camera const & rhs );
	private:
		Camera( void );
		Matrix				_initializeView(Vector const & origin, Matrix const & direction);
		Matrix				_initializeProjection(double const fov, double const width,
									double const height, double const near, double const far);

		Vertex 				_origin;
		Matrix				_direction;
		double				_far;
		double				_near;
		double				_height;
		double				_width;
		Matrix				_viewMatrix;
		Matrix				_projection;
};

#endif /* CAMERA_HPP */
