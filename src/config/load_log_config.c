#include "config.h"

/**
 * @brief Loads the network configuration from a file.
 *
 * This function reads the network configuration from the specified file and applies it to the system.
 *
 * @param file A pointer to the file containing the network configuration.
 */
void load_log_config(FILE *file)
{
    char    line[MAX_CONFIG_LINE_LENGTH];
    int     max_log_count = 0;
    char    *key, *value;

    while (fgets(line, sizeof(line), file))
    {
        printf("Line: %s\n", line);
        if (line[0] == '\n' || line[0] == '#') // skip empty lines and comments
        {
            continue;
        }
        if (line[0] == '[' || max_log_count == MAX_LOG_COUNT) // check if max log count is reached
        {
            break;
        }
        key = strtok(line, "="); // get key
        value = strtok(NULL, "\n"); // get value
        if (key && value)
        {
            max_log_count++;
            if (strcmp(key, "auth_log") != 0 && strcmp(key, "syslog") != 0) // check if key is valid
            {
                fprintf(stderr, "Invalid key in log configuration: %s expected auth_log, syslog\n", key);
                exit (EXIT_FAILURE);
            }
            strncpy(config_entries.log[max_log_count].alias, key, MAX_CONFIG_KEY_LENGTH);
            strncpy(config_entries.log[max_log_count].file, value, MAX_CONFIG_KEY_LENGTH);
        max_log_count++;
        if (key && value)
        {
            strncpy(config_entries.log[max_log_count].alias, key, MAX_CONFIG_KEY_LENGTH);
            strncpy(config_entries.log[max_log_count].file, value, MAX_CONFIG_KEY_LENGTH);
            printf("Alias: %s, File: %s\n", config_entries.log[max_log_count].alias, config_entries.log[max_log_count].file);
        }
    }
}
