#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>

#define NU 100000

using namespace std;
int c  = 0; int stop = 0; int step = 15000;
int NUM = NU;
vector <int> a;
vector <int> b;

void quickSort(int l, int r)
{
    int x = a[l + (r - l) / 2];

    int i = l;
    int j = r;

    while(i <= j)
    {
        while(a[i] < x) {i++;}
        while(a[j] > x) {j--;}
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    if (i<r)
                quickSort(i, r);

    if (l<j)
        quickSort(l, j);
}


int main()
{
    ofstream fout("cppstudio.txt");

    a.reserve(NU+5);
     b.reserve(NU+5);

    cout << " start massiv base" << endl;

    for (int i = 0; i < NUM; i++)
    {
        a.push_back  (i);
        b.push_back  (i);
        ///cout << a[i]<< " ";

    }
    cout << endl;
    ///cout.precision(5);
    cout << "l"<< endl;
    random_shuffle(b.begin(), b.end());

    do
    {
        stop =0; /// Сортировка
        for (int i=0; i < NUM; i++ )
        {
            a[i] = b [i];
        }


        LARGE_INTEGER timerFrequency, timerStart, timerStop;
        QueryPerformanceFrequency(&timerFrequency);
        QueryPerformanceCounter(&timerStart);


        //for (int i = 0; i < NUM; i++) {cout << a_old[i]<< ""; }
        quickSort(0, NUM-1);
        //for (int i = 0; i < NUM; i++) {cout << a_old[i]<< ""; }
        //cout << endl;

        QueryPerformanceCounter(&timerStop);
        double const t( static_cast<double>( timerStop.QuadPart -
        timerStart.QuadPart ) / timerFrequency.QuadPart );

       /// cout << "Time is " << t << " seconds." << endl;
        cout << "c  " << c << " t = " << t << endl;
        fout << t << "    " << c*step << endl;

//        NUM = NUM /2;

    for (int y = 0; y < step; y++) {
    for (int i = 0; i < (NUM - 1) ; i++ )
    {
        if (b[i] > b[i+1])
        {
            swap (b[i], b[i+1]); stop = 1;
        }
    }
    }
    c++;

    } while (stop ==1 );

    fout.close();

    return 0;
}
