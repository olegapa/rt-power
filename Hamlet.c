#include<stdio.h>
#include<stdio.h>
#include<sys/stat.h>
#include<assert.h>
#include<stdlib.h>

const int POISON = -123213;
struct StringIndex{
char* head;
int num;
};

int CompareStrings(char string1[], char string2[]);
void swap_strings(StringIndex* index,int index1,int index2);
void QuickSort(StringIndex* index, int head, int tail);
int BuildIndex(StringIndex* index,char text[],int size);
int unit_CompareStrings();
void PutoutString(StringIndex* index,int number);
void StrOutput1(FILE* poem, StringIndex* index, int string_num);
void StrOutput2(FILE* poem, StringIndex* index, int string_num);

int main()
{
    int string_number = POISON;
    struct stat buff;
    StringIndex* index = (StringIndex*) calloc(4500, sizeof(StringIndex));
    assert(index != NULL);
    //("tests faults = %d - unit Compare Strings\n", unit_CompareStrings ());
    FILE* poem = fopen("hamlet.txt", "rb");
    assert(poem != NULL);

    fstat(fileno(poem), &buff);
    printf("Size of the file is: %ld\n", buff.st_size);

    char* text = (char*) calloc(buff.st_size,sizeof(char));
    assert(text != NULL);

    fread(text, sizeof(char), buff.st_size, poem);

    string_number = BuildIndex(index, text, buff.st_size);
    printf("String nunber = %d", string_number);

    index = (StringIndex*) realloc(index, sizeof(char*) * string_number);

    assert(index != NULL);
  //  PutoutString(index, 10);
    QuickSort(index, 0, string_number);

    fclose(poem);
    poem = NULL;

    poem = fopen("new_hamlet.txt", "w");
    assert(poem != NULL);

    StrOutput2(poem, index, string_number);
    fclose(poem);
    free(text);
    free(index);
    return 0;



}

int CompareStrings(char* string1, char* string2)
{
    assert(string1 != NULL);
    assert(string2 != NULL);
    int i = 0, j = 0;
    while(string1[i] != '\n' || string2[j] != '\n')
    {
        if( string1[i] < 'A' || string1[i] > 'z' || (string1[i] < 'a' && string1[i] > 'Z'))
        {
            i++;
            continue;
        }
        if( string2[j] < 'A' || string2[j] > 'z' || (string2[j] < 'a' && string2[j] > 'Z'))
        {
            j++;
            continue;
        }

        if(string1[i] < string2[j]) return 0;
        if(string1[i] > string2[j]) return 1;
        i++;
        j++;
    }

    if(string1[i] == '\n') return 0;
    if(string2[j] == '\n') return 1;
    return POISON;
}

void swap_strings(StringIndex* index,int index1,int index2)
{

    StringIndex tmp = index[index2];
    index[index2] = index[index1];
    index[index1] = tmp;
}

void QuickSort(StringIndex* index, int first, int last)
{
        assert(index != NULL);

        int start = first, end = last, pivot = (first + last)/2;
        printf("start  = %d     end = %d", start, end);
        while(start <= end && start <= pivot && end >=pivot)
        {
            while(CompareStrings(index[start].head, index[pivot].head) != 1 && start <= pivot) start++;
            while(CompareStrings(index[pivot].head, index[end].head) != 0 && end >= pivot) end--;

            if(start < end) swap_strings(index, start++, end--);

        printf("start = %d\nend = %d\n firs = %d\nlast = %d\n pivot = %d\n\n", start, end, first, last, pivot);
//        PutoutString(index, pivot);
        }
        printf("start  = %d     end = %d", start, end);
        if(first <= end) QuickSort(index, first, end);
        if(last >= start) QuickSort(index, start, last);


}

int BuildIndex(StringIndex* index,char text[],int size)
{
    int j = 0, i = 0, count = 0;
    index[j].head = &text[i];
    for(i = 0; i < size; i++)
    {
        count++;
        if(text[i] == '\n')
        {
            if(text[i-1] == '\n')
            {
                count = 0;
                continue;
            }
            index[j].num = count;
            index[++j].head = &text[++i];
            count = 0;
        }
    }
    return j-1;
}

int unit_CompareStrings()
{
    int count = 1;
    char strok1[] = {"aaaa"};
    char strok2[] = {"aaab"};
    if(CompareStrings(strok1, strok2) != 0)
    {
                 printf("Error on test %d", count);
                 return count;
    }
    count++;
    count = 1;
    strok1[0] = 'r'; strok1[1] = 'p'; strok1[2] = 's'; strok1[3] = 'g';
    strok2[0] = 'r'; strok2[1] = 'p'; strok2[2] = 'a'; strok2[3] = 'g';
    if(CompareStrings(strok1, strok2) != 1)
    {
                 printf("Error on test %d", count);
                 return count;
    }
    count++;
    return 0;
}

void PutoutString(StringIndex* index,int number)
{
    for(int i = 0; i <= index[number].num; i++)
    {
        printf("%c",index[number].head[i]);
    }
    printf("\n");
}
void  StrOutput1(FILE* poem, StringIndex* index, int string_num)
{
    for(int i = 0; i <= string_num; i++) fprintf(poem, "%s\n", index[i].head);
}
void  StrOutput2(FILE* poem, StringIndex* index, int string_num)
{
    for(int i = 0; i <= string_num; i++)
    {
        fwrite(index[i].head, sizeof(char), index[i].num, poem);
        fprintf(poem, "\n");
    }
}
