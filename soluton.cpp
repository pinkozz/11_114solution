#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function prototypes
void show_menu();
int print_nums(vector<int> &vec);
int add_num(vector<int> &vec);
double disp_mean(vector<int> &vec);
int disp_small(vector<int> &vec);
int disp_large(vector<int> &vec);
void clear(vector<int> &vec);
void quit(bool &running);

int main(){
	bool running {true};
	vector <int> vec {};
	while (running == true)
	{
		
		char option {};

		show_menu();
		
		cin >> option;
		if (option == 'p' || option == 'P')
			print_nums(vec);

		else if (option == 'a' || option == 'A')
			add_num(vec);

		else if (option == 'm' || option == 'M')
			disp_mean(vec);

		else if (option == 's' || option == 'S')
			disp_small(vec);

		else if (option == 'l' || option == 'L')
			disp_large(vec);

		else if (option == 'c' || option == 'C')
			clear(vec);

		else if (option == 'q' || option == 'Q') {
			cout << "Goodbye" << endl;
		running = false;
		}

		// if user enters wrong letter or value
		else {
			cout << "Unknown selection - please try again." << endl;
		}
	}

	cout << endl;
	return 0;
}

// Functions

void show_menu() {
	cout << "\nP - Print numbers \nA - Add a number \nM - Display mean of the numbers"
		 << "\nS - Display the smallest number \nL - Display the largest number \nC - Clear list \nQ - Quit" << endl;
	cout << "\nEnter your choice: ";
}

int print_nums(vector<int> &vec) {
	// checking if vector is not empty
	if (vec.size() != 0)
	{
		cout << "\n[";
		for (auto v: vec)
		{
			cout << " " << v << " ";
		}
		cout << "]" << endl;
	}
	// if vector is empty
	else
		cout << "\n[ ] - the list is empty.\n" << endl;
	return 0;
}

int add_num(vector<int> &vec){
	// adding number to the array
	int add {};
	cout << "\nEnter a number you want to add: ";
	cin >> add;
	vec.push_back(add);
	cout << add << " added" << endl;
	return 0;
}

double disp_mean(vector<int> &vec){
	// checking if vector is not empty
	if (vec.size() != 0){
		double allnums {};
		for (int v: vec)
			allnums += v;
		double mean {};
		mean += allnums / vec.size();
		cout << "\nMean of all numbers is: " << mean << endl;
	}
	// if vector is empty
	else
		cout << "\nUnable to calculate - not enough data.\n" << endl;
	return 0;
}

int disp_small(vector<int> &vec) {
	// checking if vector is empty
	if (vec.size() != 0)
	{
		cout << "\nSmallest number: " << *min_element(vec.begin(), vec.end()) << endl;
	}
	// if vector is empty
	else
		cout << "\nUnable to calculate - not enough data.\n" << endl;
	return 0;
}

int disp_large(vector<int> &vec) {
	// checking if vector is empty
	if (vec.size() != 0)
	{
		cout << "\nLargest number: " << *max_element(vec.begin(), vec.end()) << endl;
	}
	// if vector is empty
	else
		cout << "\nUnable to calculate - not enough data.\n" << endl;
	return 0;
}

void clear(vector<int> &vec) {
	// checking if vector is empty
	if (vec.size() != 0)
	{
		vec.clear();
		cout << "\nList is cleared!" << endl;
	}
	// if vector is empty
	else
		cout << "\n[ ] - the list is empty.\n" << endl;
}

void quit(bool &running) {
	cout << "Goodbye" << endl;
	running = false;
}
