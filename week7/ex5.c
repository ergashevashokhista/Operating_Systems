#include <stdio.h>
#include <stdlib.h>
int main() {
    char **s = (char **) malloc(sizeof(char *));
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return (0);
}


//  #include <stdio.h>
// int main() {
//     char s1;
//     char *s2 = &s1;
//     char **s = &s2;
//     char foo[] = "Hello World";
//     *s = foo;
//     printf("s is %s\n", *s);
//     s[0] = foo;
//     printf("s[0] is %s\n", s[0]);
//     return 0;
// }

// int main() {
//     char *s;
//     char foo[] = "Hello World";
//     s = foo;
//     printf("s in %s \n", s);
//     printf("s[0] is %c\n", s[0]);
//     return (0);
// }