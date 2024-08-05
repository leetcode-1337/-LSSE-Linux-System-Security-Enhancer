#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <unistd.h>
void	monitor_logs() {
    t_log_entry *log = config_entries.log;

    for (int i = 0; i < MAX_LOG_COUNT; i++) {
        if (log[i].file[0] == '\0') {
            break;
        }
        printf("Monitoring log: %s\n", log[i].file);
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            execlp("tail", "tail", "-f", log[i].file, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }
}

