#ifndef SAVINGSEST_H_
#define SAVINGSEST_H_



class SavingsEst {
	public:
	    SavingsEst();                       						//default SavingsEst object declaration
		~SavingsEst();                      						//SavingsEst object destructor

		SavingsEst(double t_initInvestAmt, double t_mnthDepositAmt,
				double t_annualInterestRate, int t_numYears);		//SavingsEst object declaration

		static void displayUserInput(double &t_initInvestAmt, double &t_mnthDepositAmt,
				double &t_annualInterestRate, int &t_numYears);		//user input display function with pass by reference parameters


		void displayUserInput(); 									//user input display function with pass by reference parameters
		void outputNoDepositRpt();                  				//SavingsEst display function with no additional deposits declaration
		void outputMnthDepositRpt();                				//SavingsEst display function with additional deposits declaration
		bool anotherEstimate();

	private:
		double m_investAmt;                         				//private member variable to hold initial investment
		double m_depositAmt;                        				//private member variable to hold monthly deposit amount
		double m_interestRate;                      				//private member variable to hold annual interest rate
		int m_years;                                				//private member variable to hold term in years
};



#endif /* SAVINGSEST_H_ */
