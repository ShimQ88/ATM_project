#include "main.h"

void wait(int seconds){
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
  cout<<"Wait "<<to_string(seconds)<< " seconds"<<endl;
  while (clock() < endwait) {}
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

int main(){
	Bank bank;
	bank.Initialize();
	ATM_Machine Atm;
	int log_in_information=Atm.Log_in(bank.Sending_personal_info_to_atm(), bank.Get_the_numb_of_customers() );
	if(log_in_information<0){
		return 0;
	}

	while(1){
		int log=Atm.ATM_info();
		// cout<<"log: "<<log<<endl;
		if(log==0){
			Atm.Balance( bank.Get_customer_info(Atm.Get_current_user_idx() ) );
			wait(4);
		}else if(log==1){
			Personal_Information temp_personal_info= Atm.Deposit( bank.Get_customer_info(Atm.Get_current_user_idx() ) ) ;
			// Atm.Get_current_user_idx();
			bank.Reset_targeted_customer_info(temp_personal_info, Atm.Get_current_user_idx());
			Atm.Update_ATM_money();
			bank.Save_updated_information();
			wait(4);
		}else if(log==2){
			Personal_Information temp_personal_info= Atm.Withdraw( bank.Get_customer_info(Atm.Get_current_user_idx() ) ) ;
			bank.Reset_targeted_customer_info(temp_personal_info, Atm.Get_current_user_idx());
			Atm.Update_ATM_money();
			bank.Save_updated_information();
			wait(4);

		}else if(log==3){//break condition
			break;
		}else{
			cout<<"A command or number is incorrect, please re-type the log :)"<<endl;
		}
	}
	cout<<"Thanks for using our ATM machine, hope to see you again"<<endl;
	bank.Deallocation();
	
}