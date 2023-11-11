#include <stdio.h>
#include <string.h>

int *computePrefix(char pattern[], int plen)
{
    static int pi[20];
    int k = 0;
    pi[0] = 0;

    for (int i = 1; i < plen; i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = pi[k];
        }
        if (pattern[k] == pattern[i])
        {
            k = k + 1;
        }
        pi[i] = k;
    }
    return pi;
}

void main()
{
    char strin[20] = "ababcabcabababd", pattern[20] = "ababd";
    int *pi, q = 0;
    int slen = strlen(strin);
    int plen = strlen(pattern);
    pi = computePrefix(pattern, plen);
    for (int i = 0; i < slen; i++)
    {
        while (q > 0 && pattern[q] != strin[i])
        {
            q = pi[q-1];
        }
        if (pattern[q] == strin[i])
        {
            q = q + 1;
        }
        if(q==plen){
            printf("Pattern at index %d\n",i+1-plen);
            q = pi[q-1];
        }
    }
}