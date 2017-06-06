//Giant Calculator mess by a potato
#include<stdio.h>
//prototype declarations
void addFunc(float x, float y);
void subFunc(float x, float y);
void multiplyFunc(float x, float y);
void divideFunc(float x, float y);
float num(int x);
void sym(float x, float y);

void main() {
	float num1 = num(1);
	float num2 = num(2);
	sym(num1, num2);
	printf("This program will now shut down. If you have any complaints please direct them to /dev/null.\n");
}

//adds
void addFunc(float x, float y) {
	printf("The total is %.2f.\n", x + y);
}
//subtracts
void subFunc(float x, float y) {
	printf("The total is %.2f.\n", x - y);
}
//multiplies
void multiplyFunc(float x, float y) {
	printf("The total is %.2f.\n", x * y);
}
//divides
void divideFunc(float x, float y) {
	printf("The total is %.2f.\n", x / y);
}
//input for the numbers
float num(int x){
	float y;
       	int valid;
	do {
		printf("Enter number %d: ", x);
		scanf(" %f", &y);
		//data validation
		if (x == 0)
			printf("What are you trying to do, divide by zero? Why do you even want to use zero anyways?\n");
		else if (x == '+' || x == '-' || x == '/' || x == '*')
			printf("Why are you even entering a symbol here? Numbers only.\n");
		else
			valid = 1;
	} while (valid != 1);
	return y;
}
//symbol input and display answers
void sym(float x, float y) {
	char z;
	int valid = 0;
	do {
		printf("Enter a symbol: ");
		scanf(" %c", &z);
		if (z == '+') {
			addFunc(x, y);
			valid = 1;
		}
		else if (z == '-') {
			subFunc(x, y);
			valid = 1;
		}
		else if (z == '*') {
			multiplyFunc(x, y);
			valid = 1;
		}
		else if (z == '/') {
			divideFunc(x, y);
			valid = 1;
		}
		else
			printf("Support for other symbols will come never. For now please use the +, -, *, and / symbols.\n");
	} while (valid != 1);
}
