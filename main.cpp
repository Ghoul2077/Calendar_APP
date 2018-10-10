#include <iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//------------------------------------------------------------------------------------
bool isleapyr(int &y) //To Know if an Year is a leap year or not
{
    bool flag;
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
            {
              flag=true;
            }
            else
            {
                flag=false;
            }
        }
        else
        {
            flag=true;
        }
    }
    else
    {
        flag=false;
    }
    return flag;
}
//------------------------------------------------------------------------------------
int yrs(int l) // Calculation of extra days due to years
{
    l-=1; // Think Hard and You will know why I did This , If having a problem then try running program without this line and u will get it :)
int leapyrs=l/4-l/100+l/400;
int extra = (l-leapyrs)+leapyrs*2;
return (extra%7);
}
//------------------------------------------------------------------------------------
int months(int &m,int &l) // Calculation of extra days due to months
{
int extra;
if(isleapyr(l))
{
    int temp[]={-1,0,3,4,0,2,5,0,3,6,1,4,6,2};
    extra=temp[m];
}
else
{
    int temp[]={-1,0,3,3,6,1,4,6,2,5,0,3,5,1};
    extra=temp[m];
}
return extra;
}
//------------------------------------------------------------------------------------
int days(int &n) // Calculation of extra days due to as usual days
{
int extra=(n%7);
return extra;
}
//------------------------------------------------------------------------------------
int extra(int p, int &q , int &r) // The total no. of extra days from year+months+days
{
    int extra=yrs(r)+months(q,r)+days(p);
    extra=extra%7;
    return extra;
}
//------------------------------------------------------------------------------------
int output(int &p, int &q , int &r)
{
    cout<<endl;
    switch(extra(p,q,r))
    {
        case 0:cout<<"'Sunday'"<<endl;
        break;
        case 1:cout<<"'Monday'"<<endl;
        break;
        case 2:cout<<"'Tuesday'"<<endl;
        break;
        case 3:cout<<"'Wednesday'"<<endl;
        break;
        case 4:cout<<"'Thursday'"<<endl;
        break;
        case 5:cout<<"'Friday'"<<endl;
        break;
        case 6:cout<<"'Saturday'"<<endl;
        break;
        default:cout<<"'NULL'"<<endl;
        break;
    }
    cout<<endl;
    system("pause");
}
//------------------------------------------------------------------------------------
void calendar( int &a , int &c) // Function to print Calendar of any month
{
    int q;
    cout<<endl;
    cout<<"\t";
    switch(a)
    {
        case 1:cout<<"January, "<<c<<endl;
            break;
        case 2:cout<<"Feburary, "<<c<<endl;
            break;
        case 3:cout<<"March, "<<c<<endl;
            break;
        case 4:cout<<"April, "<<c<<endl;
            break;
        case 5:cout<<"May, "<<c<<endl;
            break;
        case 6:cout<<"June, "<<c<<endl;
            break;
        case 7:cout<<"July, "<<c<<endl;
            break;
        case 8:cout<<"August, "<<c<<endl;
            break;
        case 9:cout<<"September, "<<c<<endl;
            break;
        case 10:cout<<"October, "<<c<<endl;
            break;
        case 11:cout<<"November, "<<c<<endl;
            break;
        case 12:cout<<"December, "<<c<<endl;
            break;
        default:cout<<"'NULL'"<<c<<endl;
            break;
    }
    cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
    int temp;
    switch(extra(1,a,c))
    {
        case 0:cout<<"  1";temp=6;
            break;
        case 1:cout<<"      1";temp=5;
            break;
        case 2:cout<<"          1";temp=4;
            break;
        case 3:cout<<"              1";temp=3;
            break;
        case 4:cout<<"                  1";temp=2;
            break;
        case 5:cout<<"                      1";temp=1;
            break;
        case 6:cout<<"                          1";temp=0;
            break;
        default:cout<<"NULL";
            break;
    }
    if(a==2 && isleapyr(c)==true)
    {
        q=29;
    }
    else if(a==2 && isleapyr(c)==false)
    {
        q=28;
    }
    else
    {
        if(a==1||a==3||a==5||a==7||a==8||a==10||a==12)
            q=31;
        else
            q=30;
    }
    for(int i=2;i<=q;i++,temp--)
    {
        if(temp==0)
        {
            if(i<10)
                cout<<endl<<"  "<<i;
            else
                cout<<endl<<" "<<i;
            temp=7;
        }
        else
        {
            if(i<10)
                cout<<"   "<<i;
            else
                cout<<"  "<<i;
        }
    }
    cout<<endl<<endl;
    system("pause");

}
//------------------------------------------------------------------------------------
int main() 
{
    int x;
    do {
        system("cls");
        cout <<endl<<"1. Find the day of Month of any Year"<< endl;
        cout <<"2. Print the calender of a Month of any Year"<< endl;
        cout <<"3. Not Much I can do Other than Above 2 Options , so 'EXIT'"<<endl;
        cout<<"Enter Your Option - ";
        cin>>x;
        if(x==1)
        {
            char day[3],month[3],year[5];
            cout<<"Now Enter the date in the Following Format 'Date/Month/Year'"<<endl;
            cin.get(day,4,'/');
            cin.ignore(100,'/');
            cin.get(month,4,'/');
            cin.ignore(100,'/');
            cin.get(year,5);
            //convert them to int
            int a,b,c;
            a=atoi(day);
            b=atoi(month);
            c=atoi(year);
            output(a,b,c);
        }
        else if(x==2)
        {
            char day[3],month[3],year[5];
            cout<<"Now Enter the date in the Following Format 'Month/Year'"<<endl;
            cin.get(month,4,'/');
            cin.ignore(100,'/');
            cin.get(year,5);
            //convert them to int
            int b,c;
            b=atoi(month);
            c=atoi(year);
            calendar(b,c);
        }
        else if(x==3)
        {
            exit(0);
        }
        else
        {
            cout<<"WubalubaDubDub"<<endl;
        }
    }while(x!=3);
    system("pause");
    return 0;

}