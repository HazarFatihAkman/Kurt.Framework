#include "get_handler.h"

char *handle(void) {
  return "Test";
}

CORE_DEFINE_HANDLER(get_test, handle);
