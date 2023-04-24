#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct {
    string head;
    int num;
    int idx;
}Info;

bool compare(Info a, Info b)
{
    if (strcasecmp(a.head.c_str(), b.head.c_str()) < 0)
        return true;
    else if (strcasecmp(a.head.c_str(), b.head.c_str()) > 0)
        return false;
    else if (a.num < b.num)
        return true;
    else if (a.num > b.num)
        return false;

    return false;
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Info> info;
    for (int i = 0; i < files.size(); i++)
    {
        int headEnd = 0;
        int alphaEnd = 0;
        int flag = 0;
        string h, n;
        int num;
        int idx;
        for (int j = 0; j < files[i].size(); j++)
        {
            idx = j;
            if (flag == 0 && files[i][j] >= '0' && files[i][j] <= '9')
            {
                flag = 1;
                headEnd = j - 1;
                h = files[i].substr(0, headEnd + 1);

            }

            if (flag == 1 && (files[i][j] < '0' || files[i][j]>'9'))
            {
                alphaEnd = j - 1;
                if (alphaEnd - headEnd + 1 >= 5)
                    n = files[i].substr(headEnd + 1, 5);
                else
                    n = files[i].substr(headEnd + 1, alphaEnd - headEnd + 1);
                num = stoi(n);
                break;
            }

        }

        info.push_back({ h,num,i });
    }

    stable_sort(info.begin(), info.end(), compare);


    for (int i = 0; i < info.size(); i++)
    {
        answer.push_back(files[info[i].idx]);
    }
    return answer;
}