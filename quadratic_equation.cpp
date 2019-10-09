#include <stdio.h>
#include<assert.h>
#include<math.h>
//#include "quadratic_equation_unit_test.cpp"

const int POISON = 4082001;
const double eps  = 0.00001;

enum ANSWER_TYPES
{
    NoType,
    NoAnswer,
    LinearType,
    SquareType,
};

/// function disc considers the discriminant if the equation is square and returns its value
/// @param coeff1, coeff2, coeff3
double disc (double a, double b, double c);

/// function InputNumbers_1 reads  equation coeffs values from standard io flow
///@param coeff1, coeff2, coeff3
int InputNumbers_1(double *a, double *b, double *c);

/// function GetEquationType counts the number of solutions to the equation and returns equation type
/// @param coeff1, coeff2, coeff3
ANSWER_TYPES GetEquationType(double a, double b, double c);

/// function SloveEquation finds type of equation and calls  function, that solves determined equation
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveEquation (double a, double b, double c, double* root1, double* root2);

/// function SolveSquare solve quadratic equation and prints answer
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveSquare(double a, double b, double c, double* root1, double* root2);


/// function SolveSquare solve linear equation and prints answer
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveLinear(double b ,double c, double* root);

int main()
{
    double a = POISON, b = POISON, c = POISON, x1 = POISON, x2 = POISON;
    InputNumbers_1(&a, &b, &c);


    printf("\n a = %lg   b = %lg  c = %lg\n", a, b, c);
    SolveEquation(a, b, c, &x1, &x2);

    return 0;
}


double disc (double a, double b, double c)
{
    return b*b - 4 * a * c;
}


int InputNumbers_1(double *a, double *b, double *c)
{
    printf("Input 3 numbers\n");
    while(scanf("%lg %lg %lg", a, b, c) != 3)
    {

        printf("ERROR \t try again\n");
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

ANSWER_TYPES GetEquationType(double a, double b, double c)
{
    if (fabs(a) < eps)
    {
        if(fabs(b) < eps)
        {
            if(fabs(c) < eps)
                return NoType;
            return NoAnswer;
        }
        return LinearType;
    }
    return SquareType;
}


void SolveEquation (double a, double b, double c, double* root1, double* root2)
{
    ANSWER_TYPES type = GetEquationType(a, b, c);

    if (type == NoType)
        printf("root = 0");

    if (type == LinearType)
         SolveLinear(b, c, root1);


    if (type == SquareType)
        SolveSquare(a, b, c, root1, root2);


    if (type == NoAnswer)
        printf("NO Answer");

}

void SolveLinear(double b, double c, double* root)
{
    *root = -c / b;
    printf("root = %lg", *root);
}

void SolveSquare(double a, double b, double c, double* root1, double* root2)

{
    if (disc(a, b, c) < 0)
        printf("No results, D < 0");
    else
    {
        double sqrt_disc = sqrt(disc(a, b, c));
        *root2 = (-b + sqrt_disc) / (2 * a);
        *root1 = (-b - sqrt_disc) / (2 * a);
        printf("root1 = %lg, root2 = %lg", *root1, *root2);
    }
}


