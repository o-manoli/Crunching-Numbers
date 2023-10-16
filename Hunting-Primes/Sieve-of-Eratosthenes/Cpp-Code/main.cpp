#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void print(vector<T>& Array){
	for (const auto &a : Array)
		cout << a << "\n";
}

vector<int> sieve(const int Up2){

	if (Up2 < 2)
		return vector<int> (0);

	vector<int> N ((Up2+1)>>1);

	int index = -1;

	for (auto &e : N)
		e = index += 2;
	N[0] = 2;

	int p = 3, p2, pp;	index = 1;

	while ((pp = p*p) <= Up2){
		// Eliminate
		p2 = p<<1;

		for (int i = pp; i <= Up2; i += p2)
			N[i>>1] = 0;

		while (!N[++index]);
		p = N[index];
	}

	index = 0;

	for (const auto &e : N)
		if (e)	N[index++] = e;

	N.resize(index);

	return N;
}


int main(int argc,const char *argv[]){

	int S = 7919;	// the 1000th prime;
	bool write = false;

	if (argc > 1)
	{
		string W ("-w");

	for (int i = 1; i < argc; i++)
		if (W.compare(argv[i]) == 0)		write = true;
		else {
			try
			{
				S = stoi(argv[i]);
			}
			catch(const std::exception& e)
			{
				cout
				<< "\n\n\tInvalid Command line Arguments."
				<< "\n\tPass in a number please!\n\n"
				<< endl;
				exit(1);
			}
		}
	}


	if (!write)
		cout << "\n\tLooking for Primse Up to:\t" << S << "\n" << endl;

	auto Array = sieve(S);

	if (write)
		print(Array);

	if (!write)
		cout << "\n\tPrimes Found: " << Array.size() << "\n\n";

	return 0;
}

