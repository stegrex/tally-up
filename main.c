#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TallyLog.h"

static int upsert(int argc, char *argv[])
{
    if (argc != 5) {
        printf("Input: UUID timestamp actionString\n");
        return 1;
    }
    logTally(argv[2], atoi(argv[3]), argv[4]);
    return 0;
}

char * getLogString(int argc, char *argv[], char *outputString)
{
    return getLogContents(outputString);
}

char * getLogStringByKey(int argc, char *argv[], char *outputString)
{
    return getLogContentsByKey(argv[2], outputString);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
        printf("Valid args: upsert, dump, dumpByKey\n");
    }
    if (strcmp(argv[1], "upsert") == 0) {
        return upsert(argc, argv);
    } else if (strcmp(argv[1], "dump") == 0) {
        // Maximum log size is 16 bits.
        // Need to rebalance logs when close to this size.
        char *outputString = calloc(65536, sizeof(char));
        outputString = getLogString(argc, argv, outputString);
        printf("%s", outputString);
        free(outputString);
    } else if (strcmp(argv[1], "dumpByKey") == 0) {
        char *outputString = calloc(65536, sizeof(char));
        outputString = getLogStringByKey(argc, argv, outputString);
        printf("%s", outputString);
        free(outputString);
    } else {
        return 1;
    }
    return 0;
}