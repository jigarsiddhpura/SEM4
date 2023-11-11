#include <stdio.h>
#include <string.h>

#define d 10 // the size of the character set

void rabin_karp(char* text, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "d^(M-1)"
    for (i = 0; i < M - 1; i++)
        h = (h * d);
        
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]);
        t = (d * t + text[i]);
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i+j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i+M]);
            // if (t < 0)
            //     t = (t + 101);
        }
    }
}

int main() {
    char* text = "jklabcjkla*bc";
    char* pattern = "kla*b";
    rabin_karp(text, pattern);
    return 0;
}
