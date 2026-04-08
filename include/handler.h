#ifndef KURT_FRAMEWORK_HANDLER_H
#define KURT_FRAMEWORK_HANDLER_H

#include <stdint.h>

#define CORE_HANDLER(type, type_response, name) \
  typedef struct { \
    type value; \
    uint8_t (*validator)(const type); \
    type_response (*handle)(type*, uint8_t locked); \
  } handler_##name; \
  \
  static inline uint8_t handler_##name##_process(handler_##name *h, type_response out_res) { \
    if (h != NULL && h->validator(h->value) == 1) { \
      out_res = h->handle(&h->value, 0); \
      return 1; \
    } \
    return 0; \
  }
#endif // KURT_FRAMEWORK_HANDLER_H

