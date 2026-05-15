#ifndef KURT_FRAMEWORK_CONTROLLER_H
#define KURT_FRAMEWORK_CONTROLLER_H

#include "handler.h"
#include "request.h"

#define CORE_DECLARE_CONTROLLER_PATH(name) \
  typedef struct { \
    http_properties_t props; \
    void (*process) (req_t *req); \
  } controller_path_t; \
  \
  extern const controller_path_t name; \

#define CORE_DEFINE_CONTROLLER_PATH(name, ...) const controller_path_t name =  { __VA_ARGS__ }; \

/*
  include handler_1
  include handler_2

  const void **handlers = {
    handler_1,
    handler_2
  };

  core_controller("/v1/test", handlers, test);
*/

/* Searching algorithm should be O(1). So something like enum creator maybe fit on it. 
  
  CORE_CONTROLLER_HANDLERS(handler_get, handler_post, ...); -> works once at the start.
    ** inner CORE_CONTROLLER_HANDLERS() {
        **Think about here**
    }

  CORE_CE(get-test) -> GET_TEST;

  ** Other process **
  GET_TEST will address "get" -> GET_TEST.handler_get_process(); // improve it
*/

#endif /* KURT_FRAMEWORK_CONTROLLER_MANAGER_H */
