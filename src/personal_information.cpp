#include "personal_information.h"

void Personal_Information::Initialize_data(string* str){
	// string temp=str[0];
	// cout<<"errer?"<<endl;
	idx=atoi(str[0].c_str());
	// idx=99;
	// cout<<"str[1]: "<<str[1]<<endl;
	id=str[1];
	// cout<<"str[2]: "<<str[2] <<endl;
	password=str[2];
	// cout<<"3"<<endl;
	bank_account=str[3];
	// cout<<"4"<<endl;
	first_name=str[4];
	// cout<<"5"<<endl;
	last_name=str[5];
	dob=str[6];// dd/mm/yyyy
	checking_money=str[7];// dd/mm/yyyy
	saving_money=str[8];// dd/mm/yyyy
	// account_number=str[7];
}
void Personal_Information::Print_personal_information(){
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<"                     Personal Information                	   "<<endl;
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<" idx: "<<idx<<endl;
	cout<<" id: "<<id<<endl;
	cout<<" password: "<<password<<endl;
	cout<<" bank_account: "<<bank_account<<endl;
	cout<<" first_name: "<<first_name<<endl;
	cout<<" last_name: "<<last_name<<endl;
	cout<<" dob: "<<dob<<endl;
	cout<<" checking_money: $"<<checking_money<<endl;
	cout<<" saving_money: $"<<saving_money<<endl;
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl;
	// cout<<"account_number: "<<account_number<<endl;
}
string Personal_Information::Get_idx(){
	return to_string(idx);
}

string Personal_Information::Get_id(){
	return id;
}
string Personal_Information::Get_password(){
	return password;
}
string Personal_Information::Get_bank_account(){
	return bank_account;
}
string Personal_Information::Get_first_name(){
	return first_name;
}
string Personal_Information::Get_last_name(){
	return last_name;
}
string Personal_Information::Get_dob(){
	return dob;
}
string Personal_Information::Get_checking_money(){
	return checking_money;
}
string Personal_Information::Get_saving_money(){
	return saving_money;
}



void Personal_Information::Change_checking_money_from_deposit(string money){
	// cout<<"checking_money: "<<checking_money<<endl;
	int temp_value=atoi(checking_money.c_str())+atoi(money.c_str());
	// cout<<"temp_value: "<<temp_value<<endl;
	checking_money=to_string(temp_value);
	// cout<<"checking_money: "<<checking_money<<endl;
	cout<<endl;
}

void Personal_Information::Change_saving_money_from_deposit(string money){
	int temp_value=atoi(saving_money.c_str())+atoi(money.c_str());
	saving_money=to_string(temp_value);
	// cout<<"saving_money: "<<saving_money<<endl;
	cout<<endl;
}

void Personal_Information::Change_checking_money_from_withdraw(string money){
	// cout<<"checking_money: "<<checking_money<<endl;
	int temp_value=atoi(checking_money.c_str())-atoi(money.c_str());
	// cout<<"temp_value: "<<temp_value<<endl;
	checking_money=to_string(temp_value);
	// cout<<"checking_money: "<<checking_money<<endl;
	cout<<endl;
}

void Personal_Information::Change_saving_money_from_withdraw(string money){
	int temp_value=atoi(saving_money.c_str())-atoi(money.c_str());
	saving_money=to_string(temp_value);
	// cout<<"saving_money: "<<saving_money<<endl;
	cout<<endl;
}