#include <stdio.h>
#include <stdarg.h>

#ifdef DEBUG
#define log(...) __log(__LINE__, __FILE__, __VA_ARGS__)
#else
#define log(...)  // Không in gì trong production
#endif

int __log(int line, const char *file, const char *fmt, ...) {
    fprintf(stderr, "|%s:%d| ", file, line);
    
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    
    fprintf(stderr, "\n");
    return 0;
}

int main() {
    int x = 42;
    log("Value of x: %d", x);  // Chỉ in khi compile với -DDEBUG
    
    x = x * 2;
    log("After multiply: %d", x);
    
    return 0;
}

// Compile: gcc -DDEBUG -o program program.c
// Output: |program.c:15| Value of x: 42
//         |program.c:18| After multiply: 84