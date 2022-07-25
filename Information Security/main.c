#include <stdio.h>

int main() {
    char value[10] = "";
    int choice, a, key;
    printf("1. PT to CT\n2. CT to PT\nEnter Choice :-");
    scanf("%d", &choice);
    printf("Enter String :- ");
    scanf("%s", value);
    if (choice == 1){
        for (int n = 0; n < 10; n++) {
            if (value[n] == 0) {
                break;
            }
            key = (int) value[n] - 97 + 3;
            a = key % 26;
            printf("%c", (a+97));
        }
    }
    if (choice == 2){
        for (int n = 0; n <10; n++) {
            if(value[n] == 0)
                break;
            key = (int) value[n]-97-3;
            if(key<0)
            {
                a = 26 + key;
            } else {
                a = key % 26;
            }
            printf("%c", (a+97));
        }
    }
}
