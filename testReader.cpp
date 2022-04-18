 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;
 
int main()
{
	string fname = "tmdb_5000_credits.csv";
 
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
    int rowCounter = 0;

	fstream file (fname, ios::in);
	if(file.is_open() && rowCounter < 4804)
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	for(int i=0;i<content.size() && rowCounter < 50;i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
			cout<<content[i][j]<<" ";
            
		}
		cout<<"\n";
        rowCounter++;
	}
 
	return 0;
}
 
 