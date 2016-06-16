#include <stdio.h>
#include <stdlib.h>



int find_max_side__(int *array,int length) {    



  int result_start = 0, result_end = 0, result_sum = 0;
  int curr_start = 0;
  int curr_end = 0;
  int curr_sum = 0;


  int i;
  for (i = 0; i < length; i++) {
    curr_end = i;
    curr_sum = curr_sum + array[i];

    if (curr_sum < 0) {           //若为负  则数组起点一定此时的i大
      curr_start = i + 1;
      curr_sum = 0;
      continue;
    }

    if (curr_sum > result_sum) {
      result_sum = curr_sum;
      result_start = curr_start;
      result_end = curr_end;
    }
  }

  printf("max subarry : %d - %d, sum : %d \n", result_start, result_end, result_sum);

  return EXIT_SUCCESS;
}