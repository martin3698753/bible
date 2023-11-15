#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitLine(string s)
{
	vector<string> ret_str;
	size_t pos;
	string token;
	pos = s.find(" ");
	token = s.substr(0, pos);
	ret_str.push_back(token);
	s.erase(0, pos + 1);
	pos = s.find("\t");
	token = s.substr(0, pos);
	ret_str.push_back(token);
	s.erase(0, pos + 1);
	ret_str.push_back(s);
	return ret_str;
}

vector<string> getBooks()
{
	vector<string> books;
	ifstream file;

	file.open("bibles/asv.txt");
	if(file.fail())
	{
		cout << "Failed to open file" << endl;
	}
	while(!file.eof())
	{
		string line;
		getline(file, line);
		books.push_back(line);
	}
	file.close();
	return books;
}

int main()
{
	vector<string> books = getBooks();
	vector<string> line = splitLine(books[0]);
	cout << line[2] << endl;
	return 0;
}
