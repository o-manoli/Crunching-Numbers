
#include<iostream>
#include<vector>
#include<string>

template<typename T>
std::vector<T> sieve(T Up2)
{
   if (Up2 < 2) return std::vector<T> ();

   std::vector<bool> N ((Up2+1)>>1);	// all them odd numbers

   T p = 3, pp;

   auto index = N.begin()+1;

   while ((pp = p*p) <= Up2){

      for (auto i = N.begin() + (pp>>1); i < N.end(); i += p)   *i = true;

      do {p += 2;} while(*++index);
   }

   std::vector<T> Primes;   Primes.reserve(1 + (N.capacity()>>1));   p = 1;

   for (const auto &n : N){
      if (!n) Primes.push_back(p);
      p += 2;
   }

   Primes[0] = 2;	// correction

   return Primes;
}

template<typename T>
void print(std::vector<T> list)
{
   for (auto const &e : list)
      std::cout << e << '\n';
}

int main(int argc, char* argv[])
{
   int Up2 = 7919;

   if (argc > 1)
      Up2 = std::stoi(argv[1]);

   std::vector<int> Primes = sieve(Up2);  // could be longer

   print(Primes);

   return 0;
}


