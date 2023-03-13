#include "Number.h"
Number::~Number() {
	base_nr = 0;
	///delete[] this->value_nr_int;
}
Number::Number() { value_nr_int = new int[256]; base_nr = 10; }
Number::Number(const char* value, int base)
{
	value_nr_int = new int[256];
	int i = 0;
	while (value[i] != '\0')
	{
		if (value[i] >= '0' && value[i] <= '9')
		{
			if (base + '0' <= value[i])
			{
				printf("Nu se incadreaza in baza"); break;
			}
			value_nr_int[i] = value[i] - '0';
		}
		else
			if (value[i] >= 'A' && value[i] <= 'F')
			{
				if (value[i] - 'A' >= base - 10)
				{
					printf("Nu se incadreaza in baza"); break;
				}
				value_nr_int[i] = value[i] - 'A'+10;
			}
			else
			{
				printf("Nu se incadreaza in baza"); break;
			}
		i++;
	}
	value_nr_int[i] = -1;
	base_nr = base;
}
Number::Number(int nr)
{
	value_nr_int = new int[256];
	int i = 0;
	while (nr)
	{
		value_nr_int[i] = nr % 10;
		nr = nr / 10;
		i++;
	}
	value_nr_int[i] = -1;
	i--;
	int j = 0, c;
	while (j <= i)
	{
		c = value_nr_int[i]; value_nr_int[i] = value_nr_int[j]; value_nr_int[j] = c;
		i--; j++;
	}
	base_nr = 10;
}
void Number::Print()
{
	int i = 0;
	while (value_nr_int[i]!=-1)
	{
		if (value_nr_int[i] - 10 >= 0)
			printf("%c", value_nr_int[i] + 'A' - 10);
		else
			printf("%c",value_nr_int[i] + '0');
		i++;
	}
}
int Number::GetDigitsCount()
{
	int i = 0;
	while (value_nr_int[i] != -1)
		i++;
	return i;
}
int Number::GetBase()
{
	return base_nr;
}
void Number::SwitchBase(int newBase)
{
	int x = 0,i=GetDigitsCount()-1;
	while (i >=0)
	{
		x = x * base_nr + value_nr_int[i];
		i--;
	}
	i = 0;
	while (x != 0)
	{
		value_nr_int[i] = x % newBase;
		i++;
		x = x / newBase;
	}
	value_nr_int[i] = -1;
	int j = i - 1;
	i = 0;
	while (i <= j)
	{
		int cop = value_nr_int[i];
		value_nr_int[i] = value_nr_int[j];
		value_nr_int[j] = cop;
		i++;
		j--;
	}
	base_nr = newBase;
}

void Number::SetBase(int newBase)
{
	base_nr = newBase;
}
void Number::SetValue(int newValue[])
{
	value_nr_int = newValue;
}
Number operator+(Number obj1,Number obj2)
{
	/*if (obj1.GetBase() != obj2.GetBase())
	{
		if (obj1.GetBase() > obj2.GetBase())
			obj2.SwitchBase(obj1.GetBase());
		else
			obj1.SwitchBase(obj2.GetBase());
	}
	int t=0,v[256],i=obj1.GetDigitsCount()-1, j=obj2.GetDigitsCount()-1, k=0;
	while (i>=0 && j>=0)
	{
		
		v[k]= (obj1.value_nr_int[i] + obj2.value_nr_int[j] + t) % obj1.GetBase();
		t = (obj1.value_nr_int[i] + obj2.value_nr_int[j] + t) / obj1.GetBase();
		i--; j--;k++;
	}
	while (i>=0)
	{
		t = (obj1.value_nr_int[i] + t) / obj1.GetBase();
		v[k] = (obj1.value_nr_int[i] + t) % obj1.GetBase();
		i--;k++;
	}
	while (j>=0)
	{
		t = (obj2.value_nr_int[j] + t) / obj1.GetBase();
		v[k] = (obj2.value_nr_int[j] + t) % obj1.GetBase();
		j--; k++;
	}
	while (t)
	{
		v[k] = t % obj1.GetBase();
		t = t / obj1.GetBase();
		k++;
	}
	
	i = 0; j = k-1; v[k] = -1;
	while (i <= j)
	{
		int cp = v[i];
		v[i] = v[j];
		v[j] = cp;
		i++; j--;
	}
	Number rez("1",2);
	rez.SetValue(v);
	rez.SetBase(obj1.GetBase());
	*/
	int x = 0, i = obj1.GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * obj1.base_nr + obj1.value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	Number rez = x + y;
	if (obj1.GetBase() > obj2.GetBase())
		rez.SwitchBase(obj1.GetBase());
	else
		rez.SwitchBase(obj2.GetBase());
	return rez;
}

