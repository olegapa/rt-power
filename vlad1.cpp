#include <stdio.h>
#include <stdlib.h>

void ReverseStr(char** str, int len);

int main()
{
    int key_len = 0, str_len = 0;
    char* key = NULL, *str = NULL, *ptr = NULL;
    int count = 0;

    scanf("%d ", &key_len);

    key = (char*) calloc(key_len, sizeof(char));
    for(int i = 0; i < key_len; i++)
        scanf("%c", &key[i]);

    scanf(" %d ", &str_len);

//    printf("\nj%d", str_len);

    str = (char*) calloc(str_len, sizeof(char));

    for(int i = 0; i < str_len; i++)
    {
        scanf("%c", &str[i]);

        if(str[i] == key[count])
            count++;
        else
            count = 0;

        if(count == key_len)
        {
            ptr = str + i - count;
            ReverseStr(&ptr, count);
            count = 0;
        }



    }


    printf("%s\n", str);

    return 0;


}

void ReverseStr(char** str, int len)
{
    printf("%d  %s", len, *str);

    for(int i = 1; i <= len/2; i++)
    {
        printf("\ni = %d, len = %d, str[i] = %c, str[len-i-1] = %c", i, len, (*str)[i], (*str)[len-i-1]);

        char symb = (*str)[i];
        (*str)[i] = (*str)[len-i+1];
        (*str)[len-i+1] = symb;
    }


}
