#include <stdio.h>
#include <string.h>

#define FILENAME "inputs.txt"

int main() {
    int magnitude, v = 0;
    unsigned h = 0;
    char *line, *direction, *sep;
    size_t len;
    ssize_t read;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
        return 1;
    while ((read = getline(&line, &len, fp)) != -1) {
        sep = strchr(line, ' ');
        *sep = '\0';
        direction = line;
        sscanf(sep + 1, "%d", &magnitude);
        if (strcmp(direction, "forward") == 0)
            h += magnitude;
        else if (strcmp(direction, "down") == 0)
            v += magnitude;
        else if (strcmp(direction, "up") == 0)
            v -= magnitude;
    }
    printf("%d\n", v * h);
}
