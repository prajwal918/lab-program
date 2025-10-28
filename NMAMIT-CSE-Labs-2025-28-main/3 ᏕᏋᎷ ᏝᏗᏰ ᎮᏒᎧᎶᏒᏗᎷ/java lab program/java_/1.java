package demo;

class Account {
    int accountNo;
    String name;
    int balance;

    Account(int accountNo, String name, int balance) {
        this.accountNo = accountNo;
        this.name = name;
        this.balance = balance;
    }

    void withdraw(int amount) {
        if (amount > balance) {
            System.out.println("Insufficient balance.");
        } else {
            balance -= amount;
            System.out.println("Withdrawal of " + amount + " successful.");
        }
    }

    void deposit(int amount) {
        balance += amount;
        System.out.println("Deposit of " + amount + " successful.");
    }

    void checkBalance() {
        System.out.println("Current account balance is " + balance);
    }

    void displayInfo() {
        System.out.println("Account number   : " + accountNo);
        System.out.println("Account holder   : " + name);
        System.out.println("Balance          : " + balance);
    }
}

public class Demo {
    public static void main(String[] args) {
        Account c1 = new Account(46545, "PRAJWAL JOGI", 4658);

        c1.deposit(665);
        c1.checkBalance();

        c1.withdraw(98);
        c1.checkBalance();

        System.out.println();
        c1.displayInfo();
    }
}
