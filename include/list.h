#ifndef KURT_FRAMEWORK_LIST_H
#define KURT_FRAMEWORK_LIST_H

// CORE_CREATE_KEY_VALUE()
#define CORE_CKV(name, key_type, value_type) \
  typedef struct { \
    key_type key; \
    value_type value; \
  } name##_t; \


#define CORE_DECLARE_LIST(name, kv_type, size_l) \
  typedef struct { \
    int size; \
    kv_type values[size_l]; \
  } name##_t; \
  \
  extern const name##_t name; \

#define CORE_DEFINE_LIST(name, ...) const name##_t name = { __VA_ARGS__ }; \



#endif // KURT_FRAMEWORK_LIST_H
