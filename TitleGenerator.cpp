#include<bits/stdc++.h>
#include <fstream>
using namespace std;
string filename="TitleGenerator.txt";
int maxnum;
char point,bracket,op; //temp
char getSignal();
int getResult(int,int,char);
float Generator();

int main()
{
    string filename="TitleGenerator.txt";
    ofstream fout("TitleGenerator.txt");
    int title_num,right=0;
    double percent;
    cout<<"请输入题数：";
    cin>>title_num;
    cout<<"请输入最大数：";
    cin>>maxnum;
    cout<<"是否有小数(y/n)：";
    cin>>point;



    for(int i=0; i<title_num; i++)
    {
        srand((unsigned)time(NULL));
        Generator();


    }
    fout.close();
}

char getSignal()
{
    char signal[4]= {'+','-','*','/'};
    srand((unsigned)time(NULL));
    return signal[rand()%4];
}

float random(double start, double end)
{
    return (float)(start+(end-start)*rand()/(RAND_MAX+ 1.0));

}


int getResult(int num1,int num2,char signal)
{
    int referrence;
    switch(signal)
    {
    case '+':
        referrence=num1+num2;
        break;
    case '-':
        referrence=num1-num2;
        break;
    case '*':
        referrence=num1*num2;
        break;
    case '/':
        referrence=num1/num2;
        break;
    default:
        printf("运算符错误！\n");
    }
    return referrence;
}

float Generator()
{
    ofstream fout("TitleGenerator.txt");
    float get;
    float num1,num2,a;
    char signal;

    //srand((unsigned)time(NULL));
    signal=getSignal();
    num1=random(0,maxnum);
    num2=random(0,maxnum);

    if(signal=='-')
    {
        if(num1<num2)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }

    if(signal=='/')
    {
        if(num2==0)
        {
            num2+=1;

        }
    }
    cout<<setprecision(2)<<fixed<<num1<<signal<<setprecision(2)<<fixed<<num2<<"="<<endl;
    cin>>get;
    fout<<setprecision(2)<<num1<<signal<<setprecision(2)<<num2<<"="<<endl;

}
