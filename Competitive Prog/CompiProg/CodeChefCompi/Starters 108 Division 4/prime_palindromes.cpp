#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n) {
   if (n <= 1)
       return false;
   if (n == 2)
       return true;
   if (n % 2 == 0)
       return false;
   for (int i = 3; i * i <= n; i += 2)
       if (n % i == 0)
           return false;
   return true;
}

bool is_palindrome(int n) {
   int r, sum = 0, temp;   
   temp = n;   
   while (n > 0)   
   {   
       r = n % 10;   
       sum = (sum * 10) + r;   
       n = n / 10;   
   }   
   return (temp == sum);
}

std::vector<int> palindromic_primes(int N) {
   std::vector<int> primes;
   int i = 2;
   while (primes.size() < N) {
       if (is_prime(i) && is_palindrome(i))
           primes.push_back(i);
       i++;
   }
   return primes;
}

std::pair<int, int> count_digits(std::vector<int> primes) {
   int even_digits = 0;
   int odd_digits = 0;
   for (int prime : primes) {
       int num_digits = log10(prime) + 1;
       if (num_digits % 2 == 0)
           even_digits++;
       else
           odd_digits++;
   }
   return std::make_pair(even_digits, odd_digits);
}


int main() {
   int m; 
   std::cin>>m;
   while(m--){
       int N;
       std::cin>>N;
       std::vector<int> primes = palindromic_primes(N);
       std::pair<int, int> counts = count_digits(primes);
       std::cout << counts.first << " " << counts.second << std::endl; 
   }
   
   return 0;
}
