#include "cjson_bool.h"

cjson_bool
cjson_bool_create(int istrue) {
  cjson_bool ret;
  memset(&ret, 0, sizeof(ret));

  ret.type = BOOLEAN;
  if(istrue) {
    ret.istrue = 1;
  } else {
    ret.istrue = 0;
  }

  return ret;
}

int
cjson_bool_stringify(cjson_bool* _bool, unsigned char* buf, unsigned maxsz) {
  if(_bool == NULL) {
    return CJSON_UNINIT;
  } else if(buf == NULL) {
    return CJSON_BUFCLOSE;
  } else if(cjson_get_type(_bool) != BOOLEAN) {
    return CJSON_ERRTYPE;
  }

  if(_bool->istrue) {
    if(maxsz < 5) {
      return CJSON_NOSPACE;
    }
    buf[0] = 't';
    buf[1] = 'r';
    buf[2] = 'u';
    buf[3] = 'e';
    buf[4] = 0;
  } else {
    if(maxsz < 6) {
      return CJSON_NOSPACE;
    }
    buf[0] = 'f';
    buf[1] = 'a';
    buf[2] = 'l';
    buf[3] = 's';
    buf[4] = 'e';
    buf[5] = 0;
  }
}
