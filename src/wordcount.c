// wordcount.c — file statistics CLI (C P1)
// Teaches: stdio, malloc, file I/O, pointer arithmetic, string handling.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    long lines;
    long words;
    long bytes;
    long chars;
} Stats;

Stats count(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    Stats s = {0, 0, 0, 0};
    int c;
    int in_word = 0;

    while ((c = fgetc(f)) != EOF) {
        s.bytes++;
        s.chars++;
        if (c == '\n' || c == '\r') s.lines++;
        if (isspace(c)) in_word = 0;
        else if (!in_word) { in_word = 1; s.words++; }
    }
    fclose(f);
    return s;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <file> [<file> ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        Stats s = count(argv[i]);
        printf("%-20s lines=%-6ld words=%-6ld bytes=%-6ld chars=%-6ld\n",
               argv[i], s.lines, s.words, s.bytes, s.chars);
    }
    return 0;
}
