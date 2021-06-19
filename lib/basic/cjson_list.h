/**
 * implement of list
 */

#ifndef CJSON_LIST_H
#define CJSON_LIST_H

#include <stdlib.h>
#include "cjson_type.h"

struct __cjson_list_node {
  void* item;
  struct __cjson_list_node* prev;
  struct __cjson_list_node* next;
};

typedef struct __cjson_list_node cjson_list_node;

struct __cjson_list {
  cjson_list_node* head;
  cjson_list_node* tail;

  unsigned length;
};

typedef struct __cjson_list cjson_list;

#define cjson_list_init() ({                                                        \
  cjson_list* ret = (cjson_list*) malloc (sizeof(cjson_list));                      \
  memset(ret, 0, sizeof(cjson_list));                                               \
  ret;                                                                              \
})

#define cjson_list_push_back(list, item) ({                                           \
  int ret = CJSON_OK;                                                                 \
  if(list == NULL) {                                                                  \
    ret = CJSON_UNINIT;                                                               \
  } else {                                                                            \
    cjson_list_node* listnode = (cjson_list_node*) malloc (sizeof(cjson_list_node));  \
    memset(listnode, 0, sizeof(cjson_list_node));                                     \
    listnode->item = item;                                                            \
    if(list->head == NULL) {                                                          \
      list->head = list->tail = listnode;                                             \
    } else if(list->head == list->tail) {                                             \
      list->head->next = listnode;                                                    \
      listnode->prev = list->head;                                                    \
      list->tail = listnode;                                                          \
    } else {                                                                          \
      listnode->prev = list->tail;                                                    \
      list->tail->next = listnode;                                                    \
      list->tail = listnode;                                                          \
    }                                                                                 \
    ret = CJSON_OK;                                                                   \
  }                                                                                   \
  ret;                                                                                \
})

#define cjson_list_push_front(list, item) ({                                          \
  int ret = CJSON_OK;                                                                 \
  if(list == NULL) {                                                                  \
    ret = CJSON_UNINIT;                                                               \
  } else {                                                                            \
    cjson_list_node* listnode = (cjson_list_node*) malloc (sizeof(cjson_list_node));  \
    memset(listnode, 0, sizeof(cjson_list_node));                                     \
    listnode->item = item;                                                            \
    if(list->head == NULL) {                                                          \
      list->head = list->tail = listnode;                                             \
    } else if(list->head == list->tail) {                                             \
      list->tail->prev = listnode;                                                    \
      listnode->next = list->tail;                                                    \
      list->head = listnode;                                                          \
    } else {                                                                          \
      listnode->next = list->head;                                                    \
      list->head->prev = listnode;                                                    \
      list->head = listnode;                                                          \
    }                                                                                 \
    ret = CJSON_OK;                                                                   \
  }                                                                                   \
  ret;                                                                                \
})

#endif
