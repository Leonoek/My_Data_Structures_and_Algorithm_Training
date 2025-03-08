#ifndef ARRAY_H
#define ARRAY_H

#define SIZE(array) (sizeof(array) / sizeof(array[0]))

void Delete(int* array){
    *array = 0;
}

void Domain(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 2, 3, 10};
    int size = SIZE(array);
    for (int j, temp, i = 0; i < size - 1; i++)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] == array[j])
            {
                Delete(&array[j]);
                temp = j;
                while (temp < size - 1)
                {
                    array[temp] = array[temp + 1];
                    ++temp;
                }
                array[temp] = 0;
                --size;
            }else
            {
                ++j;
            }
        }
        
    }
}

#endif // !ARRAY_H