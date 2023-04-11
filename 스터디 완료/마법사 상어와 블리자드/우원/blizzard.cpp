#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <deque>

#define R first
#define C second

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, m, score, cnt;
int Map[55][55];
deque<pii> cmds; 
int dr[] = { 0,-1,1,0,0 };
int dc[] = { 0,0,0,-1,1 };
int turnLeft[] = { 0,3,4,2,1 };
int startP;
deque<int> v;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> Map[i][j];
            if (Map[i][j] != 0) cnt++;
        }
    }
    startP = n  / 2;
    for (int i = 0; i < m; ++i) {
        int d, s; cin >> d >> s;
        cmds.push_back({ d,s });
    }
}

void Map2V() {
    v.clear();
    int move = 1; int dir = 3; int flag = 0; pii pos = { startP, startP };
    while (1) {
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < move; ++i) {
                if (pos.R == 0 && pos.second == 0) flag = 1;
                if (flag) break;
                pii nextPos = { pos.R + dr[dir], pos.C + dc[dir] };
                v.push_back(Map[nextPos.R][nextPos.C]);
                pos = nextPos;
            }
            dir = turnLeft[dir];
            if (flag) break;
        }   
        if (flag) break;
        move++;
    }
}

void reGenerateMap(deque<int> v) {
    int move = 1; int dir = 3; int flag = 0; pii pos = { startP, startP }; int cursor = 0;
    while (1) {
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < move; ++i) {
                if (pos.R == 0 && pos.second == 0) flag = 1;
                if (flag) break;
                pii nextPos = { pos.R + dr[dir], pos.C + dc[dir] };
                if (v.size() <= cursor) Map[nextPos.R][nextPos.C] = 0;
                else Map[nextPos.R][nextPos.C]= v[cursor++];
                pos = nextPos;
            }
            dir = turnLeft[dir];
            if (flag) break;
        }
        if (flag) break;
        move++;
    }
}

void icebeam(int d, int s) {
    pii pos = { startP ,startP };
    while (s--) {
        pos.R += dr[d];
        pos.C += dc[d];
        Map[pos.R][pos.C] = 0;
    }
}

int moveNpop() {
    int sz = v.size(); int flag = 0;
    deque<int> newV; newV.push_back(v[0]);
    int last = v[0]; int cnt = 1;
    for (int i = 1; i < sz; ++i) {
        if (v[i] == 0) continue;
        if (last == v[i]) cnt++;
        if (last != v[i]) {
            if (cnt >= 4) { 
                score += last * cnt;
                while (cnt--) newV.pop_back(); 
                flag = 1;
            }
            else cnt = 1;
        }
        newV.push_back(v[i]);
        last = newV.back();
    }
    if (cnt >= 4) {
        score += last * cnt;
        while (cnt--) {
            newV.pop_back();
        }
        flag = 1;
    }
    if (newV.size() == 0) return 0;
    if (newV.size()!= 0 &&newV.front() == 0) newV.pop_front();
    v = newV;
    return flag;
}

void generateNewV() {
    int sz = v.size();
    deque<int> newV;
    int last = v[0]; int cnt = 1;
    for (int i = 1; i < sz; ++i) {
        if (last == v[i]) cnt++;
        if (last != v[i]) {
            newV.push_back(cnt);
            newV.push_back(last);
            cnt = 1;
        }
        last = v[i];
    }
    newV.push_back(cnt);
    newV.push_back(last);
    v = newV;
}

int main(){
    input();
    if (cnt == 0){
        cout << 0;
        return 0;
    }
    Map2V();
    for (int i = 0; i < m; ++i) {
        icebeam(cmds[i].first, cmds[i].second);
        Map2V();
        int flag = 1;
        while (flag) {
            flag = moveNpop();
        }
        generateNewV();
        reGenerateMap(v);
    }
    cout << score;
    int de = 1;
    return 0;
}
