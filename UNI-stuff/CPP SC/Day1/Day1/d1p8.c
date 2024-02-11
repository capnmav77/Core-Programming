#include <stdio.h>
#include <stdlib.h>

FILE *openFiles(const char *inputFile, const char *outputFile) {
    FILE *input = NULL;
    FILE *output = NULL;

    input = fopen(inputFile, "r");
    if (input == NULL) {
        goto cleanup;
    }

    output = fopen(outputFile, "w");
    if (output == NULL) {
        goto cleanup;
    }

    // do something with the files

cleanup:
    if (input != NULL) {
        fclose(input);
    }
    if (output != NULL) {
        fclose(output);
    }

    return output;
}

int main() {
    openFiles("input.txt", "output.txt");

    return 0;
}
