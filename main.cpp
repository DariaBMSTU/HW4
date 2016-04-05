#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <clocale>

using namespace std;

class Student{
private:
    char *firstName; // Закрытые поля данных. Доступ к ним осуществляется с помощью открытых методов
    char *lastName;
    char *familyName;
    int birth_date;
    char *adress;
    char *phone_number;
    char *faculty;
    int year;

public: // все, что в public, доступно всей программе

    //конструктор по умолчанию, принимает на вход арг типа void
    Student(char fName=NULL, char lName=NULL, char famName=NULL, int bDate=NULL, char adr=NULL, char num=NULL, char fclty=NULL, int course=NULL); //конструктор по умолчанию
    Student(char *fName, char *lName, char *famName, int bDate, char *adr, char *num, char *fclty, int course); // Конструктор
    Student(const Student&); //конструктор копирования

    void set_firstName(char *tmp); //метод
    const char *get_firstName() const; //метод

    void set_lastName(char *tmp);
    const char *get_lastName() const;

    void set_familyName(char *tmp);
    const char *get_familyName() const;

    void set_birth_date(int tmp);
    const int get_birth_date();

    void set_adress(char *tmp);
    const char *get_adress()const;

    void set_phone_number(char *tmp);
    const char *get_phone_number()const;

    void set_faculty(char *tmp);
    const char *get_faculty()const;

    void set_year(int tmp);
    const int get_year();

    const void show();
    ~Student(); // деструктор

};

Student::Student(char *fName, char *lName, char *famName, int bDate, char *adr, char *num, char *fclty, int course)
//:firstName(fName)// если firstName - поле const
{
    set_firstName(fName);
    set_lastName(lName);
    set_familyName(famName);
    set_birth_date(bDate);
    set_adress(adr);
    set_phone_number(num);
    set_faculty(fclty);
    set_year(course);

}

Student::~Student()
{
    delete(firstName);
    delete(lastName);
    delete(familyName);
    delete(adress);
    delete(phone_number);
    delete(faculty);
}

void Student::set_firstName(char *tmp)
{
    //delete []firstName; //если студент сменил имя, нужно удалить предыдущее имя
    firstName= new char[strlen(tmp)];
    strcpy(firstName, tmp);
}

void Student::set_lastName(char *tmp)
{
    //delete [] lastName;
    lastName=new char[strlen(tmp)];
    strcpy(lastName, tmp);
}

void Student::set_familyName(char *tmp)
{
    //delete [] familyName;
    familyName=new char[strlen(tmp)];
    strcpy(familyName, tmp);
}

void Student::set_birth_date(int tmp)
{
    birth_date = tmp;
}

void Student::set_adress(char *tmp)
{
    //delete [] adress;
    adress=new char[strlen(tmp)];
    strcpy(adress, tmp);
}

void Student::set_phone_number(char *tmp)
{
    //delete [] phone_number;
    phone_number=new char[strlen(tmp)];
    strcpy(phone_number, tmp);
}

void Student::set_faculty(char *tmp)
{
    //delete [] faculty;
    faculty=new char[strlen(tmp)];
    strcpy(faculty, tmp);
}

void Student::set_year(int tmp)
{
    year = tmp;
}

const char *Student::get_firstName()const // const вначале нужен, чтобы пользователь не смог поменять метод get_firstName
{                                         // const в конце нужен, потому что конструктор копирования принимает только
    return firstName;                     // константную ссылку
}

const char *Student::get_lastName()const
{
    return lastName;
}

const char *Student::get_familyName()const
{
    return familyName;
}

const int Student::get_birth_date()
{
    return birth_date;
}

const char *Student::get_adress() const
{
    return adress;
}

const char *Student::get_phone_number()const
{
    return phone_number;
}

const char *Student::get_faculty()const
{
    return faculty;
}

const int Student::get_year()
{
    return year;
}

//конструктор копирования
/*Student::Student(const Student &stud) //почему конструктор копирования принимает const ссылку
{
    set_firstName(stud.get_firstName());
    set_lastName(stud.get_lastName());
    set_familyName(stud.get_familyName());
    set_birth_date(stud.get_birth_date());
    set_adress(stud.get_adress());
    set_phone_number(stud.get_phone_number());
    set_faculty(stud.get_faculty());
    set_year(stud.get_year());
}*/

int N = 5;

void Students_one_faculty(Student **data, char *facultet) //список студентов заданного факультета
{
    for(int i=0; i<N; i++)
    {
        if (strcmp(data[i]->get_faculty(),facultet)==0)
        {
            data[i]->show();
            cout<<"\n";
        }
    }
}

void Students_one_faculty_and_year(Student **data, char *facultet, int curs) //список студентов для каждого факультета и курса
{
    for(int i=0; i<N; i++)
    {
        if (strcmp(data[i]->get_faculty(),facultet)==0 && (data[i]->get_year())==curs)
        {
            data[i]->show();
            cout<<"\n";
        }
    }
}

void Students_born_after(Student **data, int date) //список студентов, родившихся после заданного года
{
    for(int i=0; i<N; i++)
    {
        if (data[i]->get_birth_date()>date)
        {
            data[i]->show();
            cout<<"\n";
        }
    }
}

const void Student::show()
{
    printf("Name: %s %s %s\nDate of birth: %d \nAdress: %s \nPhone number: %s \nFaculty: %s \nStudy year: %d \n",
        get_firstName(), get_lastName(), get_familyName(), get_birth_date(), get_adress(), get_phone_number(), get_faculty(), get_year());
}




int main()
{
    setlocale(LC_ALL, "Rus");

    Student **data;
    data = new Student*[N]; // массив объектов
    data[0] = new Student("Petrov", "Aleksandr", "Igorevich", 1992, "Moscow", "905-39-42","Robotics", 6);
    data[1] = new Student("Smirnova", "Anna", "Victorovna", 1995, "Moscow", "927-27-56","Informatics", 3);
    data[2] = new Student("Ivanov", "Petr", "Nikolaevich", 1993, "Moscow", "935-09-87","Mathematics", 6);
    data[3] = new Student("Pavlova", "Evgenia", "Vladimirovna", 1997, "Moscow", "905-67-45","Robotics", 1);
    data[4] = new Student("Nikitin", "Dmitry", "Olegovich", 1994, "Moscow", "927-34-90","Informatics", 3);

    cout<<"Список студентов: \n";
    for(int i=0; i<N; i++)
    {
        data[i]->show();
        cout<<"\n";
    }
    cout<<"******************************************";
    cout<<"\n";

    char *fclty1="Mathematics";
    cout<<"task1: Студенты факультета " <<fclty1<<"\n";
    Students_one_faculty(data, fclty1);


    char *fclty2="Informatics";
    int crs=3;
    cout<<"task2: Студенты "<<crs<< " курса факультета "<<fclty2<<"\n";
    Students_one_faculty_and_year(data, fclty2, crs);

    unsigned int dt=1993; //год не может быть <0
    cout<<"task3: Студенты, родившиеся после " <<dt<<" года\n";
    Students_born_after(data, dt);

    cout<<"Демонстрация работы конструктора копирования \n";
    //Student *new_stud = new Student(data[0]);

    //new_stud->get_adress() = "hi";


    for(int i=0; i<N; i++)
        delete data[i]; // применяем delete указатель на объект класса. Автоматически вызывается деструктор
    delete []data;

   // delete new_stud;

    return 0;
}
