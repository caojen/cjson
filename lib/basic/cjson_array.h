#ifndef CJSON_ARRAY_H
#define CJSON_ARRAY_H

#include "cjson.h"

struct __cjson_array {
  TYPE type;
  unsigned length;
  void** values;
};

#endif
