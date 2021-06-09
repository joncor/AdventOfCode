#include<vector>
#include<iostream>
#include<fstream>
#include<string>

int main()
{
	std::vector<int> inputList;
	std::ifstream inputFile;
	std::string inputFileName;
	std::cout << "Please enter input file name: " << std::endl;
	std::cin >> inputFileName;
	inputFile.open(inputFileName.c_str());
	int temp = 0;
	while(inputFile.good())
	{
		inputFile >> temp;
		inputList.push_back(temp);
	}	
	inputFile.close();
	
	for(std::vector<int>::iterator i = inputList.begin(); i != inputList.end() - 1 ; ++i)
		for(std::vector<int>::iterator j = i + 1; j != inputList.end(); ++j)
		{
			if(*i + *j == 2020)
			{
				std::cout << "Values " << *i << " & " << *j << " Product: " << (*i)* (*j) << std::endl;
			}
			else if(*i + * j <= 2020)
				for(std::vector<int>::iterator k = j + 1; k != inputList.end(); ++k)
					if(*i + *j + *k == 2020)
						std::cout << "Values " << *i << " & " << *j  << " & " << *k << " Product: " << (*i)* (*j) * (*k) << std::endl;

		}
	return 0;

}
