//A program to multiply two scientific numbers together

#include<iostream>
using namespace std;
struct number
{
	char sign; // either '+' or '-' 
	int  exp; // exponent
	float mant; // mantissa
};

void get_number(number& keith)
{
	cout << "enter the sign ";
	cin >> keith.sign;
	cout << "enter the mantissa ";
	cin >> keith.mant;
	cout << "enter the exponent ";
	cin >> keith.exp;
}
void print_number(number mick)
{
	cout << mick.sign << " " << mick.mant << " x 10 " << mick.exp << endl<<endl;
}
void save_number(number a[], number mick)
{
	static int index = 0;
	if (index < 5)
	{
		a[index] = mick;
		index++;
	}
	
}
void print_array(number a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		print_number(a[i]);
	}
}
number multiply(number mick, number keith)
{
	number multiplication;
	
	multiplication.mant = mick.mant * keith.mant;
	multiplication.exp = mick.exp + keith.exp;

	if (mick.sign == '+' && keith.sign == '+' || mick.sign == '-' && keith.sign == '-')
	{
		multiplication.sign = '+';
	}
	else
	{
		multiplication.sign = '-';
	}
	return multiplication;
}
void normalize(number& keith)
{
	while ((int)(keith.mant * 10) == 0)
	{
		keith.mant = keith.mant * 10;
		keith.exp--;
	}
}
int main()
{
	number mick, keith, ron;
	number array[5];
	get_number(mick);
	print_number(mick);
	save_number(array, mick);


	get_number(keith);
	print_number(keith);
	save_number(array, keith);
	
	
	ron = multiply(mick, keith);
	print_number(ron);
	normalize(ron);
	print_number(ron);
	save_number(array, ron);
	cout << "The array is: " << endl;
	print_array(array, 3);

	return 0;
}