int Number::operator>(Number obj2)
{
	int x = 0, i = GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * base_nr + value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	if (x > y)
		return 1;
	else
	    return 0;
}

int Number::operator>=(Number obj2)
{
	int x = 0, i = GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * base_nr + value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	if (x >= y)
		return 1;
	return 0;
}
int Number::operator<(Number obj2)
{
	int x = 0, i = GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * base_nr + value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	if (x < y)
		return 1;
	return 0;
}
int Number::operator<=(Number obj2)
{
	int x = 0, i = GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * base_nr + value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	if (x <= y)
		return 1;
	return 0;
}
int Number::operator==(Number obj2)
{
	int x = 0, i = GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * base_nr + value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	if (x == y)
		return 1;
	return 0;
}
void Number::operator+=(Number obj2)
{
	if (GetBase() != obj2.GetBase())
	{
		if (GetBase() > obj2.GetBase())
			obj2.SwitchBase(GetBase());
		else
			SwitchBase(obj2.GetBase());
	}
	int t = 0, v[256], i = GetDigitsCount() - 1, j = obj2.GetDigitsCount() - 1, k = 0;
	while (i >= 0 && j >= 0)
	{

		v[k] = (value_nr_int[i] + obj2.value_nr_int[j] + t) % GetBase();
		t = (value_nr_int[i] + obj2.value_nr_int[j] + t) / GetBase();
		i--; j--; k++;
	}
	while (i >= 0)
	{
		t = (value_nr_int[i] + t) / GetBase();
		v[k] = (value_nr_int[i] + t) % GetBase();
		i--; k++;
	}
	while (j >= 0)
	{
		t = (obj2.value_nr_int[j] + t) / GetBase();
		v[k] = (obj2.value_nr_int[j] + t) % GetBase();
		j--; k++;
	}
	while (t)
	{
		v[k] = t % GetBase();
		t = t / GetBase();
		k++;
	}

	i = 0; j = k - 1; v[k] = -1;
	while (i <= j)
	{
		int cp = v[i];
		v[i] = v[j];
		v[j] = cp;
		i++; j--;
	}
	SetValue(v);
}
int Number::operator[](int index)
{
	if (value_nr_int[index] < 10)
		return value_nr_int[index] + '0';
	else
		return value_nr_int[index] + 'A' - 10;
}
void Number::operator--()
{
	int i = 0;
	for (i = 0; i < GetDigitsCount() ; i++)
		value_nr_int[i] = value_nr_int[i + 1];
}///prefixat
void Number::operator--(int)
{
	value_nr_int[GetDigitsCount() - 1] = -1;
}///postfixat
Number operator-(Number obj1, Number obj2)
{
	
	int x = 0, i = obj1.GetDigitsCount() - 1;
	while (i >= 0)
	{
		x = x * obj1.base_nr + obj1.value_nr_int[i];
		i--;
	}
	int y = 0, j = obj2.GetDigitsCount() - 1;
	while (j >= 0)
	{
		y = y * obj2.base_nr + obj2.value_nr_int[j];
		j--;
	}
	Number rez=x-y;
	if (obj1.GetBase() > obj2.GetBase())
		rez.SwitchBase(obj1.GetBase());
	else
		rez.SwitchBase(obj2.GetBase());
	return rez;
}
void Number::operator=(int nr)
{
	int i=0;
	while (nr)
	{
		value_nr_int[i] = nr % 10;
		nr = nr / 10;
		i++;
	}
	value_nr_int[i] = -1;
	i--;
	int j = 0,c;
	while (j <= i)
	{
		c = value_nr_int[i]; value_nr_int[i] = value_nr_int[j]; value_nr_int[j] = c;
		i--; j++;
	}
	base_nr = 10;
}
void Number::operator=(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			value_nr_int[i] = s[i] - '0';
		else
				printf("Gresit\n");
		i++;
	}
	value_nr_int[i] = -1;
	i--;
	int j = 0, c;
	while (j <= i)
	{
		c = value_nr_int[i]; value_nr_int[i] = value_nr_int[j]; value_nr_int[j] = c;
		i--; j++;
	}
	base_nr = 10;
}
void Number::operator=(Number obj2)
{
	for (int i = 0; i <= obj2.GetDigitsCount();i++)
		value_nr_int[i] = obj2.value_nr_int[i];
	SetBase(obj2.base_nr);
}