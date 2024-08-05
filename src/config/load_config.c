#include "config.h"

/**
 * @brief Loads the configuration from the specified file.
 *
 * This function reads the configuration file line by line and processes each line based on its content.
 * It skips lines starting with '#' or empty lines.
 * If a line starts with '[', it identifies the section and calls the corresponding load function.
 *
 * @param filepath The path to the configuration file.
 * @return 0 if the configuration is successfully loaded, -1 otherwise.
 */
int load_config(const char *filepath) {

    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open config file");
        return -1;
    }

    char line[MAX_CONFIG_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if(line[0] == '#') {
            continue;
        }
        if (line[0] == '\n') {
            continue;
        }
        if (line[0] == '[') {
            char *section = strtok(line, "[]");
            if (strcmp(section, "network") == 0) {
                load_network_config(file);
                if (line[0] == '[') 
                    section = strtok(line, "[]");
            }
            if (strcmp(section, "log_files") == 0) {
                load_log_config(file);
                if (line[0] == '[') 
                    section = strtok(line, "[]");
            }
            if (strcmp(section, "rules") == 0) {
                load_detection_config(file);
                if (line[0] == '[') 
                    section = strtok(line, "[]");
            }
            if (strcmp(section, "alerts") == 0) {
                load_report_config(file);
                if (line[0] == '[') 
                    section = strtok(line, "[]");
            if (strcmp(section, "log") == 0) {
                load_log_config(file);
            }
            if (strcmp(section, "rules") == 0) {
                load_detection_config(file);
            }
            if (strcmp(section, "alerts") == 0) {
                load_report_config(file);
            }
        }
    }
    fclose(file);
    return 0;
}
