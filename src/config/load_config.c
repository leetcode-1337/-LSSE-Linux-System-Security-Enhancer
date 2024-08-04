#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

int load_config(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open config file");
        return -1;
    }

    char line[MAX_CONFIG_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");

        if (key && value) {
            strncpy(config_entries[config_entry_count].key, key, MAX_CONFIG_KEY_LENGTH);
            strncpy(config_entries[config_entry_count].value, value, MAX_CONFIG_VALUE_LENGTH);
            config_entry_count++;
        }
    }

    fclose(file);
    return 0;
}

const char* get_config_value(const char *key)
{
    for (int i = 0; i < config_entry_count; i++) {
        if (strcmp(config_entries[i].key, key) == 0) {
            return config_entries[i].value;
        }
    }
    return NULL;
}
