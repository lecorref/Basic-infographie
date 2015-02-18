CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98 -pedantic-errors -framework OpenGL `sdl2-config --cflags --libs`

SOURCES = main.cpp \
		  Color.cpp \
		  Vertex.cpp \
		  Iswi.cpp \
		  Isometry.cpp \
		  Matrix.cpp \
		  RotationMatrixX.cpp \
		  RotationMatrixY.cpp \
		  RotationMatrixZ.cpp \
		  Renderer.cpp \
		  Triangle.cpp \
		  Lexer.cpp

OBJECTS = $(SOURCES:.cpp=.o)

LIBPATH = /nfs/zfs-student-3/users/2013_paris/tdieumeg/.brew/Cellar/sdl2/2.0.3/include/SDL2/

NAME = mod1

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME) -I $(LIBPATH)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
