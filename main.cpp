#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>

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

void make_dir(string book)
{
	namespace fs = std::filesystem;
	char* path = getenv("HOME");
	if (path == nullptr)
	{
		cerr << "ERROR: Home variable not set" << endl;
	}

	fs::path biblePath(path);
	biblePath /= ".config/bible/";

	if (!fs::exists(biblePath))
	{
		if(fs::create_directory(biblePath))
		{
			cout << "Created directory: " << biblePath << endl;
		}
		else
		{
			cerr << "Error while creating directory: " << biblePath << endl;
		}
	}

	biblePath /= book;

	if (!fs::exists(biblePath))
	{
		if(fs::create_directory(biblePath))
		{
			cout << "Created directory: " << biblePath << endl;
		}
		else
		{
			cerr << "Error while creating directory: " << biblePath << endl;
		}
	}
}

int main()
{
	srand((unsigned)time(0));
	vector<string> books = getBooks();
	cout << books[7] << endl;
	//for (int i = 0; i < books.size(); i++)
	//{
	//	vector<string> line = splitLine(books[i]);
	//	make_dir(line[0]);
	//}
	return 0;
}
