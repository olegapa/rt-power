#include<stdio.h>
#include<stdio.h>
#include<sys/stat.h>
#include<assert.h>
#include<stdlib.h>

const int POISON = -123213;

int CompareStrings(char* string1, char* string2)
{
    int i = 0;
    for(int i =0; string1[i] != '\n' || string2[i] != '\n'; i++)
    {
        if(string1[i] < string2[i]) return 0;
        if(string1[i] > string2[i]) return 1;
    }
    if(string1[i] == '\n') return 0;
    if(string2[i] == '\n') return 1;
}

void swap_strings(char* index[],int index1,int index2)
{
    char* c = index[index2];
    index[index2] = index[index1];
    index[index1] = c;
}

void QuickSort(char* index[], int head, int tail)
{
    int i = 0, j = 0, start = head, end = tail, pivot = (head + tail)/2;
    while(head <= end)
    {
        while(CompareStrings(index[head], index[pivot]) != 1) head++;
        while(CompareStrings(index[end], index[pivot]) != 0) end--;
        if(head <= end) swap_strings(index, head++, end--);
    }
    if(head < end) QuickSort(index, head, end);
    if(tail > start) QuickSort(index, start, tail);

}

int BuildIndex(char* index[],char text[],int size)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if(text[i] == '\n') index[j++] = &text[++i];
    }
    return j-1;
}

int main()
{
    int string_number = POISON;
    struct stat buff;
    char** index = (char **) calloc(3000, sizeof(char*));

    FILE *poem = fopen("hamlet.txt", "rb");
    assert(poem != NULL);
    fstat(fileno(poem), &buff);
    printf("Size of the file is: %ld\n", buff.st_size);

    char* text = (char*) calloc(buff.st_size,sizeof(char));

    fread(text, sizeof(char), buff.st_size, poem);
    string_number = BuildIndex(index, text, buff.st_size);
    index = (char**) realloc(index, sizeof(char*) * string_number);
    QuickSort(index, 0, string_number);
    fclose(poem);
    poem = fopen("new_hamlet.txt", "w");
    for(int i = 0; i < string_number; i++) fwrite(index[i], sizeof(char), s, poem)

    return 0;



}
