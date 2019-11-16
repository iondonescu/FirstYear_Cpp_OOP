#include "Complex.h"
int arr_r[100];
int arr_i[100];

// copy contructor
Complex::Complex(const Complex& pol){
    //std::cout << "S-a apelat CONSTRUCTORUL DE COPIERE"<<std::endl;//verificare
    this->pol_name = pol.pol_name;
    this->grad_polinom = pol.grad_polinom;
    this->coef_real = pol.coef_real;
	this->coef_imag = pol.coef_imag;
};


Complex::Complex(){
    this->pol_name = pol_name;
    this->grad_polinom = grad_polinom;
    this->coef_real = coef_real;
	this->coef_imag = coef_imag;
    };

Complex::Complex(int *real,int *imag,int grad,std::string name){
    this->pol_name = name;
    this->grad_polinom = grad;
    this->coef_real = real;
	this->coef_imag = imag;
};


bool Complex::operator!=(const int a)
{
	return *get_coef_real() != a && *get_coef_imag() != a;
};

bool Complex::operator>(const int a)
{
	return *get_coef_real() > a && *get_coef_imag() > a;
};

bool Complex::operator>=(const int a)
{
	return *get_coef_real() >= a && *get_coef_imag() >= a;
};

bool Complex::operator<(const int a)
{
	return *get_coef_real() < a && *get_coef_imag() < a;
};


void Complex::operator=(const int a){
    this->set_coef_real(nullptr);
    this->set_coef_imag(nullptr);
}
std::ostream& operator<<(std::ostream& stream,Complex& c)
{
   stream << c.pol_name <<": ";
        for (int i = c.get_grad();i >= 0;i--)
                    if (i != 0){
                        stream << "("<<*(c.coef_real+i);
                        if (*(c.coef_imag+i)>0) stream << "+"<< *(c.coef_imag+i) << "i"<<")"<<"X^"<<i<<"+";
                        else stream << *(c.coef_imag+i) << "i"<<")"<<"X^"<<i<<"+";
                    }
                    else {
                        stream << "("<<*(c.coef_real+i);
                        if (*(c.coef_imag+i)>0) stream << "+" << *(c.coef_imag+i) << "i"<<")";
                        else stream <<*(c.coef_imag+i) << "i"<<")";
                    }                
	return stream;
};

std::istream& operator>>(std::istream& stream,Complex& c){
   for (int i = c.get_grad();i>=0;i--) {
        std::cout << " Coeficient X^" << i <<" real: ";
        std::cin >> arr_r[i];
        std::cout << " Coeficient X^" << i <<" imaginar: ";
        std::cin >> arr_i[i];
    };
    c.set_coef_real(arr_r);
    c.set_coef_imag(arr_i);
	return stream;
};

Complex& Complex::operator=(const Complex& pol){
    this->pol_name = pol.pol_name;
    this->grad_polinom = pol.grad_polinom;
    this->coef_real =pol.coef_real;
    this->coef_imag = pol.coef_imag;
	return *this;
};

Complex Complex:: operator+(Complex pol){
    for(int i=0;i<=4;i++){
        arr_r[i] = *(this->get_coef_real()+i) + *(pol.coef_real+i);
        arr_i[i] = *(this->get_coef_imag()+i) + *(pol.coef_imag+i);
    };
    Complex aux = Complex(arr_r,arr_i,4,"Polinom_adunare");
    return aux;
};

Complex Complex:: operator-(Complex pol){
    for(int i=0;i<=4;i++){
        arr_r[i] = *(this->get_coef_real()+i) - *(pol.coef_real+i);
        arr_i[i] = *(this->get_coef_imag()+i) - *(pol.coef_imag+i);
    };
    Complex aux = Complex(arr_r,arr_i,4,"Polinom_scadere");
    return aux;
};

Complex Complex:: operator*(Complex pol){
    for (int i=0;i<=8;i++) {
        arr_r[i] = 0;
        arr_i[i] = 0;
    }
    for(int i = 0;i <= 4;i++)
        for (int j = 0;j <= 4;j++){
        arr_r[i+j] = (*(this->get_coef_real()+i))*(*(pol.coef_real+j))-(*(this->get_coef_imag()+i)*(*(pol.coef_imag+j)));
        arr_i[i+j] = (*(this->get_coef_real()+i))*(*(pol.coef_imag+j))+(*(this->get_coef_imag()+i)*(*(pol.coef_real+j)));
    };
    Complex aux = Complex(arr_r,arr_i,8,"Polinom_inmultire");
    return aux;
};
Complex::~Complex(){};
