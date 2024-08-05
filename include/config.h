#ifndef CONFIG_H
# define CONFIG_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_CONFIG_LINE_LENGTH 256
# define MAX_CONFIG_KEY_LENGTH 50
# define MAX_CONFIG_VALUE_LENGTH 200
# define MAX_NETWORK_COUNT 5
# define MAX_LOG_COUNT 5

typedef struct s_network_entry {
    char interface[50]; // network interface to monitor for network traffic 
    char ip[50]; // ip address of the machine running the program
    char mask[50]; // subnet mask of the machine running the program
} t_network_entry;

typedef struct s_log_entry {
    char file[50]; // path to the log file to monitor
    char alias[50]; // name of the log file to monitor
} t_log_entry;

typedef struct s_detection_entry {
    int threshold; // number of failed login attempts before an intrusion is detected
    int interval; // time interval in seconds to monitor for failed login attempts
    int lock_time; // time in seconds to lock the account after an intrusion is detected
    int lock_threshold; // number of intrusions before the account is locked
    int report_threshold; // number of intrusions before a report is generated
} t_detection_entry;

typedef struct s_report_entry {
    char report_dir[50]; // path to the directory to write the intrusion report
    char report_mail[50]; // email address to send the intrusion report
    int interval;   // time interval in seconds to generate the intrusion report
} t_report_entry;

typedef struct s_config_entry{
    t_network_entry network[MAX_NETWORK_COUNT];
    t_log_entry log[MAX_LOG_COUNT];
    t_detection_entry detection;
    t_report_entry report;
} t_config_entry;

static t_config_entry config_entries;


static int config_entry_count;
int load_config(const char *filepath);

void load_network_config(FILE *file);
void load_log_config(FILE *file);
void load_detection_config(FILE *file);
void load_report_config(FILE *file);


#endif
