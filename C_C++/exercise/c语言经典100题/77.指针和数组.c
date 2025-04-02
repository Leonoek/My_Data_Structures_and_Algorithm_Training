#include <stdio.h>

void Practice1() {
    printf("Practice1:\n");
	int a = 3;
	int* intptr = &a;
    printf("num value: %38d\nnum of address:%34p\nint ptr address: %32p\nint ptr pointed address:%25p\n",
        *intptr, &a, &intptr, intptr);
    printf("\n");
}

void Practice2() {
    printf("Practice2:\n");
    int a = 3, b = 4, c = 5;
    int array1[] = { a, b, c };

    int* array2[] = { &a, &b, &c };
    printf("array2: a:%d, b:%d, c:%d\n", *array2[0], *array2[1], *array2[1]);

    int (*array3)[] = &array1;
    printf("array3: a:%d, b:%d, c:%d\n", (*array3)[0], (*array3)[1], (*array3)[2]);

    int* (*array4)[] = array2;
    printf("array4: a:%d, b:%d, c:%d\n", *((*array4)[0]), *((*array4)[1]), *((*array4)[2]));
    printf("\n");
    printf("array1 address: %33p\narray1 of address: %30p\narray1 element: %d\nelement1: %d\nelement2: %d\nelement3: %d\n",
        array1, &array1, *array1, *(array1 + 0), *(array1 + 1), *(array1 + 2));
    printf("\n");
    printf("array2 address: %33p\narray2 of address: %30p\narray2 element: %d\nelement1: %d\nelement2: %d\nelement3: %d\n",
        array2, &array2, **array2, *(*(array2 + 0)), *(*(array2 + 1)), *(*(array2 + 2)));
    printf("\n");
    printf("array3 address: %33p\narray3 of address: %30p\narray3 element: %d\nelement1: %d\nelement2: %d\nelement3: %d\n",
        array3, &array3, **array3, *((*array3) + 0), *((*array3) + 1), *((*array3) + 2));
    printf("\n");
    printf("array4 address: %33p\narray4 of address: %30p\narray4 element: %d\nelement1: %d\nelement2: %d\nelement3: %d\n",
        array4, &array4, ***array4, **((*array4) + 0), **((*array4) + 1), **((*array4) + 2));
    printf("\n");
}

void Practice3() {
    printf("Practice3:\n");
    int a = 10, b = 20, c = 30, d = 40, e = 50, f = 60, g = 70, h = 80, i = 90;
    int array1[][3] = { {a, b, c}, {d, e, f}, {g, h, i} };
    printf("array1: a:%d, e:%d, f:%d\n", **array1, *(*(array1 + 1) + 1), *(*(array1 + 2) + 2));

    int* array2[][3] = { {&a, &b, &c}, {&d, &e, &f}, {&g, &h, &i} };
    printf("array2: a:%d, b:%d, c:%d\n", ***array2, *(*(*(array2 + 1) + 1)), *(*(*(array2 + 2) + 2)));

    int (*array3)[3] = array1;
    printf("array3: a:%d, b:%d, c:%d\n", **array3, *(*(array3 + 1) + 4), *(*array3 + 8));

    int* (*array4)[] = array2;
    printf("array4: a:%d, b:%d, c:%d\n", ***array4, *(*(*array4 + 4)), *(*(*array4 + 8)));
    printf("\n");
}

void Practice4() {
    printf("Practice4:\n");
    int a = 1, b = 2, c = 3;
    int* array[3] = { &a, &b, &c };
    int** p_array = &array;
    printf("%d, %d, %d\n", *array[0], *array[1], *array[2]);
    printf("%d, %d, %d\n", **(p_array + 0), **(p_array + 1), **(p_array + 2));

    int test[][4] = { {0, 10, 20, 90}, {30, 40, 50, 100}, {60, 70, 80, 110} };
    int (*p)[4] = test;
    printf("%d\n", *(*(p + 1) + 1));
    
    printf("\n");
}

void Practice5() {
    printf("Practice5w:\n");
    char* str1 = "hahah";
    char* str2 = "test";
    char* str3 = "mem";
    char* str[] = { str1, str2, str3 };
    printf("%s, %s, %s\n", str1, str2, str3);

    const char* s[] = { "ahhaha", "smile", "dou" };
    const char** sptr;
    for (int i = 0; i < 3; ++i) {
        //sptr = s + i;
        sptr = &s[i];
        printf("%s\n", *sptr);
    }
    printf("\n");
}


int main() {
    Practice1();
    Practice2();
    Practice3();
    Practice4();
    Practice5();

    
	return 0;
}