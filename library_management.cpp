#include <iostream>
using namespace std;
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void input();
void output();
void del();
void design();
void modify();
void search();
void in();
void ou();
void de();
void mo();
void se();
int c;
class book
{
private:
    int code;
    char name[20];
    char author[20];
    int qty;
    int stcode;
    char stname[20];

public:
    void enter()
    {
        cout << "ENTER BOOK CODE :";
        cin >> code;
        cout << "ENTER BOOK NAME  :";
        cin >> name;
        cout << "ENTER AUTHOR NAME :";
        cin >> author;
        cout << "ENTER QUANTITY :";
        cin >> qty;
    }
    void display()
    {
        cout << "BOOK CODE  :" << code << endl;
        cout << "BOOK NAME  :" << name << endl;
        cout << "AUTHOR NAME :" << author << endl;
        cout << "QUANTITY :" << qty << endl;
    }
    void en()
    {
        cout << "ENTER ADMISSION MO.  :";
        cin >> stcode;
        cout << "ENTER STUDENT NAME  :";
        cin >> stname;
    }
    void di()
    {
        cout << "\n ADMISSION MO.  :" << stcode;
        cout << "\n STUDENT NAME :" << stname;
    }
    int bd()
    {
        return code;
    }

    int st()
    {
        return stcode;
    }
};
book co;
using namespace std;
int main()
{
    char f, ch;

    cout << "\n\n\n\n\n\n";
    cout << "*****************************************************************************************\n\n";
    cout << "                           LIBRARY MANAGEMENT                                            \n\n";
    cout << "*****************************************************************************************\n";
    getch();
    system("cls");
    cout << "\n\n\n\n";
    cout << "==========================================================================================\n";
    cout << "==========================================================================================\n";
    cout << "                           WELCOME TO LIBRARY                                             \n";
    cout << "==========================================================================================\n";
    cout << "==========================================================================================\n";
    getch();
    system("cls");
    design();
    if (c == 1)
    {
        getch();
        system("cls");
        do
        {
            getch();
            system("cls");
            cout << "==========================================================================================\n";
            cout << "                           WELCOME TO STUDENT PANEL                                       \n";
            cout << "==========================================================================================\n";
            cout << "1 .ADD NEW BOOK\n2 .DISPLAY LIST OF BOOKS\n3 .MODIFY BOOK\n4 .DELETE BOOK\n5 .SEARCH ANY BOOK\n6. EXIT\n\n";

            cout << "ENTER YOUR CHOICE :";
            cin >> c;
            getch();
            system("cls");
            switch (c)
            {
            case 1:
            {
                input();
            }
            break;
            case 2:
            {
                output();
            }
            break;
            case 3:
            {
                modify();
            }
            break;
            case 4:
            {
                del();
            }
            break;
            case 5:
            {
                search();
            }
            break;
            case 6:
            {
                cout << " \nWE MUST LET U IN MORE OPTIONS!!\n";
                getch();
                system("cls");
                design();
            }
            break;
            }
            cout << "\n DO YOU WANT TO ENTER MORE :";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }
    if (c == 2)
    {
        int n;
        cout << "\nENTER PASSWORD :";
        cin >> n;
        if (n == 00)
        {
            do
            {
                getch();
                system("cls");
                cout << "==========================================================================================\n";
                cout << "                           WELCOME TO LIBRARIAN PANEL                                       \n";
                cout << "==========================================================================================\n";
                cout << "1 .ADD NEW STUDENT\n2 .DISPLAY LIST OF STUDENTS\n3 .MODIFY STUDENT DETAILS\n4 .DELETE STUDENT NAME\n5 .SEARCH ANY STUDENT\n6 .EXIT\n";

                cout << "ENTER YOUR CHOICE :";
                cin >> c;
                getch();
                system("cls");
                switch (c)
                {
                case 1:
                {
                    in();
                }
                break;
                case 2:
                {
                    ou();
                }
                break;
                case 3:
                {
                    mo();
                }
                break;
                case 4:
                {
                    de();
                }
                break;
                case 5:
                {
                    se();
                }
                break;
                case 6:
                {
                    cout << " \nWE MUST LET U IN MORE OPTIONS!!\n";
                    design();
                }
                break;
                }
                cout << "\nDO YOU WANT TO ENTER MORE :";
                cin >> f;
            } while (f == 'y' || f == 'Y');
        }

        else
        {
            cout << " \nYOU ARE A WRONG PERSON. YOU DON'T HAVE PERMISSION TO VIEW THIS";
            getch();
            system("cls");
            design();
        }
    }
}
void input()
{
    ofstream f("book.dat", ios::binary | ios::app);
    co.enter();
    f.write((char *)&co, sizeof(co));
    f.close();
}
void output()
{
    ifstream g("book.dat", ios::binary);
    while (g.read((char *)&co, sizeof(co)))
    {
        cout << "*****************************************************************************************\n";
        co.display();
        cout << "*****************************************************************************************\n";
    }
    g.close();
}
void del()
{
    int d;
    cout << "\nENTER CODE OF BOOK WHICH TO BE DELETE :";
    cin >> d;
    ifstream g("book.dat", ios::binary);
    ofstream m("b.dat", ios::binary);
    while (g.read((char *)&co, sizeof(co)))
    {
        if (d != co.bd())
        {
            m.write((char *)&co, sizeof(co));
        }
    }
    g.close();
    m.close();
    remove("book.dat");
    rename("b.dat", "book.dat");
}
void design()
{
    cout << "##########################################################################################\n";
    cout << "                                SELECT                                                   \n";
    cout << "##########################################################################################\n";
    cout << "\n\n\n\n\n\n";
    cout << "  $$$$$$$$$$$                  $$$$$$$$$$$$$                                            $$$$$$$$\n";
    cout << "  $ STUDENT $                  $ LIBRARIAN $                                            $ EXIT $ \n";
    cout << "  $$$$$$$$$$$                  $$$$$$$$$$$$$                                            $$$$$$$$\n";
    cout << "      1                              2                                                     3     \n";
    cout << "\n";
    cout << "                                ENTER YOUR DEISGNATION :                                        \n";
    cin >> c;
}
void modify()
{
    int d;
    cout << "\nENTER CODE OF BOOK WHICH TO BE MODIFY :";
    cin >> d;
    ifstream g("book.dat", ios::binary);
    ofstream m("b.dat", ios::binary);
    while (g.read((char *)&co, sizeof(co)))
    {
        if (d == co.bd())
        {
            co.enter();
        }
        m.write((char *)&co, sizeof(co));
    }
    g.close();
    m.close();
    remove("book.dat");
    rename("b.dat", "book.dat");
}
void search()
{
    int t, g = 0;
    cout << "ENTER CODE FOR THE BOOK TO BE SEARCH :";
    cin >> t;
    ifstream s("book.dat", ios::binary);
    s.read((char *)&co, sizeof(co));
    if (t == co.bd())
    {
        co.display();
        g++;
    }
    if (g == 0)
    {
        cout << "\nNOT FOUND";
    }
}
void in()
{
    ofstream k("ad.dat", ios::binary | ios::app);
    co.en();
    k.write((char *)&co, sizeof(co));
    k.close();
}
void ou()
{
    ifstream l("ad.dat", ios::binary);
    while (l.read((char *)&co, sizeof(co)))
    {
        cout << "\n*****************************************************************************************\n";
        co.di();
        cout << "\n*****************************************************************************************\n";
    }
    l.close();
}
void de()
{
    int d;
    cout << "\nENTER ADMISSION NUMBER OF STUDENT WHICH TO BE DELETE :";
    cin >> d;
    ifstream l("ad.dat", ios::binary);
    ofstream n("a.dat", ios::binary);
    while (l.read((char *)&co, sizeof(co)))
    {
        if (d != co.st())
        {
            n.write((char *)&co, sizeof(co));
        }
    }
    l.close();
    n.close();
    remove("ad.dat");
    rename("a.dat", "ad.dat");
}
void mo()
{
    int d;
    cout << "\nENTER ADMISSION NUMBER OF STUDENT WHICH TO BE MODIFY :";
    cin >> d;
    ifstream l("ad.dat", ios::binary);
    ofstream n("a.dat", ios::binary);
    while (l.read((char *)&co, sizeof(co)))
    {
        if (d == co.st())
        {
            co.en();
        }
        n.write((char *)&co, sizeof(co));
    }
    l.close();
    n.close();
    remove("ad.dat");
    rename("a.dat", "ad.dat");
}
void se()
{
    int t, g = 0;
    cout << "ENTER ADMISSION NUMBER OF STUDENT TO BE SEARCH :";
    cin >> t;
    ifstream o("ad.dat", ios::binary);
    o.read((char *)&co, sizeof(co));
    if (t == co.st())
    {
        co.di();
        g++;
    }
    if (g == 0)
    {
        cout << "\nNOT FOUND";
    }
}
