#include <stdio.h>
#include <string.h>
void main_triangle(int height, char space, char star){
    
    for (int k = 0; k < height; ++k) {

        for (int i = 0; i < height - k - 1; ++i) {
            printf("%c", space);
        }

        for (int i = 0; i < k*2 + 1; ++i) {
            printf("%c", star);
        }

        for (int i = 0; i < height - k - 1; ++i) {
            printf("%c", space);
        }

        printf("\n");

    }
}

void triangle(int height, char space, char star){
    for (int k = 0; k < height; ++k) {

        for (int i = 0; i < k + 1; ++i) {
            printf("%c", star);
        }

        for (int i = 0; i < height - k - 1; ++i) {
            printf("%c", space);
        }

        printf("\n");

    }
}

void cursor(int height, char space, char star){
    int new_height = (height/2);
    
    for (int k = 0; k <= height; ++k) {
        if(k < new_height){
            for (int i = 0; i < k + 1; ++i) {
                printf("%c", star);
            }
        }
        else {
            for (int i = 0; i < height - k; ++i) {
                printf("%c", star);
            }
        }

        printf("\n");

    }
}

void rectangle(int height, char space, char star){
    
     for (int k = 0; k < height; ++k) {
         for (int i = 0; i < height; ++i) {
            printf("%c", star);
        }
        printf("\n");
     }
}

int main(){
    int height; 
    scanf("%d", &height);

    char space = ' ';
    char star = '*';
    
    main_triangle(height, space, star);

    return 0;
}