/**
 * 
 * Specify 'type' of Value
 * 'type' is a string, number(int or double), boolean(true or false), null, array or object
 * 
 * All types are constructed as follow:
 * {
 *     type: (enum __cjson_type)
 *     // value: implemented based on the type
 * }
 * 
 * Note that enum is stored as int, 4 bits.
 * 
 * So, if a void pointer got, we can just use (enum __cjson_type)pointer to specify the type
 * 
 * Each type implemented one method like `cjson_xx_stringify`
 * This methods is to parse an value into string.
 * For example, number 10 => "10"; string "abc" => "\"abc\""
 * 
 */

#ifndef CJSON_TYPE_H
#define CJSON_TYPE_H

#include <stdio.h>
#include <string.h> // include for memset, strlen...

enum __cjson_type {
  STRING,
  NUMBER,
  BOOLEAN,
  NUL,
  ARRAY,
  OBJECT
};

typedef enum __cjson_type TYPE;

#define cjson_get_type(ptr) (*(enum __cjson_type*)(ptr))

/**
 * Define some values that can be used in returned function.
 */
#define CJSON_OK 0
#define CJSON_UNINIT 1
#define CJSON_NOSPACE 2
#define CJSON_BUFCLOSE 3
#define CJSON_ERRTYPE 4

#define CJSON_BUFLEN(buf) ({              \
  unsigned char* ptr = buf;               \
  unsigned ret = 0;                       \
  while(*ptr) {                           \
    ++ret, ++ptr;                         \
  }                                       \
  ret;                                    \
})

#define CJSON_BUFREV(buf) do {            \
  unsigned len = CJSON_BUFLEN(buf);       \
  for(unsigned i = 0; i < len / 2; i++) { \
    unsigned char tmp = buf[i];           \
    buf[i] = buf[len - i - 1];            \
    buf[len - i - 1] = tmp;               \
  }                                       \
} while (0)

#endif
