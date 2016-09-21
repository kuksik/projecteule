#include <iostream>
// #include <string.h>
#include <vector>

using namespace std;

int main()
{
  char a[] = "82";
  char b[] = "32";
  char c[10];
  int d = 0;
  int decade = 0;
  vector<int> res;

  string sa(a);
  string sb(b);
  string sc(c);

  if ( sa.length() < sb.length() ) 
  {
    sc = sa;
    sa = sb;
    sb = sc;
  }

  int ia = atoi(sa.c_str());
  int ib = atoi(sb.c_str());

  string ona(a);
  string onb(b);
  
  for(int i=0; i<sa.length(); i++)
  {
    if(sb[sb.length()-i])
    {
      ona = sa[sa.length()-i];
      onb = sb[sb.length()-i];
      ia = atoi(ona.c_str());
      ib = atoi(onb.c_str());

      d = ia + ib + decade;
      decade = 0;
      if (d>10)
      {
        decade = (d - d%10)/10;
      }
    }
    else
    {
      d = sa[sa.length()-i] + decade;
      decade = 0;
    }
    res.push_back(d);
  }

  for (int i=res.size()-1; i>=0; i--)
  {
    cout << res[i];
  }
  cout << endl;
  return 0;
}

