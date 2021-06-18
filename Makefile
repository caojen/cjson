CC = gcc
OBJ_DIR = obj
LIB_DIR = lib
SRC_DIR = src
BIN_DIR = bin
CFLAG = -Wall -I${LIB_DIR} -I${LIB_DIR}/basic
HEADERS = ${LIB_DIR}/cjson.h ${LIB_DIR}/basic/cjson_array.h ${LIB_DIR}/basic/cjson_bool.h ${LIB_DIR}/basic/cjson_null.h \
	${LIB_DIR}/basic/cjson_number.h ${LIB_DIR}/basic/cjson_object.h ${LIB_DIR}/basic/cjson_string.h ${LIB_DIR}/basic/cjson_type.h

OBJS = ${OBJ_DIR}/cjson_number.o

all: ${OBJS}

${OBJ_DIR}/cjson_number.o: ${LIB_DIR}/basic/cjson_number.c ${HEADERS}
	${CC} ${CFLAG} $< -c -o $@

TESTS = ${BIN_DIR}/test_number

tests: ${TESTS}

${BIN_DIR}/test_number: ${SRC_DIR}/test_number.c ${OBJS}
	${CC} ${CFLAG} $^ -o $@