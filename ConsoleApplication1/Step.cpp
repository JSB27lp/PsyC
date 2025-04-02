#include "Step.h"

Step::Step(Color color, Color colorBorder, Vector3 position, bool empty) :color_{ color }, colorBorder_{ colorBorder }, cubePosition{ position }, empty_(empty) {

}

void Step::draw() {
    if (!empty_) { DrawCube(cubePosition, largeur, hauteur, profondeur, color_); }

    DrawCubeWires(cubePosition, largeur, hauteur, profondeur, colorBorder_);
}

bool Step::collide(Camera3D camera) {
    if (camera.position.x > cubePosition.x - largeur / 2 && camera.position.x < cubePosition.x + largeur / 2) {
        if (camera.position.y > cubePosition.y - hauteur / 2 && camera.position.y < cubePosition.y + hauteur / 2) {
            if (camera.position.z > cubePosition.z - profondeur / 2 && camera.position.z < cubePosition.z + profondeur / 2) {
                return true;
            }
        }
    }
    return false;
}
