#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
#include <queue>

int main() {
    std::ifstream myfile("input.txt");
    std::map<std::string, int> words;
    std::priority_queue<std::pair<int,std::string>>pq;
    std::string line;
    if (myfile.is_open())
    {
        std::getline(myfile, line);
        std::string copline = line;
        std::string word;
        int i = 0;
        while (copline[i] != '\0')
        {
            copline[i]=tolower(copline[i]);
            if (copline[i] != ' ' && (copline[i] < 'a' || copline[i]>'z'))
                copline[i] = ' ';
            i++;
        }
        std::istringstream iss(copline);
        while (std::getline(iss,word,' '))
        {
            if (word != "")
            {
                const std::string cop = word;
                words[cop]++;
                ///std::cout << cop << " " << words[cop] << std::endl;
            }
        }
        std::map<std::string, int>::iterator index = words.begin();
        while (index != words.end())
        {
            std::pair<int,std::string>pairw;
            pairw.first = index->second;
            pairw.second = index->first;
            pq.push(pairw);
            ++index;
        }
        std::vector<std::pair<std::string, int>>vect_val;
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
            for(int i=pr;i<ul-1;i++)
                for(int j=i+1;j<ul;j++)
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
        myfile.close();
    }
    else std::cout<<"Unable to open file";
    return 0;
}