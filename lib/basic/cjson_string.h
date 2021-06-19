/**
 * string
 * 
 * no extra 0 is tailing.
 */

#ifndef CJSON_STRING_H
#define CJSON_STRING_H

#include "cjson_type.h"

struct __cjson_string {
  TYPE type;

  unsigned length;
  unsigned capcity;
  unsigned char* buf;
};

typedef struct __cjson_string cjson_string;

cjson_string cjson_string_init();
cjson_string cjson_string_from_cstring(const unsigned char* str);
int cjson_string_set_cstring(cjson_string* string, const unsigned char* str);
int cjson_string_to_cstring(const cjson_string* string, unsigned char* buf, unsigned maxsz);
int cjson_string_free(cjson_string* string);

/**
 * string stringify
 * 10 => "10"
 * sk99 => "sk99"
 * this's abc "ttt" => "this's abc \"ttt\""
 * what? \/ => "what? \\/"
 */
int cjson_string_stringify(const cjson_string* string, unsigned char* buf, unsigned maxsz);
#define cjson_string_parse cjson_string_from_cstring

#endif
