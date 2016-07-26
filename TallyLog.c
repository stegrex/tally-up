#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int ACTION_REMOVE = 0;
static const int ACTION_APPEND = 1;
static const char LOG_FILE_NAME[] = "logFile.txt";

struct TallyLog {
    char                *id;
    unsigned long int   timestamp;
    unsigned short int  action;
};

static void
logTallyToFile(struct TallyLog tallyLog)
{
    FILE *logFile;
    logFile = fopen(LOG_FILE_NAME, "a");
    // DEBUG
    ///*
    printf(
        "Stored record: %s %lu %hu\n",
        tallyLog.id,
        tallyLog.timestamp,
        tallyLog.action
    );
    //*/
    fprintf(
        logFile,
        "%s %lu %hu\n",
        tallyLog.id,
        tallyLog.timestamp,
        tallyLog.action
    );
    fclose(logFile);
}

void
logTally(
    char *id,
    unsigned long int timestamp,
    char actionString[]
)
{
    struct TallyLog tallyLog;
    tallyLog.id = id;
    tallyLog.timestamp = timestamp;
    if (strcmp(actionString, "remove") == 0) {
        tallyLog.action = ACTION_REMOVE;
    } else {
        tallyLog.action = ACTION_APPEND;
    }
    logTallyToFile(tallyLog);
}

char *
getLogContents(char *outputString)
{
    FILE *logFile;
    logFile = fopen(LOG_FILE_NAME, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, logFile)) != -1) {
        strcat(outputString, line);
    }
    free(line);
    fclose(logFile);
    return outputString;
}

char *
getLogContentsByKey(char *key, char *outputString)
{
    FILE *logFile;
    logFile = fopen(LOG_FILE_NAME, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    while ((read = getline(&line, &len, logFile)) != -1) {
        char lineCpy[256];
        strcpy(lineCpy, line);
        token = strtok(lineCpy, " ");
        if (strcmp(token, key) == 0) {
            //printf("%s", line);
            strcat(outputString, line);
        }
    }
    free(line);
    fclose(logFile);
    return outputString;
}