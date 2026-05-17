#ifndef KURT_FRAMEWORK_UTILS_H
#define KURT_FRAMEWORK_UTILS_H

#define CORE_ENUM(name, list) \
typedef enum { \
    list(GENERATE_ENUM) \
} name; \
const char* name##_Strings[] = { \
    list(GENERATE_STRING) \
};

#define GENERATE_ENUM(item) item,
#define GENERATE_STRING(item) #item,

#endif // KURT_FRAMEWORK_UTILS_H

