#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

string weapon[3] = {"Scissors","Rock","Paper"};

class Player
{
private:
    string name;
    int selection;
    int wins;
    int draws;
public:
    Player(): Player("",0,0,0) {}
    Player(string name): Player(name,0,0,0) {}
    Player(string name, int selection, int wins, int draws): name(name),selection(selection), wins(wins), draws(draws) {}

    void randSelection()
    {
        srand (time(NULL));
        selection = rand() % 3;
    }

    void showBattle(Player &c)
    {
        cout    << "\t" << name << "(" << weapon[selection] << ") VS "
                << c.name << "(" << weapon[c.selection] << ")" << endl;
    }

    friend bool operator==(Player &a, Player &b);
    friend bool operator>(Player &a, Player &b);

    //prefix DRAW
    Player& operator++();
    //postfix WINS
    Player operator++(int);

    friend istream& operator>>(istream& is, Player& p);
    friend ostream& operator<<(ostream& os, Player& p);

    friend bool operator>=(Player &a, Player &b);
};

bool operator==(Player &a, Player &b)
{
    return (a.selection == b.selection);
}
bool operator>(Player &a, Player &b)
{
    return ((a.selection == 0 && b.selection == 2)
        ||  (a.selection == 1 && b.selection == 0)
        ||  (a.selection == 2 && b.selection == 1));
}

//prefix DRAW
Player& Player::operator++()
{
    draws++;
}
//postfix WINS
Player Player::operator++(int)
{
    wins++;
}

istream& operator>>(istream& is, Player& p)
{
    do
    {
        system("cls");
        cout << "--- Rock, Paper, Scissors ---" << endl;
        cout << "[0] Scissors" << endl;
        cout << "[1] Rock" << endl;
        cout << "[2] Paper" << endl;
        cout << "Selection " << p.name << ": ";

        is >> p.selection;
        cout << endl;

        if(p.selection >= 0 && p.selection <= 2)
            break;
        cout << "Wrong input!" << endl;
        system("pause");
    }
    while(true);
}
ostream& operator<<(ostream& os, Player& p)
{
    os  << "[" <<p.name
        << "]\t Wins: " << p.wins
        << "\t Draws: " << p.draws << endl;
}

bool operator>=(Player &a, Player &b)
{
    if(a.wins > b.wins)
    {
        cout    << a.name << " has won!" << endl
                << "He won " << a.wins << " times." << endl
                << "Difference is " << (a.wins - b.wins)
                << " win(s)." << endl;
    }
    else if(a.wins < b.wins)
    {
        cout    << b.name << " has won!" << endl
                << "He won " << b.wins << " times." << endl
                << "Difference is " << (b.wins - a.wins)
                << " win(s)." << endl;
    }
    else //draw
    {
        cout    << "It is a draw!" << endl
                << "Player and Computer had "
                << a.draws << " draw(s) and "
                << a.wins << " win(s)." << endl;
    }
}

int main()
{
    const int NUM_OF_GAMES = 5;
    Player player = Player("Player");
    Player computer = Player("Computer");

    for(int i=0; i<NUM_OF_GAMES; i++)
    {
        cin >> player;
        computer.randSelection();
        player.showBattle(computer);

        if(player == computer)
        {
            ++player;
            ++computer;
        }
        else if(player > computer)
            player++;
        else
            computer++;

        cout << player;
        cout << computer;
        system("pause");
    }

    system("cls");
    cout << "--- Rock, Paper, Scissors ---" << endl;
    cout << "---------- Results ----------" << endl;
    cout << player;
    cout << computer;
    cout << endl;

    player >= computer;

    system("pause");
    return 0;
}
