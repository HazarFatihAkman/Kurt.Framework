#ifndef KURT_FRAMEWORK_REQUEST_H
#define KURT_FRAMEWORK_REQUEST_H

#include "http_attribute.h"

#define CORE_DECLARE_REQUEST(properties, content_type, uuid) \
  typedef struct { \
    const uint32_t uuid; \
    const http_properties_t properties; \
    const void *content; \
  } req_##uuid##_t;
  \

#define CORE_DEFINE_REQUEST()

#define CORE_EXTRACT_REQUEST(data, content_type) \

#endif // KURT_FRAMEWORK_REQUEST_H