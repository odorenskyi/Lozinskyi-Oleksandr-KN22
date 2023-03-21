
int SampleAddInt(int a, int b)
{int c;
    if(a+3<=b)
        c=1;
    else
        c=0;
    return c;
}
void name()
{
    system("1251");
    system("cls");
    setlocale(LC_ALL, "ukr");
cout <<"\n---------------------------------------\n"
     <<"|Lozinskiy Olexandr, CNTU,opd@kntu.kr.ua|\n"
     <<"|Лозінський Олександр, ЦНТУ,opd@kntu.kr.ua|\n"
     <<"\n------"<<(char)169<<"All Rights Reserved-------\n\n";
}
int calloz(int x,int z)
{
    int S=SampleAddInt(x,z);
    cout<<"Десяткова система числення:\n ";
    cout<<"х= "<<dec<<x<<endl;
    cout<<"z= "<<dec<<z<<endl;
    cout<<"S= "<<dec<<S<<endl;
    cout<<"Шістандцяткова система числення: \n ";
    cout<<"х=0x"<<hex<<x<<endl;
    cout<<"z=0x"<<hex<<z<<endl;
    cout<<"S=0x"<<hex<<S<<endl;


    return 0;
}
