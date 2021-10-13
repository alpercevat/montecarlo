#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double func(double x);

int main () {
     double area, xin, yin, xout, yout, hit;
     int ntrials; 
     hit += 1;
	 cout << "Enter n:" << endl;
	 cin >> ntrials;
     srand48(time(NULL));

	 bool in;
     ofstream out("arbitrary.dat");
     for (int i = 0; i < ntrials; i++) {
         double x = drand48();    //! BURASI DEĞİŞEBİLİR
         double y = 4*drand48();  //! BURASI DEĞİŞEBİLİR
		 double fx = func(x);
		 if (y < fx) { 
             xin = x;
             yin = y;
             hit += 1;
			 in = true;
         } else {
             xout = x;
             yout = y;
			 in = false;
         }
		 //out << xin << " " << yin << " " << xout << " " << yout << endl;
		 out << x << " " << y << " " << in << endl;
	 }
	 out.close();
	 area = 4 * (hit / ntrials);     //! BURASI DEĞİŞEBİLİR
	 cout << "Area: " << area << endl;
	 cout << "Actual area: " << M_PI << endl;
	 cout << "Fractional error: " << fabs( M_PI - area) << endl;
}

double func(double x)
{
    double value;
    value = 4. / (1.+x*x); //! BURASI DEĞİŞEBİLİR
    return value;
}
