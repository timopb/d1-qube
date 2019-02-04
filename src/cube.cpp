#include "defs.h"
#include "output.h"
#include "cube.h"

void Cube::tick()
{
  if (!rotateCube) return;

  r[0] = r[0] + PI / 180.0; // Add a degree
  r[1] = r[1] + PI / 180.0; // Add a degree
  r[2] = r[2] + PI / 180.0; // Add a degree
  if (r[0] >= 360.0 * PI / 180.0) r[0] = 0;
  if (r[1] >= 360.0 * PI / 180.0) r[1] = 0;
  if (r[2] >= 360.0 * PI / 180.0) r[2] = 0;

  for (int i=0; i<8; i++)
  {
    float px2 = px[i];
    float py2 = cos(r[0]) * py[i] - sin(r[0]) * pz[i];
    float pz2 = sin(r[0]) * py[i] + cos(r[0]) * pz[i];

    float px3 = cos(r[1]) * px2 + sin(r[1]) * pz2;
    float py3 = py2;
    float pz3 = -sin(r[1]) * px2 + cos(r[1]) * pz2;

    float ax = cos(r[2]) * px3 - sin(r[2]) * py3;
    float ay = sin(r[2]) * px3 + cos(r[2]) * py3;
    float az = pz3-150;

    p2x[i] = SCREEN_WIDTH / 2 + ax * CUBE_SHAPE_SIZE / az;
    p2y[i] = SCREEN_HEIGHT / 2 + ay * CUBE_SHAPE_SIZE / az;
  }

  output.display->clearDisplay();

  for (int i=0;i<3;i++)
  {
    output.display->drawLine(p2x[i],   p2y[i],   p2x[i+1], p2y[i+1], WHITE);
    output.display->drawLine(p2x[i+4], p2y[i+4], p2x[i+5], p2y[i+5], WHITE);
    output.display->drawLine(p2x[i],   p2y[i],   p2x[i+4], p2y[i+4], WHITE);
  }
  output.display->drawLine(p2x[3], p2y[3] ,p2x[0] ,p2y[0], WHITE);
  output.display->drawLine(p2x[7], p2y[7] ,p2x[4] ,p2y[4], WHITE);
  output.display->drawLine(p2x[3], p2y[3] ,p2x[7] ,p2y[7], WHITE);

  output.display->display();
}
