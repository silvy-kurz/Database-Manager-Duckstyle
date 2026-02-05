#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


typedef int32_t i32;
typedef uint8_t u8;
typedef uint64_t u64;



void log_key_part(u64 part, int part_index) {
  int byte;
  printf("  Part_%d: ",part_index);
  for (byte = 0; byte < 8; byte++) {
    printf("%02X|", (part >> 8 * byte) & 0xFF);
    
  }
  printf("\n");
}

void log_key_ptr_pair(FixedSizeKey pair) {
  int index;
  printf("key: \n");
  for (index = 0; index < pair.key_size; index++) {
    log_key_part(pair.key_parts[index], index);
  }
  printf("payload: %p\n", pair.payload);
}
