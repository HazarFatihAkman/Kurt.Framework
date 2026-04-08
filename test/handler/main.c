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

CORE_HANDLER(_test_t_, uint8_t, post_test);
CORE_HANDLER(_test_t_, _test_ptr_, get_test);

int main(int argv, char *args[]) {
  handler_post_test post_test = {
    .value = "test",
    .validator = validate_test,
    .handle = handle_post
  };

  uint8_t post_status = 0;
  handler_post_test_process(&post_test, post_status);

  handler_get_test get_test = {
    .value = "test get",
    .validator = validate_test,
    .handle = handle_get
  };

  _test_ptr_ get_res;
  handler_get_test_process(&get_test, get_res);
  return 0;
}

