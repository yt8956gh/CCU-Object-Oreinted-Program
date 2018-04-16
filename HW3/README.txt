

##The test driver of the program will create 3 User A, B, and C like below,

-------------------------------------
Account (ID:0)  constructed
Transaction (type:Create)   constructed
User    (ID:0)  constructed

Account (ID:1)  constructed
Transaction (type:Create)   constructed
User    (ID:1)  constructed

Account (ID:2)  constructed
Transaction (type:Create)   constructed
User    (ID:2)  constructed





##then transaction function will be test with money produced by random 100 times like below. 

----------Transaction start----------

Transaction (type:Deposit)  constructed
Deposit successfully
Transaction (type:Deposit)  constructed
Deposit successfully
Transaction (type:Deposit)  constructed
Deposit successfully
Fail to withdraw
.....






##After transaction the detail will be print like below

----------Transaction print----------


Pooh

Type: Create
Type: Pooh Deposit 0
Type: Pooh Deposit 400
Type: Pooh Deposit 300
Type: Transferred 700 to Piget
Type: Pooh Deposit 100
Type: Pooh Deposit 100
Type: Pooh Deposit 200
Type: Pooh Deposit 100
Type: Pooh Deposit 600
Type: Pooh Withdraw 300






##,and the final result will show 

------------Final Result-------------

A's name: Pooh
A's Amount: 2600
A's ID: 0
-------------------------------------
B's name: Piget
B's Amount: 1300
B's ID: 1
-------------------------------------
A's name: Tigger
A's Amount: 1200
A's ID: 2
-------------------------------------




##Destructed

Account (ID:2)  destructed
Account (ID:1)  destructed
Account (ID:0)  destructed
User    (ID:2)  destructed
Transaction (type:Create)   destructed
...