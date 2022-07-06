// 1201201140
// 八木洸太

#include<stdio.h>
#include<stdlib.h> 
#include<math.h>

// is_prime returns 1 if n is a prime number, 0 otherwise.
int is_prime(int n) {
	if (n <= 1) {
		return 0;
	}

	if (n <= 3) {
		return 1;
	}

	if (n % 2 == 0 || n % 3 == 0) {
		return 0;
	}

	int limit = (int)floor(sqrt((double)n) + 1.0);
	for (int i = 5; i < limit; i+=6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	if (is_prime(n) == 1) {
		printf("%d is a prime number\n", n);
	} else {
		printf("%d is not a prime number\n", n);
	}

	return 0;
}
