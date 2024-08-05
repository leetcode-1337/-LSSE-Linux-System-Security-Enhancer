#include "config.h"

void load_report_config(FILE *file)
{
    char    line[MAX_CONFIG_LINE_LENGTH];
    int     max_report_count = 0;
    char    *key, *value;

    while (fgets(line, sizeof(line), file))
    {
        if (line[0] == '\n' || line[0] == '#') // skip empty lines and comments
        {
            continue;
        }
        if (line[0] == '[') // check if max report count is reached
        {
            break;
        }
        key = strtok(line, "="); // get key
        value = strtok(NULL, "\n"); // get value
        max_report_count++;
        if (key && value)
        {
            ;
        }
    }
}
