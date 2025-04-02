#include "Door.h"

void Door::draw() {
    DrawCube(cubePosition, 2.0f, 4.0f, 0.5f, color);
    DrawCubeWires(cubePosition, largeur, hauteur, profondeur, colorBorder);
}

bool Door::collide(Camera3D camera) {
    if (camera.position.x > cubePosition.x - largeur / 2 && camera.position.x < cubePosition.x + largeur / 2) {
        if (camera.position.y > cubePosition.y - hauteur / 2 && camera.position.y < cubePosition.y + hauteur / 2) {
            if (camera.position.z > cubePosition.z - profondeur / 2 && camera.position.z < cubePosition.z + profondeur / 2) {
                return true;
            }
        }
    }
    return false;
}