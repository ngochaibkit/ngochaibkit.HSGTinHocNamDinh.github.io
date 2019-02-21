#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f1,f2;
    f1.open("KSAN.INP", ios::in);
    if (!(f1.is_open()))
    {
        //cout << "No results found for \"KSAN.INP\"";
    }
    else
    {
        int n;
        f2.open("KSAN.OUT" ,ios::out);
        while(true)
        {
            f1 >> n;
            if (f1.eof())
            {
                break;
            }
            int A[n+1],B[n+1],P[n+1];
            for (int i=1; i<=n; i++)
            {
                f1 >> A[i];
            }
            for (int i = 1 ;i<=n; i++)
            {
                f1 >> B[i];
            }
            int m = 1;
            P[1]=B[1];
            for (int i= 2; i<=n; i++)
            {
                for (int j=1; j<i; j++)
                {
                    P[j]=P[j]-(A[i]-A[i-1]);
                }
                bool ConPhongTrong = false;
                for (int j=1; j<i; j++)
                {
                    if (P[j]<=0)
                    {
                        ConPhongTrong = true;
                        P[j]=B[i];
                        break;
                    }
                }
                if (ConPhongTrong==0)
                {
                    m++;
                    P[m]=B[i];
                }
            }
            f2 << m << endl;
        }
        f2.close();
    }
    f1.close();
    return 0;
}
//Coder: JamesPham
