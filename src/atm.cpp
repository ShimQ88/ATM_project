#include "atm.h"

void ATM_Machine::Load_ATM_money(){
	ifstream file("data/atm_data/atm_money.data");
	if ( file.is_open() ){
		string mystring;
		getline(file, mystring);
		current_note_value=atoi(mystring.c_str());
		file.close();
	}else{
		cout<<"nothing"<<endl;
	}
}
void ATM_Machine::Update_ATM_money(){
	fstream file("data/atm_data/atm_money.data");
	if ( file.is_open() ){
  		file << to_string(current_note_value);
		file.close();
	}
}

// string ATM_Machine::Validation(Personal_Information* person_info, int the_numb_of_customers){
// 	for(int i=0;i<the_numb_of_customers;i++){
// 			cout<<"Id: "<<person_info[i].Get_id()<<endl;
// 			if()
// 		}
// }
int ATM_Machine::Log_in(Personal_Information* person_info, int the_numb_of_customers){

	string command;
	cout<<"Please, Insert Card and Type Your ID"<<endl;
	cout<<"ID:";
	cin >> command;
	bool is_password_correct=false;
	bool is_found_the_id=false;
	int log_in_fail=0;
	int password_fail=0;

	while(1){
		for(int i=0;i<the_numb_of_customers;i++){
			// cout<<"Id: "<<person_info[i].Get_id()<<endl;
			if(command==person_info[i].Get_id()){
				cout<<"Welcome! "<<person_info[i].Get_first_name()<<", "<<person_info[i].Get_last_name()<<endl;
				idx_of_customer=i;
				while(1){
					cout<<"Password:";
					cin >> command;	
					if(command==person_info[i].Get_password()){
						is_password_correct=true;
						break;
					}else{
						if(password_fail<3){
							cout<<"Wrong Password, please type again"<<endl;
						}
						password_fail++;
					}

					if(password_fail>=3){
						cout<<"you type the wrong password three time. Please take your card, Thanks you"<<endl;
						return -1;
					}

				}
				if(is_password_correct==true){
					break;
				}
			}
		}
		if(is_password_correct==true){
			break;
		}
		log_in_fail++;
		if(log_in_fail>=3){
			cout<<"you type the wrong ID three time take your card, Thanks you"<<endl;
			return -2;
		}
		cout<<"We could not find your ID from our system, Please write your ID again"<<endl;
		cout<<"ID:";
		cin >> command;
	}

	

//     cout<<"Currently $"<<current_note_value<<" in this ATM"<<endl;
//     cout<<endl;
//     cout<<"choose command:";
//     cin >> command;
//     cout<<"you choose the command of ["<<command<<"]"<<endl;
//     if((command=="list")||(command=="0")){
//     	return 0;
//     }else if((command=="create")||(command=="1")){
//     	return 1;
//     }else if((command=="login")||(command=="2")){
//     	return 2;
//     }else if((command=="exit")||(command=="3")){
//     	return 3;
//     }else{
//     	return -10;
//     }
	return 1;
}

int ATM_Machine::ATM_info(){

	string command;
	cout<<"#################################################################"<<endl;
    cout<<"#           hello this is the virtual atm program               #"<<endl;
    cout<<"#################################################################"<<endl;

    cout<<"#################################################################"<<endl;
    cout<<"# [Balance] or 0: showing your current balance                  #"<<endl;
    cout<<"# [Deposit] or 1: Cash in into your account                     #"<<endl;
    cout<<"# [Withdraw] or 2: Cash out from your account                   #"<<endl;
    cout<<"# [exit] or 3: finishing atm program                            #"<<endl;
    cout<<"#################################################################"<<endl;

    cout<<"Currently $"<<current_note_value<<" in this ATM"<<endl;
    cout<<endl;
    cout<<"choose command:";
    cin >> command;
    cout<<"you choose the command of ["<<command<<"]"<<endl;
    if((command=="Balance")||(command=="0")){
    	return 0;
    }else if((command=="Deposit")||(command=="1")){
    	return 1;
    }else if((command=="Withdraw")||(command=="2")){
    	return 2;
    }else if((command=="exit")||(command=="3")){
    	return 3;
    }else{
    	return -10;
    }
}

void ATM_Machine::Balance(Personal_Information log_in_customer){
	cout<<"#################################################################"<<endl;
	cout<<"#                     Balance Information                	#"<<endl;
	cout<<"#################################################################"<<endl;
    cout<<"Hello!! ";
    cout<<log_in_customer.Get_first_name()<<", "<<log_in_customer.Get_last_name()<<" "<<endl;
    cout<<"% Checking Account Number: "<<log_in_customer.Get_bank_account()<<"-00"<<endl;
    cout<<"% Checking Balance: $"<<log_in_customer.Get_checking_money()<<endl;
    cout<<endl;
    cout<<"% Saving Account Number: "<<log_in_customer.Get_bank_account()<<"-01"<<endl;
    cout<<"% Saving Balance: $"<<log_in_customer.Get_saving_money()<<endl;
    cout<<"#################################################################"<<endl;
}

