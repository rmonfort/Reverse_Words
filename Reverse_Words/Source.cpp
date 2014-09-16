#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::vector;

void load_iss_into_vector(istringstream &iss, vector<string> &words)
{
	string temp;
	while (getline(iss, temp, ' '))
	{
		words.push_back(temp);
	}
}

void reverse_print_vector(const vector<string> &words)
{
	for (auto beg = words.crbegin(); beg != words.crend(); beg++)
	{
		cout << *beg << " ";
	}
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	// Cycle through file until EOF
	string line;
	while (getline(ifs, line))
	{
		// Ignore empty lines
		if (line.empty())
		{
			continue;
		}
		istringstream iss(line);

		// Obtain words from line and swap their position
		vector<string> words;
		load_iss_into_vector(iss, words);
		reverse_print_vector(words);
		cout << endl;
	}

	return 0;
}