// Demonstrating the buffer overflow in C
#include <stdio.h>

int main()
{

    // declaring two strings one after another in hopes that
    // they get allocated in the adjacent memory
    // location(usually the case)
    char str1[10];
    char str2[25] = "Something meaningful";

    // reading strings
    printf("Enter the str1: ");
    scanf("%[^\n]s ", str1);

    // printing strings
  printf("str1: %s\nstr2: %s", str1, str2);
    return 0;
}