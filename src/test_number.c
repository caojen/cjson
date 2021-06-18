#include <stdio.h>
#include "cjson.h"

int main() {
  cjson_number x = cjson_number_integer(102);
  char buf[20] = { 0 };
  cjson_number_stringify(&x, (char*)buf, 20);
  printf("%s\n", buf);
}
