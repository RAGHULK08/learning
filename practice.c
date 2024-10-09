#include <stdio.h>
#include <math.h>
int main()
{
    double a,b;
    char o='+';
    while(o=='+' || o=='-' || o=='*' || o=='/' || o=='%')
    {
        printf("Enter 2 numbers with operator(+,-,*,/,%): ");
        scanf("%lf%c%lf",&a,&o,&b);
        switch(o)
        {
            case '+':
                printf("ADDITION: %.2f\n",a+b);
                break;
            case '-':
                printf("SUBTRACTION: %.2f\n",a-b);
                break;
            case '*':
                printf("MULTIPLICATION: %.2f\n",a*b);
                break;
            case '/':
                if(b!=0)
                {
                    printf("DIVISION: %.2f\n",a/b);
                }
                else
                {
                    printf("Cannot be divided by Zero");
                }
                break;
            case '%':
                printf("MODULUS: %.2f\n",fmod(a,b));
                break;
            default:
                printf("Invalid Input");
                break;
        }
    }
    return 0;
}
