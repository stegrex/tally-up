extern void logTally(
    char *id,
    unsigned long int timestamp,
    char actionString[]
);

extern char * getLogContents(char *outputString);

extern char * getLogContentsByKey(char *key, char *outputString);