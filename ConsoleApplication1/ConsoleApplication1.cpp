#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Numbers 
{
	vector <int> numbers;
public:
	Numbers() 
	{
	}

	int size() 
	{
		return numbers.size();
	}

	void push(int n) 
	{
		numbers.push_back(n);
	}

	void remove() 
	{
		numbers.pop_back();
	}

	void clear() 
	{
		numbers.clear();
	}


	void INBD() 
	{
		ofstream out;      
		out.open("numbers.txt");  
		out.clear();
		if (out.is_open())
		{
			for (size_t i = 0; i < numbers.size(); i++)
			{
				out << to_string(numbers[i]) << " ";
			}
		}
		out.close();
	}

	void OUTBD() 
	{
		string line;
		ifstream in("numbers.txt"); 
		if (in.is_open())
		{
			while (getline(in, line))
			{
				cout << line << std::endl;
			}
		}
		in.close();   

		numbers.clear();

		size_t last_pos = 0;
		size_t pos = 0;
		while (line.find(' ', pos + 1) != line.npos)
		{
			pos = line.find(' ', pos + 1);
			numbers.push_back(stoi(line.substr(last_pos, pos - last_pos)));
			last_pos = pos + 1;
		}
	}

	void ranodom(int size, int a, int b) 
	{
		random_device random_device;
		mt19937 generator(random_device());
		uniform_int_distribution<> distribution(a, b);
		for (size_t i = 0; i < size; i++)
		{
			numbers.push_back(distribution(generator));
		}
	}

	int& operator[] (const int index) 
	{
		return numbers.at(index);
	}

};


class Iterator 
{
	Numbers buff;
public:
	Iterator(Numbers n) : buff(n) {};

	void sort() 
	{
		cout << "Before\n";
		for (size_t i = 0; i < buff.size(); i++)
		{
			cout << buff[i] << " ";
		}
		Numbers result;
		for (size_t i = 0; i < buff.size(); i++)
		{
			if (buff[i] % 2 != 0) result.push(buff[i]);
		}
		cout << "\nResult:\n";
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
	}
};

int main()
{
	Numbers numb;
	cout << "Select the array fill type:\n1 - From file(if file is empty then array will be empty)\n2 - Random\n3 - Input";
	int n;
	cout << "\nWhat oyu choose -> ";
	cin >> n;
	if (n == 1) {
		numb.OUTBD();
		Iterator it(numb);
		it.sort();
	}
	else if (n == 2)
	{
		cout << "\nEnter the number of numbers in the range from and to";
		int size, a, b;
		cin >> size >> a >> b;
		numb.ranodom(size, a, b);
		numb.INBD();
		Iterator it(numb);
		it.sort();
	}
	else if (n == 3)
	{
		cout << "\nEnter the number of numbers -> ";
		int size;
		cin >> size;
		for (size_t i = 0; i < size; i++)
		{
			int buff;
			cout << "\nInput number -> ";
			cin >> buff;
			numb.push(buff);
		}
		numb.INBD();
		Iterator it(numb);
		it.sort();
	}
	else cout << "\nWrong choose";

}