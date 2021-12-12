#include <stdio.h>
#include <stdint.h>

#define FILENAME "inputs.txt"

int main() {
    int n, out = 0, k, l;
    char *line_buf;
    size_t line_buf_size;
    ssize_t line_size;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
        return 1;
    line_size = getline(&line_buf, &line_buf_size, fp);
    sscanf(line_buf, "%d", &l);
    while (line_size >= 0) {
        line_size = getline(&line_buf, &line_buf_size, fp);
        sscanf(line_buf, "%d", &k);
        if (k > l)
            ++out;
        l = k;
    }
    printf("%d\n", out);
}
