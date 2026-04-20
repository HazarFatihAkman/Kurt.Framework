#ifndef KURT_FRAMEWORK_HANDLER_H
#define KURT_FRAMEWORK_HANDLER_H

#include <stdint.h>
#include <stddef.h>

/*
* @brief Default handler with validator.
* Example : GET v1/campings/winter-1
*/
#define CORE_DH(type, type_response, name) \
  typedef struct { \
    uint8_t (*validator)(const type); \
    type_response (*handle)(type); \
  } handler_##name; \
  \
  extern const handler_##name name; \
  static inline uint8_t handler_##name##_process( \
    const handler_##name *self, \
    type value, \
    type_response *out_res \
  ) { \
    if (self != NULL \
     && self->handle != NULL \
     && self->validator != NULL \
     && self->validator(value) == 1) { \
      *out_res = self->handle(value); \
      return 1; \
    } \
    return 0; \
  } \

/*
* @brief No-input handler.
* Example : GET v1/campings
*/
#define CORE_NIH(type_response, name) \
  typedef struct { \
    type_response (*handle)(void); \
  } handler_##name; \
  \
  extern const handler_##name name; \
  static inline uint8_t handler_##name##_process( \
    const handler_##name *self, \
    type_response *out_res \
  ) { \
    if (self != NULL \
     && self->handle != NULL) { \
      *out_res = self->handle(); \
      return 1; \
    } \
    return 0; \
  } \

#define CORE_GET_DECL(_1, _2, _3, MACRO, ...) MACRO
#define CORE_DECLARE_HANDLER(...) CORE_GET_DECL(__VA_ARGS__, CORE_DH, CORE_NIH)(__VA_ARGS__)

#define CORE_DEFINE_HANDLER(name, ...) const handler_##name name = { __VA_ARGS__ }; \

#endif // KURT_FRAMEWORK_HANDLER_H
