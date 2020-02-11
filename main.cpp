#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <complex.h>
#include <stdlib.h>

#define PI M_PI
#define DEG PI/180
#define SECOND CLOCKS_PER_SEC
#define MINUTE 60 * CLOCKS_PER_SECOND
#define HOUR 60 * SECOND
#define bool _Bool 
#define complex _Complex
#define JIM _Complex_I

double INF = INFINITY;

bool is_zero(double x){
  bool flag = fabs(x) <= 1/INF;
  return flag;
}

bool is_inf(double x) {
  bool flag = fabs(x) >= INF;
  return flag;
}

void sleep(clock_t delay){
  clock_t ti = clock_t();
  while(clock()<ti+delay){};
}

void sleep_until(clock_t mark) {
  while(clock_t()<mark){}
}

int flag_int(bool x, int place){
  int ret = (int) pow(2,place);
  ret *= (int) x ;
  return ret;
}


class Watch{
  //Watch objects keep track of time
  public:
  clock_t birth = clock(); //  time of instantiation, n clock cycles sincd program execution
  bool out = 0; //all-purpose output boolean
  int tick = 0; //all-purpose counter
  clock_t clk_last = clock();

  clock_t since(void){
    clock_t ret = clock() - clk_last;
    return ret;
  }

  void rec(void){clk_last = clock();}

  void inc(clock_t delay){
    sleep(delay);
    tick++;
  }

  bool before(clock_t cuando){
    clock_t mark = clk_last + cuando;
    return clock()<mark;
  }

  clock_t life(void) {return clock() - birth;}

  void report(void){
    printf("Watch object has following instance variables\n");
    printf("clk_last = %i \ntick = %i \nbirth = %i \nout = %x\nEND instance variable \n\n",clk_last,tick,birth,out);
  }


  
};



int main(void){
  printf("Realidad.cpp running\n\n");
  Watch wa = Watch();
  wa.report();
  int leo = (int) wa.life();
  printf("wa.life() = %i",leo);

  return 0;

}