#include <string>
#include <ctime>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void slova3(char* s, vector<string>& ch, vector<string>& kolv)
{
	char slovo[20];
	int i, j; i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == ' ' || (s[i] == ',')))  //пропуск разделителей
			i++;

		if (s[i] != '\0')					//формирование слова
		{
			j = 0;
			while (s[i] != '\0' && (s[i]) != ' ' && s[i] != ',')
			{
				slovo[j] = s[i]; i++; j++;
			}
			slovo[j] = '\0';
			if (find(ch.begin(), ch.end(), slovo) == ch.end())
				ch.push_back(slovo);
			kolv.push_back(slovo);
			if (s[i] != '\0') i++;
		}
	}
}

int kolv_slova(string slovo, vector<string> mas) {
	int s = 0;
	for (int i = 0; i < mas.size(); i++)
		if (mas[i]==slovo)
			s += 1;
	return s;
}

int main()
{
	vector<string> kolv_dict;
	vector<string> ch_dict;

	char str[1024];
	gets_s(str);

	string s1 = str;

	slova3(str, ch_dict, kolv_dict);

	int j = 0;
	for (int i = 0; i < ch_dict.size(); i++)
	{
		int kolv = kolv_slova(ch_dict[i], kolv_dict);
		if (kolv > 1) {
			int k = 0;
			int flag = 0;
			while (k < s1.size())
			{
				//cout << k << "   " << ch_dict[i] << "   " << ch_dict[i].size() << "   " << endl << s1 << endl;
				if (s1.compare(k, ch_dict[i].size(), ch_dict[i]) == 0) {
					if (flag == 1) {
						s1.erase(k, ch_dict[i].size() + 1);
						k--;
					}
						
					else
						flag += 1;
				}
				k++;
				//cout << s1 << endl;
			}
			int r = s1.find(ch_dict[i], j);
			s1.insert(r, "(" + to_string(kolv) + ")");
		}
	}
	cout << s1;
	return 0;
}
