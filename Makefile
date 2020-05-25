NAME = 42run
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,obj/%.o,$(SRC))
UNAME = $(shell uname -s)
CXXFLAGS = -I ./include -I ./glfw/include -I ./glad/include -std=gnu++14 -Wall -Wextra -Wno-deprecated-declarations # -Werror
ifneq (, $(findstring MINGW, $(UNAME)))
	LDFLAGS = -L ./glfw/lib-mingw -lglfw3 -lgdi32
	NAME = 42run.exe
else ifeq ($(UNAME), Darwin)
	# https://www.glfw.org/docs/3.0/build.html#build_link_osx
	LDFLAGS = -L ./glfw/lib-macos -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
endif
.PHONY: all clean fclean re

all: obj $(NAME)

obj:
	mkdir -p obj/

obj/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/glad.o: glad/src/glad.c
	$(CXX) $(CXXFLAGS) -o $@ -c $<

obj/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ) obj/glad.o
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all
