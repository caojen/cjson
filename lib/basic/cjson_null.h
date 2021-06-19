#ifndef CJSON_NULL_H
#define CJSON_NULL_H

#include "cjson_type.h"

struct __cjson_null {
  TYPE type;
};

typedef struct __cjson_null CJSON_NULL;

CJSON_NULL cjson_null_create();

#define CJSON_null cjson_null_create()

int cjson_null_stringify(CJSON_NULL* null, unsigned char* buf, unsigned maxsz);

#endif
