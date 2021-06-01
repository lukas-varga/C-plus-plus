#include <iostream>

using namespace std;

class Film
{
friend class FilmList;
private:
    string title;
    int year;
    string genre;
    Film *successor;
public:
    Film(): successor(NULL){}
    ~Film(){}
    Film(string t, int y, string g): title(t), year(y), genre(g), successor(NULL){}
};

class FilmList
{
private:
    Film *beginning;
    Film *end;
public:
    FilmList(): beginning(NULL), end(NULL){}
    ~FilmList()
    {
        delete beginning;
        delete end;
        cout << "Whole list deleted!" << endl;
    }

    void add(Film *newFilm)
    {
        if(beginning == NULL && end == NULL)
        {
            end = newFilm;
            beginning = newFilm;
        }
        else
        {
            end->successor = newFilm;
            end = newFilm;
        }
    }

    void clearList()
    {
        Film *next;
        while(beginning != NULL)
        {
            next = beginning->successor;
            delete beginning;
            beginning = next;
            cout << "Film deleted!" << endl;
        }
    }

    void displayElements()
    {
        Film *pointer;
        for (pointer = beginning; pointer != NULL; pointer = pointer->successor)
        {
            cout << "Title: " << pointer->title << "\tYear: " << pointer->year << "\tGenre: " << pointer->genre << endl;
        }
    }
};

int main()
{
    cout << "Film List!" << endl;
    FilmList list;

    Film *f1 = new Film("Pulp Fiction", 1993, "Action Movie");
    Film *f2 = new Film("Interstellar", 2015, "Mystery");
    Film *f3 = new Film("Peaky Blinders", 2018, "Mafia Movie");

    list.add(f1);
    list.add(f2);
    list.add(f3);

    list.displayElements();

    list.clearList();

    system("pause");
    return 0;
}
