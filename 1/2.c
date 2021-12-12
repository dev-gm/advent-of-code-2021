#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define FILENAME "./inputs.txt"

int main() {
    int out = 0, k[4];
    char *line_buf = NULL;
    size_t line_buf_size;
    ssize_t line_size;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
        return 1;
    for (unsigned char i = 0; i < 3; ++i) {
        line_size = getline(&line_buf, &line_buf_size, fp);
        sscanf(line_buf, "%d", k + i);
    }
    while (line_size >= 0) {
        line_size = getline(&line_buf, &line_buf_size, fp);
        memmove(k, k + 1, 3 * sizeof(int));
        sscanf(line_buf, "%d", &k[3]);
        if (k[1] + k[2] + k[3] > k[0] + k[1] + k[2])
            ++out;
    }
    printf("%d\n", out);
}
