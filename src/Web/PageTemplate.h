#ifndef _PAGETEMPLATE_H
#define _PAGETEMPLATE_H

#include <WString.h>

class PageTemplate {
public:
  PageTemplate() {};
  virtual ~PageTemplate() {}
  String PageBegin();
  String PageFooter();
  String PageEnd();
  String NavBar();
  String Title = "";
};

#endif
