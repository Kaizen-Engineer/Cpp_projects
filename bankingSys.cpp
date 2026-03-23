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

long long readPhonenum(){
    ifstream inFile("phonenum.txt");
    long long phonenum=0;
    if(inFile.is_open()){
        inFile>>phonenum;
        inFile.close();
    }
    return phonenum;
}

void writePhonenum(long long phonenum){
    ofstream outFile("phonenum.txt");
    if(outFile.is_open()){
        outFile<<phonenum;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

string readAddress(){
    ifstream inFile("address.txt");
    string address="";
    if(inFile.is_open()){
        getline(inFile, address);
        inFile.close();
    }
    return address;
}

void writeAddress(string address){
    ofstream outFile("address.txt");
    if(outFile.is_open()){
        outFile<<address;
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

string readDeptime(){
    ifstream inFile("deptime.txt");
    string deptime="";
    if(inFile.is_open()){
        getline(inFile, deptime);
        inFile.close();
    }
    return deptime;
}

void writeDeptime(string deptime){
    ofstream outFile("deptime.txt");
    if(outFile.is_open()){
        outFile<<deptime;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

string readWithtime(){
    ifstream inFile("withtime.txt");
    string withtime="";
    if(inFile.is_open()){
        getline(inFile, withtime);
        inFile.close();
    }
    return withtime;
}

void writeWithtime(string withtime){
    ofstream outFile("withtime.txt");
    if(outFile.is_open()){
        outFile<<withtime;
        outFile.close();
    }
    else{
        cout<<"Error";
    }
}

string getTimestamp(){
    time_t now = time(0);
    tm *ltm=localtime(&now);

    char buffer[80];

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

int main(){
    int digit=18;
    double balance = readBal();
    double depotransaction = readDepTransaction();
    double transaction = readTransaction();
    char options;
    string deptime = readDeptime();
    string withtime = readWithtime();
    string currentTime=getTimestamp();
    string currentTimewith=getTimestamp();
    string name;
    long long phonenum;
    string address;
    long long accNum=12992983828991;

    cout<<"Chose what to do (C = create account, D = deposite, W = withdraw, A = account details): ";
    cin>>options;

    if(options=='C'){
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Enter phonenumber: ";
        cin>>phonenum;
        cin.ignore();
        cout<<"Enter address: ";
        getline(cin, address);

        writeName(name);
        writePhonenum(phonenum);
        writeAddress(address);
        writeAccnum(accNum); 
        cout<<"Account created successfully";
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
        writeDeptime(currentTime);
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
            writeWithtime(currentTimewith);
            cout<<"Available balance: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient balance!"<<endl;
        }
    }
    else if(options=='A'){
        name = readName();
        accNum = readAccnum();
        phonenum = readPhonenum();
        address = readAddress();
        balance = readBal();
        depotransaction = readDepTransaction();
        transaction = readTransaction();
        deptime = readDeptime();
        withtime = readWithtime();

        
        cout<<"Name: "<<name<<endl;
        cout<<"Account number: "<<accNum<<endl;
        cout<<"Phone number: "<<phonenum<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Last transaction: "<<endl;
        cout<<"Deposite: +"<<depotransaction<<" "<<deptime<<endl;
        cout<<"Withdraw: -"<<transaction<<" "<<withtime<<endl;

    }
    return 0;
}