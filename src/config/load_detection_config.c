#include "config.h"

void load_detection_config(FILE *file)
{
    char    line[MAX_CONFIG_LINE_LENGTH];
    char    *key, *value;

    while (fgets(line, sizeof(line), file))
    {
        printf("Line: %s\n", line);
        if (line[0] == '\n' || line[0] == '#') // skip empty lines and comments
        {
            continue;
        }
        if (line[0] == '[')
        {
            break;
        }
        key = strtok(line, "="); // get key
        value = strtok(NULL, "\n"); // get value
        if (key && value)
        {
            ;
        }
    }
}