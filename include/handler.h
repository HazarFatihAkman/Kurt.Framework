#ifndef KURT_FRAMEWORK_HANDLER_H
#define KURT_FRAMEWORK_HANDLER_H

#include <stdint.h>
#include <stddef.h>

#define CORE_DECLARE_HANDLER(type, type_response, name) \
  typedef struct { \
    uint8_t (*validator)(const type); \
    type_response (*handle)(type); \
  } handler_##name; \
  \
  extern const handler_##name name; \
  static inline uint8_t handler_##name##_process( \
    const handler_##name *self, \
    type value, \
    type_response out_res \
  ) { \
    if (self != NULL \
     && self->validator != NULL \
     && self->validator(value) == 1) { \
      out_res = self->handle(value); \
      return 1; \
    } \
    return 0; \
  } \

#define CORE_DEFINE_HANDLER(validator, handle, name) \
  const handler_##name name = { \
    .validator = validator, \
    .handle = handle \
  }; \

#endif // KURT_FRAMEWORK_HANDLER_H
