#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
private:
// atribute
    std::string pol_name;// numele polinomului
    int grad_polinom;   // gradul polinomului
    int *coef_real; // pointer catre coeficientii reali
    int *coef_imag; // pointer catre coeficientii imaginar
public:
// metode
    void set_name(std::string name){pol_name = name;};
    std::string get_name(){ return pol_name;};
    void set_grad(int grad){grad_polinom = grad;};
    int get_grad(){return grad_polinom;};
    void set_coef_real(int arr1[]){coef_real = arr1;};
    void set_coef_imag(int arr2[]){coef_imag = arr2;};
    int *get_coef_real(){
        return this->coef_real;
        };
    int *get_coef_imag(){
        return this->coef_imag;
        };
    //constructori
    Complex();
    Complex(const Complex& pol);
    Complex(int *real,int *imag,int grad,std::string name);
    ~Complex();
    friend std::ostream& operator<<(std::ostream& stream,Complex& c);
    friend std::istream& operator>>(std::istream& stream,Complex& c);
    Complex& operator=(const Complex& pol);
    Complex operator+(Complex pol);
    Complex operator-(Complex pol);
    Complex operator*(Complex pol);
    bool operator!=(const int nr);
    bool operator>(const int nr);
    bool operator>=(const int nr);
    bool operator<(const int nr);
    void operator=(const int nr);
    Complex operator-();
    };

#endif // COMPLEX_H
