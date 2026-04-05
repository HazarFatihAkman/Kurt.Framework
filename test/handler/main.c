#include "../../include/handler.h"
#include <stdint.h>
#include <stdio.h>

typedef struct _test_ {
  const char *val;
} _test_t_;

uint8_t validate_test(const _test_t_ t) {
  if (t.val == NULL || t.val[0] == '\0') return 0;
  return 1;
}

uint8_t handle_post(_test_t_ *test, uint8_t locked) {
  printf("%s\n", test->val);
  return 1;
}

typedef _test_t_* _test_ptr_;

_test_ptr_ handle_get(_test_t_ *test, uint8_t locked) {
  printf("%s\n", test->val);
  return test;
}

__HANDLER__(_test_t_, uint8_t, post_test);
__HANDLER__(_test_t_, _test_ptr_, get_test);

int main(int argv, char *args[]) {
  handler_post_test post_test = {
    .value = "test",
    .validator = validate_test,
    .handle = handle_post
  };

  if (post_test.validator(post_test.value) == 1) {
    post_test.handle(&post_test.value, 0);
  }

  handler_get_test get_test = {
    .value = "test get",
    .validator = validate_test,
    .handle = handle_get
  };

  if (get_test.validator(get_test.value) == 1) {
    get_test.handle(&get_test.value, 0);
  }

  return 0;
}

