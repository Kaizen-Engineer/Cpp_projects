#include<iostream>
#include<cstring>
#include<string.h>
#include<fstream>
#include<random>
#include<cmath>
#include<ctime>
using namespace std;

double readBal(){
    ifstream inFile("balance.txt");
    double balance = 0.0;
    if(inFile.is_open()){
        inFile>>balance;
        inFile.close();
    }
    return balance;
}
string readName(){
    ifstream inFile("accname.txt");
    string name = "";
    if(inFile.is_open()){
        inFile>>name;
        inFile.close();
    }
    return name;
}
void writeName(string name){
    ofstream outFile("accname.txt");
    if(outFile.is_open()){
        outFile<<name;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}
long long readAccnum(){
    ifstream inFile("accnumber.txt");
    long long accNum1=0;
    if(inFile.is_open()){
        inFile>>accNum1;
        inFile.close();
    }
    return accNum1;                        
}
void writeAccnum(long long accNum1){
    ofstream outFile("accnumber.txt");
    if(outFile.is_open()){
        outFile<<accNum1;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

void writeBal(double balance){
    ofstream outFile("balance.txt");
    if(outFile.is_open()){
        outFile<<balance;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

double readTransaction(){
    ifstream inFile("transaction.txt");
    double transaction=0.0;
    if(inFile.is_open()){
        inFile>>transaction;
        inFile.close();
    }
    return transaction;
}

void writeTransaction(double transaction){
    ofstream outFile("transaction.txt");
    if(outFile.is_open()){
        outFile<<transaction;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

double readDepTransaction(){
    ifstream inFile("depotransaction.txt");
    double depotransaction=0.0;
    if(inFile.is_open()){
        inFile>>depotransaction;
        inFile.close();
    }
    return depotransaction;
}

void writeDepTransaction(double depotransaction){
    ofstream outFile("depotransaction.txt");
    if(outFile.is_open()){
        outFile<<depotransaction;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

int main(){
    int digit=18;
    double balance = readBal();
    double depotransaction = readDepTransaction();
    double transaction = readTransaction();
    char options;
    string name;
    long long accNum=12992983828991;

    cout<<"Chose what to do (C = create account, D = deposite, W = withdraw, A = account details): ";
    cin>>options;

    if(options=='C'){
        cout<<"Enter your name: ";
        cin>>name;

        writeName(name);
        writeAccnum(accNum);
        cout<<"Name: "<<name<<endl;
        cout<<"Account number: "<<accNum<<endl;
    }
    else if(options=='D'){
        double depositeAmount;
        double depotransaction;
        cout<<"Enter amount to deposite: ";
        cin>>depositeAmount;

        balance+=depositeAmount;
        writeBal(balance);
        depotransaction=depositeAmount;
        writeDepTransaction(depotransaction);
        cout<<"Successfully deposited the amount of "<<depositeAmount<<" to the account "<<endl;
    }
    else if(options=='W'){
        double withdrawalAmount;
        double transaction;
        cout<<"Enter amount to withdraw: ";
        cin>>withdrawalAmount;

        transaction=withdrawalAmount;
        writeTransaction(transaction);
        if(withdrawalAmount<=balance){
            balance-=withdrawalAmount;
            writeBal(balance);
            cout<<"Available balance: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient balance!"<<endl;
        }
    }
    else if(options=='A'){
        ifstream readName("accname.txt");
        ifstream readAccnum("accnumber.txt");
        ifstream readBal("balance.txt");
        ifstream readDepTransaction("depotransaction.txt");
        ifstream readTransaction("transaction.txt");

        getline(readName, name);
        readAccnum>>accNum;
        readBal>>balance;
        readDepTransaction>>depotransaction;
        readTransaction>>transaction;

        cout<<"Name: "<<name<<endl;
        cout<<"Account number: "<<accNum<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Last transaction: "<<endl;
        cout<<"Deposite: +"<<depotransaction<<endl;
        cout<<"Withdraw: -"<<transaction<<endl;

        readName.close();
        readAccnum.close();
        readBal.close();
        readDepTransaction.close();
        readTransaction.close();
    }
    return 0;
}