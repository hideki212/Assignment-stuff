#include <stdio.h>

char *months[] =
    {
        " ",
        "\nJanuary",
        "\nFebruary",
        "\nMarch",
        "\nApril",
        "\nMay",
        "\nJune",
        "\nJuly",
        "\nAugust",
        "\nSeptember",
        "\nOctober",
        "\nNovember",
        "\nDecember"};

int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void calender();
void calc();
void prime();
void oddEven();
void minMax();
void buildCalender(int month, int year, int first_day);
int leapyear(int year);
int first_day_year(int year);
int checkPrimeNumber(int number);
void addFunc(float x, float y);
void subFunc(float x, float y);
void multiplyFunc(float x, float y);
void divideFunc(float x, float y);
float num(int x);
void sym(float x, float y);
void getEven(int number);
void getOdd(int number);
void getInput();
void findMin();
void findMax();

int numbers[100];

int i, values, arrSize;

int main()
{
    int choice = 1, con = 1;
    while (con == 1)
    {
        if (choice > 6 || choice < 1)
            printf("Please chose a valid option\n\n1: Display the calendar of the month\n2: Calculator\n3: Find prime number from a list \n4: Find odd and even numbers from a list\n5:Find a minimum and maximum numbers from a list\n6:Exit the program\n\n");
        else
            printf("1: Display the calendar of the month\n2: Calculator\n3: Find prime number from a list \n4: Find odd and even numbers from a list\n5: Find a minimum and maximum numbers from a list\n6: Exit the program\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            calender();
            break;

        case 2:
            calc();
            break;

        case 3:
            prime();
            break;

        case 4:
            oddEven();
            break;

        case 5:
            minMax();
            break;

        case 6:
            printf("thanks see you again\n");
            con = 0;
            break;
        default:
            choice = 99;
            break;
        }
        printf("\n");
    }
}

int first_day_year(int year)
{
    int first_day;
    int x;
    int y;
    int z;

    x = (year - 1.) / 4.0;
    y = (year - 1.) / 100.;
    z = (year - 1.) / 400.;

    first_day = (year + x - y + z) % 7;

    return first_day;
}

int leapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        month_days[2] = 29;
        return 1;
    }
    else
    {
        month_days[2] = 28;
        return 0;
    }
}

void buildCalender(int month, int year, int first_day)
{
    int i;

    printf("%s %d\n\n", months[month], year);
    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (i = 0; i < month; i++)
    {
        first_day = (first_day + month_days[month]) % 7;
    }

    for (i = 1; i <= 1 + first_day * 5; i++)
    {
        printf(" ");
    }

    for (i = 1; i <= month_days[month]; i++)
    {
        printf("%2d", i);

        if ((i + first_day) % 7 > 0)
            printf("   ");
        else
            printf("\n ");
    }
}

void calender()
{
    int year;
    int month;
    int first_day;

    do
    {
        printf("Enter a month (1 - 12): ");
        scanf("%d", &month);
    } while (month < 1 || month > 12);

    do
    {
        printf("Enter a year (1978 - 3000): ");
        scanf("%d", &year);
    } while (year < 1978 || year > 3000);

    first_day = first_day_year(year);
    leapyear(year);
    buildCalender(month, year, first_day);
    printf("\n\n\n");
}

//Calculator and functions
void calc()
{
	float num1 = num(1);
	float num2 = num(2);
	sym(num1, num2);
	printf("This calculator will now shut down. If you have any complaints please direct them to /dev/null.\n");
}

void addFunc(float x, float y) // +
{
	printf("The total is %.2f.\n", x + y);
}

void subFunc(float x, float y) // -
{
	printf("The total is %.2f.\n", x - y);
}

void multiplyFunc(float x, float y) // *
{
	printf("The total is %.2f.\n", x * y);
}

void divideFunc(float x, float y) // /
{
	printf("The total is %.2f.\n", x / y);
}

float num(int x) //Number input
{
	float y;
	int valid;
	do 
	{
		printf("Enter number %d: ", x);
		scanf(" %f", &y);
		if (x == 0) //data validation
			printf("What are you trying to do, divide by zero? Why do you even want to use zero anyways?\n");
		else if (x == '+' || x == '-' || x == '/' || x == '*')
			printf("Why are you even entering a symbol here? Numbers only.\n");
		else
			valid = 1;
	} while (valid != 1);
	return y;
}

void sym(float x, float y) //Symbol input and answer display
{
	char z;
	int valid = 0;
	do
	{
		printf("Enter a symbol: ");
		scanf(" %c", &z);
		if (z == '+') 
		{
			addFunc(x, y);
			valid = 1;
		}
		else if (z == '-')
		{
			subFunc(x, y);
			valid = 1;
		}
		else if (z == '*')
		{
			multiplyFunc(x, y);
			valid = 1;
		}
		else if (z == '/')
		{
			divideFunc(x, y);
			valid = 1;
		}
		else
			printf("Support for other symbols will come never. For now please use the +, -, *, and / symbols.\n");
	} while (valid != 1);
}

void prime()
{
    int number1, number2, i, found;

    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);

    printf("Prime numbers in range %d and %d are:\n", number1, number2);

    for (i = number1 + 1; i < number2; ++i)
    {
        found = checkPrimeNumber(i);

        if (found == 1)
            printf("%d ", i);
    }

    printf("\n");
}

int checkPrimeNumber(int number)
{
    int j, found = 1;

    for (j = 2; j <= number / 2; ++j)
    {
        if (number % j == 0)
        {
            found = 0;
            break;
        }
    }

    return found;
}

void oddEven()
{
    int number1, number2, i, found;

    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);

    printf("Prime numbers in range %d and %d are:\n", number1, number2);

    for (i = number1 + 1; i < number2; ++i)
    {
        if (i % 2 == 0)
            getEven(i);
        else
            getOdd(i);

        printf("\n");
    }

    printf("\n");
}

void getOdd(int number)
{
    printf("%d is odd.", number);
}

void getEven(int number)
{
    printf("%d is even.", number);
}

void minMax()
{
    printf("How many number do you want to comapare: ");

    scanf("%d", &arrSize);

    printf("Enter numbers \n");

    for (i = 0; i < arrSize; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

void findMin()
{
    values = numbers[0];

    for (i = 1; i < arrSize; i++)
    {
        if (numbers[i] < values)
        {
            values = numbers[i];
        }
    }

    printf("Minimum = %d \n", values);
}

void findMax()
{
    values = numbers[0];

    for (i = 1; i < arrSize; i++)
    {
        if (numbers[i] > values)
        {
            values = numbers[i];
        }
    }
    printf("Maximum = %d\n", values);
}

