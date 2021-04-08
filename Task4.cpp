// 2018556502 Muhammed Ali ARICI
// 2019556461 Mahmut Can ÇINGI
// 2020556061 Emre ULUSOY

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

class date {
  char *p;
  public:
  date(char *s);
  ~date() {
    cout << "Destructing" << endl;
  }
  char *get() { return p; }
  friend void cleaner(date obj) { delete  obj.p; } // Delete [] p function.
};

date::date(char *s) {
  int l;
  l = strlen(s) + 1;
  p = new char[l];
  if (!p) {
    cout << "Allocation error" << endl;
    exit(1);
  }
  strcpy(p, s);
}

void show(date x) {
  char *s;
  s = x.get();
  cout << s << endl;
}

int main() {
  char sd[10]= "04/06/21";
  char xd[10]= "00/00/00";
  date sdate(sd); 
  date xdate(xd); 

  show(sdate);
  show(xdate);
  xdate = sdate;
  cout << sdate.get() << " " << xdate.get() << endl;
  
  cleaner(xdate); // Delete [] p

  return 0;
}