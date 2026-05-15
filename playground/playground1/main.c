#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "get_handler.h"
#include "../../include/controller.h"

CORE_DECLARE_CONTROLLER_PATH(v1_playground);

static const http_properties_t props = {
  .path = "v1/playground",
  .format = APP_JSON,
  .type = GET
};

void v1_playground_process(req_t *req) {
  char *out = (char*) malloc(5);
  handler_get_test_process(&get_test, &out);
  printf("Response : %s\n", out);
}

CORE_DEFINE_CONTROLLER_PATH(v1_playground, props, v1_playground_process);

static const controller_path_t paths[1] = {
  v1_playground
};

int main(int argv, char *args[]) {
  printf("args 1 : %s\nargs : 2 %s\n", args[1], args[2]);
  while (1) {
    req_t req = {
      .props = props,
      .content_len = 0,
      .content = ""
    };

    for (int i = 0; i < 1; i++) {
      if (strcmp(args[1], paths[i].props.path) == 0 && atoi(args[2]) == paths[i].props.type) {
        paths[i].process(&req);
      }
    }

    sleep(5);
  }

  return 0;
}
