/*Use a single array to implement three stacks*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 30

typedef struct tagStack{
	int *sp1;
	int *sp2;
	int *sp3;
	int *stack1;
	int *stack2;
	int *stack3;
}STACK;

STACK *createStack(int size)
{
	STACK *hstack;

	hstack = (STACK *)malloc(sizeof(STACK));

	hstack->stack1 = calloc(ARR_SIZE, sizeof(int));

	hstack->sp1 = hstack->stack1;
	hstack->stack2 = hstack->sp2 = hstack->stack1 + (ARR_SIZE / 2);
	hstack->stack3 = hstack->sp3 = hstack->stack1 + (ARR_SIZE - 1);

	return hstack;
}

void push1(STACK *hstack, int val)
{
	if(hstack->sp1 < hstack->stack2){
		*hstack->sp1++ = val;
	}else{
		fprintf(stderr, "Stack1 Overflow!..\n");
		return;
	}
}

static int isShiftable(STACK *hstack)
{
	if(hstack->sp1 + 2 < hstack->stack2 && hstack->sp2 >= hstack->sp3)
		return 1;
	return 0;
}

void push2(STACK *hstack, int val)
{
	if(hstack->sp2 < hstack->sp3){
		*hstack->sp2++ = val;
	} else if(isShiftable(hstack)){
			printf("Stack2 is being shifted..\n");
			
			int stacksize2 = (hstack->sp2) - (hstack->stack2);
			
			hstack->stack2 = memmove(hstack->sp1 + 3, hstack->stack2, stacksize2 * sizeof(int));

			hstack->sp2 = (hstack->stack2) + stacksize2;

			memset(hstack->sp2, 0, ((hstack->sp3 + 1) - (hstack->sp2)) * sizeof(int));

			*(hstack->sp2++) = val;
		} else{
			fprintf(stderr, "Stack2 Overflow!..\nCan not shift Stack2 because Stack1 is full!..\n");
			return;
		}
}

void push3(STACK *hstack, int val)
{
	if(hstack->sp3 >= hstack->sp2){
		*hstack->sp3-- = val;
	}else{
		fprintf(stderr, "Stack3 Overflow!..\n");
		return;
	}
}

void printStack(STACK *hstack)
{
	int *temp = hstack->stack1;

	for(int i = 0; i < ARR_SIZE; ++i)
		printf("%d ", *temp++);
	printf("\n");
}

void destroyStack(STACK *hstack)
{
	free(hstack->stack1);
	free(hstack);
}

int main(){
	STACK *hstack;

	hstack = createStack(ARR_SIZE);

	push1(hstack, 1);
	push1(hstack, 2);
	push1(hstack, 3);
	push1(hstack, 4);
	push1(hstack, 5);

	push2(hstack, 15);
	push2(hstack, 25);
	push2(hstack, 35);
	push2(hstack, 45);
	push2(hstack, 55);

	push3(hstack, 355);
	push3(hstack, 365);
	push3(hstack, 375);
	push3(hstack, 385);

	push2(hstack, 65);
	push2(hstack, 75);
	push2(hstack, 85);
	push2(hstack, 95);
	push2(hstack, 105);
	push2(hstack, 115);

	printStack(hstack);

	destroyStack(hstack);
}