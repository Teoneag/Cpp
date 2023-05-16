#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;

  const unsigned int NUM_SECONDS_IN_DAY = 3600 * 24*4;
  time (&rawtime);
  rawtime -= NUM_SECONDS_IN_DAY;
  timeinfo = localtime (&rawtime);
  cout<<"Today's local time and date: %s"<< asctime(timeinfo);

  return 0;
}