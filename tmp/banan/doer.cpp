#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

string l1 = "08 10 1e 0b 0d 06 b l h 33 16 06 34 Q 10 R V J 19 07 3a 0f 26 e h J 2c Q 0a 3a 14 45 3c 04 2d 3d N 12 13 L 3c 08 21 0d 37 0d 13 S e U\n";
//string l2 = "0c 10 B a n a n a n a";
string l2 = "0c 10 B a n a 56";
string l3 = "#00 0c\n 08 13 0c\n 00 08\n";

string c2h(char c)
{
    ostringstream os;
    os << hex << (int)(c);
    string r = os.str();
    if ( r.size() < 2 ) r = "0" + r;
    return r;
}

int main()
{
    int SZ = 256;
    for ( int i2 = 0; i2 < SZ; i2++ )
    {
        // for( int i3=16; i3<17; i3++ )
        //for( int i4=32; i4<SZ; i4++ )
        {
            string n;
            {
                ofstream of("z.h");
                n = l2 + ' ' + c2h(char(i2))
                    + ' ' + "16" + ' ' + "76" + '\n';

                of << l1 << n << l3;
            }

            system("./h2ban z.h > z.bn");
            system("./monkeyDo z.bn > z.r");
            {
                ifstream in("z.r");
                string s;
                bool ok = true;
                while (1)
                {
                    char a;
                    in.get(a);
                    if (!in) break;
                    s += a;
                    if ( a < 32 || a > 126 ) ok = false;
                }
                cout << s << '\n';

                //if( ok )
                {
                    ofstream fr("z.re2", ios::app);
                    fr << n << ' ' << s << '\n';
                }
            }
        }
        cout << "next " << i2 << '\n';
    }
}