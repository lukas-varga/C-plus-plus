#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Creature
{
private:
    int healthPoints;
    int damage;
public:
    Creature(){}
    Creature(int h): healthPoints(h){}

    int getHealthPoints()
    {
        return healthPoints;
    }

    void setHealthPoints(int hp)
    {
        healthPoints = hp;
    }

    int getDamage()
    {
        return damage;
    }

    void setRandHealthPoints()
    {
        healthPoints = randomNum(30,50);
    }

    void setRandDamage()
    {
        damage = randomNum(10,20);
    }

    static int randomNum(const int min,const int max)
    {
        srand(time(NULL));
        return rand() % (max-min) + min;
    }
};

class Player : public Creature
{
private:
    int potionOfLife;
public:
    Player(int h, int p): Creature(h), potionOfLife(p){}

    int getPotionOfLife()
    {
        return potionOfLife;
    }

    void drinkPotionOfLife()
    {
        if(potionOfLife>0)
            --potionOfLife;
        else
            cout << "You do not have enough potions of life!"<<endl;
    }
};

int main()
{
    const int NUM_OF_POTIONS = 1;
    Player *p = new Player(100,NUM_OF_POTIONS);

    const int NUM_MONSTERS = 3;
    Creature *m [NUM_MONSTERS];

    int i = 0;
    bool gameIsOn = true;
    do
    {
        system("cls");
        cout << "---MENU---" << endl;
        cout << "[1] Attack" << endl;
        cout << "[2] Drink potion" << endl;
        cout << "[3] Flee" << endl;

        int input;
        cout << "Enter: ";
        cin >> input;

        switch(input)
        {
        case 1:
            system("cls");
            cout << "[1] Attack" << endl;
            m[i] = new Creature();
            m[i]->setRandHealthPoints();

            cout << "BEFORE FIGHT"<<endl;
            cout << "Player's HP: "<< p->getHealthPoints() << endl;
            cout << "Monster's HP: "<< m[i]->getHealthPoints() << endl ;
            system("pause");
            cout << endl;

            while(true)
            {
                //Player's attack
                p->setRandDamage();
                int monstersHp = m[i]->getHealthPoints() - p->getDamage();
                monstersHp = (monstersHp < 0) ? 0 : monstersHp;
                m[i]->setHealthPoints(monstersHp);

                cout << "PLAYER'S TURN"<<endl;
                cout << "Player's HP: "<< p->getHealthPoints() << endl;
                cout << "Monster's HP: "<< m[i]->getHealthPoints() << endl;

                if(m[i]->getHealthPoints() < 1)
                {
                    cout << "Monster[" << i+1 << "] has died!"<<endl;
                    ++i;
                    break;
                }
                system("pause");
                cout << endl;


                //Monster's attack
                m[i]->setRandDamage();
                int playersHp = p->getHealthPoints() - m[i]->getDamage();
                playersHp = (playersHp < 0) ? 0 : playersHp;
                p->setHealthPoints(playersHp);

                cout << "MONSTER'S TURN"<<endl;
                cout << "Player's HP: "<< p->getHealthPoints() << endl;
                cout << "Monster's HP: "<< m[i]->getHealthPoints() << endl;

                if(p->getHealthPoints() < 1)
                {
                    cout << "Player has died! He has slayed " << i << " monsters." << endl;
                    gameIsOn = false;
                    break;
                }
                system("pause");
                cout << endl;
            }

            if(i > NUM_MONSTERS-1)
            {
                cout << "Player has found the treasure!" << endl;
                if(p->getPotionOfLife() == NUM_OF_POTIONS)
                {
                    cout << "Achievement unlocked: TRUE HERO"<< endl;
                }
                gameIsOn = false;
            }

            system("pause");
            break;
        case 2:
            system("cls");
            cout << "[2] Drink potion" << endl;

            if(p->getPotionOfLife() == 0)
            {
                cout << "You haven't got any potions of life left!" << endl;
            }
            else
            {
                p->drinkPotionOfLife();
                int health = p->getHealthPoints();
                cout << "Cheers! You have now " << health << " HP." << endl;
            }

            system("pause");
            break;
        case 3:
            system("cls");
            cout << "[3] Flee" << endl;

            cout << "Player has run away! He has slayed " << i << " monsters." << endl;
            gameIsOn = false;

            system("pause");
            break;
        default:
            system("cls");
            cout << "Wrong input!" << endl;
            system("pause");
        }
    }while(gameIsOn);

    delete p;
    delete [] m;

    return 0;
}
