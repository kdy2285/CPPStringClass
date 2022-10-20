#include <iostream>
#include <cassert>
#include "MyString.h"

using namespace MyStringClass;
using namespace std;

int main()
{
	MyString str1("Hello");
	MyString str1Reverse("olleH");

	MyString str2(str1);
	MyString str3 = "Writing ";
	MyString str4 = "print 10 and then 5 more";
	MyString str5 = "world";
	MyString str3_5Append = "Writing world";

	cout << "Constructor : ";
	str1.PrintLn();
	cout << "CopyConstructor : ";
	str2.PrintLn();

	assert(str1.GetLength() == 5);

	str1.Reverse();
	assert(str1 == str1Reverse);
	assert(str3.Append(str5) == str3_5Append);

	MyString sumOperation = str1 + str5;
	MyString sumOperationResult = "olleHworld";

	assert(str1 + str5 == sumOperationResult);
	assert(!(str1 == str5));

	MyString str6 = "Test string: ";
	MyString str7 = "x";
	MyString str8 = "Test string: x";

	assert(str6 + str7 == str8);

	MyString str9 = "TO LOWeR ALpha TEst";
	MyString str9Lower = "to lower alpha test";
	str9.ToLower();

	assert(str9 == str9Lower);

	MyString str10 = "to Lower AlpHa Test";
	MyString str10Upper = "TO LOWER ALPHA TEST";
	str10.ToUpper();

	assert(str10 == str10Upper);
}