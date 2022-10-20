#include "MyString.h"
#include <iostream>

using namespace std;

namespace MyStringClass
{
	MyString::MyString(const char* str)
		:mLength(MyStrLen(str) + 1)
	{
		mString = new char[mLength];
		memcpy(mString, str, mLength);
	}

	MyString::MyString(const MyString& other)
		:mLength(other.mLength)
	{
		mString = new char[mLength];
		memcpy(mString, other.mString, mLength);
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength - 1;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	MyString& MyString::Append(const MyString& other)
	{
		int sumLength = mLength + other.mLength - 1;
		char* sumString = new char[sumLength + 1];

		memcpy(sumString, mString, mLength);
		MyStrCat(sumString, other.mString);
		delete[] mString;

		mString = sumString;
		mLength = sumLength;

		return *this;
	}

	MyString MyString::operator+(const MyString& other)
	{
		int sumLength = mLength + other.mLength - 1;
		char* sumString = new char[sumLength + 1];

		memcpy(sumString, mString, mLength);
		MyStrCat(sumString, other.mString);

		MyString result(sumString);
		delete[] sumString;

		return result;
	}

	void MyString::Reverse()
	{
		char* start = mString;
		char* end = mString + mLength - 2;

		while (start < end)
		{
			char tmp = *start;
			*start = *end;
			*end = tmp;
			start++;
			end--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mLength != rhs.mLength)
		{
			return false;
		}

		size_t count = mLength;

		while (count > 0)
		{
			if (*mString != *rhs.mString)
			{
				return false;
			}
			count--;
		}

		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		delete[] mString;
		int rhsLength = rhs.mLength;
		mString = new char[rhsLength + 1];
		memcpy(mString, rhs.mString, rhs.mLength);

		return *this;
	}

	void MyString::ToLower()
	{
		for (size_t i = 0; i < mLength; i++)
		{
			if (mString[i] >= 65 && mString[i] <= 90)
			{
				mString[i] += 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		for (size_t i = 0; i < mLength; i++)
		{
			if (mString[i] >= 97 && mString[i] <= 122)
			{
				mString[i] -= 32;
			}
		}
	}

	void MyString::PrintLn()
	{
		for (size_t i = 0; i < mLength; i++)
		{
			cout << mString[i];
		}
		cout << "\n";
	}

	unsigned int MyString::MyStrLen(const char* str) const
	{
		unsigned int count = 0;

		while (*str != '\0')
		{
			count++;
			str++;
		}
		return count;
	}

	char* MyString::MyStrCat(char* dest, const char* src)
	{
		char* p = dest;

		while (*dest != '\0')
		{
			dest++;
		}

		while (*src != '\0')
		{
			*dest = *src;
			dest++;
			src++;
		}

		*dest = '\0';

		return p;
	}
}