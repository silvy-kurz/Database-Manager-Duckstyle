#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>




void log_key_ptr_pair(FixedSizeKey pair) {
  int index;
  printf("key: ");
  printf("Part_0: %d", pair.key_parts[0]);
  for (index = 1; index < pair.key_size * 4; index++) {
    printf("%d ", pair.key_parts[index]);
  }
}
