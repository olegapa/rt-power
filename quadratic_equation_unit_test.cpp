#include<stdio.h>
#include "quadratic_equation.c"


/// function unit_find_type tests function find_type
int UnitGetEquationType ()
{
    int count = 1;
    if (GetEquationType(0, 0, 0) != NoType)
    {
        printf("0, 0, 0 gives not correct ans");
        return count;
    }
    count++;

    if (GetEquationType(0, 0, 5) != NoAnswer)
    {
        printf("0, 0, 5 gives not correct ans");
        return count;
    }
    count++;

    if (GetEquationType(0, 5, 0) != LinearType)
    {
        printf("0, 5, 0 gives not correct ans");
        return count;
    }
    count++;

    if (GetEquationType(2, 0, 0) != SquareType)
    {
        printf("2, 0, 0 gives not correct ans");
        return count;
    }
    return 0;
}

/// function unit_SolveEquation tests function SolveEquation
int UnitSolveEquation()
{
    int count = 1;
    float x1 = POISON, x2 = POISON;

    SolveEquation(0, 0, 0, &x1, &x2);
    if(x1 != POISON || x2 != POISON)
    {
        printf("0, 0, 0 gives not correct answer");
        return count;
    }

    count++;

    SolveEquation(0, 3, 2, &x1, &x2);
    if (x1 != (-2/3) && x2 != POISON)
    {
        printf("0, 3, 2 gives not correct answer");
        return count;
    }

    count++;

    SolveEquation(1, 2, 1, &x1, &x2);
    if (x1 != (-1) && x2 != (-1))
    {
        printf("1, 2, 1 gives not correct answer");
        return count;
    }

    count++;

    SolveEquation(1, 2, 3, &x1, &x2);
    if (x1 != POISON || x2 != POISON)
    {
        printf("1, 2, 2 gives nor correct answer");
        return count;
    }

    count++;

    SolveEquation(2, -1, -10, &x1, &x2);
        if (x1 != (-2) && x2 != (5/2))
    {
        printf("0, 3, 2 gives not correct answer");
        return count;
    }
}

/// function test_square test functions
int TestSquare()
{
    UnitSolveEquation();
    UnitGetEquationType;
}

int main()
{
    TestSquare();
    return 0;
}
