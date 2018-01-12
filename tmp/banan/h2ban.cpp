#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string tran(char c)
{
    string r = "bananas";

    for ( int i = 0; i < 7; i++ )
    {
        int j = 6 - i;
        if ( c & 1 ) r[j] = r[j] - 'a' + 'A';
        c >>= 1;
    }

    return r;
}

string banan(string w)
{
    char c = w[0];
    if ( w.size() == 2 ) c = (char)stoi(w, 0, 16);
    else
    {
        if (0);
        else if ( c >= 'A' && c <= 'Z' ) c = char('A' + (101 - c));
        else if ( c >= 'a' && c <= 'z' ) c = char('a' + (127 - c));
    }

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

        if ( line.empty() ) continue;
        if ( line[0] == '@' ) break;
        if ( line[0] == '#' ) continue;

        stringstream is(line);

        bool nl = true;

        while (1)
        {
            string w;
            is >> w;
            if (!is) break;
            if ( !nl ) cout << ' '; else nl = !nl;
            cout << banan(w);
        }
        cout << '\n';

        //cout<<line<<'\n';
    }
}
