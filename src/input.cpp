/*
    Input handling demo utilizing the Wemos 1-Button Shield
    and the Switch library by Albert van Dalen
*/
#include "Input.h"

Input::Input(Cube *cubeRef)
{
    cube = cubeRef;
}

void Input::tick()
{
    button.poll();

    if (button.pushed())
    {
        cube->rotateCube = !cube->rotateCube;
    }
}
