#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
void addtostr(string x, string &m)
{
    int xl = x.size(), ml = m.size();
    if (xl > ml)
    {
        string c = x;
        x = m;
        m = c;
        xl = x.size();
        ml = m.size();
    }

    int t = 0, xc,mc;
    ml--; xl--;
    while(ml>=0 && xl>=0)
    {
        mc = m[ml] - '0';
        xc = x[xl] - '0';
        m[ml] = (mc + xc+t) % 10+'0';
        t = (mc + xc+t) / 10;
        ml--;
        xl--;
    }
    while (ml >= 0)
    {
        mc = m[ml] - '0';
        m[ml] = (mc + t) % 10 + '0';
        t = (mc + t) / 10;
        ml--;
    }
}
void main()
{
   ifstream d;
    d.open("C:\\Users\\Bombita\\OOP\\ex1\\ex1\\Text.txt");
    if (d.is_open())
    {
        string s; 
        getline(d, s);
        string r;
        while (getline(d, r))
        {
            addtostr(r, s);
        }
        d.close();
        cout << s;
    }
    else
        cout << "Nope";
}