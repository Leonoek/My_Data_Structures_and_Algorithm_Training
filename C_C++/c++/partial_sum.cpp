/*
前缀和
*/

#include <iostream>
#include <vector>

#define NUM_SIZE 25
#define NUM_RANGE_SMALL_END 0
#define NUM_RANGE_BIG_END 100
#define NUM_MOD (NUM_RANGE_BIG_END - NUM_RANGE_SMALL_END)
 
int main()
{
   srand(time(0));
   std::vector<int> num_vector(NUM_SIZE);
   for (int i = 0; i < NUM_SIZE; i++)
   {
      num_vector[i] = rand() % NUM_MOD + NUM_RANGE_SMALL_END;
   }
   std::cout << "rand num: " << std::endl;
   for (int i : num_vector)
   {
      std::cout << i << " ";
   }
   std::cout << std::endl;
   

   std::vector<int> partial_sum_vector(NUM_SIZE);
   for (int i = 0; i < NUM_SIZE; i++)
   {
      if (i)
      {
         partial_sum_vector[i] = partial_sum_vector[i - 1];
      }
      
      partial_sum_vector[i] += num_vector[i];
   }
   std::cout << "partial num: " << std::endl;
   for (auto i = partial_sum_vector.begin(); i < partial_sum_vector.end(); ++i)
   {
      std::cout << *i << " ";
   }
   std::cout << std::endl;

   // get 5-6 partial sum
   int partial_sum = partial_sum_vector[6] - partial_sum_vector[4];
   std::cout << partial_sum << " " << std::endl;
   
   printf("\n");
     
   return 0;
}