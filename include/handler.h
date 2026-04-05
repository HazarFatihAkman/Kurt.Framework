#ifndef KURT_FRAMEWORK_HANDLER_H
#define KURT_FRAMEWORK_HANDLER_H

#include <stdint.h>

#define __HANDLER__(type, type_response, name) \
  typedef struct { \
    type value; \
    uint8_t (*validator)(const type); \
    type_response (*handle)(type*, uint8_t locked); \
  } handler_##name;

#endif // KURT_FRAMEWORK_HANDLER_H

