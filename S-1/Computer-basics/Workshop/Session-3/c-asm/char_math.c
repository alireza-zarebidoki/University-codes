// char_math.c - Character arithmetic in pure C
// Compile: gcc char_math.c -o char_math.exe
// Generate assembly: gcc -S char_math.c -o char_math.s

#include <stdio.h>

int main() {
    char x = 'A';  // ASCII 65
    char y = 'B';  // ASCII 66  
    char z;
    
    // Character arithmetic - add 3 to y
    z = y + 3;     // Should be 'E' (69)
    
    printf("x = '%c' (%d)\n", x, x);
    printf("y = '%c' (%d)\n", y, y);
    printf("z = y + 3 = '%c' (%d)\n", z, z);
    
    return 0;
}