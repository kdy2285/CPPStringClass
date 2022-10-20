#pragma once
namespace MyStringClass
{
	class MyString
	{
	public:
		MyString(const char* str);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		MyString& Append(const MyString& other);
		MyString operator+(const MyString& other);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();
		void PrintLn();

	private:
		char* mString;
		unsigned int mLength;

		unsigned int MyStrLen(const char* str) const;
		char* MyStrCat(char* dest, const char* src);
	};
}