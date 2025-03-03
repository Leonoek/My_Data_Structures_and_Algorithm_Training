#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "heap.h"

#define TMP_ARRAY_SIZE 50

int get_operators_priority(char var);
const char* convert_infix_to_suffix(const char* target);
const char* convert_suffix_to_infix(const char* target);

int main(int argc, char *argv[])
{
    const char* result1; const char* result2;
    const char target[] = {"1 + 3 / 4"};
    result1 = convert_infix_to_suffix(target);
    result2 = convert_suffix_to_infix(result1);
    return 0;
}

/* 优先级比较 */
int get_operators_priority(char var){
    int temp;
    switch (var)
    {
    case '+': case '-':
        temp = 0;
        break;
    case '*': case '/':
        temp = 1;
        break;
    case '^':
        temp = 2;
        break;
    
    default:
        break;
    }

    return temp;
}

/* 中缀转后缀 */
const char* convert_infix_to_suffix(const char* target){
    char num;
    Myheap result_heap, operators_heap;
    char* p;
    char* result = malloc(sizeof(char) * TMP_ARRAY_SIZE);

    result_heap = create();
    operators_heap = create();
    p = (char*)target;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            ++p;
            continue;
        }
        

        if (!isdigit(*p))
        {
            while (true)
            {
                if(*p == '(')
                {
                    add(&operators_heap, *p);
                }
                else if (*p == ')')
                {
                    do
                    {
                        num = pop(operators_heap);
                        if (num == '(')
                        {
                            break;
                        }
                        add(&result_heap, num);
                        add(&result_heap, ' ');
                    } while (true);
                }else if (isempty(operators_heap) || '(' == gettop(operators_heap))
                {
                    add(&operators_heap, *p);
                }else if (get_operators_priority(*p) > get_operators_priority(gettop(operators_heap)))
                {
                    add(&operators_heap, *p);
                }else{
                    add(&result_heap, pop(operators_heap));
                    add(&result_heap, ' ');
                    continue;
                }
                break;
            }
            
            ++p;
            continue;
        }
        
        while (isdigit(*p))
        {
            add(&result_heap, *p);
            ++p;
        }
        add(&result_heap, ' ');
    }

    while (!isempty(operators_heap))
    {
        add(&result_heap, pop(operators_heap));
        add(&result_heap, ' ');
    }
    
    add(&result_heap, '\0');

    /* output to array */
    for (int i = getsize(result_heap) - 1; !isempty(result_heap); i--)
    {
        num = pop(result_heap);
        result[i] = num;
    }
    
    delete(result_heap);
    delete(operators_heap);

    return (const char*)result;
}

/* 后缀转中缀 */
const char* convert_suffix_to_infix(const char* target){
    Myheap result_heap;
    char* result; char* p;
    
    result_heap = create();
    result = malloc(sizeof(char) * TMP_ARRAY_SIZE);
    p = result;

    while (*target != '\0')
    {
        if (*target == ' ')
        {
        }else if (isdigit(*target)){
            add(&result_heap, *target);
        }else
        {
            if (getsize(result_heap) > 1)
            {
                *p++ = ' ';
                *p++ = pop(result_heap);
                *p++ = ' ';
                *p++ = *target;
                *p++ = ' ';
                *p++ = pop(result_heap);
            }else
            {
                *p++ = ' ';
                *p++ = *target;
                *p++ = ' ';
                *p++ = pop(result_heap);
            }
        }
        ++target;
    }
    *p = '\0';
    return (const char*)result;
}