#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>






void counting_sort(int count, int *counts, int *randoms, int *prefix_sums) {
  int bucket_range = (int) pow(2, 8);
  int i;
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
}



