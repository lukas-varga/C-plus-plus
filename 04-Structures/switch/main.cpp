#include <iostream>

using namespace std;


int Subpoena();
bool Verdict();

int main()
{
    int AboveSpeedLimit;
    cout << "Please enter the above speed limit:" << endl;
    cin >> AboveSpeedLimit;

    int Penalty = 0;
    bool PenaltyDegree = true;

    switch(AboveSpeedLimit) {
        case 0 : {
            Penalty = 0;
            break;
        }
        case 10 : {
            Penalty = 20;
            break;
        }
        case 15 : {
            Penalty = 50;
            break;
        }
        case 20 :
        case 25 :
        case 30 : {
            Penalty = AboveSpeedLimit * 10;
            break;
        }
        default : {
            Penalty = Subpoena();
            PenaltyDegree = Verdict();
        }
    }

    cout << "Penalty: " << Penalty << "; Verdict: " << PenaltyDegree << endl;
    return 0;
}

int Subpoena()
{
    return -1;
}

bool Verdict()
{
    return false;
}
