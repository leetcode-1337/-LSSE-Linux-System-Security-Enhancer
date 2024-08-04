#include "init.h"
#include "log_monitor.h"
#include "net_monitor.h"
#include "detection.h"
#include "report.h"

int	main() {
	initialize();
	monitor_logs();
	monitor_network();
	detect_intrusions();
	generate_report();
	return 0;
}
