#include "Headers.h"

string &tolowerString(string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}

int main() {
	setlocale(LC_ALL, "russian");
	map<string, int> dictionary;
	deque<string> words;
	string word;
	short a;

	ifstream in("ins.txt");
	if (!in)
	{
		cerr << "error\n";
	}
	else
	{
		while (!in.eof()){
				in >> word;
				words.push_back(word);
		}
	}

	for (int i = 0; i < words.size();i++)
		tolowerString(words[i]);

	for (int i = 0; i < words.size();i++)
		dictionary[words[i]]++;

	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
		cout << it->first << ": " << it->second << endl;
	in.close();
	int count;
	cout << "\n-----------------------------------------------\n";
	in.open("ins2.txt");
	if (!in)
	{
		cerr << "error\n";
	}
	else
	{
		while (!in.eof()) {
			in >> word;
			tolowerString(word);
			count = 0;
			for (auto it = dictionary.begin(); it != dictionary.end(); it++) {
				if (word == it->first)
				{
					count++;
				}
			}
			if (count == 0)
			{
				cout << word << " - такого слова нет в частотном словаре\n";
				cout << "хотите заменить это слово или добавить его в частотный словарь как есть?1/2\n";
				cin >> a;
				switch (a) {
				case 1:
				{
					cout << "введите новое слово, чтобы заменить старое: "; cin >> word;
					dictionary[word]++;

				}break;

				case 2: {
					dictionary[word]++;
				}break;

				}


			}
			
		}
	}

	ofstream out;
	out.open("ins3.txt");
	out << word;
	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
		out << it->first << ": " << it->second << endl;


	system("pause");
	return 0;
}