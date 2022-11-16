// mod3workingWithData.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//template function
template <typename T>
void printVector(const vector<T>& v, ostream& os)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
	os << endl;
}


int main()
{
    cout << "Module 3 Competency Project by Kevin Bell\n\n";
	cout << "Enter an integer between 20 and 50: ";
	int num;
	cin >> num;
	// try catch block to catch invalid input
	try
	{
		if (num < 20 || num > 50)
		{
			throw num;
		}
	}
	catch (int num)
	{
		cout << "Invalid input. Please enter an integer between 20 and 50: ";
		cin >> num;
	}
	// create vector of size num
	vector<int> v(num);
	// fill vector with random numbers
	for (int i = 0; i < num; i++)
	{
		v[i] = rand() % 100;
	}
	// print vector
	cout << "Vector: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//smallest number
	cout << "Smallest number: " << *min_element(v.begin(), v.end()) << endl;
	//largest number
	cout << "Largest number: " << *max_element(v.begin(), v.end()) << endl;
	// sort vector
	sort(v.begin(), v.end());
	// print sorted vector
	cout << "Sorted vector: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	// print sum of vector
	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += v[i];
	}
	// print average of vector
	cout << "Average of vector: " << sum / num << endl;
	
}