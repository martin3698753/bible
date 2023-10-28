#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define NUM_BOOKS 31102

using namespace std;

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
	cout << books[0] << endl;
	/*for(int i = 0; i < NUM_BOOKS; i++)
	{
		cout << books[i] << endl;
	}
	return 0;*/
}
