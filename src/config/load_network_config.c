#include "config.h"

/**
 * @brief Loads the network configuration from a file.
 *
 * This function reads the network configuration from the specified file and applies it to the system.
 *
 * @param file A pointer to the file containing the network configuration.
 */
void load_network_config(FILE *file)
{
    bool    interface_found = false, ip_found = false, mask_found = false;
    char    line[MAX_CONFIG_LINE_LENGTH];
    int     max_network_count = 0;
    char    *key, *value;

    while (fgets(line, sizeof(line), file))
    {
        if (line[0] == '\n' || line[0] == '#') // skip empty lines and comments
        {
            continue;
        }
        if (line[0] == '[' || max_network_count == MAX_NETWORK_COUNT) // check if max network count is reached
        {
            break;
        }
        key = strtok(line, "="); // get key
        value = strtok(NULL, "\n"); // get value
        if (mask_found) // check if all values are found and reset flags
        {
            interface_found = false;
            ip_found = false;
            mask_found = false;
            max_network_count++;
        }
        if (key && value)
        {
            if (strcmp(key, "interface") == 0)
            {
                interface_found = true;
                strncpy(config_entries.network[max_network_count].interface, value, MAX_CONFIG_KEY_LENGTH);
            }
            if (strcmp(key, "ip") == 0)
            {
                if (!interface_found)
                {

                    fprintf(stderr, "Error: IP address found before interface\n");

                    exit (EXIT_FAILURE);
                }
                ip_found = true;
                strncpy(config_entries.network[max_network_count].ip, value, MAX_CONFIG_KEY_LENGTH);
            }
            if (strcmp(key, "mask") == 0)
            {
                if (!ip_found)
                {
                    fprintf(stderr, "Error: Subnet mask found before IP address\n");
                    exit (EXIT_FAILURE);
                }
                if (!interface_found)
                {
                    fprintf(stderr, "Error: Subnet mask found before interface\n");
                    exit (EXIT_FAILURE);
                }
                mask_found = true;
                strncpy(config_entries.network[max_network_count].mask, value, MAX_CONFIG_KEY_LENGTH);
            }
        }
    }
}
