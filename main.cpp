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
    delete[] p;
  }
  char *get() { return p; }
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
  date sdate("04/06/21");
  date xdate("00/00/00");

  xdate = sdate;
  show(sdate);
  show(xdate);

  cout << sdate.get() << " " << xdate.get() << endl;

  return 0;
}