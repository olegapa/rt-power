#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a = 0;

    FILE* dat = NULL, * ans = NULL;

    dat = fopen("squares.dat", "r");
    ans = fopen("squares.ans", "w");

    fscanf(dat, "%d", &a);

    int root = sqrt(a);

    if(root * root == a)
        root--;

    int res = 0;
    while(a > 0)
    {
        a -= root*root;
        res++;

        root = sqrt(a);
    }

    fprintf(ans, "%d", res);

    fclose(dat);
    fclose(ans);

    return 0;

}
