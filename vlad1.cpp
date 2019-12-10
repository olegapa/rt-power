#include <stdio.h>
#include <stdlib.h>

void ReverseStr(char** str, int len);

int main()
{
    int key_len = 0, str_len = 0;
    char* key = NULL, *str = NULL;
    int count = 0;
    char* ptr = NULL;

    scanf("%d ", &key_len);

    key = (char*) calloc(key_len, sizeof(char));
    for(int i = 0; i < key_len; i++)
        scanf("%c", &key[i]);

    scanf(" %d ", &str_len);

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
            ReverseStr(&ptr, count);
            count = 0;
        }

        printf("%s\n", str);

        return 0;

    }





}

void ReverseStr(char** str, int len)
{
    for(int i = 0; i <= len/2; i++)
    {
        char symb = *str[i];

        *str[i] = *str[len-i];
        *str[len-i] = symb;
    }


}
