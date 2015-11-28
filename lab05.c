#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char S[2001], Si[2001], b[2001][2001];
    int c[2001][2001];
    int Slen, n, *mut, i, j , k;

    scanf("%s", S);
    Slen = strlen(S);

    scanf("%d", &n);
    mut = malloc(n*sizeof(int));
    for(k = 0; k < n; k++)
        scanf("%d", &mut[i]);

    for(i = 0, j = Slen-1; i < Slen, j >=0; i++, j--)
        Si[i] = S[j];


    //para cada posição i, qual o maior palindromo até esse i?
    for(i = 0; i < Slen; i++)
        c[i][0] = 0;
    for(j = 0; j < Slen; j++)
        c[0][j] = 0;

    for(i = 1; i < Slen; i++)
    {
        for(j = 1; j < Slen; j++)
        {
            if (S[i] == Si[j])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'd';
            }
            else
            if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'v';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'h';
            }
        }
    }

}

