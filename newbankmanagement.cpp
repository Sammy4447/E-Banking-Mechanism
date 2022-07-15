#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class account
{
    int acno;
    char name[30];
    int deposit;
    char type;
    string pass;

public:
    void create_account();
    void show_account();
    void modify();
    void login();

    void dep(int);
    void draw(int);

    void report() const;
    int retacno() const;
    int retdeposit() const;
    char rettype() const;
};
// void account:: login()
// {
    
//     string passWord;
//     cout<<"Enter the password: ";
//     cin>>pass;
//     if(pass==passWord)
//     {
//     cout<<"============";
//     }


void account::create_account()
{
    cout<<"Enter the account no:";
    cin>>acno;    
    //login();
    cout << "\n Enter the name of the account holder : ";
    cin.ignore();
    cin.getline(name, 30);

    cout << "\n Enter the type of the account : ";
    cin >> type;
    // type = toupper(type);
    cout << "\n Enter the initial amount (>=500 for saving and >= 1000 for current) : ";
    cin >> deposit;

    cout << "\n \n \n \n Account created !";
}

void account::show_account()
{
    cout << "\n Account No : " << acno<<endl;

    cout << "\n Account Holder's Name : ";
    cin>>name;
    cout << "\n Type of account : " << type;
    cout << "\n Balance Amount : " << deposit;
    }



void account::modify()
{

    cout << "\n Account No : " << acno<<endl;
    
    cout << "\nModify account  holders name : ";
    cin>>name;
    cout << "\nModify Type of Account : ";
    cin >> type;
    cout << "\nModify Balance amount : ";
    cin >> deposit;
}
void account::dep(int x)
{
    deposit += x;
}
void account::draw(int x)
{
    deposit -= x;
}
void account::report() const
{
    cout << acno << setw(5) << " " << name << setw(5) << " " << type << setw(6) << deposit << endl;
}
int account::retacno() const
{
    return acno;
}
int account ::retdeposit() const
{
    return deposit;
}
char account::rettype() const
{
    return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();

int main()
{
    ifstream myfile;
    int a[100],choice;
    int t,x,y,acno;
    char ch;
    int num;
    intro();
    myfile.open("exam.txt");
    myfile>>x>>y;
    do{
    do
    {
        abc:
    cout << "\n Enter the account no : ";
    cin >> acno;

    for (int i=0;i<100;i++)
    {
        if(a[i]==acno)
        {
            goto nocreate;
        }
    }
    a[t]=acno;
    t++;
    if (acno>x && acno<=y)
    {
        account ac;
        ac.create_account();
    
    }
    else{
        nocreate:
        cout<<"Invalid creation!";
        goto abc;

    }
    cout<<"Enter another option!";
    cin>>choice;
    system("cls");
    if(choice==1)
    {
        cout<<"ok";
        
    }
    if(choice ==2)
    {
        intro();
    }

    }
    while (choice ==1);
    }
    while (acno>x && acno<=y);


        system("cls");
        cout << "\n MAIN MENU : ";

        cout << "\n \t1. NEW ACCOUNT : ";
        cout << "\n \t2. DEPOSIT AMOUNT : ";
        cout << "\n \t3. WITHDRAW AMOUNT : ";
        cout << "\n \t4. BALANCE ENQUIRY ";
        cout << "\n \t5. ALL ACCOUNT HOLDER LIST : ";
        cout << "\n \t6. CLOSE AN ACCOUNT : ";
        cout << "\n \t7. MODIFY AN ACCOUNT : ";
        cout << "\n \t8. EXIT !";

        cout << "\n Enter your choice(1-8) !";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n Enter the account no : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n Enter the account no :";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout << "\n Enter the account no :";
            cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout << "\n Enter the account no :";
            cin >> num;
            delete_account(num);
            break;
             case '7':
            cout << "\n Enter the account no :";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n Thanks for using the bank management system :";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();

while (ch != '8');
    return 0;
}


void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}

void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n File cannot be open ! Press any key...";
        return;
    }
    cout << "\n BALANCE DETAILS :";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() == n)

        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n Account no does not exist !";
}
void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n File could not be open !  Please press any key !";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n Enter new details of the account : ";
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n Records updated !!";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n Records not found !!";
}
void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n File could not be open !  Please press any key :";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "\n Records Deleted !";
}
void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n File could not be open ! Press any key to continue !";
        return;
    }
    cout << "\n Account Holders list ::";
    cout << "===================================\n";
    cout << "Ac/No.          NAME          Type Balance\n";
    cout << "===================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}
void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n The file could not be found !  Press any another key to continue !";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n To deposit the amount :";
                cout << "\n Enter the amount to be deposited:";
                cin >> amt;
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n To withdraw amount :";
                cout << "\n Enter the amount to be withdrawn :";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
                    cout << "\n Insufficient balance !!";
                else
                    ac.draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n Record updated !";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n Record not found !";
}
void intro()
{
    cout << "\n\t BANK ";
    cout << "\n \t Management";
    cout << "\n \t System";
    cout << "\n \t Made By: Group of bank management system !";
    cout << "\n \t University: Far-Western University! ";
}
