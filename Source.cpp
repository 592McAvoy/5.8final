//�����ջ�
//1.ͨ������<,>ʵ�ֶ�sort���������ʹ�ã������Ϳ���ͨ���Ƚ��������ĳһ�������������������� ��line15,112,122,125
//2.ͨ������struct������class�� Node����ʵ�ֲ�ͬ���͵����������ϵ ��line19

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<set>
#include<stack>
#include<algorithm>

using namespace std;

struct Node {
	Node() {};
	Node(int nn, string ss) :n(nn), suffix(ss) {};
	int n;
	string suffix;
};

void read();
void set_map(int n);
void search();
bool operator>(const Node& a, const Node& b);
bool operator<(const Node& a, const Node& b);

vector<string> dict;
map<string, vector<string>> suffix_map;
stack<string> suffix_stack;


int main() {
	read();
	while (true) {
		cout << "what do you want to do?(enter 0 to quit)\n";
		cout << "1.input n\n";
		cout << "2.input suffix\n";
		cout << "your choice: ";
		char ch;
		cin >> ch;
		if (ch == '0')break;
		switch (ch) {
		case'1': {
			cin.get();
			cout << "input an int: ";
			int n;
			cin >> n;
			set_map(n);
			search();
			break;
		}
		case'2': {
			cin.get();
			cout << "input your suffix: ";
			string ss;
			getline(cin, ss);
			int num = ss.size();
			set_map(num);
			for (int i = 0; i < suffix_map[ss].size(); i++)
				cout << suffix_map[ss][i] << " ";
			cout << endl;
			break;
		}
		default:cout << "invalid input\n";
		}
		cout << endl;
	}
}

void read() {
	ifstream ff;
	ff.open("dictionary.txt");
	string word;
	while (!ff.eof()) {
		getline(ff, word);
		dict.push_back(word);//��dict������ļ��еĵ���
	}
}

void set_map(int n) {
	set<string> suffix_set;
	const int size = dict.size();
	for (int i = 0; i < size; i++) {
		string word = dict[i];
		int length = word.size();
		if (length < n);
		else {
			string suffix = word.substr(length - n);
			suffix_map[suffix].push_back(word);
			if (suffix_set.find(suffix) == suffix_set.end()) {
				suffix_stack.push(suffix);	
				suffix_set.insert(suffix);				
			}			
		}
	}
}

void search() {
	vector<Node> nn;
	while (!suffix_stack.empty()) {
		string suf = suffix_stack.top();
		suffix_stack.pop();
		int num = suffix_map[suf].size();
		nn.push_back(Node(num, suf));
	}

	sort(nn.begin(), nn.end());

	for (int i = 0; i < 10; i++) {
		cout << nn[i].suffix << ": " << nn[i].n << endl;
		for (int j = 0; j < suffix_map[nn[i].suffix].size(); j++)
			cout << suffix_map[nn[i].suffix][j] << " ";
		cout << endl;
	}
}

bool operator>(const Node& a, const Node& b){
	return (a.n < b.n);
}
bool operator<(const Node& a, const Node& b) {
	return (a.n > b.n);
}
