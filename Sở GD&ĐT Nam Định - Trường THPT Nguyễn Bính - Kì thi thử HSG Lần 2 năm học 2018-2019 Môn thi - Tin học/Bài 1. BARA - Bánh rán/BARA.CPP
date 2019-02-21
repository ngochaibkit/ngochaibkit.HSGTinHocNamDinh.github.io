#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream f1,f2;
    f1.open("BARA.INP", ios::in);
    if (!(f1.is_open()))
    {
        //cout << "No results found for \"BARA.INP\"";
    }
    else
    {
        int n, k;
        f2.open("BARA.OUT",ios::out);
        while(true)
        {
            f1 >> n >> k;
            if (f1.eof())
                break;
            //Neu so luong banh co it hon luong banh max co the ran thi thoi gian can ran luon bang 10'
            if (n<=k)
                f2 << 10 << endl;
            else if (n%k==0) //Neu luong banh cho chia het cho max ran
                f2 << (n/k)*10 << endl;
            else
            {
                double thuong = (double)n/k;
                int pre = (int)thuong, next = pre+1;
                double TB=(pre+next)/2.0;
                if (thuong<=TB)
                    f2 << pre*10+5 << endl;
                else f2 << next*10 << endl;
            }
        }
        f2.close();
    }
    f1.close();
    return 0;
}
//Coder: JamesPham
