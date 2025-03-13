/*
堆排序
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void countingSort1(int* array, int num){
    if (num == 1 || num == 0)
    {
        return;
    }
    
    // get max and min value
    int max_val = array[0];
    int min_val = array[0];
    for (int i = 0; i < num; i++)
    {
        if (max_val < array[i])
        {
            max_val = array[i];
        }

        if (min_val > array[i])
        {
            min_val = array[i];
        }
    }

    // make container
    int container_nums = max_val - min_val + 1;
    int container[container_nums] = {};
    memset(container, 0, container_nums);

    // detect
    int tmp;
    for (int i = 0; i < num; i++)
    {   
        tmp = array[i];
        container[tmp - min_val]++;
    }

    for (int i = 0, j = 0; i < container_nums; i++)
    {
        if (container[i] != 0)
        {
            for (int k = container[i]; k > 0; k--)
            {
                array[j++] = min_val + i;
            }
        }
    }    
}

void countingSort2(int* array, int num){
    if (num == 1 || num == 0)
    {
        return;
    }
    
    // get max and min value
    int max_val = array[0];
    int min_val = array[0];
    for (int i = 0; i < num; i++)
    {
        if (max_val < array[i])
        {
            max_val = array[i];
        }

        if (min_val > array[i])
        {
            min_val = array[i];
        }
    }

    // make container
    int container_nums = max_val - min_val + 1;
    int container[container_nums] = {};
    memset(container, 0, container_nums);

    // detect
    int tmp;
    for (int i = 0; i < num; i++)
    {   
        tmp = array[i];
        container[tmp - min_val]++;
    }

    // Prefix sun
    for (int i = 0; i < container_nums; i++)
    {   
        if (i)
        {
            container[i] += container[i - 1];
        }
        
        container[i] = container[i];
    }

    int tmp_array[num];
    for (int i = num - 1; i > -1; i--)
    {
        tmp = container[array[i] - min_val] - 1;
        tmp_array[tmp] = array[i];
        container[array[i] - min_val] --;
    }   

    printf("in countingSort2, the array:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", tmp_array[i]);
    }
    printf("\n");
}

int main(){
    srand((unsigned)time(NULL));
    int array_num = rand() % 10;
    while (!array_num)
    {
        array_num = (rand() % 10);
    }

    int input_array1[array_num];
    for (int i = 0; i < array_num; i++)
    {
        input_array1[i] = rand() % 10;
        printf("%d ", input_array1[i]);
    }
    printf("\n");

    countingSort1(input_array1, array_num);
    countingSort2(input_array1, array_num);
    
    printf("the array:\n");
    for (int i = 0; i < array_num; i++)
    {
        printf("%d ", input_array1[i]);
    }
    return 0;
}