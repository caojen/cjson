#include "cjson_array.h"

cjson_array*
cjson_array_init() {
  cjson_array* ret = (cjson_array*) malloc (sizeof(cjson_array));
  memset(ret, 0, sizeof(cjson_array));
  ret->list = cjson_list_init();
  return ret;
}

int
cjson_array_push(cjson_array* array, void* value) {
  if(array == NULL) {
    return CJSON_UNINIT;
  } else if(value == NULL) {
    value = cjson_null_create();
  }

  return cjson_list_push_back(array->list, value);
}

void* cjson_array_at(cjson_array* array, unsigned index) {
  if(index >= array->list->length) {
    return NULL;
  }

  cjson_list_node* listnode = array->list->head;
  while(index--) {
    listnode = listnode->next;
  }
  return listnode->item;
}

int
cjson_array_free(cjson_array* array) {
  if(array) {
    cjson_list_free(array->list);
    free(array);
  }
  return CJSON_OK;
}
