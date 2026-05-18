#ifndef KURT_FRAMEWORK_ENUM_H
#define KURT_FRAMEWORK_ENUM_H

#include <string.h>

#define CORE_ENUM(name, list, str_list) \
  typedef enum { \
      list(GENERATE_ENUM) \
  } name; \
  const char* name##_Strings[] = { \
      str_list(GENERATE_STRING) \
  };

#define GENERATE_ENUM(item) item,
#define GENERATE_STRING(item) #item,

#endif // KURT_FRAMEWORK_ENUM_H
