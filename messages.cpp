#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream file("D:\\input.csv");
	ofstream ofile("D:\\output.csv");
	vector<string> initV;
	vector<string> mainV;
	vector<int> cnt;
	string S;  //Считываемое слово из файла
	vector<string>::iterator iter;
	int c = 1,k = 0;

	while (getline(file, S, ','))
	{
		if (S.find_first_of("NR") == string::npos)
			initV.push_back(S);  //Считывание в вектор с указанием разделителя
	}

	for (unsigned int i = 0; i<initV.size(); i++) 
		cout << initV.at(i) << endl;
	cout << endl << endl << endl;
	for (unsigned int i = 0; i <= initV.size(); i++)
	{
		if (i == 0)
		{
			mainV.push_back(initV.at(0));
			initV.erase(initV.begin());
			for (unsigned int z = 0; z < initV.size(); z++)
			{
				if (initV.at(z) == mainV.at(k))
				{
					iter = (initV.begin() + z);
					initV.erase(iter);
					z = z - 1;
					c++;
				}
			}
			cnt.push_back(c);
			continue;
		}
		i = -1;
		k++;
		c = 1;
		if (initV.empty())
			break;
	}
	ofile << "sep=," << endl;
	for (unsigned int i = 0; i < mainV.size(); i++)
	{
		ofile << mainV.at(i) << ",";
		ofile << cnt.at(i) << "," << endl;
	}
	ofile << endl;
	for (unsigned int i = 0; i<mainV.size(); i++)
		cout << mainV.at(i) << endl;
	cout << endl << endl << endl;
	for (unsigned int i = 0; i<cnt.size(); i++)
		cout << cnt.at(i) << endl; //Вывод вектора на экран
}
