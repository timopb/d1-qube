#ifndef _PERFORMER_H
#define _PERFORMER_H

class Performer {
public:
  Performer();
  virtual ~Performer() {}
  void tick();
private:
  int tickcount;
  int tps;
  int beat;
};

#endif
