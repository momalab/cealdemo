#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string c2h(char c)
{
    ostringstream os;
    os << hex << (int)(c);
    string r = os.str();
    if ( r.size() < 2 ) r = "0" + r;
    return r;
}

string tran(char c)
{
    string r = " ";

    if ( c >= 102 && c <= 127 ) return r + char('a' + (127 - c));
    if ( c > 75 && c <= 101 ) return r + char('A' + (101 - c));

    r = c2h(c);

    return ' ' + r;
}

string banan(string w)
{
    string d = w;
    transform(d.begin(), d.end(), d.begin(), ::tolower);
    if ( d != "bananas" ) { cout << "\n\n\n\n\nERROR need bananas\n"; return ""; }

    char c = '\0';
    for ( int i = 0; i < 7; i++ )
        c |= ( (w[6 - i] == d[6 - i]) ? 0 : 1 ) << i;

    return tran(c);
}

int main(int ac, char * av[])
{
    if ( ac < 2 ) return 0;

    ifstream in(av[1]);

    while (1)
    {
        string line;
        getline(in, line);
        if ( !in ) break;

        stringstream is(line);

        //string w1,w2;
        //is>>w1>>w2;
        //cout<<banan(w2)<<banan(w1);

        while (1)
        {
            string w;
            is >> w;
            if (!is) break;
            cout << banan(w);
        }
        cout << '\n';

        //cout<<line<<'\n';
    }
}
