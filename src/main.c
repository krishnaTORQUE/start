#include <cdeferlib/defer.h>
#include <cdeferlib/try.h>
#include <stdio.h>
#include <stdlib.h>

char* file_content(char* name) {
    char* buf = malloc(1024);
    Defer free(buf);

    FILE* f;
    Try(f, fopen(name, "r"), return "");
    Defer fclose(f);

    fgets(buf, 1024, f);
    return buf;
}

int main() {
    char* content = file_content("start.txt");
    Defer free(content);
    printf("%s\n", content);
    return 0;
}
