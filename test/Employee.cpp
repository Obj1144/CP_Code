#include<iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;
class Name {
public:
	Name(const char*);
	void Changename(const char*);
	void display() { cout << name; }
private:
	char name[20];
};
class Employee {
public:
	Employee(const char*,const char*,const char*,const char*,const char*);
	void ChangeName(const char*);
	void Display();
private:
	Name name;
	char adr[20];
	char shi[20];
	char sheng[20];
	char post[20];
};

Employee::Employee(const char* n,const char* ad, const char* c, const char* cou, const char* p):name(n) {
//	strncpy_s(name, n, sizeof(n));
//	name[sizeof(name) - 1] = '\0';
	strncpy_s(adr, ad, sizeof(adr));
	adr[sizeof(adr) - 1] = '\0';
	strncpy_s(shi, c, sizeof(shi));
	shi[sizeof(shi) - 1] = '\0';
	strncpy_s(sheng, cou, sizeof(sheng));
	sheng[sizeof(sheng) - 1] = '\0';
	strncpy_s(post, n, sizeof(post));
	post[sizeof(post) - 1] = '\0';
}
void Employee::ChangeName(const char* newname){
	name.Changename(newname);
}
void Employee::Display() {
	name.display();
	cout << "/" << adr << "/" << shi << "/" << sheng << "/" << post << endl;
}
Name::Name(const char* na){
	strncpy_s(name, na, sizeof(name));
	name[sizeof(name) - 1] = '\0';
}
void Name::Changename(const char* newname){
	strncpy_s(name, newname, sizeof(name));
	name[sizeof(name) - 1] = '\0';
}
int main() {
	Employee em("Mark Brooks", "5 West St.", "Revere", "CA", "12290");
	em.Display();
	em.ChangeName("Richard Voss");
	em.Display();
}

