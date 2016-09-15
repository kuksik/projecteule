#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int prime(int num) {
  for ( int j=2; j<=num/2; j++)
  {
      if ( num%j == 0 ) return 0;
  }
  return 1;
};

int abundantNumber (int number, std::vector<int> primes) {

  std::vector<int> dividers;
  std::vector<int> array;
  dividers.push_back(1);
  int power;
  int n = number;
  int sumOfDividers = 0;

  for ( int j=1; j<primes.size(); j++ ) {

    if ( number/2 <  primes[j] ) {
        break;
    }

    power = 0;
    while ( n%primes[j] == 0 ) {
        n /= primes[j];
        power++;
    }

    for (int k = 1; k<=power; k++) {
        array.push_back(pow( primes[j], k) );
    };

    int divNum = dividers.size();

    for ( int j=0; j<divNum; j++) {
      for ( int k=0; k<array.size(); k++) {

        int newDivider = dividers[j]*array[k];
        sumOfDividers += newDivider;

        if (newDivider == number) return 0;
        if (sumOfDividers > number) return 1;

        dividers.push_back(newDivider);
      }
    }
    array.clear();
  }

  return 0;
}

using namespace std;
int main(){
    int number;
    cout << "type number" << endl;
    cin >> number;

    clock_t startTime = clock();

    std::vector<int> primes;
    // time = +- 0.02-0.03 s number = 28123
    for (int i=1; i<=number/2+1; i++) {
        if (prime(i)) {
          primes.push_back(i);
        }
    };
    int generalSum = 0;
    std::vector<int> abundantNumbers;
    std::vector<int> compositeNumbers;

    // find all primes and all dividers for number for 1 to 28123 = 0.3s
    for (int i=1; i <= number; i++) {
      generalSum += i;
      if (abundantNumber(i, primes) ) {
        abundantNumbers.push_back(i);
      }
    }

    // int sum = 0;
    for (int i=0; i<abundantNumbers.size(); i++) {
      for ( int j=i; j < abundantNumbers.size(); j++ ) {
        int newElem = abundantNumbers[i] + abundantNumbers[j];
        if (newElem > number) break;

        // std::vector<int>::iterator it;
        //
        // it = find(compositeNumbers.begin(), compositeNumbers.end(), newElem);
        //
        // if (it == compositeNumbers.end()) {
          compositeNumbers.push_back(newElem);
          // sum += newElem;
        // }
      }
    };

    sort(compositeNumbers.begin(), compositeNumbers.end());
    int sum = compositeNumbers[0];
    for (int i =1; i<compositeNumbers.size(); i++) {
      if (compositeNumbers[i] != compositeNumbers[i-1]) {
        sum += compositeNumbers[i];
      }
      // cout << compositeNumbers[i] << endl;
    }


    cout << sum << endl;
    cout << generalSum << "   " << generalSum -  sum << endl;


    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    cout << timeInSeconds << endl;
    return 0;
}
