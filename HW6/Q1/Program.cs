using Classes;
using System;

namespace Q1
{
    class Program{
        private static void Main(string[] args)
        {
            Console.WriteLine("Student ID: B10831020");
            var accounts = new BankAccount[3];
            accounts[0] = new BankAccount("無名氏", 1352);
            accounts[1] = new BankAccount("有名氏", 23454);
            accounts[2] = new BankAccount("非無名氏", 235243);

            foreach(BankAccount acc in accounts){
                Console.WriteLine($"Account {acc.Number} was created for {acc.Owner} with {acc.Balance} balance.");
            }
            foreach(BankAccount acc in accounts){
                acc.MakeWithdrawal(50, DateTime.Now, "Rent payment");
                acc.MakeDeposit(200, DateTime.Now, "friend paid me back");
                acc.MakeWithdrawal(50, DateTime.Now, "Rent payment");
                acc.MakeWithdrawal(30, DateTime.Now, "Rent payment");
            }
            foreach(BankAccount acc in accounts){
                Console.WriteLine(acc.GetAccountHistory());
            }
            Console.ReadKey();
            
        }
    }
}