/**
 * 
 * Specify 'type' of Value
 * 'type' is a string, number(int or double), boolean(true or false), null, array or object
 * 
 */

#ifndef CJSON_TYPE_H
#define CJSON_TYPE_H

enum __cjson_type {
  STRING,
  NUMBER,
  BOOLEAN,
  NULL,
  ARRAY,
  OBJECT
};

#endif
