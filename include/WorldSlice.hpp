#ifndef WORLDSLICE_HPP
#define WORLDSLICE_HPP

#include <iostream>
#include <Cube.hpp>

#define LEFT  1
#define FRONT 2
#define RIGHT 3

class WorldSlice {
public:
	WorldSlice();
	int getDirection() const {return direction;}
	void draw(glm::mat4 modelMat) const;

private:
	int direction;
    Cube ground{{0, 1, 0}};
    Cube test{{1, 0, 1}};

};

#endif
