#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

int prime(int num) {
  for ( int j=2; j<=num/2; j++)
  {
      if ( num%j == 0 ) return 0;
  }
  return 1;
};

std::vector<int> findDividers (int number, std::vector<int> primes) {

  std::vector<int> powers;
  std::vector<int> dividers;
  dividers.push_back(1);
  int power;
  int n = number;

  for ( int j=1; j<primes.size(); j++ ) {
    if ( number/2 <  primes[j] ) {
        break;
    }

    power = 0;
    while ( n%primes[j] == 0 ) {
        n /= primes[j];
        power++;
    }

    powers.push_back(power);
  }

  for (int i=0; i<powers.size(); i++ ) {
    std::vector<int> array;
    for (int k = 1; k<=powers[i]; k++) {
        array.push_back(pow( primes[i+1], k) );
    };

    int divNum = dividers.size();

    for ( int j=0; j<divNum; j++) {
      for ( int k=0; k<array.size(); k++) {
        if (dividers[j]*array[k] == number) break;
        dividers.push_back(dividers[j]*array[k]);
      }
    }
  }

  return dividers;
}

int abundantNumber(int number, std::vector<int> primes) {
  std::vector<int> dividers = findDividers(number, primes);

  int sum = 0;
  for ( int j=0; j<dividers.size(); j++) {
      sum += dividers[j];
  }
  if ( sum > number ) return 1;
  return 0;
}

using namespace std;
int main(){
    int number;
    cout << "type number" << endl;
    cin >> number;

    std::vector<int> primes;

    for (int i=1; i<=number/2+1; i++) {
        if (prime(i)) {
          primes.push_back(i);
        }
    };

    int generalSum = 0;
    std::vector<int> abundantNumbers;

    for ( int i=1; i<=number; i++ ) {
        generalSum += i;
        if ( abundantNumber(i, primes) ) {
          abundantNumbers.push_back(i);
        }
    }

    std::vector<int> compositeNumbers;

    for (int i=0; i<abundantNumbers.size(); i++) {
      for ( int j=i; j < abundantNumbers.size(); j++ ) {
        int newElem = abundantNumbers[i] + abundantNumbers[j];
        if (newElem > number) break;

        std::vector<int>::iterator it;

        it = find (compositeNumbers.begin(), compositeNumbers.end(), newElem);

        if (it == compositeNumbers.end()) {
          compositeNumbers.push_back(newElem);
        }
      }
    };


    int sum = 0;
    for ( int i=0; i < compositeNumbers.size(); i++) {
      sum += compositeNumbers[i];
    }

    cout << sum << endl;
    cout << generalSum << "   " << generalSum -  sum << endl;

    return 0;
}
