#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "inputs.txt"

int main() {
    size_t len, input_len, i, j;
    char *line;
    FILE *fp = fopen(FILENAME, "r");
    if (!fp || (input_len = getline(&line, &len, fp)) == -1)
        return 1;
    --input_len;
    int count[input_len];
    for (i = 0; i < input_len; ++i)
        count[i] = 0;
    char gamma[input_len], epsilon[input_len];
    do {
        ++j;
        for (i = 0; i < input_len; ++i)
            if (line[i] != '0')
                ++count[i];
    } while (getline(&line, &len, fp) != -1);
    for (i = 0; i < input_len; ++i) {
        gamma[i] = count[i] > j - count[i] ? '1' : '0';
        epsilon[i] = gamma[i] == '1' ? '0' : '1';
    }
    printf("%lu\n", strtoul(gamma, NULL, 2) * strtoul(epsilon, NULL, 2));
}
