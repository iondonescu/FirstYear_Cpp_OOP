#ifndef REAL_H
#define REAL_H

#include <string>
#include <iostream>
#include <typeinfo>
#include "Complex.h"


/* variabila globala array coeficienti. Globala pt ca avem pointer catre coeficienti si altfel s-ar pierde */
template <typename T>
T arr[100];

template <class T>
class Polinom  {

private:
// atribute
    std::string pol_name;// numele polinomului
    int grad_polinom;   // gradul polinomului
    T *coef{nullptr}; // pointer catre coeficientii polinomului
public:
// metode
    void set_name(std::string name){pol_name = name;};
    std::string  get_name() { return pol_name;};
    void set_grad(int grad) {grad_polinom = grad;};
    int get_grad() {return grad_polinom;};
    void set_coef(T arr1[]){coef = arr1;};
    T *get_coef(){
        return this->coef;
        };
// constructori
    Polinom();
    Polinom(std::string pol_name);//obiecte create in urma operatiilor +,-,*
    Polinom(std::string pol_name,int grad_polinom);//obiecte create cu citire a coeficientilor de la tastatura
    Polinom(std::string pol_name,int grad_polinom,T *coef);//obiecte cu coeficienti predefiniti
    Polinom(const Polinom<T>& pol); //constructor de copiere
    Polinom(T value);
    

// destructor
~ Polinom();

//operatori
    Polinom<T>& operator=(const Polinom<T>& pol);
    Polinom<T> operator+(Polinom<T> pol);
    Polinom<T> operator-(Polinom<T> pol);
    Polinom<T> operator*(Polinom<T> pol);
    bool operator == (const Polinom<T> pol);
//overloaded unary operators
    Polinom<T> operator+();
    Polinom<T> operator-();
//conversie a tipurilor    
    operator T();
};

//Definire constructori
template <class T>
Polinom<T>::Polinom(){
    //std::cout << "Constructor fara argumente"<<std::endl;
    this->pol_name = pol_name;
	this->grad_polinom = grad_polinom;
    this->coef = coef;
};

template <class T>
Polinom<T>::Polinom(std::string pol_name){
 //std::cout << "S-a apelat constructorul cu un argument"<<std::endl;//verificare
    this->pol_name = pol_name;
};

template <class T>
Polinom<T>::Polinom(std::string pol_name, int grad_polinom){
   //std ::cout<<"S-a apelat constructorul cu 2 argumente"<< std::endl;//verificare
   this->pol_name = pol_name;
   this->grad_polinom = grad_polinom;
};

template <class T>
Polinom<T>::Polinom(std::string pol_name,int grad_polinom,T *coef){
    //std::cout << "S-a apelat constructorul cu 3 argumente"<<std::endl;//verificare
    this->pol_name = pol_name;
    this->grad_polinom = grad_polinom;
    this->coef = coef;
};


template <class T>
Polinom<T>::Polinom(const Polinom<T>& pol){
    //std::cout << "S-a apelat copy constructor"<<std::endl;//verificare
    this->pol_name = pol.pol_name;
    this->grad_polinom = pol.grad_polinom;
    this->coef = pol.coef;
}

template <class T>
Polinom<T>::Polinom(T value){
    if(typeid(T) != typeid(int) || typeid(T) != typeid(float)){
        this->pol_name = get_name();
        this->grad_polinom = get_grad();
        this->coef = &value;
    }
    else {
        this->pol_name = "Conversie";
        this->grad_polinom = 0;
        this->coef = &value;
    }
}
//destructor
template<class T>
Polinom<T>::~Polinom()
{
}

//operator de afisare
template <class T>
std::ostream& operator<<(std::ostream& stream, Polinom<T>& pol){
        T *aux = pol.get_coef();
        if(typeid(T) == typeid(int) || typeid(T) == typeid(float)){
        stream << pol.get_name() <<":   ";
        for (int i = pol.get_grad();i >= 0;i--) {
                if (i == pol.get_grad()) stream <<*(aux+i) << "X^" << i;
                else {
                    if (i == 0 && *(aux + i) != 0)  {if (*(aux+i) > 0) stream << "+" <<*(aux+i);
                                    else stream <<*(aux+i);}
                    else if (*(aux+i) >= 0 ) stream << "+"<<*(aux+i) << "X^" << i;
                            else if (*(aux+i) < 0) stream << *(aux+i) << "X^"<< i;
                }
            }
        }
        
        else stream << *(aux);
        std::cout <<std::endl;
        return stream;
}

// operatorul de citire de la tastatura
template <class T>
std::istream& operator>>(std::istream& stream, Polinom<T>& pol)
{
    T *aux = pol.get_coef();
    if(typeid(T) == typeid(int) || typeid(T) == typeid(float)){
        for (int i = pol.get_grad();i>=0;i--) {
            std::cout << " Coeficient X^" << i <<": ";
            std::cin >> arr<T> [i];
        };
        pol.set_coef(arr<T>);
    }
    else std::cin >> *(aux);
	return stream;
}

