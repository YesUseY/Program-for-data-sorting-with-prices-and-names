#include <iostream>
#include <fstream>

using namespace std;

struct prekes{
    string vardas;
    string pav;
    int kaina;
    };

int main()
{
    ifstream fin("data.txt");
    int a;
    fin >> a;
    prekes P[a];

    char eil[22];

    for (int i=0; i<a; i++){
        fin.ignore(80,'\n');
        fin >> P[i].vardas;
        fin.get(eil,22);
        P[i].pav = eil;
        fin >> P[i].kaina;
        cout << P[i].pav << " " << P[i].kaina << endl;
    }

    cout << endl;


    for (int i=0; i <a; i++) {

        for (int j=i; j<a; j++) {
            if (P[i].vardas > P[j].vardas) {
                swap(P[i], P[j]);
            }
            else if (P[i].vardas == P[j].vardas) {
                if (P[i].kaina < P[j].kaina){
                    swap(P[i], P[j]);
                }
            }
        }
    }
    ofstream fout("qweasd.txt");

    for (int i=0; i < a; i++) {
        fout << P[i].pav << " " << P[i].kaina << " " << P[i].vardas << endl;
    }


    return 0;
}
