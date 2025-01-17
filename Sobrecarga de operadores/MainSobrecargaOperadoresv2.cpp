#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <Math.h>
using namespace std;
class Pareja {

private:
    int a, b;

public:
    // constructor base
    Pareja() : a(0), b(0) {}

    // constructor parametrizado
    Pareja(const int a,const int b) {
	this->a = a;
	this->b = b;
    }

    // constructor de copia
    Pareja(const Pareja&);

    // operadores miembros
    Pareja& operator + (const Pareja &p);
    Pareja& operator +=(const Pareja &p);
    Pareja& operator - (const Pareja &p);
    Pareja& operator -=(const Pareja &p);
    Pareja& operator * (const Pareja &p);
    Pareja& operator / (const Pareja &p);
    Pareja& operator = (const Pareja &p);
	Pareja& operator % (const Pareja &p);
    Pareja& operator ++();
    Pareja& operator --();
    bool    operator ==(const Pareja &p) const;
    bool    operator !=(const Pareja &p) const;
    bool    operator >=(const Pareja &p) const;
    bool    operator <=(const Pareja &p) const;
    bool    operator <(const Pareja &p) const;
    bool    operator >(const Pareja &p) const;
    bool    operator ||(const int) const;

    // operadores no miembros
    friend ostream& operator << (ostream &o,const Pareja &p);
    friend istream& operator >> (istream &o, Pareja &p);
};


// implementacion de los operadores para la clase Pareja
//....................................
Pareja::Pareja(const Pareja &p)
{
    *this=p;
}
//....................................
//Implementado por: Angel Castillo
//Funcion que determina +=  de dos clases mediante el modulo
//12-jun-2020
//....................................

