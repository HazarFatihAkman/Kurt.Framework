#ifndef KURT_FRAMEWORK_HTTP_ATTRIBUTE_H
#define KURT_FRAMEWORK_HTTP_ATTRIBUTE_H

#include "handler.h"

typedef enum {
  GET,
  HEAD,
  OPTIONS,
  TRACE,
  PUT,
  DELETE,
  POST,
  PATCH,
  CONNECT
} req_type_e;

typedef struct {
  req_type_e type;
  const char *path;
  const char *format;
  const char *conn_type;
} http_properties_t;

/*
* @brief Route definition.
* CORE_ROUTE(GET, "v1/campings", "application/json")
**/
#define CORE_ROUTE(type, path, format, handler)

#endif // KURT_FRAMEWORK_HTTP_ATTRIBUTE_H
