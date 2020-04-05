#include <WorldSlice.hpp>

WorldSlice::WorldSlice() {
	direction = LEFT;

    glm::mat4 modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, -10.0f));
    modelMat = glm::scale(modelMat, glm::vec3(0.2, 0.2, 0.2));
    test.setModelMat(modelMat);

    modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, -sliceLength/2));
    modelMat = glm::scale(modelMat, glm::vec3(2, 0.1, sliceLength + 2));
    ground.setModelMat(modelMat);
}

void WorldSlice::draw(glm::mat4 viewMat) const {
    ground.draw(viewMat);
    test.draw(viewMat);
}
