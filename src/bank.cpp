#include "bank.h"

// Bank::Bank(){}
// Bank::~Bank(){}
int Bank::Get_the_numb_of_customers(){
	return the_numb_of_customers;
}
Personal_Information* Bank::Sending_personal_info_to_atm(){
	return customer;
}

void Bank::Initialize(){
	the_numb_of_customers=Get_the_numb_of_class(dataset_path);
	the_numb_of_personal_data=Get_the_numb_of_personal_data(dataset_path);
	customer=new Personal_Information[the_numb_of_customers];
	Load_personal_information_from_dataset(dataset_path, the_numb_of_customers, the_numb_of_personal_data, customer);
}
void Bank::Deallocation(){
	delete[] customer;
}



void Bank::Display_customer_information(){
	customer[1].Print_personal_information();
	// cout<<"he"<<endl;
}

int Bank::Get_the_numb_of_class(string path){
	string temp_file_path=path;
	ifstream file(temp_file_path);
	int i=0;
	if ( file.is_open() ) {
		string mystring;
		while( getline(file, mystring) ) {
			// std::cout << mystring<<endl;
			i++;
			// getchar();
		}
		file.close();
	}
	i--;
	// cout<<"i: "<<i<<endl;
	return i;
}

int Bank::Get_the_numb_of_personal_data(string path){
	string temp_file_path=path;
	ifstream file(temp_file_path);
	int i=0;
	if ( file.is_open() ) {
		string mystring;
		getline(file, mystring);
		int delimiter=0;
			// string output_file_name;
		
		while(delimiter!=-1){
			delimiter = mystring.find(',');
			mystring=mystring.substr(delimiter+1);
			i++;
		}
		file.close();
	}
	// i--;
	// cout<<"i: "<<i<<endl;
	return i;
}

void Bank::Load_personal_information_from_dataset(string path, int customer_numb, int data_numb, Personal_Information* person_info){
	string loaded_data[customer_numb][data_numb];

	string temp_file_path=path;
	
	//Write file
	ifstream file(temp_file_path);
	if ( file.is_open() ) {
		string mystring;
		int cus_i=0;
		getline(file, mystring);
		while( getline(file, mystring) ) {
			// std::cout << mystring;

			int delimiter=0;
			// string output_file_name;
			int data_i=0;
			while(delimiter!=-1){
				delimiter = mystring.find(',');
				string data=mystring.substr(0,delimiter);
				mystring=mystring.substr(delimiter+1);
				loaded_data[cus_i][data_i]=data;
				// idx++;
				data_i++;
				// cout<<"data:"<<data<<endl;
			}
			cus_i++;
			// getchar();
		}
		file.close();
	}
	// cout<<"the_numb_of_personal_data: "<<the_numb_of_personal_data<<endl;
	// cout<<"what the fucnk"<<endl;
	for(int i=0;i<customer_numb;i++){
		// cout<<"here"<<endl;
		person_info[i].Initialize_data(loaded_data[i]);
		// cout<<"here"<<endl;
		// person_info[i].Print_personal_information();

	}
}

Personal_Information Bank::Get_customer_info(int index){
	return customer[index];
}

void Bank::Reset_targeted_customer_info(Personal_Information person_info, int customer_index){
	customer[customer_index]=person_info;
}

void Bank::Save_updated_information(){
	fstream file("data/bank_data/dataset.data");
	cout<<"sys log: Updating data on bank system"<<endl;
	if ( file.is_open() ){
		file <<"index,id,password,bank_account,first_name,last_name,dob,saving_money,checking_money\n";
		for(int i=0;i<the_numb_of_customers;i++){
			file <<customer[i].Get_idx();
			file <<",";
			file <<customer[i].Get_id();
			file <<",";
			file <<customer[i].Get_password();
			file <<",";
			file <<customer[i].Get_bank_account();
			file <<",";
			file <<customer[i].Get_first_name();
			file <<",";
			file <<customer[i].Get_last_name();
			file <<",";
			file <<customer[i].Get_dob();
			file <<",";
			file <<customer[i].Get_checking_money();
			file <<",";
			file <<customer[i].Get_saving_money();
			if(i==the_numb_of_customers-1){

			}else{
				file <<"\n";	
			}
			
		}
		file.close();
	}
	cout<<"sys log: Updating completed!"<<endl;
}