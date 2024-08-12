#include <stdio.h>
int main() {
    int i, j, k, n, r, c;
    char a[3][3], v;
    printf("Welcome To TIC-TAC-TOE Game\n");
    int s = 1;
    while (s != 0) 
    {
        printf("To start: press 1\nTo Stop: press 0\n");
        scanf("%d", &s);
        if (s == 0) 
        {
            printf("THANK YOU\n");
            break;
        }
        printf("Let's Start\n");
        for (i = 0; i < 3; i++) 
        {
            for (j = 0; j < 3; j++) 
            {
                a[i][j] = ' ';
            }
        }
        for (i = 0; i < 9; i++) 
        {
            printf("Enter position (1-9): ");
            scanf("%d", &n);
            printf("Enter 'x' or 'o': ");
            scanf(" %c", &v);
            if (v == 'x' || v == 'o') 
            {
                r = (n - 1) / 3;
                c = (n - 1) % 3;
                if (a[r][c] == ' ') 
                {
                    a[r][c] = v;
                } else 
                {
                    printf("Position already taken. Please choose another position.\n");
                    i--;
                    continue;
                }
            } 
            else 
            {
                printf("Enter valid input (x or o)\n");
                i--;
                continue;
            }
            for (j = 0; j < 3; j++) 
            {
                for (k = 0; k < 3; k++) 
                {
                    printf("%c\t", a[j][k]);
                }
                printf("\n");
            }
            for (j = 0; j < 3; j++) 
            {
                if ((a[j][0] == v && a[j][1] == v && a[j][2] == v) || (a[0][j] == v && a[1][j] == v && a[2][j] == v)) 
                {
                    printf("Winner is player '%c'\n", v);
                    break;
                }
            }
            if ((a[0][0] == v && a[1][1] == v && a[2][2] == v) || (a[0][2] == v && a[1][1] == v && a[2][0] == v)) 
            {
                printf("Winner is player '%c'\n", v);
                break;
            }
        }
        if (i == 9) 
        {
            printf("Match Draw\n");
        }
    }
    return 0;
}
