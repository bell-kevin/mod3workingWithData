// mod3workingWithData.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
void printVector(const vector<T>& v, ostream& os)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, "  "));
	os << endl;
}


class Input {
private:
	int input = 0;
	double doubleInput = 0;
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
		double temp = 0;
		cin >> temp;
		if (temp < 60){
			throw TooDoubleLow();
		}
		else if (temp > 100) {
			throw TooDoubleHigh();
		}
		else {
			input = temp;
			return true;
		}
	}
	
	//return double input
	double getDoubleInputValue() {
		return input;
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
	vector<int> v;
	cout << "Module 3 Competency Project by Kevin Bell\n\n";
	//loop 10 times
	for (int i = 0; i < 10; i++) {
		//get input
		cout << "Enter an integer between 20 and 50: ";
		try {
			inputValid = input.getInput();
		}
		catch (Input::TooLow) {
			cout << "Input is too low.\n\n";
			i--;
		}
		catch (Input::TooHigh) {
			cout << "Input is too high.\n\n";
			i--;
		}
		//if input is valid, add to vector
		if (inputValid) {
			v.push_back(input.getInputValue());
		}
	}
	//print vector
	cout << "Vector contains:\n";
	printVector(v, cout);
	cout << endl;
	//smallest value
	cout << "Smallest one is " << *min_element(v.begin(), v.end()) << endl;
	//largest value
	cout << "Largest one is " << *max_element(v.begin(), v.end()) << endl;
	//sort vector
	sort(v.begin(), v.end());
	//print sorted vector
	cout << "Sorted vector contains:\n";
	printVector(v, cout);
	//sum of vector
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	//print average of vector
	cout << "Average of this list is " << sum / v.size() << endl;
	cout << endl;


	
	cout << "DOUBLE version\n";
	Input doubleInput;
	bool inputDoubleValid = false;
	//create vector
	vector<double> dv;
	//loop 10 times
	for (int i = 0; i < 10; i++) {
		//get input
		cout << "Enter a double between 60 and 100: ";
		try {
			inputDoubleValid = doubleInput.getDoubleInput();
		}
		catch (Input::TooDoubleLow) {
			cout << "Input is too low.\n\n";
			i--;
		}
		catch (Input::TooDoubleHigh) {
			cout << "Input is too high.\n\n";
			i--;
		}
		//if input is valid, add to vector
		if (inputDoubleValid) {
			dv.push_back(doubleInput.getDoubleInputValue());
		}
	}
	//print vector
	cout << "Vector contains:\n";
	printVector(dv, cout);
	cout << endl;
	//smallest value
	cout << "Smallest one is " << *min_element(dv.begin(), dv.end()) << endl;
	//largest value
	cout << "Largest one is " << *max_element(dv.begin(), dv.end()) << endl;
	//sort vector
	sort(dv.begin(), dv.end());
	//print sorted vector
	cout << "Sorted vector contains:\n";
	printVector(dv, cout);
	//sum of vector
	double dsum = 0;
	for (int i = 0; i < dv.size(); i++) {
		dsum += dv[i];
	}
	//print average of vector
	cout << "Average of this list is " << dsum / dv.size() << endl;
	system("pause");
	return 0;
} // end main function
