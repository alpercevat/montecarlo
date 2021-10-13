#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {
     double mypi, vol1, vol2, xin, yin, zin, hit;
     double xout, yout, zout;
	 int ntrials;
     cout << "Enter n: " << endl;
     cin >> ntrials;
     srand48(time(NULL));
     
     ofstream out("Sphere.dat");
     for (int i = 0; i < ntrials; i++) {
         double x = 2*(drand48()-.5);
         double y = 2*(drand48()-.5);
         double z = 2*(drand48()-.5);
         double r = sqrt(x*x + y*y + z*z);
         if (r < 1.0) {
             xin = x;
             yin = y;
             zin = z;
             hit += 1;
         } else {
             xout = x;
             yout = y;
             zout = z;
         }
         out << xin << " " << yin << " " << zin << " " 
			 << xout << " " << yout << " " << zout << endl;
     }
     out.close();
     mypi = 6 * (hit / ntrials);  //(?)
	 vol1 = (4/3.)*mypi;
	 vol2 = (4/3.)*M_PI;
     cout << "mypi: " << mypi << endl;
     cout << "Calculated volume: " << vol1 << endl;
     cout << "Actual volume    : " << vol2 << endl;
     cout << "Error            : " << "% " << (fabs(vol1-vol2)/vol2)*100. << endl;
}



//!"sphere.dat" u 1:2:3 w p ; replot "sphere.dat" u 4:5:6 w p



//! TERMİNALDE YAZILACAK KOMUT grafik için