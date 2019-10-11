#include <stdio.h>
#include<assert.h>
#include<math.h>
#include "quadratic_equation_unit_test.cpp"

#define YOU_ARE_BOT -123456

const double POISON = 4082001.666;
const double eps  = 0.00001;

enum ANSWER_TYPES
{
    Error = -1,
    NoType,     // 0
    NoAnswer,   // 1
    LinearType, // 2
    SquareType, // 3
};

/// function disc considers the discriminant if the equation is square and returns its value
/// @param coeff1, coeff2, coeff3
double Disc (double a, double b, double c);

/// function InputNumbers_1 reads  equation coeffs values from standard io flow
///@param coeff1, coeff2, coeff3
int InputNumbers_1(double *a, double *b, double *c);

/// function GetEquationType counts the number of solutions to the equation and returns equation type
/// @param coeff1, coeff2, coeff3
ANSWER_TYPES GetEquationType(double a, double b, double c);

/// function SloveEquation finds type of equation and calls  function, that solves determined equation
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
ANSWER_TYPES SolveEquation (double a, double b, double c, double* root1, double* root2);

/// function SolveSquare solve quadratic equation and prints answer
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
ANSWER_TYPES SolveSquare(double a, double b, double c, double* root1, double* root2);


/// function SolveSquare solve linear equation and prints answer
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveLinear(double b ,double c, double* root);

/// function PrintAnswer prints answer of equation
/// @param root1, root2
void PrintAnswer(double x1, double x2, ANSWER_TYPES answer_t);

int main()
{
    double a = POISON, b = POISON, c = POISON, x1 = POISON, x2 = POISON;
    //*(long long*)(&a) = POISON;
    if(InputNumbers_1(&a, &b, &c) == YOU_ARE_BOT)
        return YOU_ARE_BOT;

    printf("\n a = %lg   b = %lg  c = %lg\n", a, b, c);

    ANSWER_TYPES answer_t = SolveEquation(a, b, c, &x1, &x2);
    assert(answer_t != Error);

    PrintAnswer(x1, x2, answer_t);

    return 0;
}


inline double Disc (double a, double b, double c)
{
    return b*b - 4 * a * c;
}


int InputNumbers_1(double *a, double *b, double *c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Input 3 numbers\n");

    int i = 0;

    while(scanf("%lg %lg %lg", a, b, c) != 3)
    {
        if(i == 10)
        {
            printf("You are stupid bot! You was banned");
            return YOU_ARE_BOT;
        }

        i++;

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


ANSWER_TYPES SolveEquation (double a, double b, double c, double* root1, double* root2)
{
    assert(root1 != NULL);
    assert(root2 != NULL);

    ANSWER_TYPES type = GetEquationType(a, b, c);

    if (type == NoType)
        return NoType;

    if (type == LinearType)
    {
        SolveLinear(b, c, root1);
        return LinearType;
    }

    if (type == SquareType)
        return SolveSquare(a, b, c, root1, root2);

    if (type == NoAnswer)
        return NoAnswer;
    return Error;

}

void SolveLinear(double b, double c, double* root)
{
    assert(root != NULL);

    *root = -c / b;
//    printf("root = %lg", *root);
}

ANSWER_TYPES SolveSquare(double a, double b, double c, double* root1, double* root2)
{
    assert(root1 != NULL);
    assert(root2 != NULL);


    if (Disc(a, b, c) < 0)
        return NoAnswer;
    else
    {
        double sqrt_disc = sqrt(Disc(a, b, c));

        *root2 = (-b + sqrt_disc) / (2 * a);
        *root1 = (-b - sqrt_disc) / (2 * a);
        return SquareType;
//        printf("root1 = %lg, root2 = %lg", *root1, *root2);
    }
}

void PrintAnswer(double x1, double x2, ANSWER_TYPES answer_t)
{
    if (answer_t == NoType)
    {
        assert( fabs(x1 - POISON) < eps);
        assert( fabs(x2 - POISON) < eps);

        printf("answer: x = 0\n");
    }

    if (answer_t == LinearType)
    {
        assert( fabs(x1 - POISON) > eps);
        assert( fabs(x2 - POISON) < eps);

        printf("answer: x = %lg\n", x1 );
    }

    if (answer_t == SquareType)
    {
        assert(fabs(x1 - POISON) > eps);
        assert(fabs(x2 - POISON) > eps);

        printf("root1 = %lg\troot2 = %lg\n", x1, x2);
    }

    if (answer_t == NoAnswer)
    {
        assert( fabs(x1 - POISON) < eps);
        assert( fabs(x2 - POISON) < eps);

        printf("this equation have no answer");
    }
}
