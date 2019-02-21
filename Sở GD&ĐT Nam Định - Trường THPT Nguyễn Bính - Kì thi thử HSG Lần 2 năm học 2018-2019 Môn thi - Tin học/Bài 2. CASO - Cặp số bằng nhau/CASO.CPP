#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream f1,f2;
    f1.open("CASO.INP", ios::in);
    if (!(f1.is_open()))
    {
        //cout << "No results found for \"CASO.INP\";
    }
    else
    {
        f2.open("CASO.OUT", ios::out);
        int n;
        while(true)
        {
            f1 >> n;
            if (f1.eof())
                break;
            int A[n+1];
            for (int i=1; i<=n; i++)
            {
                f1 >> A[i];
            }
            int dem=0;
            for (int i=1; i<n; i++)
            {
                for (int j=i+1; j<=n; j++)
                {
                    if (A[j]==A[i])
                        dem++;
                }
            }
            f2 << dem << endl;
        }
        f2.close();
    }
    f1.close();
    return 0;
}
//Coder: JamesPham
