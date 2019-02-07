#include "Input.h"

void Input::tick(Cube *cube)
{
    button.poll();

    if (button.pushed())
    {
        cube->rotateCube = !cube->rotateCube;
    }
}
