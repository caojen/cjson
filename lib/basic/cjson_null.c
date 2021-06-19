#include "cjson_null.h"

CJSON_NULL
cjson_null_create() {
  CJSON_NULL ret;
  ret.type = NUL;

  return ret;
}

int
cjson_null_stringify(CJSON_NULL* null, unsigned char* buf, unsigned maxsz) {
  if(maxsz < 5) {
    return CJSON_NOSPACE;
  } else if(buf == NULL) {
    return CJSON_BUFCLOSE;
  } else if(null == NULL) {
    return CJSON_UNINIT;
  }

  buf[0] = 'n';
  buf[1] = 'u';
  buf[2] = 'l';
  buf[3] = 'l';
  buf[4] = 0;

  return CJSON_OK;
}
