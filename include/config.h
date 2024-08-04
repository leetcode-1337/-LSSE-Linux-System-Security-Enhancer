#ifndef CONFIG_H
# define CONFIG_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAX_CONFIG_LINE_LENGTH 256
#define MAX_CONFIG_KEY_LENGTH 50
#define MAX_CONFIG_VALUE_LENGTH 200

typedef struct s_config{
    char key[MAX_CONFIG_KEY_LENGTH];
    char value[MAX_CONFIG_VALUE_LENGTH];
} t_config;

static t_config config_entries[100];
static int config_entry_count = 0;

#endif
