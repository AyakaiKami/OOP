#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
int main()
{
    std::map<const std::string, int>Map_Of_Words;
    FILE *in;
    in = fopen("textin.txt", "r");
    char c;
    char word[100]; int word_lenght=0;
    //word = new std::string;
    while (fread(&c, 1, 1, in))
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            word[word_lenght++]=tolower(c);
        else
        {
            word[word_lenght]='\0';
            const char* word_cop = word;
            if (word_lenght)
            {
                Map_Of_Words[word_cop]++;
            }
            word_lenght=0;
        }
    }
    
    word[word_lenght] = '\0';
    const char* word_cop = word;
    if (word_lenght)
    {
        Map_Of_Words[word_cop]++;
    }

    std::map<const std::string, int>::iterator index = Map_Of_Words.begin();
    std::priority_queue < std::pair<int, std::string>>pq;
    while (index!=Map_Of_Words.end())
    {
        std::pair<int, std::string>pairvers;
        pairvers.first = index->second;
        pairvers.second = index->first;
        pq.push(pairvers);
        ++index;
    }
    std::vector < std::pair<std::string, int>>vect_val;
    int pr = 0, ul = 0;
    
    while (!pq.empty())
    {
        std::pair<std::string, int>cop_pairw;
        int aparitii = pq.top().first;
        cop_pairw.first = pq.top().second;
        cop_pairw.second = pq.top().first;
        while (!pq.empty() && pq.top().first == aparitii)
        {
            cop_pairw.first = pq.top().second;
            cop_pairw.second = pq.top().first;
            vect_val.push_back(cop_pairw);
            ul++;
            pq.pop();
        }
        for (int i = pr; i < ul - 1; i++)
            for (int j = i + 1; j < ul; j++)
                if (vect_val[i].first > vect_val[j].first)
                {
                    std::pair<std::string, int>trans = vect_val[i];
                    vect_val[i] = vect_val[j];
                    vect_val[j] = trans;
                }
        pr = ul;
    }
    for (int i = 0; i < ul; i++)
        std::cout << vect_val[i].first << "==>" << vect_val[i].second << std::endl;
    fclose(in);
    return 0;
}