#include "../include/http_attribute.h"

#include <stdio.h>

void print_props(const http_properties_t props) {
  printf("\tType : %d | Path : %s | Format : %d\n",
    props.type,
    props.path,
    props.format);
}
