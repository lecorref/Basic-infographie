#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "ProjectionMatrix.hpp"
# include "TranslationMatrix.hpp"
# include "ProjectionMatrix.hpp"
# include "Matrix.hpp"
# include "Vertex.hpp"
# include "Vector.hpp"

class Camera
{
	public:
		Camera( void );
		Camera(Camera const & src );
		~Camera( void );



		Vertex		watchVertex(Vertex vertex);
		Trian	watchtriangle(Vertex vertex);
		Camera &	operator=( Camera const & rhs );
	private:
		Vertex				_origin;
		Matrix				_direction;
		RotationMatrix		_tRotation;
		TranslationMatrix	_tTranslation;
		Matrix				_viewMatrix;
		double				_near;
		double				_far;
		double				_ratio;
		ProjectionMatrix	_projection;
};

#endif /* CAMERA_HPP */
