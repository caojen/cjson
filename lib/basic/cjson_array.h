#ifndef CJSON_ARRAY_H
#define CJSON_ARRAY_H

#include "cjson.h"

struct __cjson_array {
  TYPE type;
  unsigned length;
  void** values;
};

typedef struct __cjson_array cjson_array;

cjson_array* cjson_array_init();

#define CJSON_ARRAY_INITIALIZER cjson_array_init()

/**
 * Push a value at the end of array
 */
int cjson_array_push(cjson_array* array, void* value);


void* cjson_array_at(cjson_array* array, unsigned index);

#endif
