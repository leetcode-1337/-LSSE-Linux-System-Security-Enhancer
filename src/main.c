#include "init.h"
#include "config.h"
#include "log_monitor.h"
#include "net_monitor.h"
#include "detection.h"
#include "report.h"

int	main(int ac, char **av) {
	initialize(ac, av);
	for (int i = 0; i < config_entry_count; i++) {
		printf("Network: %s, %s, %s\n", config_entries.network[i].interface, config_entries.network[i].ip, config_entries.network[i].mask);
	}
	for (int i = 0; i < config_entry_count; i++) {
		printf("Log: %s, %s\n", config_entries.log[i].alias, config_entries.log[i].file);
	}
	monitor_logs();
	monitor_network();
	detect_intrusions();
	generate_report();
	return 0;
}
