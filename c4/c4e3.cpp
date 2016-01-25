#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<double> dist;
	double temp;
	while(cin>>temp){
		dist.push_back(temp);
	}
	double sum;
	int i = 0;
	for(;i < dist.size(); ++i){
		sum += dist[i];
	}
	cout << "The sum of the numbers is " << sum << ",\n";
	sort(dist.begin(), dist.end());
	cout << "The shortest distance was " << dist[0] 
	<< ",\nand the longest distance was " << dist[i-1]
	<< ",\nand the mean distance was " << (sum/ (i-1) ) << '.';
	return 0;
}