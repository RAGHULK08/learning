#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
double binaryToDecimal(double num)
{
    double intPart, fracPart;
    fracPart = modf(num, &intPart);
    double result = 0;
    double factor = 1;
    while ((int)intPart != 0)
    {
        int digit = (int)fmod(intPart, 10);
        result += digit * factor;
        factor *= 2;
        intPart /= 10;
    }
    double fracFactor = 0.5;
    while (fracPart > 0 && fracFactor > 1e-10)
    {
        fracPart *= 2;
        int digit = (int)fracPart;
        result += digit * fracFactor;
        fracPart -= digit;
        fracFactor /= 2;
    }
    return result;
}
double octalToDecimal(double num)
{
    double intPart, fracPart;
    fracPart = modf(num, &intPart);
    double result = 0;
    double factor = 1;
    while ((int)intPart != 0)
    {
        int digit = (int)fmod(intPart, 10);
        result += digit * factor;
        factor *= 8;
        intPart /= 10;
    }
    double fracResult = 0;
    double multiplier = 1.0 / 8.0;
    while (fracPart > 0 && multiplier > 1e-10)
    {
        fracPart *= 8;
        int digit = (int)fracPart;
        fracResult += digit * multiplier;
        fracPart -= digit;
        multiplier /= 8;
    }
    return result + fracResult;
}
double hexToDecimal(const char *hex)
{
    double result = 0;
    const char *point = strchr(hex, '.');
    int len = (point != NULL) ? (point - hex) : strlen(hex);
    for (int i = 0; i < len; i++)
    {
        char c = hex[i];
        int digit = 0;
        if (c >= '0' && c <= '9')
            digit = c - '0';
        else if (c >= 'A' && c <= 'F')
            digit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            digit = c - 'a' + 10;
        result = result * 16 + digit;
    }
    if (point != NULL)
    {
        double frac = 0;
        double factor = 1.0 / 16;
        for (const char *p = point + 1; *p != '\0'; p++)
        {
            int digit = 0;
            if (*p >= '0' && *p <= '9')
                digit = *p - '0';
            else if (*p >= 'A' && *p <= 'F')
                digit = *p - 'A' + 10;
            else if (*p >= 'a' && *p <= 'f')
                digit = *p - 'a' + 10;
            frac += digit * factor;
            factor /= 16;
        }
        result += frac;
    }
    return result;
}
void decimalToBinary(double num)
{
    double intPart, fracPart;
    fracPart = modf(num, &intPart);
    char intBin[64] = "";
    int i = 0;
    if (intPart == 0)
        intBin[i++] = '0';
    while (intPart > 0)
    {
        int remainder = (int)fmod(intPart, 2);
        intBin[i++] = remainder ? '1' : '0';
        intPart = floor(intPart / 2);
    }
    intBin[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = intBin[j];
        intBin[j] = intBin[i - 1 - j];
        intBin[i - 1 - j] = temp;
    }
    char fracBin[64] = "";
    int j = 0;
    while (fracPart > 0 && j < 20)
    { 
        fracPart *= 2;
        int digit = (int)fracPart;
        fracBin[j++] = digit ? '1' : '0';
        fracPart -= digit;
    }
    fracBin[j] = '\0';

    if (j > 0)
        printf("Binary Number: %s.%s\n", intBin, fracBin);
    else
        printf("Binary Number: %s\n", intBin);
}
void decimalToOctal(double num)
{
    double intPart, fracPart;
    fracPart = modf(num, &intPart);
    char intOct[64] = "";
    int i = 0;
    if (intPart == 0)
        intOct[i++] = '0';
    while (intPart > 0)
    {
        int remainder = (int)fmod(intPart, 8);
        intOct[i++] = '0' + remainder;
        intPart = floor(intPart / 8);
    }
    intOct[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = intOct[j];
        intOct[j] = intOct[i - 1 - j];
        intOct[i - 1 - j] = temp;
    }
    char fracOct[64] = "";
    int j = 0;
    while (fracPart > 0 && j < 20)
    {
        fracPart *= 8;
        int digit = (int)fracPart;
        fracOct[j++] = '0' + digit;
        fracPart -= digit;
    }
    fracOct[j] = '\0';

    if (j > 0)
        printf("Octal Number: %s.%s\n", intOct, fracOct);
    else
        printf("Octal Number: %s\n", intOct);
}
void decimalToHex(double num)
{
    double intPart, fracPart;
    fracPart = modf(num, &intPart);
    char intHex[64] = "";
    int i = 0;
    if (intPart == 0)
        intHex[i++] = '0';
    while (intPart > 0)
    {
        int remainder = (int)fmod(intPart, 16);
        if (remainder < 10)
            intHex[i++] = '0' + remainder;
        else
            intHex[i++] = 'A' + (remainder - 10);
        intPart = floor(intPart / 16);
    }
    intHex[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = intHex[j];
        intHex[j] = intHex[i - 1 - j];
        intHex[i - 1 - j] = temp;
    }
    char fracHex[64] = "";
    int j = 0;
    while (fracPart > 0 && j < 20)
    {
        fracPart *= 16;
        int digit = (int)fracPart;
        if (digit < 10)
            fracHex[j++] = '0' + digit;
        else
            fracHex[j++] = 'A' + (digit - 10);
        fracPart -= digit;
    }
    fracHex[j] = '\0';

    if (j > 0)
        printf("Hexadecimal Number: %s.%s\n", intHex, fracHex);
    else
        printf("Hexadecimal Number: %s\n", intHex);
}
int main()
{
    int choice;
    printf("Enter your choice:\n");
    printf("0 - Binary to Decimal\n1 - Octal to Decimal\n2 - Hexadecimal to Decimal\n");
    printf("3 - Decimal to Binary\n4 - Decimal to Octal\n5 - Decimal to Hexadecimal\n");
    scanf("%d", &choice);
    if (choice < 0 || choice > 5)
    {
        printf("Enter a valid choice\n");
        return 1;
    }
    if (choice == 0)
    {
        double b;
        printf("Enter Binary Number: ");
        scanf("%lf", &b);
        char buf[50];
        sprintf(buf, "%.25f", b);
        for (int i = 0; i < strlen(buf); i++)
        {
            if (buf[i] != '0' && buf[i] != '1' && buf[i] != '.')
            {
                printf("Enter valid Input\n");
                return 1;
            }
        }
        double dec = binaryToDecimal(b);
        printf("Decimal Value: %.10f\n", dec);
    }
    else if (choice == 1)
    {
        double o;
        printf("Enter Octal Number: ");
        scanf("%lf", &o);
        char buf[50];
        sprintf(buf, "%.10f", o);
        for (int i = 0; i < strlen(buf); i++)
        {
            if ((buf[i] < '0' || buf[i] > '7') && buf[i] != '.')
            {
                printf("Enter valid Input\n");
                return 1;
            }
        }
        double dec = octalToDecimal(o);
        printf("Decimal Value: %.10f\n", dec);
    }
    else if (choice == 2)
    {
        char hex[50];
        printf("Enter Hexadecimal Number: ");
        scanf("%s", hex);
        for (int i = 0; i < strlen(hex); i++)
        {
            if (!((hex[i] >= '0' && hex[i] <= '9') ||
                  (hex[i] >= 'A' && hex[i] <= 'F') ||
                  (hex[i] >= 'a' && hex[i] <= 'f') ||
                  (hex[i] == '.')))
            {
                printf("Enter valid Input\n");
                return 1;
            }
        }
        double dec = hexToDecimal(hex);
        printf("Decimal Value: %.10f\n", dec);
    }
    else if (choice == 3)
    {
        double d;
        printf("Enter Decimal Number: ");
        scanf("%lf", &d);
        decimalToBinary(d);
    }
    else if (choice == 4)
    {
        double d;
        printf("Enter Decimal Number: ");
        scanf("%lf", &d);
        decimalToOctal(d);
    }
    else if (choice == 5)
    {
        double d;
        printf("Enter Decimal Number: ");
        scanf("%lf", &d);
        decimalToHex(d);
    }
    return 0;
}
