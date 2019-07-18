#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);

main()
{
	double start, finish, elapse;
	int i;
	int v[100000];
	int n;

	start = (double)clock() / CLOCKS_PER_SEC;
	for (i = 0; i < 100000; ++i) {
		v[i] = i;
	}
	/*start = (double) clock() / CLOCKS_PER_SEC;*/
	n = binsearch(999, v, 100000);
	finish = (double) clock() / CLOCKS_PER_SEC;
	elapse = finish - start;
	printf("%lf\n", elapse);
	printf("%d\n", n);
}

//int binsearch(int x, int v[], int n)
//{
//	int low, high, mid;
//
//	low = 0;
//	high = n - 1;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		if (x < v[mid]) {
//			high = mid - 1;
//		}
//		else if (x > v[mid]) {
//			low = mid + 1;
//		}
//		else {
//			return mid;
//		}
//	}
//	return -1;
//}

/* 版本 2 */
// int binsearch(int x, int v[], int n)
// {
	// int low, high, mid;

	// low = 0;
	// high = n - 1;
	// while (low <= high) {
		// mid = (low + high) / 2;
		// if (x < v[mid]) {
			// high = mid - 1;
		// }
		// else {
			// low = mid + 1;
		// }
	// }
	// if (x == v[high]) {
		// return high;
	// }
	// else {
		// return -1;
	// }
// }

/* 版本3 */
int binsearch(int t[], int x)
{
	int lowest, mid, highest;
	int i;
	
	for (i = 0; t[i] != '\0'; i++) {
		;
	}
	lowest = 0;
	highest = i - 1;
	while (lowest <= highest) {
		mid = (lowest + highest) / 2;
		if (x > t[mid]) {
			lowest = mid + 1;
		} else if (x < t[mid]) {
			highest = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

/* 版本4 */
int binsearch(int t[], int x)
{
	int lowest, mid, highest;
	int i;
	
	for (i = 0; t[i] != '\0'; i++) {
		;
	}
	lowest = 0;
	highest = i - 1;
	mid = (lowest + highest) / 2;
	while (lowest <= highest && x != t[mid]) {
		if (x > t[lowest]) {
			mid = lowest + 1;
		} else {
			mid = highest - 1;
		}
		mid = (lowest + highest) / 2;
	}
	if (x == t[mid]) {
		return mid;
	}
	else {
		return -1;
	}
}