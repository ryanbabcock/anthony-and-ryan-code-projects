
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int median(vector<double>temps) {
	double median = 0;
	sort(temps.begin(), temps.end());
	if (temps.size()%2==0){
		double middle = (temps.size()/2)-1;
		//subtract 1 because vectors start at 0
		median = (temps[middle] + temps[middle+1])/2;
	}
	else
		median=temps[round(temps.size()/2)];
	return median;
}
int main(){
	vector<double> temps;
	for(double temp; cin >> temp;){
		temps.push_back(temp);
		if (cin.fail()==true)
			break;
	}
	cout << median(temps);
}