Pareja& Pareja::operator +=(const Pareja &p)
{
    this->a += p.a;
    this->b += p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator + (const Pareja &p)
{
    this->a += p.a;
    this->b += p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator - (const Pareja &p)
{
    this->a -= p.a;
    this->b -= p.b;
    return *this;
}
//....................................
//....................................
//Implementado por: Angel Castillo
//Funcion que determina -=  de dos clases mediante el modulo
//12-jun-2020
//....................................

Pareja& Pareja::operator -=(const Pareja &p)
{
    this->a -= p.a;
    this->b -= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator * (const Pareja &p)
{
    this->a *= p.a;
    this->b *= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator / (const Pareja &p)
{
    if (p.a != 0) this->a /= p.a;
    if (p.b != 0) this->b /= p.b;
    return *this;
}
//....................................
Pareja& Pareja::operator = (const Pareja &p)
{
    if(this!=&p){ //Comprueba que no se est� intentanod igualar un objeto a s� mismo
        if (p.a != 0) this->a = p.a;
        if (p.b != 0) this->b = p.b;
    }
    return *this;
}
//....................................
//Implementado por: Angel Castillo
//Funcion que determina % de dos clases mediante el modulo
//9-jun-2020
//....................................

Pareja& Pareja::operator % (const Pareja &p)
{
        if (p.a != 0) this->a % p.a;
        if (p.b != 0) this->b % p.b;
    return *this;
}

//....................................
Pareja& Pareja::operator ++ ()
{
    this->a ++;
    this->b ++;
    return *this;
}
//....................................
//Implementado por: Angel Castillo
//Funcion que determina != de dos clases mediante el modulo
//9-jun-2020
//....................................

bool Pareja::operator != (const Pareja &p) const
{
    return this->a == p.a && this->b == p.b;
}

//....................................
bool Pareja::operator == (const Pareja &p) const
{
    return this->a == p.a && this->b == p.b;
}
//....................................
//Implementado por: Cristopher Chicaiza
//Funcion que determina >= de dos clases mediante el modulo cast de int a float
//8-jun-2020
//....................................

bool Pareja::operator >= (const Pareja &p) const
{
	return float((sqrt(a*a+b*b)))  >= float((sqrt(p.a*p.a+p.b*p.b)));
}
//....................................
//Implementado por: Angel Castillo
//Funcion que determina <= de dos clases mediante el modulo
//10-jun-2020
//....................................
bool Pareja::operator <= (const Pareja &p) const
{
	return float((sqrt(a*a+b*b)))  <= float((sqrt(p.a*p.a+p.b*p.b)));
}
//Implementado por: Cristopher Chicaiza
//Funcion que determina < de dos clases mediante el modulo cast de int a float
//9-jun-2020
//....................................

bool Pareja::operator < (const Pareja &p) const
{
	return float((sqrt(a*a+b*b)))  < float((sqrt(p.a*p.a+p.b*p.b)));
}
//Implementado por: Cristopher Chicaiza
//Funcion que determina > de dos clases mediante el modulo cast de int a float
//10-jun-2020
//....................................

bool Pareja::operator > (const Pareja &p) const
{
	return float((sqrt(a*a+b*b)))  > float((sqrt(p.a*p.a+p.b*p.b)));
}

//Implementado por: Cristopher Chicaiza
//Funcion que realiza una resta tipo -- a una clase
//11-jun-2020
//....................................
Pareja& Pareja::operator -- ()
{
    this->a --;
    this->b --;
    return *this;
}

//Implementado por: Cristopher Chicaiza
//Funcion que determina si existe un elemento en una clase
//12-jun-2020
//....................................

bool Pareja::operator || (const int comparar) const
{
    return a==comparar||b==comparar;
}



// implemetaci�n de operadores no miembros
ostream& operator << (ostream &o,const Pareja &p)
{
    o << "(" << p.a << ", " << p.b << ")";
    return o;
}

istream& operator >> (istream &i, Pareja &p)
{
    cout << "Introducir valores para ( a, b) :";
    i >> p.a >> p.b;
    i.ignore();
    return i;
}
int main(int argc, char** argv) {
    Pareja A(150,  75);
    Pareja B(100, 15);
    Pareja C;
    bool a;
	cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "........................." << endl;
    C = A + B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
    
    C = A += B;
    cout << "A += " << A << "\n";
    cout << "C += " << C << endl;
    cout << "........................." << endl;
	C = A - B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
        C = A -= B;
    cout << "A -= " << A << "\n";
    cout << "C -= " << C << endl;
    cout << "........................." << endl;
 	C = A * B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;
	C = A % B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;     
 	C = A / B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;  
	++C;
    cout << "C = " << C << endl;
    cout << "A != B " << ( (A!=B) ? "Si": "No" );
    cout << "........................." << endl;
    ++C;
    cout << "C = " << C << endl;
    cout << "A == B " << ( (A==B)?"  True \n": "  False  \n");
    cout << "........................." << endl;
    C = A = B = ++C;
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "B = " << B << endl;
    cout << "........................." << endl;
    Pareja D (2,1);
    Pareja E (2,1);
    cout << "D = " << D << "\n";
    cout << "E = " << E << "\n";
    a=D>=E;
    cout << "Es D >= E ?	R: " << a << "	(siendo 0 = falso y 1 = verdadero)\n";
    cout << "........................." << endl;
    a=D<=E;
    cout << "Es D <= E ?	R: " << a << "	(siendo 0 = falso y 1 = verdadero)\n";
    cout << "........................." << endl;
    a=D<E;
    cout << "Es D < E ?	R: " << a << "	(siendo 0 = falso y 1 = verdadero)\n";
    cout << "........................." << endl;
    a=D>E;
    cout << "Es D > E ?	R: " << a << "	(siendo 0 = falso y 1 = verdadero)\n";
    cout << "........................." << endl;
    --D;
    cout << "D = " << D << "\n";
    a= D||0;
    cout << "Existe un elemento con valor 0 en D ?  	R: " << a << "	(siendo 0 = falso y 1 = verdadero)\n";
    cout << "........................." << endl;
	return 0;
}
