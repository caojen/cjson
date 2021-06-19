#include "cjson.h"

int main() {
  cjson_object* object = cjson_object_init();
  char buf[1000];
  int ret = 0;

  cjson_string* sone = cjson_string_parse("one");
  cjson_number* none = cjson_number_integer(1);
  cjson_string* stwo = cjson_string_parse("two");
  cjson_number* ntwo = cjson_number_integer(2);
  cjson_string* sthr = cjson_string_parse("three");
  cjson_number* nthr = cjson_number_integer(3);
  cjson_string* sfou = cjson_string_parse("four");
  cjson_number* nfou = cjson_number_integer(4);
  cjson_string* sfiv = cjson_string_parse("five\"\"\"\"\"");
  cjson_string* sfv = cjson_string_parse("ok. it is a string...");
  cjson_string* six = cjson_string_parse("six");
  cjson_null* null_six = CJSON_NULL_INITIALIZER;
  cjson_string* sev = cjson_string_parse("sev");
  cjson_bool* bt = CJSON_BOOL_TRUE;
  cjson_string* eig = cjson_string_parse("eight");
  cjson_bool* bf = CJSON_BOOL_FALSE;
  cjson_bool* bf2 = CJSON_BOOL_FALSE;
  
  cjson_object_set(object, sone, none);
  cjson_object_set(object, stwo, ntwo);
  cjson_object_set(object, sthr, nthr);
  cjson_object_set(object, sfou, nfou);
  cjson_object_set(object, sfiv, sfv);
  cjson_object_set(object, six, null_six);
  cjson_object_set(object, sev, bt);
  cjson_object_set(object, eig, bf);
  // reset
  cjson_object_set(object, six, bf2);

  ret = cjson_object_stringify(object, buf, 1000);
  printf("%s, %d\n", buf, ret);
}
