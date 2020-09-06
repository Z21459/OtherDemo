#include <iostream>
using namespace std;
#include <vector>

vector<string> split_string(const string& s, const char* del)
{
	size_t pos = 0, pre_pos = 0;
	vector<string> tmp;
	while ((pos = s.find(del, pre_pos)) != string::npos)
	{
		tmp.push_back(s.substr(pre_pos, pos - pre_pos));
		pre_pos = ++pos;
	}
	if (pre_pos != s.size())  tmp.push_back(s.substr(pre_pos, s.size() - pre_pos));
	return tmp;
}

int main()
{
	string s = "how are you?";
	const char * del = " ";
	vector<string> tmp = split_string(s, del);
	cout << tmp.size() << endl; //输出分割的段数
	for (size_t i = 0; i < tmp.size(); ++i)
		out << tmp[i] << endl;  //输出分割后的子串    
		
	cin.get();
	
	system("pause");
	return 0;

} 
