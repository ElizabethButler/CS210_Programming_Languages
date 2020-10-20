
#include <iostream>    	/*cin, cout*/
#include <string>		/*char*/
#include <iomanip>		/*setw, setfill*/

#include "SavingsEst.h"

using namespace std;

int main() {
	//Declare required variables
	double t_initInvestAmt;           //to hold initial investment
	double t_mnthDepositAmt;          //to hold monthly deposit
	double t_annualInterestRate;      //to hold annual interest rate
	int t_numYears;                   //to hold term in years
  	bool another = true;			  //to hold user's decision to create another estimate


	do {										//loop to allow user to repeat functions for estimates

		//call function to display input required and accept and assign user input parameters
		SavingsEst::displayUserInput(t_initInvestAmt, t_mnthDepositAmt, t_annualInterestRate, t_numYears);

		//declare yourSavingsEst object
		SavingsEst yourSavingsEst(t_initInvestAmt, t_mnthDepositAmt, t_annualInterestRate, t_numYears);


		//output savings estimate with initial deposit only
		yourSavingsEst.outputNoDepositRpt();

		//output savings estimate including monthly deposits
		yourSavingsEst.outputMnthDepositRpt();

		//as user if they want another savings estimate
      	another = yourSavingsEst.anotherEstimate();

    } while(another);
}

