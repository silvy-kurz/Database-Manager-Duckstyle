#include "sort_algorithm.c"
#include "normalisation.c"
#include "logging.c"



#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef int32_t i32;
typedef uint8_t u8;
typedef uint64_t u64;





int get_random_integer(int low, int high) {
    return low + arc4random_uniform(high - low + 1);
}

float get_random_float(float low, float high) {
  float r = (float)arc4random() / (float)UINT32_MAX;

    return low + r * (high - low);
}


int main(int argc, char *argv[])
{
  int count = 20;
  double digit_count = 1;
  int bucket_range = (int) pow(10, digit_count);
  int counts[bucket_range];
  int prefix_sums[bucket_range];
  memset(counts, 0, sizeof(counts));
  prefix_sums[0] = 0;
  int i;

  int randoms[count];
  printf("[");
  for (int i = 0; i < count; i++) {
    randoms[i] = get_random_integer(0, bucket_range - 1);
    printf("%d ", randoms[i]);
  }
  printf("]\n");
  
  for (i = 0; i < count; i++) {
    counts[randoms[i]] += 1;
  }
  int j; 
  int sorteds[count];
  int current = 0;
  int total_prefix = 0;
  for (int i = 0; i < bucket_range; i++) {
    total_prefix += counts[i];  
    prefix_sums[i + 1] = total_prefix;
  }


  for (int i = 0; i < count; i++) {
    sorteds[prefix_sums[randoms[i]]] = randoms[i];
    prefix_sums[randoms[i]] += 1;
  }



  printf("[");
  for (int i = 0; i < bucket_range; i++) {
    printf("%d ", counts[i]);
  }
  printf("]\n");

  printf("[");
  for (int i = 0; i < bucket_range; i++) {
    printf("%d ", prefix_sums[i]);
  }
  printf("]\n");

  printf("[");
  for (int i = 0; i < count; i++) {
    printf("%d ", sorteds[i]);
  }
  printf("]\n");





  u64 val = 0x10;
  u64 parts[1] = {val};
  // u8 bytes[sizeof(u64)];
  // // Kopiert die rohen Bytes in das Array
  // memcpy(bytes, &val, sizeof(val));
  int payload_vals[4];
  // Zugriff auf Byte 0 (bei Little-Endian: 0x78)
  // printf("%d\n", bytes[0]);
  // printf("%d\n", bytes[1]);
  // printf("%d\n", bytes[2]);
  // printf("%d\n", bytes[3]);
  FixedSizeKey test_key = {
    .key_parts = parts,
    .key_size = 1,
    .payload = &payload_vals,
  };
  log_key_ptr_pair(test_key);
  return 0;
}

