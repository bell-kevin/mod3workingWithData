// mod3workingWithData.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
void printVector(T begin, T end)
{
	while (begin != end)
	{
		cout << *begin << " ";
		begin++;
	}
	cout << endl;
}

template <typename T>
void calculateAverage(T begin, T end)
{
	double sum = 0;
	int count = 0;
	while (begin != end)
	{
		sum += *begin;
		count++;
		begin++;
	}
	cout << "Average: " << sum / count << endl;
}


class Input {
private:
	int input = 0;
	double doubleInput = 0.0;
public:
	//exception classes
	class TooLow {};
	class TooHigh {};
	class TooDoubleLow {};
	class TooDoubleHigh {};
	
	Input(){
		input = 0;
	}
	
	bool getInput(){
		int temp = 0;
		cin >> temp;
		if (temp < 20) {
			throw TooLow();
		}
		else if (temp > 50) {
			throw TooHigh();
		}
		else {
			input = temp;
			return true;
		}
	}

	bool getDoubleInput(){
		double temp = 0.0;
	
		cin >> temp;
		if (temp < 60){
			throw TooDoubleLow();
		}
		else if (temp > 100) {
			throw TooDoubleHigh();
		}
		else {
			doubleInput = temp;
			return true;
		}
	}
	
	//return double input
	double getDoubleInputValue() {
		return doubleInput;
	}
	
	//return input
	int getInputValue(){
		return input;
	}
};

int main() {
	Input input;
	bool inputValid = false;
	//create vector
	vector<int> intVector;
	cout << "Module 3 Competency Project by Kevin Bell\n\n";
	//loop 10 times
	for (int i = 0; i < 10; i++) {
		//get input
		cout << "Enter an integer between 20 and 50: ";
		try {
			inputValid = input.getInput();
			intVector.push_back(input.getInputValue());
		}
		catch (Input::TooLow) {
			cout << "Input is too low.\n\n";
			i--;
		}
		catch (Input::TooHigh) {
			cout << "Input is too high.\n\n";
			i--;
		}
	}
	//print vector
	cout << "Vector contains:\n";
	printVector(intVector.begin(), intVector.end());
	cout << endl;
	//smallest value
	cout << "Smallest value in vector is: " << *min_element(intVector.begin(), intVector.end()) << endl;
	//largest value
	cout << "Largest value in vector is: " << *max_element(intVector.begin(), intVector.end()) << endl;
	//sort vector
	sort(intVector.begin(), intVector.end());
	//print sorted vector
	cout << "Sorted vector contains:\n";
	printVector(intVector.begin(), intVector.end());
	//sum of vector
	int sum = 0;
	for (int i = 0; i < intVector.size(); i++) {
		sum += intVector[i];
	}
	//print average of vector
	cout << "Average of vector is: " << sum / intVector.size() << endl;
	cout << endl;
	//double
	//clear vector
	vector<double> doubleVector;
	//get double input in a loop 10 times
	for (int i = 0; i < 10; i++) {

		cout << "Enter a double between 60 and 100: ";
		try {
			inputValid = input.getDoubleInput();
			doubleVector.push_back(input.getDoubleInputValue());
		}
		catch (Input::TooDoubleLow) {
			cout << "Input is too low.\n\n";
			i--;
		}
		catch (Input::TooDoubleHigh) {
			cout << "Input is too high.\n\n";
			i--;
		}

		
	}
	//print vector
	cout << "Vector contains:\n";
	printVector(doubleVector.begin(), doubleVector.end());
	cout << endl;
	//smallest value
	cout << "Smallest value in vector is: " << *min_element(doubleVector.begin(), doubleVector.end()) << endl;
	//largest value
	cout << "Largest value in vector is: " << *max_element(doubleVector.begin(), doubleVector.end()) << endl;
	//sort vector
	sort(doubleVector.begin(), doubleVector.end());
	//print sorted vector
	cout << "Sorted vector contains:\n";
	printVector(doubleVector.begin(), doubleVector.end());
	//sum of vector
	double doubleSum = 0.0;
	for (int i = 0; i < doubleVector.size(); i++) {
		doubleSum += doubleVector[i];
	}
	//print average of vector
	cout << "Average of vector is: " << doubleSum / doubleVector.size() << endl;
	system("pause");
	return 0;
} // end main function
