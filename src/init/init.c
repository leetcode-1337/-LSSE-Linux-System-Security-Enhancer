#include <stdio.h>
#include <stdlib.h>
#include "config.h"

void	initialize(void)
{
	if (load_config("config/lsse.conf") != 0) {
		fprintf(stderr, "Failed to load configuration.\n");
		exit(EXIT_FAILURE);
	}
	printf("Initialization complete.\n");
}
