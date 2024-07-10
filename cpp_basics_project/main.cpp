#include <iostream>
#include <string>
#include <array>
#define max_size 100
#define add_option 1
#define fetch_option 2
#define exit 3
#define initial_value 0

using namespace std;


void print_menu(void);
void add_record(string func_name, int func_age);
void fetch_record(int id);
string get_name(void);
int get_age(void);
int get_option(void);
int get_id(void);
int record_counter=initial_value;
class person
{
public:
    int age;
    string name;
    person(string n,int a)
    {
        name=n;
        age=a;
    } 
    person() //why??
    {
    
    }
};
array<person,max_size>id;
int main()
{
    int op=initial_value; // is this right??
    cout<<"User Sign up Application\n";
    while (op != exit)
    {
        print_menu();
        op=get_option();
        if (op==add_option) //is this right??
        {
            string name=get_name();
            int age=get_age();
            add_record(name,age);
        }
        else if (op == fetch_option)
        {
            int id=get_id();
            fetch_record(id);
        }
        else if (op == exit)
        {
            continue;
        }
        else
        {
            cout<<"Wrong Entery! Please try agian\n";
        }
    }
    return 0;
}
void add_record(string func_name, int func_age) //naming ???????
{
    person obj(func_name,func_age);
    id[record_counter]=obj; //?????
    record_counter++;
}
void print_menu(void)
{
    cout<<"Please select an option\n";
    cout<<"1.Add record\n";
    cout<<"2.Fetch record\n";
    cout<<"3.Exit\n\n";
}
void fetch_record(int ID)
{
    if (ID < record_counter)            //bug???
    {
        cout<<"Name: ";
        cout <<id[ID].name<<"\n";
        cout<<"Age: ";
        cout <<id[ID].age<<"\n";
    }
    else
    {
        cout<<"Wrong ID. Please try again\n";
    }
}
int get_age(void)
{
    int age;
    cout<<"Enter age: ";
    cin>>age;
    return age;
}
string get_name(void) //is static can all program see it??
{
    string name;
    cout<<"Add user ! Enter name: ";
    cin>>name;
    return name;
}
int get_option(void)
{
    cout<<"Enter an option ";
    int select; //where static store in memory and why not use global
    cin >> select;
    return select;
}
int get_id(void)
{
    cout<<"Fetch record! Enter ID: ";
    int id;
    cin>>id;
    return id;
}