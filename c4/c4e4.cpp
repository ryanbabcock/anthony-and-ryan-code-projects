#include <iostream>

using namespace std;

char yes_or_no;
int guess = 0;

void guesser(int max, int min, int we_are_on){
		cin >> yes_or_no;
		if (yes_or_no == 'y')
			max=we_are_on;
		else if (yes_or_no == 'n')
			min=we_are_on;
		else
			cout << "Bad Input!\n";
		cout << "Max: "<<max << " Min: " << min << " Running Guess: " << we_are_on;
		we_are_on= min + ((max-min)/2 );//add 1 to round integer division (integer division alway truncates, rememeber this)
		cout << "\nIs your number less than " << we_are_on << '?';
		if (max - min <= 1){
			guess = we_are_on;
			return;
		}
		guesser(max, min, we_are_on);
}

int main() {
	cout << "Is your number less than 50? ";
	guesser(101, 1, 50);
	cout << "\n Your number is " << guess;
	return 0;
}
