#include <stdio.h>
#include "cjson.h"

int main() {
  cjson_number x = cjson_number_integer(1012);
  char buf[20] = { 0 };
  cjson_number_stringify(&x, (char*)buf, 20);
  printf("%s\n", buf);

  cjson_number y = cjson_number_double(172.32);
  cjson_number_stringify(&y, (char*)buf, 20);
  printf("%s\n", buf);
}
