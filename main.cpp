#include <iostream>
#include "Vector3.h"

using namespace std;

istream& operator >> (istream& is, Vector3& v) {
    cin >> v.x >> v.y >> v.z;
    return is;
}

ostream& operator << (ostream& os, const Vector3& v) {
    cout << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return os;
}

int main() {
    Vector3 vect;

    //cin >> vect;
    //cout << vect << endl;

    vect.x = 1;
    vect.y = 3;
    vect.z = 2;

    Vector3 plus(2, 6, 7);

    Vector3 res = vect^plus;
    cout << "Vect * : " << res << endl;

    /*float scal = vect * plus;
    cout << scal << endl;
    cout << vect - plus << endl;

    cout << vect*5 << endl;
    cout << 4*vect << endl;*/

    return 0;
}