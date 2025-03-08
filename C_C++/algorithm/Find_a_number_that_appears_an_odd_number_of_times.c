/*
寻找一个出现了奇数个数的数
Find a number that appears an odd number of times
*/
#include <stdio.h>

int main(){
  int input_array[] = {34, 67, 45, 34, 67};
  int output = 0;
  for (int i = 0; i < sizeof(input_array) / sizeof(input_array[0]); i++)
  {
    output ^= input_array[i];
  }
  
  printf("result: %d\n", output);

  return 0;
}