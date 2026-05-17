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

typedef enum {
  APP_JSON,
  //...
} format_e;

typedef struct {
  req_type_e type;
  char *path;
  format_e format;
  // parameter_count should be parameter count of path.
  // example : {main_path:v1/playground}/{parameter_1:products}/{parameter_2:productName} = 2
  int parameter_count;
  // const char *conn_type;
} http_properties_t;

void print_props(const http_properties_t props);

#endif // KURT_FRAMEWORK_HTTP_ATTRIBUTE_H
