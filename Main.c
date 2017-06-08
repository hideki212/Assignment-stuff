#include <stdio.h>

void calc();
void prime();
void oddEven();
void minMax();
void addFunc(float x, float y);
void subFunc(float x, float y);
void multiplyFunc(float x, float y);
void divideFunc(float x, float y);
void sym(float x, float y);
void getEven(int number);
void getOdd(int number);
void getInput();
void findMin();
void findMax();
void calendar(int y, int m);
void startCalendar();

int checkPrimeNumber(int number);
int todayOf(int y, int m, int d);
int leapYears(int y);
int isLeapYear(int y);

long days(int y, int m, int d);
float num(int x);

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
            startCalendar();
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

/*
    True if leap year
    child method of calender
*/

int isLeapYear(int y)
{
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

/*
    The number of leap year
    child method of calender
*/
int leapYears(int y)
{
    return y / 4 - y / 100 + y / 400;
}

/*
    number of days since the beginning of the year
    child method of calender
*/
int todayOf(int y, int m, int d)
{
    static int DayOfMonth[] =
        {-1 /*dummy*/, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    return DayOfMonth[m] + d + ((m > 2 && isLeapYear(y)) ? 1 : 0);
}
/*
    Total number of days
    child method of calender
*/
long days(int y, int m, int d) /* Total number of days */
{
    int lastYear;

    lastYear = y - 1;

    return 365L * lastYear + leapYears(lastYear) + todayOf(y, m, d);
}
/*
    Start calender functionality here
    has 1 child method called Calender()
*/
void startCalendar()
{
    int year, month;

    printf("Enter the month and year: ");
    scanf("%d %d", &month, &year);

    calendar(year, month);
}
/*
    display calendar at m y
    child method of startCalender
*/
void calendar(int y, int m) 
{
    const char *NameOfMonth[] = {NULL /*dummp*/,
                                 "January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};
    char Week[] = "Su Mo Tu We Th Fr Sa";
    int DayOfMonth[] =
        {-1 /*dummy*/, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekOfTopDay;
    int i, day;

    weekOfTopDay = days(y, m, 1) % 7;
    if (isLeapYear(y))
        DayOfMonth[2] = 29;
    printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);

    for (i = 0; i < weekOfTopDay; i++)
        printf("   ");
    for (i = weekOfTopDay, day = 1; day <= DayOfMonth[m]; i++, day++)
    {
        printf("%2d ", day);
        if (i % 7 == 6)
            printf("\n");
    }
    printf("\n");
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
/*
    Get prime number
    has 2 child methods
*/
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
/*
    Check for prime number
    Child method to prime()
*/
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
/*
    Input odd even numbers
*/
void oddEven()
{
    int number1, number2, i, found;

    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);

    printf("Odd even in range %d and %d are:\n", number1, number2);

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
/*
    Find odd number function
*/
void getOdd(int number)
{
    printf("%d is odd.", number);
}
/*
    Find Even number function
*/
void getEven(int number)
{
    printf("%d is even.", number);
}
/*
    Input Odd Even
*/
void minMax()
{
    printf("How many number do you want to comapare: ");

    scanf("%d", &arrSize);

    printf("Enter numbers \n");

    for (i = 0; i < arrSize; i++)
    {
        scanf("%d", &numbers[i]);
    }
    findMin();
    findMax();
}
/*
    Find Min
    child method of minMax()
*/
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
/*
    Find Max
    child method of minMax()
*/
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
