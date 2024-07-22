#include <stdio.h>
int main()
{
    int a,b;
    char o='+';
    while(o=='+' || o=='-' || o=='*' || o=='/' || o=='%')
    {
        printf("Enter 2 numbers with operator(+,-,*,/,%): ");
        scanf("%d%c%d",&a,&o,&b);
        switch(o)
        {
            case '+':
                printf("ADDITION: %d\n",a+b);
                break;
            case '-':
                printf("SUBTRACTION: %d\n",a-b);
                break;
            case '*':
                printf("MULTIPLICATION: %d\n",a*b);
                break;
            case '/':
                printf("DIVISION: %d\n",a/b);
                break;
            case '%':
                printf("MODULUS: %d\n",a%b);
                break;
            default:
                printf("Invalid Input");
        }
    }
    return 0;
}