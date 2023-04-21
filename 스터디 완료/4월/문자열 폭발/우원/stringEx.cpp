#include <string>
#include <iostream>
#include <deque>
using namespace std;
int len;
bool isEqual(deque<char> tmp, string findval) {
	for (int i = 0; i < len; ++i) {
		if (tmp[i] != findval[i]) return 0;
	}
	return 1;
}


int main(){
	string str, findval;
	cin >> str >> findval;
	len = findval.size();
	string ret;
	string tmp;

	for (int i = 0; i < str.size(); ++i) {
		ret+=str[i];
		tmp+=str[i];
		if (tmp.size() > len) tmp=tmp.substr(1);
		if (tmp == findval) {
			ret.erase(ret.end() - len, ret.end());
			tmp.clear();
			int sz = ret.size();
			for (int i = 0; (tmp.size() != len) && sz - 1 - i >= 0 ; ++i) {
				tmp = ret[sz - 1 - i] + tmp;
			}
		}
	}
	if (ret.size() == 0) cout << "FRULA\n";
	else {
		for (int i = 0; i < ret.size(); ++i) {
			cout << ret[i];
		}
	}
	
}
