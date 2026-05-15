#ifndef KURT_FRAMEWORK_CONTROLLER_H
#define KURT_FRAMEWORK_CONTROLLER_H

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

#define CORE_CONTROLLER(path, name, data) \
  typedef struct { \
    char *path; \
    char *data; \
  } controller_##name; \
  \
  static inline uint8_t controller_##name##__process( \
    const controller_##name *self \
  ) { \
    return 0; \
  }


#endif /* KURT_FRAMEWORK_CONTROLLER_MANAGER_H */
