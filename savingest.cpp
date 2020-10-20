#include <iostream>    	/*cin, cout*/
#include <string>		/*char*/
#include <iomanip>		/*setw, setfill*/
#include <exception>    /*exception, terminate*/
#include <ctype.h>      /*isDigit*/

#include "SavingsEst.h"

using namespace std;

//constructor to set values for savingsEst object
SavingsEst::SavingsEst(double t_initInvestAmt, double t_mnthDepositAmt, double t_annualInterestRate, int t_numYears) {
	this->m_investAmt = t_initInvestAmt;														//to hold initial investment
    this->m_depositAmt = t_mnthDepositAmt;														//to hold monthly deposit
    this->m_interestRate = t_annualInterestRate;												//to hold annual interest rate
    this->m_years = t_numYears;																	//to hold years in term
}

//~SavingsEst destructor
SavingsEst::~SavingsEst() {
}

//display user input using pass by reference parameters
void SavingsEst::displayUserInput(double &t_initInvestAmt, double &t_mnthDepositAmt,
		double &t_annualInterestRate, int &t_numYears) {

//=========================OUTPUT DATA INPUT SCREEN===================================
	//Display initial data input screen header
	cout << "\n*****WELCOME TO SAVINGS ESTIMATE APP*****" << endl <<endl;
	cout << "****************************************" << endl;
	cout << "************** Data Input **************" << endl;
	cout << "Initial Investment Amount:	$" << endl;
	cout << "Monthly Deposit:	$" << endl;
	cout << "Annual Interest:	%" << endl;
	cout << "Number of Years:	" << endl << endl;

	char i;  																			//create char to capture input
	cout << "Press 'V' to input your values...";										//prompt for user input
	cin >> i;																			//assign i with value for loop

	//Create loop to capture correct input of 'v' or 'V'	     						NOTE:tried cin.get() but it was causing unpredictable results
	while (i != 'v' && i != 'V') {
		cout << "Press 'V' to input your values..." << endl;							//if input is V or v continue to Your Data Input
		cin >> i;																		//if input is not V or v capture new input
	}

//=========================OUTPUT YOUR INPUT SCREEN===================================
		//Prompt for and display user input values and assign to parameters
		cout << "Please Enter Your Values Below" << endl;							    //prompt for user input values
		cout << "****************************************" << endl;
		cout << "************** Your Input **************" << endl;
		try {                                                                           //establish exception handler for invalid input
																						//which will automatically handle letters
																						//and characters. Negative numbers are
																						//handled below

			cout << "Initial Investment Amount:	$";										//prompt for initial investment
			cin >> t_initInvestAmt;														//collect and assign initial investment parameter

			cout << "Monthly Deposit:	$";												//prompt for monthly deposit
			cin >> t_mnthDepositAmt;													//collect and assign monthly deposit parameter

			cout << "Annual Interest Rate:	%";											//prompt for annual interest rate
			cin >> t_annualInterestRate;												//collect and assign annual interest rate parameter

			cout << "Number of Years:	";												//prompt for number of years in term
			cin >> t_numYears;															//collect and assign number of years parameter

          	if ((t_initInvestAmt <= 0) || (t_mnthDepositAmt <= 0) || (t_annualInterestRate <= 0) || (t_numYears <= 0)) {
				throw 0;                                                                //handle negative numbers by throwing control to catch block
        }
    }
		catch(...) {																	//if invalid input control thrown here
			cout << "\nInput Value Not Allowed." << endl;                           	//message to user to indicate input errors
			cout << "Exiting Program" << endl;											//message to indicate end of program
			terminate();																//end the program
		}

    char j;  																			//create char to capture input
    cout << "Press 'C' to continue to estimate..."  <<endl;								//prompt for user input to continue to estimate
    cin >> j;																			//assign j with value for loop

    //Create loop to capture correct input of 'c' or 'C'								NOTE:tried cin.get() but it was causing unpredictable results
    while (j != 'c' && j != 'C') {
        cout << "Press 'C' to continue to estimate..." << endl;							//if input is C or c continue to estimate display
        cin >> j;																		//if input is not C or c capture new input
    }
}

