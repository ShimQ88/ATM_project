This is virtual ATM program

Designed from Kyuwon Shim
mail:kyu.shim88@gmail.com

dataset Information: data/bank_data/dataset.data (personal information "I will encrypt data information for further updating")

ATM Money Information: data/atm_data/atm_money.data (The money which is currently stored in this ATM)

User List
0. ID: kyu_shim, Password:1234
1. ID:john_park, Password:5678
2. ID:black_diamond, Password:0000
3. ID:cute_hani, Password:hani1212
4. ID:jun123, Password:123
5. ID:morning_glory, Password:222
6. ID:hi_jenny, Password:jen11

How to compile: make

clean compile: make clean

userID:

How to run: 
write command (./main) -> write the userID (any ID from user list) -> its password 
-> choose the action as writing command 0(Balance), 1(Deposite), 2(Withdraw) or 3(exit program)

Balance (command 0): It simply shows the balance of saving and checking account.

Deposite (command 1): The function puts in certain amount of money inside your account.  
Choose the checking (command 0) or saving (command 1) -> write amount wish to cash in 
-> Updating dataset file(data/bank_data/dataset.data)-> Updating ATM money(data/atm_data/atm_money.data) -> done.

Withdraw (command 2): It shows the balance of saving and checking account.
Choose the checking (command 0) or saving (command 1) -> write amount wish to cash out (must be less money 
than your account) && (must be less money than stored ATM money) -> Updating dataset file(data/bank_data/dataset.data)-> Updating ATM money(data/atm_data/atm_money.data) -> done
-> Done.


