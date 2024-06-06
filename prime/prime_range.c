#include <stdio.h>
#include <stdlib.h>

#define PRIME_FILE "prime_list.txt"


int main()
{
	int limit;
	printf("Limit: ");
	scanf("%d", &limit);
	getchar();							// trim Enter

	// sieve[i] = 0 means i is prime
	// sieve[i] = 1 means i is not prime
	// initially all indices are considered prime
	// composite numbers will be marked 1 later
	int *sieve = calloc(limit+1, sizeof(int));

	if (sieve == NULL) {
		printf("Could not allocate enough memory to create the sieve.\n");
		return 1;
	}

	sieve[0] = 1;
	sieve[1] = 1;

	// writing in a file because it is faster than writing to stdout
	FILE *primefile = fopen(PRIME_FILE, "w");
	// printf("Prime numbers: [");

	if (limit >= 2) {
		fprintf(primefile, "%d", 2);
		// printf("%d", 2);
		for (int i = 4; i <= limit; i+=2)
			sieve[i] = 1;
	}

	for (int i = 3; i <= limit; ++i) {
		if (sieve[i] == 0) {
			fprintf(primefile, ", %d", i);
			// printf(", %d", i);
			for (int j = 2*i; j <= limit; j+=i)
				sieve[j] = 1;
		}
	}

	fclose(primefile);
	free(sieve);

	printf("Prime numbers: [");
	fflush(stdout);

	char command[100];
	// using cat to print in stdout because it is faster than printf
	sprintf(command, "cat " PRIME_FILE);
	system(command);

	printf("]\n");

	return 0;
}

