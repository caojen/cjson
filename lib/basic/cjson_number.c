#include "cjson_number.h"

cjson_number
cjson_number_integer(isize_64 value) {
  cjson_number ret;
  memset(&ret, 0, sizeof(ret));
  ret.type = NUMBER;
  ret.valuetype = integer;
  ret.value.i = value;
  return ret;
}

cjson_number
cjson_number_double(double value){
  cjson_number ret;
  memset(&ret, 0, sizeof(ret));
  ret.type = NUMBER;
  ret.valuetype = ldouble;
  ret.value.d = value;
  return ret;
}

int
cjson_number_set_integer(cjson_number* number, isize_64 value) {
  if(number == NULL) {
    return CJSON_UNINIT;
  }

  number->valuetype = integer;
  number->value.i = value;
  return CJSON_OK;
}

int
cjson_number_set_double(cjson_number* number, double value) {
  if(number == NULL) {
    return CJSON_UNINIT;
  }

  number->valuetype = ldouble;
  number->value.d = value;
  return CJSON_OK;
}

int
cjson_number_stringify(cjson_number* number, unsigned char* buf, unsigned int maxsz) {
  if(number == NULL) {
    return CJSON_UNINIT;
  }
  if(buf == NULL) {
    return CJSON_BUFCLOSE;
  }

  int ret = CJSON_OK;

  switch (cjson_number_type(*number)) {
    case integer:
      ret = cjson_number_stringify_integer(number, buf, maxsz);
      break;
    case ldouble:
      ret = cjson_number_stringify_double(number, buf, maxsz);
      break;
    default:
      ret = CJSON_ERRTYPE;
  }

  return ret;
}

static int
cjson_number_stringify_integer(cjson_number* number, unsigned char* buf, unsigned int maxsz) {
  if(number == NULL) {
    return CJSON_UNINIT;
  } else if(buf == NULL) {
    return CJSON_BUFCLOSE;
  } else if(maxsz == 0) {
    return CJSON_NOSPACE;
  } else if(cjson_get_type(number) != NUMBER) {
    return CJSON_ERRTYPE;
  }

  unsigned char* ptr = buf;
  isize_64 value = cjson_number_get_integer(*number);
  if(value == 0) {
    if(maxsz <= 1) {
      return CJSON_NOSPACE;
    }
    *ptr = '0';
    *(ptr + 1) = 0;
    return CJSON_OK;
  }

  if(value < 0) {
    *ptr = "-";
    ++ptr;
    value = -value;
  }

  while(value) {
    int digit = value % 10;
    value /= 10;
    if(ptr - buf >= maxsz) {
      return CJSON_NOSPACE;
    }
    *ptr = digit + '0';
    ++ptr;
  }
  if(ptr - buf >= maxsz) {
    return CJSON_NOSPACE;
  }
  *ptr = 0;
  return CJSON_OK;
}

static int
cjson_number_stringify_double(cjson_number* number, unsigned char* buf, unsigned int maxsz) {
  if(number == NULL) {
    return CJSON_UNINIT;
  } else if(buf == NULL) {
    return CJSON_BUFCLOSE;
  } else if(maxsz == 0) {
    return CJSON_NOSPACE;
  } else if(cjson_get_type(number) != NUMBER) {
    return CJSON_ERRTYPE;
  }

  double value = cjson_number_get_double(*number);
  unsigned char* ptr = buf;

  if(value == 0) {
    if(maxsz <= 1) {
      return CJSON_NOSPACE;
    }
    *ptr = '0';
    *(ptr + 1) = 0;
    return CJSON_OK;
  }

  if(value < 0) {
    *ptr = '-';
    ++ptr;
    value = -value;
  }

  isize_64 i = value;
  double f = value - i;

  if(i == 0) {
    if(ptr - buf >= maxsz) {
      return CJSON_NOSPACE;
    }
    *ptr = '0';
    ++ptr;
  } else {
    while(i) {
      int digit = i % 10;
      i /= 10;
      if(ptr - buf >= maxsz) {
        return CJSON_NOSPACE;
      }
      *ptr = digit + '0';
      ++ptr;
    }
  }

  if(ptr - buf >= maxsz) {
    return CJSON_NOSPACE;
  }
  *ptr = '.';
  ++ptr;

  int digit_count = 0;
  while(f && digit_count < CJSON_NUMBER_DOUBLE_MAX_DIGIT) {
    int digit = f * 10;
    f -= (int)f;
    ++digit_count;

    if(ptr - buf >= maxsz) {
      return CJSON_NOSPACE;
    }
    *ptr = digit + '0';
    ++ptr;
  }

  if(ptr - buf >= maxsz) {
    return CJSON_NOSPACE;
  }
  *ptr = 0;
  return CJSON_OK;
}
