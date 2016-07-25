#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TallyLog.h"

static int
upsert(int argc, char *argv[])
{
    if (argc != 5) {
        printf("Input: UUID timestamp actionString\n");
        return 1;
    }
    logTally(argv[2], atoi(argv[3]), argv[4]);
    return 0;
}

void
dump(int argc, char *argv[])
{
    dumpLog();
}

void
dumpByKey(int argc, char*argv[])
{
    dumpLogByKey(&argv[2]);
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
        dump(argc, argv);
    } else if (strcmp(argv[1], "dumpByKey") == 0) {
        dumpByKey(argc, argv);
    } else {
        return 1;
    }
    return 0;
}