#include "student.h"
#include <iostream>
#include <fstream>

using namespace std;


bool ifExists(const char* fn, const int nr)
{
    fstream pl(fn, ios::in);
    if (!pl)
    {
        cout << "\n ererer";
        return false;
    }

    student s;
    pl.seekg(sizeof(student) * (nr - 1));
    pl.read(reinterpret_cast<char*>(&s), sizeof(student));
    pl.close();
    if (s.number != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getNumber(const char* pyt)
{
    int nr;
    do 
    {
        cout << pyt << "[1-100] : ";
        cin >> nr;

        if (nr == 0)
            return 0;
    }     while (nr < 1 || nr > 100);

    return nr;
}

int newStudent(const char* fn)
{
    fstream pl(fn, ios::in | ios::out);
    if (!pl)
    {
        return -1;
    }
    int nr = getNumber("\n Enter the number of the new student (0 - exit) ");
    student s;
    while(nr > 0 && nr <= 100)
    {
        if (ifExists(fn, nr))
        {
            cout << "\n Cannot add because the number already exists \n";
        }
        else
        {
            cout << "\n Name Surname Average ";
            cin >> s.name >> s.surname >> s.average;

            s.newS(); s.editS();

            s.number = nr;
            
            pl.seekp((nr - 1) * sizeof(student));

            pl.write(reinterpret_cast<const char*> (&s), sizeof(student));


        }

        nr = getNumber("\n Enter the number of the new student (0 - exit) ");
    }

    pl.close();
    return 0;
}

int newFile(const char* fn)
{
    ofstream pl(fn, ios::out);

    student s;
    for (int i = 0; i < 100; i++)
    {
        pl.write(reinterpret_cast<const char*> (&s), sizeof(student));

    }

    pl.close();
    return 0;

}

int listing(const char* fn)
{
    ifstream ps(fn, ios::in);
    if (!ps)
    {
        cout << "\n Failed to open the file" << fn << endl;
        return -1;
    }

    system("cls");
    student::head(cout);
    student s;

    while (!ps.eof())
    {
        ps.read(reinterpret_cast<char*> (&s), sizeof(student));

        if (s.number != 0)
        {
            cout << s;
        }

    }
        ps.close();
        return 0;

}


int Edit(const char* fn)
{
    fstream pl(fn, ios::in | ios::out);
    if (!pl)
    {
        return -1;
    }

    int nr = getNumber("\n Enter the number to modify (0-end) ");
    student s;

    while (nr > 0 && nr <= 100)
    {
        if (ifExists(fn, nr))
        {
            pl.seekg(sizeof(student) * (nr - 1));

            pl.read(reinterpret_cast<char*> (&s), sizeof(student));

            student::head(cout);
            cout << s;


            cout << "\n Enter new average value ...: ";
            float avg = 0;
            cin >> avg;

            s.average = avg;
            s.editS();

            pl.seekg(sizeof(student) * (nr - 1));
            pl.write(reinterpret_cast<char*> (&s), sizeof(student));

            nr = getNumber("\n Enter the number to modify (0-end) ");
        }
        else
        {
            cout << "\n Enter the number to modify (0-end) \n";
            nr = getNumber("\n Enter the number to modify (0-end) ");
        }
    }

    pl.close();
    return 0;
}

int exportTxt(const char* fn)
{
    ifstream pl(fn, ios::in);
    if (!pl) return -1;

    ofstream fex("result.txt", ios::out);
    if (!fex) return-1;

    student::head(fex);
    student s;
    int counter = 0;

    while (pl && !pl.eof())
    {
        pl.read(reinterpret_cast<char*> (&s), sizeof(student));

        if ((s.number != 0) && (s.average > 2.00))
        {
            fex << s; counter++;
        }
    }

    cout << "\n exported <" << counter << " > student's" << endl;

    pl.close();
    fex.close();
    return 0;
}

int main()
{
    bool end = false;
    while (!end)
    {
        cout << "\n --------------------------------------------\n";
        cout << "\t 100 - create a new data file \n";
        cout << "\t 1 - Student list \n";
        cout << "\t 2 - Add a new record\n";
        cout << "\t 3 - Edit the student\n";
        cout << "\t 4 - export\n";
        cout << "\t 0 - END \n";
        cout << "\n --------------------------------------------\n";

        int o = 0;
        cout << " <select> "; cin >> o;
        int w;
        switch (o)
        {
        case 0:
            end = true;
            break;
        case 100:
            w = newFile("student.dat");
            break;
        case 1:
            w = listing("student.dat");
            break;
        case 2:
            w = newStudent("student.dat");
            break;
        case 3:
            w = Edit("student.dat");
        case 4:
            w = exportTxt("student.dat");
            break;

        default:
            break;

        }
    }
}
