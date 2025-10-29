#include <cdeferlib/defer.h>
#include <stdio.h>
#include <stdlib.h>

char* file_content(char* name) {
    char* buf = malloc(1024);
    Defer free(buf);

    FILE* f = fopen(name, "r");
    if (!f) {
        return NULL;
    }

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
