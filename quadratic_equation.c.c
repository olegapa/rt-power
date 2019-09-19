#include <stdio.h>
#include<assert.h>
#include<math.h>

const int POISON = 4082001;


/// function disc considers the discriminant if the equation is square and returns its value
/// @param coeff1, coeff2, coeff3
float disc (float a, float b, float c)
{
    return b*b - 4 * a * c;
}

enum ANSWER_TYPES
{
    WRONG_INPUT        = -1,
    NO_ANSWER          = 0,
    LINEAR_EQUATION    = 1,
    QUADRATIC_EQUATION = 2,
};
/// function InputNumbers_1 reads  equation coeffs values from standard io flow
///@param coeff1, coeff2, coeff3
int InputNumbers_1(float *a, float *b, float *c)
{
    printf("Input 3 numbers\n");
    while(scanf("%f %f %f", &*a, &*b, &*c) != 3)
    {

        printf("ERROR\n");
        fflush(stdin);
    }
    return 0;
}

/*int* InputNumbers_2()
{
    static int data[3] = {};

    while(scanf("%f %f %f", data[0], data[1], data[2]) != 3)
    {
        printf("ERROR\n");
        fflush(stdin);
    }
    return data;
}
*/
/// function finde_type counts the number of solutions to the equation and returns their number
/// @param coeff1, coeff2, coeff3
int find_type(float a, float b, float c)
{
    if (a == 0)
    {
        if(b == 0)
        {
            if(c == 0)
                return WRONG_INPUT;
            return NO_ANSWER;
        }
        return LINEAR_EQUATION;
    }
    return QUADRATIC_EQUATION;
}

/// function SloveEquation solves the equation and outputs the answer
/// @param coeff1, coeff2, coeff3
int SolveEquation (float a, float b, float c, float* root1, float* root2)
{
    switch(find_type(a, b, c))
    {
    case NO_ANSWER:
 //       printf("no answer");
        return NO_ANSWER;
        break;
    case LINEAR_EQUATION:
        *root1 = -c / b;
        return LINEAR_EQUATION;
        break;
    case QUADRATIC_EQUATION:
        if (disc(a, b, c) < 0)
        {
 //           printf("No results, D < 0");
            return NO_ANSWER;
        }
        else
        {
            float sqrt_disc = sqrt(disc(a, b, c));
            *root2 = (-b + sqrt_disc) / (2 * a);
            *root1 = (-b - sqrt_disc) / (2 * a);
 //           printf("root1 = %g, root2 = %g", root1, root2);
            return QUADRATIC_EQUATION;
        }
        break;
    case WRONG_INPUT:
//        printf("all the solutions are possible");
        return WRONG_INPUT;
        break;
    default:
        return POISON;
        break;
    }
}
/// function unit_find_type tests function find_type
int unit_find_type ()
{
    int count = 1;
    if (find_type(0, 0, 0) != WRONG_INPUT)
    {
        printf("0, 0, 0 gives not correct ans");
        return count;
    }
    count++;

    if (find_type(0, 0, 5) != NO_ANSWER)
    {
        printf("0, 0, 5 gives not correct ans");
        return count;
    }
    count++;

    if (find_type(0, 5, 0) != LINEAR_EQUATION)
    {
        printf("0, 5, 0 gives not correct ans");
        return count;
    }
    count++;

    if (find_type(2, 0, 0) != QUADRATIC_EQUATION)
    {
        printf("2, 0, 0 gives not correct ans");
        return count;
    }
    return 0;
}
/// function unit_SolveEquation tests function SolveEquation
int unit_SolveEquation()
{
    int count = 1;
    float x1 = POISON, x2 = POISON;
    if (SolveEquation(0, 0, 0, &x1, &x2) != WRONG_INPUT)
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
    if (SolveEquation(1, 2, 3, &x1, &x2) != 0)
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
int test_square()
{
    unit_find_type();
    unit_SolveEquation();
}

/// function SloveEquation solves the equation and outputs the answer
/// @param coeff1, coeff2, coeff3
int main()
{
    float a = POISON, b = POISON, c = POISON, x1 = POISON, x2 = POISON;
    test_square();
    InputNumbers_1(&a, &b, &c);

    assert(a != POISON);
    assert(b != POISON);
    assert(c != POISON);

    printf("\n a = %f   b = %f  c = %f\n", a, b, c);
    switch (SolveEquation(a, b, c, &x1, &x2))
    {
    case 0:
        printf("No answer");
        break;
    case 1:
        printf("it's linear, root = %f", x1);
        break;
    case 2:
        printf("root1 = %f\t root2 = %f", x1, x2);
        break;
    default:
        printf("something wrong");
        break;
    }
    return 0;
}
