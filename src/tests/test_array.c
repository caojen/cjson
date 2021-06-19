#include "cjson.h"

int main() {
  int one = 1, two = 2, three = 3;

  cjson_array* array = cjson_array_init();
  cjson_array_push(array, &one);
  cjson_array_push(array, &two);
  cjson_array_push(array, &three);
  cjson_array_free(array);
}