// operatorul de atribuire

template<class T>
Polinom<T>& Polinom<T>::operator = (const Polinom<T>& pol) {
        this->pol_name = pol.pol_name;
        this->grad_polinom = pol.grad_polinom;
        this->coef = pol.coef;
        return *this;
};

template <class T>
Polinom<T> Polinom<T>:: operator+(Polinom<T> pol){
    T *aux = pol.coef;
     Polinom<T> pol_adunare;
    if(typeid(T) == typeid(int) || typeid(T) == typeid(float)){
        for(int i=0;i<=4;i++) arr<T>[i] = *(this->get_coef()+i) + *(aux+i);
        pol_adunare.set_name("Polinom_adunare");
        pol_adunare.set_grad(4);
        pol_adunare.set_coef(arr<T>);
        return pol_adunare;
    }
    else {
        pol_adunare.set_name("Polinom_adunare");
        pol_adunare.set_grad(4);
        T aux1 = *(this->coef) + *aux;
        pol_adunare.coef = &aux1;
        std::cout << pol_adunare<<std::endl;
        return pol_adunare;
    }
};

template <class T>
Polinom<T> Polinom<T>:: operator-(Polinom<T> pol){
    Polinom<T> pol_scadere;
    T *aux = pol.get_coef();
    if(typeid(T) == typeid(int) || typeid(T) == typeid(float)){
        for(int i=0;i<=4;i++) arr<T>[i] = *(this->get_coef()+i) - *(aux+i);
        pol_scadere.set_name("Polinom_scadere");
        pol_scadere.set_grad(4);
        pol_scadere.set_coef(arr<T>);
        return pol_scadere;
        }
     else {
        Polinom<T> pol_scadere;
        pol_scadere.set_name("Nume");
        pol_scadere.set_grad(4);
        T rhs = *(pol.coef);
        T lhs = *(this->coef);
        T aux1 = lhs - rhs;
        pol_scadere.coef = &aux1;
        std::cout << pol_scadere<<std::endl;
        return pol_scadere;
    }
};

template <class T>
Polinom<T> Polinom<T>:: operator*(Polinom<T> pol){
    Polinom<T> pol_inmultire;
    T *aux1 = this->get_coef();
    T *aux2 = pol.get_coef();
    if(typeid(T) == typeid(int) || typeid(T) == typeid(float)){
        for (int i=0;i<=8;i++) arr<T>[i] = 0;
        for(int i=0;i<=4;i++)
            for (int j=0;j<=4;j++)
            arr<T>[i+j] = arr<T>[i+j] + (*(aux1+i)) * (*(aux2+j));
        pol_inmultire.set_name("Polinom_inmultire");
        pol_inmultire.set_grad(8);
        pol_inmultire.set_coef(arr<T>);
        return pol_inmultire;
    }
    else {
        pol_inmultire.set_name("Polinom_inmultire");
        pol_inmultire.set_grad(8);
        T aux =  (*(aux1))*(*(aux2));
        pol_inmultire.coef = &aux;
        std::cout << pol_inmultire<<std::endl;
        return pol_inmultire;
    }
};

template <class T>
bool Polinom<T>::operator==(Polinom<T> pol)
{
    std::string value = "true";
    T *aux1 = this->get_coef();
    T *aux2 = pol.get_coef();
     for (int i=0;i<=4;i++)
        if ((*(aux1+i)) != (*(aux2+i))) value = "false";
    if (this->get_grad() != pol.get_grad()) value = "false";
	if (value == "true") return true;
    else return false;
};

//+ unar
template <class T>
 Polinom<T> Polinom<T>::operator+ () {
    Polinom<T> pol_plus;
    T *aux = this->get_coef();
        for (int i=0;i<=4;i++)
        arr<T>[i] = (*(aux+i));
    pol_plus.set_name("Polinom_plus");
    pol_plus.set_grad(4);
    pol_plus.set_coef(arr<T>);
    return pol_plus;
};

//- unar
template <class T>
 Polinom<T> Polinom<T>::operator- () {
        Polinom<T> pol_invers;
        T *aux = this->get_coef();
     if(typeid(T) == typeid(int) || typeid(T) == typeid(float)){
            for (int i=0;i<=4;i++)
            arr<T>[i] = -(*(aux+i));
        pol_invers.set_name("Polinom_invers");
        pol_invers.set_grad(4);
        pol_invers.set_coef(arr<T>);
         return pol_invers;}
     else{
        pol_invers.coef = aux;
        return pol_invers;
     }
};

template<class T> 
    Polinom<T>::operator T()  { 
        T *aux = this->get_coef();
    return *(aux);  }
    
    
#endif // REAL_H
