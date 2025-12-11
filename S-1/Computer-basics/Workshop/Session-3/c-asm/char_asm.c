// char_asm.c - Character arithmetic with inline assembly
// Compile: gcc char_asm.c -o char_asm.exe  
// Generate assembly: gcc -S char_asm.c -o char_asm.s

#include <stdio.h>

int main() {
    char x, y, z;
    
    // Inline assembly for character operations
    // GCC uses AT&T syntax by default
    __asm__ (
        "movb $65, %[x_var]\n"      // x = 'A' (65)
        "movb $66, %[y_var]\n"      // y = 'B' (66)
        "movb %[y_var], %%al\n"     // AL = y
        "addb $3, %%al\n"           // AL = AL + 3 (y + 3)
        "movb %%al, %[z_var]\n"     // z = AL
        : 
        [x_var] "=m" (x),
        [y_var] "=m" (y),
        [z_var] "=m" (z)
        : 
        : "al", "cc"
    );
    
    printf("x = '%c' (%d)\n", x, x);
    printf("y = '%c' (%d)\n", y, y); 
    printf("z = y + 3 = '%c' (%d)\n", z, z);
    
    return 0;
}