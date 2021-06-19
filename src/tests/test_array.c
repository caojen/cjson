#include "cjson.h"

int main() {
  cjson_number* one = cjson_number_integer(1);
  cjson_number* two = cjson_number_integer(2);
  cjson_number* three = cjson_number_integer(3);
  cjson_number* done = cjson_number_double(2.09);
  cjson_number* dtwo = cjson_number_double(905.12);
  cjson_number* four = cjson_number_integer(4);

  cjson_array* array = cjson_array_init();
  cjson_array_push(array, one);
  cjson_array_push(array, two);
  cjson_array_push(array, three);
  cjson_array_push(array, done);
  cjson_array_push(array, dtwo);
  cjson_array_push(array, four);
  cjson_string* sone = cjson_string_from_cstring("one");
  cjson_array_push(array, sone);
  cjson_string* stwo = cjson_string_from_cstring("two23\"\\");
  cjson_array_push(array, stwo);
  cjson_string* null = cjson_null_create();
  cjson_array_push(array, null);

  char buf[200];
  int res;
  res = cjson_array_stringify(array, buf, 200);

  printf("%s, %d\n", buf, res);
  cjson_array_free(array);
}