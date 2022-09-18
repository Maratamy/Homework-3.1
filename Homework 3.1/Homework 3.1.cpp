#include <iostream>
using namespace std;

class  NumericArray {
protected:
    double* arr;
    int length;
public:
    NumericArray(int Size){
        arr = new double[Size];
        length = Size;
    }
    virtual void Show_me() {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    double& operator[](int index) {
        return arr[index];
    }
    double operator[](int index) const {
        return arr[index];
    }
    void operator+=(double increment) {
        for (int i = 0; i < length; i++)
        {
           arr[i] += increment;
        }
    }
    void operator-=(double decrement) {
        for (int i = 0; i < length; i++)
        {
            arr[i] -= decrement;
        }
    }
    void operator/=(double numeric) {
        for (int i = 0; i < length; i++)
        {
            arr[i] /= numeric;
        }
    }
    void operator*=(double numeric) {
        for (int i = 0; i < length; i++)
        {
            arr[i] *= numeric;
        }
    }
     
    ~NumericArray(){}
};

class SquareMatrix: virtual public NumericArray {
public:
    SquareMatrix() : NumericArray(4){}
   
    void Show_me() override{
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
            if (i % 2 != 0) cout << endl;
        }
        cout << endl;
    }
    void operator=(SquareMatrix CopyMat) {
        for (int i = 0; i < length; i++)
        {
            arr[i] = CopyMat[i];
        }
    }
};

int main()
{
    SquareMatrix A, B;
    B[1] = 7;
    B[0] = 8;
    B[2] = 9;
    B[3] = 10;
    A[1] = 1;
    A[0] = 0;
    A[2] = 2;
    A[3] = 3;
    A.Show_me();
    A += 3;
    A.Show_me();
    cout << "BV" << endl;
    B.Show_me();
    A = B;
    A.Show_me();
}