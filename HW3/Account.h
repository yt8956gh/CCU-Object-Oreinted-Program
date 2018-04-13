
class Account
{
    private:
        int ID;
        int amount;

    public:
        //Member initialization list
        Account(int,const int);

        bool withdraw(int);

        bool deposit(int);

        bool transferMoney(Account &, int);

        int getAmount();
};