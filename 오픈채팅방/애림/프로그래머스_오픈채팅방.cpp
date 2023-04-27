#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map <string, string> m;

typedef struct
{
    string order, id;
}info;

vector<string> split(string str, char d)
{
    istringstream  iss(str);
    vector <string> res;
    string buf;

    while (getline(iss, buf, d))
    {
        res.push_back(buf);
    }

    return res;
}

vector <info> in;
vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++)
    {
        // cout<<"DDDDD";
        vector <string> v;
        v = split(record[i], ' ');
        //for(int i=0;i<v.size();i++)
        //    cout<<v[0]<<" "<<v[1]<<" "<<endl;


        if (v[0] == "Enter")
        {
            //있으면
            if (m.find(v[1]) != m.end())
            {
                m[v[1]] = v[2];
            }
            else
                m.insert({ v[1],v[2] });
        }
        else if (v[0] == "Change")
        {
            if (m.find(v[1]) != m.end())
            {
                m[v[1]] = v[2];
            }
        }

        in.push_back({ v[0],v[1] });
    }

    //  for(auto a:m)
        //  cout<<a.first<<" "<<a.second<<endl;
    for (int i = 0; i < in.size(); i++)
    {

        string ans = "";
        if (in[i].order == "Enter")
        {
            if (m.find(in[i].id) != m.end())
                ans += m[in[i].id];
            ans += "님이 들어왔습니다.";
            answer.push_back(ans);
        }

        else if (in[i].order == "Leave")
        {
            if (m.find(in[i].id) != m.end())
                ans += m[in[i].id];
            ans += "님이 나갔습니다.";
            answer.push_back(ans);
        }


    }

    return answer;
}