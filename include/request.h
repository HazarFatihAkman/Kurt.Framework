#ifndef KURT_FRAMEWORK_REQUEST_H
#define KURT_FRAMEWORK_REQUEST_H

#include "http_attribute.h"

typedef struct {
  http_properties_t props;
  int content_len;
  char *content;
} req_t;

#define CORE_DECLARE_REQUEST() \

#define CORE_DEFINE_REQUEST()

#define CORE_EXTRACT_REQUEST(data) \
/*
  DATA EXTRACT METHODS
*/

#endif // KURT_FRAMEWORK_REQUEST_H