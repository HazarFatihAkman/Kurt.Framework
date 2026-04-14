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

#define CORE_CONTROLLER(path, handlers, name, data) \
  typedef struct { \
    char *path; \
    void **handlers; \
    char *data; \
  } controller_##name; \
  \
  static inline uint8_t controller_##name##__process( \
  ) { \
    return 0; \
  }


#endif /* KURT_FRAMEWORK_CONTROLLER_MANAGER_H */
