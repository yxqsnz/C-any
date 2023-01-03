#include "./any.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct any num;
  anyify(num, 10);

  printf("%d = %d and %d\n", (int)(long)num.value, isint(&num), ischar(&num));
}
