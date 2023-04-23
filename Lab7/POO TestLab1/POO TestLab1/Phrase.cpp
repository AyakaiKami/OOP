#include "Phrase.h"
Phrase::Phrase()
{
	size = 0;
	Word = new char*[256];
	Word[0] = new char[256];
}
Phrase::Phrase(const char* in)
{
	size = 0;
	Word = new char* [256];
	Word[0] = new char[256];
	int index = 0;
	int index_word = 0;
	while (in[index] == ' ')
		index++;
	while (in[index] != '\0')
	{
			while (in[index] != ' ' && in[index] != '\0')
			{
				Word[size][index_word] = in[index];
				index_word++;
				index++;
			}
			Word[size][index_word] = '\0';
			index_word = 0;
			size++;
			this->Grow();
			while (in[index] == ' ')
				index++;
	}
	Word[size][index_word] ='\0';
}
Phrase::~Phrase(){}
void Phrase::Grow()
{
	Word[size] = new char[256];
}
void Phrase::operator=(const char* in)
{
	int index = 0;
	int index_word = 0;
	while (in[index] == ' ')
		index++;
	while (in[index] != '\0')
	{
		while (in[index] != ' ' && in[index] != '\0')
		{
			Word[size][index_word] = in[index];
			index_word++;
			index++;
		}
		Word[size][index_word] = '\0';
		index_word = 0;
		size++;
		this->Grow();
		while (in[index] == ' ')
			index++;
	}
	Word[size][index_word] = '\0';
}
Phrase::operator int() 
{
	return size;
}
void Phrase::Print()
{
	for (int i = 0; i <size; i++)
		printf("%s\n", Word[i]);
}
char* Phrase::operator[](int i)
{
	if (i <size && i >= 0)
		return Word[i];
	else
		return nullptr;
}
int Phrase::CountLetter(int index, char ch)
{
	int i = 0,s=0;
	while (Word[index][i] != '\0')
	{
		if (Word[index][i] == ch)
			s++;
		i++;
	}
	return s;
}
int Phrase::CountLetter(char ch)
{
	int i = 0, s = 0;
	int index;
	for (index = 0; index < size; index++)
	{
		while (Word[index][i] != '\0')
		{
			if (Word[index][i] == ch)
				s++;
			i++;
		}
		i = 0;
	}
	return s;
}
char* Phrase::GetLongestWord()
{
	int longest = 0,size_Longest=0;
	int i = 0;
	for (int index = 0; index <size; index++)
	{
		while (Word[index][i] != '\0')
		{
			i++;
		}
		if (i > size_Longest)
		{
			longest = index;
			size_Longest = i;
		}
		i = 0;
	}
	return Word[longest];
}
int Phrase::CountVowels() 
{
	int i = 0, s = 0;
	int index;
	for (index = 0; index <size; index++)
	{
		while (Word[index][i] != '\0')
		{
			char ch = Word[index][i];
			if (ch== 'a'|| ch=='e' || ch=='o' || ch=='u' || ch=='i' || ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I' )
				s++;
			i++;
		}
		i = 0;
	}
	return s;
}