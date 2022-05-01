#ifndef PERSONAL_INFORMATION
#define PERSONAL_INFORMATION
#include "main.h"

class ATM_Machine;
class Bank;

class Personal_Information{
private:
	int idx;
	string id;
	string password;
	string bank_account;
	string first_name;
	string last_name;
	string dob;// dd/mm/yyyy
	string checking_money;// dd/mm/yyyy
	string saving_money;// dd/mm/yyyy
public:
	// Personal_Information();
	// ~Personal_Information();
	void Initialize_data(string* str);
	void Print_personal_information();
	string Get_idx();
	string Get_id();
	string Get_password();
	string Get_bank_account();
	string Get_first_name();
	string Get_last_name();
	string Get_dob();
	string Get_checking_money();
	string Get_saving_money();

	void Change_checking_money_from_deposit(string money);
	void Change_saving_money_from_deposit(string money);
	void Change_checking_money_from_withdraw(string money);
	void Change_saving_money_from_withdraw(string money);
	// Personidal_Information(string i_first_name, string i_last_name, string i_dob, string i_account_number,
	// 	string i_id, string i_password){
	// 	first_name=i_first_name;
	// 	last_name=i_last_name;
	// 	dob=i_dob;
	// 	account_number=i_account_number;
	// 	id=i_id;
	// 	password=i_password;
	// }
};

#endif