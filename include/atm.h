#ifndef ATM
#define ATM
#include "main.h"

class Personal_Information;

class ATM_Machine{
private:
	int current_note_value=0;
	int idx_of_customer;
public:
	ATM_Machine(){Load_ATM_money();}
	~ATM_Machine(){}
	int Log_in(Personal_Information* person_info, int the_numb_of_customers);
	int ATM_info(); //simple information
	void Load_ATM_money();
	void Update_ATM_money();

	int Get_current_user_idx();
	Personal_Information Withdraw(Personal_Information log_in_customer);
	Personal_Information Deposit(Personal_Information log_in_customer);
	void Balance(Personal_Information log_in_customer);
};

#endif