#ifndef _INPUT_H
#define _INPUT_H

#include <Arduino.h>
#include <Switch.h>

#include "cube.h"

class Input
{
  public:
    Input(Cube *cubeRef);
    virtual ~Input() {}
    void begin();
    void tick();
  private:
    Switch button = Switch(D3);
    Cube *cube;
};

#endif
