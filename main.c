#include <stdio.h>
#include <string.h>

int main() {
    char palavra[16];
    char cifrada[16];
    int shift, n, i;

    
    int fib[15] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};

    printf("Palavra: ");
    scanf("%15s", palavra);

    printf("SHIFT: ");
    scanf("%d", &shift);

    n = strlen(palavra);

    
    for (i = 0; i < n; i++) {
        int pos = (palavra[i] - 'a' + shift + fib[i]) % 26;
        cifrada[i] = pos + 'a';
    }
    cifrada[n] = '\0';  

   
    printf("\nPalavra criptografada: %s\n", cifrada);

    
    FILE *fp = fopen("resultado_criptografia.txt", "w");
    fprintf(fp, "Palavra codificada: %s | SHIFT: %d | Tipo: 3 | Letras: %d\n",
            cifrada, shift, n);
    fclose(fp);

    return 0;
}