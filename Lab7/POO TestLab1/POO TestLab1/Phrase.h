#ifndef PHRASE
#define PHRASE
#include <stdio.h>
class Phrase {

private:
	char** Word;
	int size;
public:
	Phrase();
	Phrase(const char* in);
	~Phrase();
	void Grow();
	void operator=(const char* in);
	operator int();
	void Print();
	char* operator[](int i);
	int CountLetter(int index, char ch);
	int CountLetter(char ch);
	char* GetLongestWord();
	int CountVowels();
};
#endif // !PHRASE
