#include "Vector.h"
#include <iostream>

using namespace std;

#pragma pack(1)
class VectorPacked
{
    int* num; 
    int size;
};


int main() {

    cout << "Size of Vector class: " << sizeof(Vector) << " bytes" << endl;
    cout << "Size of PackedVector class: " << sizeof(VectorPacked) << " bytes" << endl;
    cout << "------------------------------------" << endl;

    Vector v1;

    int arr[] = { 3, 4 };
    Vector v2(2, arr);

    Vector v3 = v2;

    cout << "v1 (default): " << v1 << endl;
    cout << "v2 (initialization): " << v2 << " Norm: " << v2.norm() << endl;
    cout << "v3 (copy of v2): " << v3 << endl;

    cout << endl << "Enter v1 (format: <size> <element1> <element2> ...): " << endl;
    cin >> v1;
    cout << "Your vector v1: " << v1 << endl << endl;

    int scalar = 2;
    Vector v4 = v1 * scalar;
    cout << "v1 * " << scalar << " = " << v4 << endl << endl;
    
        if (v1 == v2) 
            cout << "v1 is equal to v2" << endl;
        else 
            cout << "v1 is not equal to v2" << endl;

    if (v1 > v2) cout << "v1 > v2" << endl;
    if (v1 < v2) cout << "v1 < v2" << endl;
    if (v1 >= v2) cout << "v1 >= v2" << endl;
    if (v1 <= v2) cout << "v1 <= v2" << endl << endl;


    if (v1.getSize() > 0) {
        cout << "v1[0] = " << v1[0] << endl;
        v1[0] = 100;
        cout << "Changed v1: " << v1 << endl;
    }

    return 0;
}