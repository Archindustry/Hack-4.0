/**
 * Author: Tristan Ragland, Brent Lucke, John Hosch, and Kyle Hancock
 * Date: 2019/02/27
 *
 *
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]) {

  double startAmount = atof(argv[1]);                                           //delaring variables, defining with commandline arguments
  double monthCont = atof(argv[2]);
  double rateOfReturn = atof(argv[3]);
  double inflation = atof(argv[4]);
  int numYears = atof(argv[5]);
  double currBalance = startAmount;                                             //starts balance
  double totalNest;
  double currInterest;
  double totalInterest = 0;
  int numMonths = numYears * 12;

  double inflatAdjROR = ((1 + rateOfReturn) / (1 + inflation)) - 1;             //creating rate of return adjusted for inflation

  if ((monthCont * 12) > 18500) {
    printf ("Illegal: monthly contributions exceed $18,500 annual limit.");     //printing warning if contribution is not allowed
  }
  else{
    printf("Month Interest Balance\n");
    for(int i = 1; i <= numMonths; i++) {                                       //calculating interest and balance my month and adding to totals
      currInterest = currBalance * (inflatAdjROR / 12);
      currInterest = round(currInterest * 100) / 100;                           //rounds to nearest cent
      currBalance = currBalance + monthCont + currInterest;
      currBalance = round(currBalance * 100) / 100;
      totalInterest += currInterest;
      totalNest = currBalance;
      printf("%d $ %.2lf $ %.2lf\n", i, currInterest, currBalance);
    }
    printf("Total Interest Earned: $ %.2lf\n", totalInterest);
    printf("Total Nest Egg: $ %.2lf\n", totalNest);
  }

  return 0;
}
