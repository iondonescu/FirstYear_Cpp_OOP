#include <iostream>
#include "Real.h"
#include "Complex.h"

using namespace std;

int main()
{
// //citire de la tastatura si afisare polinoame
//    cout <<"Citire de la tastatura polinoame cu coeficienti de tip diferit si afisare"<<endl;
//    
//    cout <<"\nCoeficienti reali\n";
//    int grad{0};
//    cout <<"Citeste gradul polinomului 1:";
//    cin >> grad;
//    Polinom <int> p1("Polinom 1",grad);
//    cout <<"Citeste coeficientii polinomului ( tip int ) "<< p1.get_name() <<endl;
//    cin>> p1;
//  
//    cout <<"Citeste gradul polinomului 2:";
//    cin >> grad;
//    Polinom<float> p2("Polinom 2",grad);
//    cout <<"Citeste coeficientii polinomului ( tip float )"<< p2.get_name() <<endl;
//    cin>> p2;
//    
//    cout<< "\nCele doua polinoame sunt:" <<endl;
//    cout << p1;
//    cout << p2;
//    cout<<"----------------------------"<<endl;
//    cout <<"\nCoeficienti complexi\n";
//    int grad_complex{0};
//    cout <<"Citeste gradul polinomului complex:";
//    cin >> grad_complex;
//    int arr_rc[100],arr_ic[100];
//    Polinom <Complex> p_complex(Complex(arr_rc,arr_ic,grad_complex,"Complex")); 
//    cout <<"Citeste coeficientii polinomului ( tip complex ) "<< p_complex.get_name() <<endl;
//    cin>> p_complex;
//    cout << "\n----------------------------\nPolinomul complex este:\n";
//    cout << p_complex;
// //end citire de la tastatura polinoame  cu coeficienti de tip diferit
//    cout<<"\n----------------------------\n"<<endl;
    
    cout<<"Operatii cu polinoame avand coeficienti predefiniti intregi"<<endl;
    int arr1[5] = {2,-3,-4,5,2};
    Polinom<int> p3("Primul polinom",4,arr1);
    cout << p3;
     int arr2[5] = {1,-2,3,1,-3};
    Polinom<int> p4("Al doilea polinom",4,arr2);
    cout << p4;
    cout<<endl;
    // supraincarcare operator () conversie
    int pol_conversie_int = p4;
    cout <<"\nConversie a tipurilor "<<pol_conversie_int<<endl;
    cout << p4;
    cout<<"----------------------------"<<endl;
    Polinom<int> p5;
    p5 = p3+p4;
    cout << p5;
    Polinom<int> p6;
    p6 = p3-p4;
    cout << p6;
    Polinom <int> p7;
    p7 = p3*p4;
    cout << p7<<endl;;
    cout<<"Operatii cu polinoame avand coeficienti predefiniti reali"<<endl;
    float arr3[5] = {2.1,-3.2,-4.2,5.1,2.1};
    Polinom<float> p8("Primul polinom <float>",4,arr3);
    cout << p8;
    
    float arr4[5] = {1.1,-2.2,3.2,1.1,-3.1};
    Polinom<float> p9("Al doilea polinom <float>",4,arr4);
    cout << p9;
    cout<<endl;
    float pol_conversie_float = p9;
    cout <<"\nConversie a tipurilor "<<pol_conversie_float<<endl;
    cout<<"----------------------------"<<endl;
    Polinom<float> p10;
    p10 = p8+p9;
    cout << p10;
    Polinom<float> p11;
    p11 = p8-p9;
    cout << p11;
    Polinom<float> p12;
    p12 = p8*p9;
    cout << p12<<endl;
    cout << "Operatori = si =="<<endl;
    cout<<"----------------------------"<<endl;
    cout << "Polinom 3 == Polinom 4 ?: " << (p3 == p4) << endl;
    Polinom <int> p13;
    p13 = p3;
    cout << p13;
    cout << "Polinom 3 == Polinom 13 ?: " << (p3 == p13) << endl;
    cout << "\nOperatori unari + si -"<<endl;
    cout<<"----------------------------"<<endl;
    Polinom <int> p14;
    p14=+p3;
    cout << p14;
    Polinom <int> p15;
    p15 = -p3;
    cout << p15<<endl;
    cout<<"Operatii cu polinoame avand coeficienti predefiniti tip complex"<<endl;
    int arr_real1[5] = {2,-3,2,-4,1};
    int arr_imag1[5] = {3,5,3,7,1};
    Polinom <Complex> p16 = Polinom<Complex>(Complex(arr_real1,arr_imag1,4,"Complex1"));
    cout << p16;
    
    int arr_real2[5] = {-3,1,1,4,2};
    int arr_imag2[5] = {9,7,3,6,5};
    Polinom <Complex> p17 = Polinom<Complex>(Complex(arr_real2,arr_imag2,4,"Complex2"));
    cout << p17;
    cout<<endl;
    
    cout<<"----------------------------"<<endl;
    Polinom <Complex> p18 = p16 + p17;
    //cout << p18; //eroare se pierd valorile dupa operatia de adunare
    Polinom <Complex> p19 = p16 - p17;
    Polinom <Complex> p20 = p16 * p17;
    //cin.get();
    return 0;
}