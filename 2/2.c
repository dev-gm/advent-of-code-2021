#include <stdio.h>
#include <string.h>

#define FILENAME "inputs.txt"

int main() {
    int magnitude, aim = 0;
    unsigned depth = 0, h = 0;
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
        if (strcmp(direction, "forward") == 0) {
            h += magnitude;
            depth += magnitude * aim;
        } else if (strcmp(direction, "down") == 0)
            aim += magnitude;
        else if (strcmp(direction, "up") == 0)
            aim -= magnitude;
    }
    printf("%d\n", depth * h);
}
