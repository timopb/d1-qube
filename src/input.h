#ifndef _INPUT_H
#define _INPUT_H

#include <Arduino.h>
#include <Switch.h>

#include "cube.h"

class Input
{
  public:
    Input() {}
    virtual ~Input() {}
    void begin();
    void tick(Cube *cubeRef);
  private:
    Switch button = Switch(D3);
};

#endif