//=============output report with no additional monthly deposits========================
void SavingsEst::outputNoDepositRpt(){
    double mnthEarnedInt1 = 0.0, totEarnedInt1 = 0.0;									//initialize local calculation variables

    //print header for no deposit balance sheet
	cout << "====================================================================" << endl;
    cout << "     BALANCE AND INTEREST WITHOUT ADDITIONAL MONTHLY DEPOSITS  " << endl;
	cout << "====================================================================" << endl;
	cout << setw(8) << "Year"															//output Year setting field width to 8 bytes
		 << setw(26) << "Year End Balance"  											//output Year End Balance setting field width to 26 bytes
		 << setw(34) << "Year End Earned Interest" << endl;								//output Year End Earned Interest setting field width to 34 bytes
	cout << "--------------------------------------------------------------------"  << endl;

	double balanceAmt1 = this->m_investAmt;												//declare balanceAmt parameter initializing with deposit amount


	//establish loop over number of years to iterate through each year and display corresponding calculations
	//ASSUMING NO ADDITIONAL DEPOSITS MADE DURING FULL TERM AFTER FIRST INVESTMENT
	for (int i = 1; i <= this->m_years ; ++i) {

		//establish loop over 12 months to add and compound interest
		for (int j = 1; j <= 12; ++j) {

			mnthEarnedInt1 = (balanceAmt1 * (this->m_interestRate/100)/12); 			//calculate interest earned by month
			balanceAmt1 += mnthEarnedInt1;												//add interest to balance
			totEarnedInt1 += mnthEarnedInt1;											//add interest to total interest

//==========BELOW TESTING CODE WILL OUTPUT MONTHLY ESTIMATE AMOUNTS TO TEST THAT LOOP IS FUNCTION CORRECTLY=============

		/*--------TESTING OUTPUT - FIXME PRIOR TO PUBLISH----------------------------
		|	cout << "TESTING OUTPUT - FIXME PRIOR TO PUBLISH" << endl;				|			//TEST code to check monthly output
		|	cout << setw(8) << setprecision(2) << fixed << i						|			//TEST output year number
		|		 << setw(16) << "$" << setw(10) << balanceAmt1						|			//TEST output year end balance ($ aligned up to one million)
		|		 << setw(24) << "$" << setw(10) << totEarnedInt1 << endl;			|			//TEST output total interest earned ($ aligned up to one million)
		----------END TESTING OUTPUT-----------------------------------------------*/
		}


		cout << setw(8) << setprecision(2) << fixed << i										//output year number setting field width to 8 bytes
			 << setw(16) << "$" << setw(10) << balanceAmt1										//output year end balance setting field width to 26 bytes
			 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	//($ aligned up to one million)
			 << setw(24) << "$" << setw(10) << totEarnedInt1 << endl;							//output total interest earned setting field width to 34 bytes
																								//($ aligned up to one million)
	}
}

//============output report with additional monthly deposits====================================
void SavingsEst::outputMnthDepositRpt(){
    double earnedInt2 = 0.0, totEarnedInt2 = 0.0;												//initialize local calculation variables

	//print header for balance sheet with deposits
	cout << "====================================================================" << endl;
	cout << "      BALANCE AND INTEREST WITH ADDITIONAL MONTHLY DEPOSITS    " << endl;
	cout << "====================================================================" << endl;
	cout << setw(8) << "Year"																	//output Year setting to 8 bytes
		 << setw(26) << "Year End Balance"  													//output Year End Balance setting to 26 bytes
		 << setw(34) << "Year End Earned Interest" << endl;										//output Year End Earned Interest setting to 34 bytes
	cout << "--------------------------------------------------------------------"  << endl;

	double balanceAmt2 = this->m_investAmt;														//declare balanceAmt parameter initializing with deposit amount

	//establish loop over years to iterate through each year and display corresponding calculations
	for (int i = 1; i <= this->m_years ; ++i) {

		//establish loop over 12 months to add and compound interest
		//ASSUMING FIRST DEPOSIT + 12 MONTHLY DEPOSITS EACH YEAR AFTER FIRST INVESTMENT
		for (int j = 1; j <= 12; ++j) {
			earnedInt2 = ((balanceAmt2 + this->m_depositAmt) * (this->m_interestRate/100)/12); 	//calculate interest earned by month
			balanceAmt2 =(balanceAmt2 + this->m_depositAmt + earnedInt2);						//add deposit + interest to balance
			totEarnedInt2 += earnedInt2;														//add interest to total interest


//==========BELOW TESTING CODE WILL OUTPUT MONTHLY ESTIMATE AMOUNTS TO TEST THAT LOOP IS FUNCTION CORRECTLY=============

		/*--------TESTING OUTPUT - FIXME PRIOR TO PUBLISH----------------------------
		|	cout << "TESTING OUTPUT - FIXME PRIOR TO PUBLISH" << endl;				|			//TEST code to check monthly output
		|	cout << setw(8) << setprecision(2) << fixed << i						|			//TEST output year number
		|		 << setw(16) << "$" << setw(10) << balanceAmt2						|			//TEST output year end balance ($ aligned up to one million)
		|		 << setw(24) << "$" << setw(10) << totEarnedInt2 << endl;			|			//TEST output total interest earned ($ aligned up to one million)
		------------END TESTING OUTPUT---------------------------------------------*/

		}
		cout << setw(8) << setprecision(2) << fixed << i										//output year number setting field width to 8 bytes
			 << setw(16) << "$" << setw(10) << balanceAmt2										//output year end balance setting field width to 26 bytes
			 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	//($ aligned up to a million)
			 << setw(24) << "$" << setw(10) << totEarnedInt2 << endl;							//output total interest earned setting field width to 34 bytes
																								//($ aligned up to a million)
	}
}
//=============function to ask if user wants to input another savings estimate. Returns true or false to main which
//=============in turn will clear the screen and loop back to another estimate or exit the program.
bool SavingsEst::anotherEstimate() {
	char more;                                                                                  //parameter to hold user's choice
  	cout << "Would you like another savings estimate (Y for more)?" << endl;                    //allow user to choose to input another estimate
	cin >> more;                                                                                //collect and assign user's choice

		if (more != 'Y' && more != 'y') {                                                       //check if user wants to continue or end
			cout << "Exiting Program";                                                          //if ending, tell user program is ending
			return false;                                                                       //end program
		}
        else {
        	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";     //if continuing clear screen
        	return true;																		 //return true to main to loop through again
        }
	}




