#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>


typedef int32_t i32;
typedef uint8_t u8;
typedef uint64_t u64;

typedef struct {
  u64 *key_parts;
  u8 key_size;
  void *payload;

} FixedSizeKey;



// FixedSizeKey *create_unsorted_key_run(sorting_column, payload_column) {
//
//
// }






