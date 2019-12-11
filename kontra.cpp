#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

struct Devushka
{
    int og;
    int ot;
    int ob;

    int sum;

};

void QuickSort(struct Devushka* konk, int left, int right)
{


    int first = left, last = right;
    struct Devushka tmp;
    assert(konk != NULL);

    while(first < last)
    {

        while(konk[last].sum >= konk[first].sum && last > first)
        {
            if(konk[last].sum == konk[first].sum)
            {
                if(konk[last].og == konk[first].og)
                {
                    if(konk[last].ot == konk[first].ot)
                    {
                        if(konk[last].ob > konk[first].ob)
                            break;
                    }

                    if(konk[last].ot < konk[first].ot)
                        break;
                }
                if(konk[last].og > konk[first].og)
                    break;

            }
        last--;
        }

        tmp = konk[last];
        konk[last] = konk[first];
        konk[first] = tmp;

        first++;

        while(konk[last].sum >= konk[first].sum && last > first)
        {
            if(konk[last].sum == konk[first].sum)
            {
                if(konk[last].og == konk[first].og)
                {
                    if(konk[last].ot == konk[first].ot)
                    {
                        if(konk[last].ob > konk[first].ob)
                            break;
                    }

                    if(konk[last].ot < konk[first].ot)
                        break;
                }

                if(konk[last].og > konk[first].og)
                    break;

            }
        first++;
        }

        tmp = konk[last];
        konk[last] = konk[first];
        konk[first] = tmp;

        last--;

//        SwapStrings(index, first, last--);

    }

    if(first > left) QuickSort(konk, left, first-1);
    if(last < right) QuickSort(konk,last+1, right);
}

int main()
{
    struct Devushka* konk = NULL;
    int n = 0;

    scanf("%d", &n);

    konk = (struct Devushka*) calloc(n, sizeof(struct Devushka));

    for(int i= 0; i < n; i++)
    {
        scanf("%d %d %d", &konk[i].og, &konk[i].ot, &konk[i].ob);
        konk[i].sum = konk[i].og + konk[i].ot + konk[i].ob;
    }

    QuickSort(konk, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d %d %d\n", konk[i].og, konk[i].ot, konk[i].ob);

    free(konk);


    return 0;

}
