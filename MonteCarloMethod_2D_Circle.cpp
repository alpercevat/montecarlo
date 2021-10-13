#include <iostream>
#include <fstream>
#include <stdlib.h>      // Rastgele sayı üreten drand48 ile ilgili bir kütüphane
#include <math.h>

using namespace std;

int main()  {

    double area, xin, yin, xout, yout, hit;
    int ntrials;
    cout << "Enter n: " << endl;
    cin >> ntrials;
    //srand48(time(NULL));   //Rastgele sayı için başlangıç komutu   //Bu komutu iptal ederek aynı rastgele sayı seti ile çalışabiliriz.

    for (int i=0; i < 10; i++){   //ilk 10 sayıyı görme amaçlı bastırıyoruz.
        printf("Random Number #%d: %f\n" , i , drand48());   //Drand48 rastgele sayı üretir 0 ile 1 arasında

    }


    bool in;
    ofstream out("Circle.dat");  //verilerin yazılacağı dosya
    for(int i=0; i<ntrials; i++) {
        double x = 2*(drand48()-.5);    // !0 ile 1 arasında gelen random sayıyı bu komut sayesinde -1 ile +1 arasına genişletiriz. Burası sınavda değiştirilebilir.
        double y = 2*(drand48()-.5);    // !0 ile 1 arasında gelen random sayıyı bu komut sayesinde -1 ile +1 arasına genişletiriz. Burası sınavda değiştirilebilir.
        double r = sqrt(x*x + y*y);

        if (r < 1.0) {   // ! eğer r 1'den küçükse hit'i 1 arttır ve yollanan nokta içerdedir.
            hit = hit + 1;
            in = true;
            //xin = x;
            //yin = y;
        }   else{   //! değilse arttırma ve yollanan nokta dışardadır.
            in = false;
            //xout = x;
            //yout = y;

        }
        out << x << " " << y << " " << in <<endl;   //! Circle.dat dosyasına x ve y değerini yazdır.
        //out << xin << " " << yin << " " << xout << " " << yout << endl;
    }

    out.close();
    area = 4*(hit/ntrials);
    cout << "Area: " << area << endl;
    cout << "Actual area: " << M_PI << endl;
    cout << "Error: " << "%" << (fabs(M_PI-area)/M_PI)*100. << endl;


}

// ! plot "Circle.dat" using 1:($3==1?$2:1/0) w p pt 3 ; replot "Circle.dat" using 1:($3==0?$2:1/0) w p pt 7

//! TERMİNALDE YAZILACAK KOMUT Grafik için