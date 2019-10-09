#include <stdio.h>
#include<assert.h>
#include<math.h>

const int POISON = 4082001;


enum ANSWER_TYPES
{
    NoType,
    NoAnswer,
    LinearType,
    SquareType,
};

/// function disc considers the discriminant if the equation is square and returns its value
/// @param coeff1, coeff2, coeff3
float disc (float a, float b, float c);

/// function InputNumbers_1 reads  equation coeffs values from standard io flow
///@param coeff1, coeff2, coeff3
int InputNumbers_1(float *a, float *b, float *c);

/// function GetEquationType counts the number of solutions to the equation and returns equation type
/// @param coeff1, coeff2, coeff3
ANSWER_TYPES GetEquationType(float a, float b, float c);

/// function SloveEquation finds type of equation and calls  function, that solves determined equation
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveEquation (float a, float b, float c, float* root1, float* root2);

/// function SolveSquare solve quadratic equation and prints answer
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveSquare(float a, float b, float c, float* root1, float* root2);


/// function SolveSquare solve linear equation and prints answer
/// @param coeff1, coeff2, coeff3, [out] root1, [out] root2
void SolveLinear(float b ,float c, float* root);

int main()
{
    float a = POISON, b = POISON, c = POISON, x1 = POISON, x2 = POISON;
    InputNumbers_1(&a, &b, &c);


    printf("\n a = %f   b = %f  c = %f\n", a, b, c);
    SolveEquation(a, b, c, &x1, &x2);

    return 0;
}


float disc (float a, float b, float c)
{
    return b*b - 4 * a * c;
}


int InputNumbers_1(float *a, float *b, float *c)
{
    printf("Input 3 numbers\n");
    while(scanf("%f %f %f", a, b, c) != 3)
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

ANSWER_TYPES GetEquationType(float a, float b, float c)
{
    if (a == 0)
    {
        if(b == 0)
        {
            if(c == 0)
                return NoType;
            return NoAnswer;
        }
        return LinearType;
    }
    return SquareType;
}


void SolveEquation (float a, float b, float c, float* root1, float* root2)
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

void SolveLinear(float b, float c, float* root)
{
    *root = -c / b;
    printf("root = %f", *root);
}

void SolveSquare(float a, float b, float c, float* root1, float* root2)

{
    if (disc(a, b, c) < 0)
        printf("No results, D < 0");
    else
    {
        float sqrt_disc = sqrt(disc(a, b, c));
        *root2 = (-b + sqrt_disc) / (2 * a);
        *root1 = (-b - sqrt_disc) / (2 * a);
        printf("root1 = %f, root2 = %f", *root1, *root2);
    }
}


