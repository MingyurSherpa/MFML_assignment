#include <stdio.h>

int main()
{
    int a[3][4];
    int i, j, k;
    float factor;
    float x, y, z;

    printf("Enter the augmented matrix [A|B] (3x4):\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nInput Augmented Matrix:\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    // Convert to Row Echelon Form

    for(i = 0; i < 3; i++)
    {
        // Make the diagonal element non-zero if required
        if(a[i][i] == 0)
        {
            for(k = i + 1; k < 3; k++)
            {
                if(a[k][i] != 0)
                {
                    for(j = 0; j < 4; j++)
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                    break;
                }
            }
        }

        // Eliminate elements below pivot 
        for(k = i + 1; k < 3; k++)
        {
            if(a[k][i] != 0)
            {
                factor = (float)a[k][i] / a[i][i];

                for(j = 0; j < 4; j++)
                {
                    a[k][j] = a[k][j] - factor * a[i][j];
                }
            }
        }
    }

    printf("\nRow Echelon Form :\n");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%8.2f", (float)a[i][j]);
        }
        printf("\n");
    }

    // Back substitution 

    z = (float)a[2][3] / a[2][2];
    y = ((float)a[1][3] - a[1][2] * z) / a[1][1];
    x = ((float)a[0][3] - a[0][1] * y - a[0][2] * z) / a[0][0];

    printf("\nSolution:\n");
    printf("x = %.2f\n", x);
    printf("y = %.2f\n", y);
    printf("z = %.2f\n", z);

    return 0;
}