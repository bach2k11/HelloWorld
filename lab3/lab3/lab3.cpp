#include <stdio.h>

typedef enum {
	IDLE,
	D0,
	D01,
	D010
} FSMState;

int Find(int n) {
	static FSMState currentState = IDLE;
	switch (currentState) {

	case IDLE:
		if (n == 0) {
			currentState = D0;
		}

		else currentState = IDLE;
		break;

	case D0:
		if (n == 1) {
			currentState = D01;
		}
		else {
			currentState = D0;
		}
		break;
	case D01:
		if (n == 0) {
			currentState = D010;
		}
		else {
			currentState = IDLE;
		}
		break;
	case D010:
		if (n == 0)currentState = D0;
		else currentState = D01;
		break;
	}
	return currentState == D010;
}

int main() {

	int (*ptr)(int) = &Find;
	while (1) {
		int n;
		printf("nhap: "); scanf_s("%d", &n);

		printf("output =%d\n", (*ptr)(n));
		if (n == 5) break;
	}

	return 0;
}


