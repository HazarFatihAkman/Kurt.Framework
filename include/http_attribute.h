#ifndef KURT_FRAMEWORK_HTTP_ATTRIBUTE_H
#define KURT_FRAMEWORK_HTTP_ATTRIBUTE_H

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

#define HTTP_REQUEST(req_type, path, format, conn_type)

#endif // KURT_FRAMEWORK_HTTP_ATTRIBUTE_H
