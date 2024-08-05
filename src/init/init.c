#include <stdio.h>
#include <stdlib.h>
#include "config.h"

void	initialize(int ac, char **av)
{
	bool custom_config = false;
	for (int i = 1; i < ac; i++) {
		if (strcmp(av[i], "-h") == 0) {
			printf("Usage: %s [-h] [-v] [-c file]\n", av[0]);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(av[i], "-v") == 0) {
			printf("Version: 1.0\n");
			exit(EXIT_SUCCESS);
		}
		if (strcmp(av[i], "-c") == 0) {
			custom_config = true;
			if (ac < i + 1) {
				fprintf(stderr, "Missing argument for -c\n");
				exit(EXIT_FAILURE);
			}
			if (load_config(av[i + 1]) != 0) {
				fprintf(stderr, "Failed to load configuration.\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	if (!custom_config) {
		if (load_config("~/.lsse/lsse.conf") != 0) {
			fprintf(stderr, "Failed to load configuration.\n");
			exit(EXIT_FAILURE);
		}
	}
	if (ac == 1)
	{
		printf("Usage: %s [-h] [-v] [-c file]\n", av[0]);
		exit(EXIT_SUCCESS);
	}
}
