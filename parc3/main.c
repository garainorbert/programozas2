#include <stdio.h>

int szamol_paros(int n){
    if (n == 0){
        return 0;
    }
    int utolso_szamjegy = n % 10;
    if (utolso_szamjegy % 2 == 0){
        return 1 + szamol_paros(n / 10);
    } else {
        return szamol_paros(n / 10);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1){
        printf("Hibas bemenet!\n");
        return 1;
    }

    if (n == 0){
        printf("1\n");
    } else {
        if (n < 0){
            n = -n;
        }
        int eredmeny = szamol_paros(n);
        printf("%d\n", eredmeny);
    }
    return 0;
}
