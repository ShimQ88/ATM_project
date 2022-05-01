#ifndef BANK
#define BANK
#include "main.h"
// #include "personal_information.h"
class Personal_Information;

class Bank{
private:
	Personal_Information* customer;
	// Personal_Information customer[20];
	int the_numb_of_customers;
	int the_numb_of_personal_data;
	string dataset_path="data/bank_data/dataset.data";
	string balance;
	string streamline;
	string saving;
public:
	// Bank(){}
	// ~Bank(){}
	void Initialize();
	void Deallocation();
	void Save_updated_information();
	int Get_the_numb_of_class(string path);
	int Get_the_numb_of_personal_data(string path);
	Personal_Information Get_customer_info(int index);
	void Load_personal_information_from_dataset(string path, int customer_numb, int data_numb, Personal_Information* person_info);
	Personal_Information* Sending_personal_info_to_atm();
	int Get_the_numb_of_customers();
	void Display_customer_information();
	void Reset_targeted_customer_info(Personal_Information person_info, int customer_index);

};


#endif