Personal_Information ATM_Machine::Deposit(Personal_Information log_in_customer){
	string command;
	cout<<"Choose your account [0 (Checking account), 1 (Saving account)]: ";
	cin>>command;
	while(1){
		string money_command;
		if(command=="0"){
			cout<<"You choose Checking"<<endl;
			cout<<"Please, Insert money (type money value): ";
			
			cin>>money_command;
			log_in_customer.Change_checking_money_from_deposit(money_command);
			cout<<"You put $"<<money_command<<" on checking account"<<endl;
			
			current_note_value=current_note_value+atoi(money_command.c_str());//atm money update

			cout<<"current balance is on checking account: $"<<log_in_customer.Get_checking_money()<<endl;
			cout<<"Thanks"<<endl;
			break;
		}else if(command=="1"){
			cout<<"You choose Saving"<<endl;
			cout<<"Please, Insert money (type money value): ";
			cin>>money_command;
			log_in_customer.Change_saving_money_from_deposit(money_command);
			cout<<"You put $"<<money_command<<" on saving account"<<endl;

			current_note_value=current_note_value+atoi(money_command.c_str());//atm money update
			
			cout<<"current balance is on saving account: $"<<log_in_customer.Get_saving_money()<<endl;
			cout<<"Thanks"<<endl;
			break;
		}else{
			cout<<"Error: Please type 0 or 1"<<endl;
		}
		cout<<"Choose your account [0 (Checking account), 1 (Saving account)]: ";
		cin>>command;
	}
	return log_in_customer;
}

Personal_Information ATM_Machine::Withdraw(Personal_Information log_in_customer){
	string command;
	cout<<"Choose your account [0 (Checking account), 1 (Saving account)]: ";
	cin>>command;
	while(1){
		string money_command;
		if(command=="0"){

			string user_check_money=log_in_customer.Get_checking_money();
			cout<<"You choose Checking"<<endl;
			cout<<"Currently $"<<to_string(current_note_value)<<"in this ATM"<<endl;
			cout<<"Please, Withdraw money less than $"<<to_string(current_note_value)<<endl;
			cout<<"your current balance in checking account $"<<user_check_money<<endl;
			cout<<"Type value for withdraw: ";
			
			cin>>money_command;
			while(1){
				if( atoi(user_check_money.c_str()) < atoi(money_command.c_str()) ){
					cout<<"Error, this value is more than your checking account"<<endl;
				}else{
					if( current_note_value < atoi(money_command.c_str()) ){
						cout<<"Error, this value is more than ATM money"<<endl;
					}else{
						break;
					}
				}
				cout<<"Currently [$"<<to_string(current_note_value)<<"] in this ATM"<<endl;
				cout<<"Please, Withdraw money less than [$"<<to_string(current_note_value)<<"]"<<endl<<endl;
				cout<<"your current balance in checking account $"<<user_check_money<<endl;
				cout<<"Type value for withdraw: ";
				cin>>money_command;
			}
			cout<<"You cash out $"<<money_command<<" from checking account"<<endl;

			log_in_customer.Change_checking_money_from_withdraw(money_command);			


			
			
			
			current_note_value=current_note_value-atoi(money_command.c_str());//atm money update

			cout<<"current balance is on checking account: $"<<log_in_customer.Get_checking_money()<<endl;
			cout<<"Thanks"<<endl;
			break;
		}else if(command=="1"){
			string user_check_money=log_in_customer.Get_saving_money();
			cout<<"You choose Saving"<<endl;
			cout<<"Currently [$"<<to_string(current_note_value)<<"] in THIS ATM"<<endl;
			cout<<"Please, Withdraw money less than [$"<<to_string(current_note_value)<<"]"<<endl<<endl;
			cout<<"your current balance in checking account $"<<user_check_money<<endl;
			cout<<"Type value for withdraw: ";
			
			cin>>money_command;
			while(1){
				if( atoi(user_check_money.c_str()) < atoi(money_command.c_str()) ){
					cout<<"Error, this value is more than your checking account"<<endl;
				}else{
					if( current_note_value < atoi(money_command.c_str()) ){
						cout<<"Error, this value is more than ATM money"<<endl;
					}else{
						break;
					}
				}
				cout<<"Currently [$"<<to_string(current_note_value)<<"] in this ATM"<<endl;
				cout<<"Please, Withdraw money less than [$"<<to_string(current_note_value)<<"]"<<endl<<endl;
				cout<<"your current balance in checking account [$"<<user_check_money<<"]"<<endl;
				cout<<"Type value for withdraw: ";
				cin>>money_command;
			}

			cout<<"You cash out $"<<money_command<<" from checking account"<<endl;

			log_in_customer.Change_saving_money_from_withdraw(money_command);			
						
			
			current_note_value=current_note_value-atoi(money_command.c_str());//atm money update

			cout<<"current balance is on saving account: $"<<log_in_customer.Get_saving_money()<<endl;
			cout<<"Thanks"<<endl;
			break;
		}else{
			cout<<"Error: Please type 0 or 1"<<endl;
		}
		cout<<"Choose your account [0 (Checking account), 1 (Saving account)]: ";
		cin>>command;
	}
	return log_in_customer;
}

int ATM_Machine::Get_current_user_idx(){
	return idx_of_customer;
}