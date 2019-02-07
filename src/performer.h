#ifndef _PERFORMER_H
#define _PERFORMER_H

class Performer {
public:
  Performer();
  virtual ~Performer() {}
  void tick();
  unsigned long tps;
private:
  unsigned long tickcount;
  unsigned long beat;
};

#endif
