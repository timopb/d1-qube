#ifndef _CUBE_H
#define _CUBE_H

class Cube {
public:
  Cube() {};
  virtual ~Cube() {}
  void tick();
  bool rotateCube = false;
private:
  float d = 3;
  float px[8] = {-d,  d,  d, -d, -d,  d,  d, -d };
  float py[8] = {-d, -d,  d,  d, -d, -d,  d,  d };
  float pz[8] = {-d, -d, -d, -d,  d,  d,  d,  d };
  float p2x[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  float p2y[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  float r[8] = {0, 0, 0};
};

#endif
