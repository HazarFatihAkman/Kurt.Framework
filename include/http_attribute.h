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

typedef enum {
  APP_JSON,
  //...
} format_e;

typedef struct {
  req_type_e type;
  const char *path;
  const char *format;
  const char *conn_type;
} http_properties_t;

/*
* @brief Route definition. Example : (GET, "v1/campaings", APP_JSON, APP_JSON, getCampaings)
**/
#define CORE_ROUTE(type, path, accepted_format, response_format, handler) \


#endif // KURT_FRAMEWORK_HTTP_ATTRIBUTE_H
