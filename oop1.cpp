
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
void sort(string buf[],int sizebuf)
{
	string c;
	for(int i=0;i<sizebuf;i++)
		for(int j=i;j <=sizebuf; j++)
			if (buf[i].size() < buf[j].size())
			{
				c = buf[j];
				buf[j] = buf[i];
				buf[i] = c;
			}
			else
				if (buf[i].size() < buf[j].size())
				{
					int k = 0;
					for(k=0;k<=buf[i].size();k++)
						if(buf[i][k]< buf[j][k])
						{
							c = buf[j];
							buf[j] = buf[i];
							buf[i] = c;
							break;
						}
				}
}
void main()
{
	ifstream d;
	d.open("C:\\Users\\Bombita\\OOP\\oop1\\in.txt");
	if (d.is_open())
	{
		string buf[101];
		string r;
		int i = -1;
		while (getline(d, r))
		{
			buf[++i] = r;
			cout << buf[i] << endl;
		}
		sort(buf, i );
		cout << endl;
		d.close();
		for(int j=0;j<=i;j++)
			cout << buf[j]<< endl;
	}
	else
		cout << "Nope";
}