#include <iostream>
#include "Vector3.h"

using namespace std;

int main() {
    Vector3 vect;

    //cin >> vect;
    //cout << vect << endl;

    vect.x = 1;
    vect.y = 3;
    vect.z = 2;

    //--vect;

    vect.Rotate('x', 90);

    cout << vect << endl;

    Vector3 rot = vect.GetRotated('x', 90);
    cout << rot << endl;

//    Vector3 plus(2, 6, 7);
//
//    vect + plus;
//    cout << vect << endl;
//
//    vect - 2*plus;
//    cout << vect << endl;
//
//    Vector3 res = vect^plus;
//    cout << "Vect * : " << res << endl;

    /*float scal = vect * plus;
    cout << scal << endl;
    cout << vect - plus << endl;

    cout << vect*5 << endl;
    cout << 4*vect << endl;*/

    return 0;
}