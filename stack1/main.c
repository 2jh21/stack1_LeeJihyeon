#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10

typedef int element;
element stack[MAX_STACK_SIZE];
int  top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else return stack[top--];
}

element peek() {
	if (is_empty()) {
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else return stack[top];
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 30; i++) {
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0) {
			push(rand_num);
			printf("[%d] Push %d\n", i + 1, rand_num);
		}
		else
			printf("[%d]Pop %d\n", i + 1, pop());
	}
	system("pause");
	return 0;
}
