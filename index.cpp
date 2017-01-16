#include <iostream>
#include <vector>

using namespace std;

int showString(vector<int>vec)
{
  for (int i=0; i < vec.size(); i++) {
    cout << vec[i];
  }
  cout << endl;
  return 0;
}

vector<int>nextFibonacciNumber(vector<int>a, vector<int>b)
{
  vector<int> result;
  int aLength = a.size();
  int bLength = b.size();
  int sum;
  bool increaseToOne = false;

  for (int i=1; i<=aLength; i++) {
      if (bLength-i > -1) {
        sum = a[aLength - i] + b[bLength - i];
        if (increaseToOne) {
          sum++;
          increaseToOne = false;
        };

        if (sum > 9) {
          sum = sum - 10;
          increaseToOne = true;
        }
        result.push_back(sum);
      } else {
        sum = a[aLength - i];
        if (increaseToOne) {
          sum++;
          increaseToOne = false;
        };
        result.push_back(sum);
      }
  }
  if (increaseToOne) {
    result.push_back(1);
    increaseToOne = false;
  }
  reverse(result.begin(), result.end());
  return result;
}


int main()
{
  vector<int> a;
  vector<int> b;
  vector<int> c;

  a.push_back(1);
  b.push_back(1);

  int index = 2;

  while(a.size() < 1000) {
    c = nextFibonacciNumber(a, b);
    b = a;
    a = c;
    index++;
    // showString(a);
  }
  cout << index << endl;

  return 0;
}
