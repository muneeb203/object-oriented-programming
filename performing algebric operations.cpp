#include <iostream>
using namespace std;

class Number {
    private:
        int var;
    public:
        Number(int v = 0) : var(v) {}
        int getVar() const { return var; }
        void setVar(int v) { var = v; }
};

Number operator+(const Number& a, const Number& b) {
    return Number(a.getVar() + b.getVar());
}

Number operator-(const Number& a, const Number& b) {
    return Number(a.getVar() - b.getVar());
}

Number operator*(const Number& a, const Number& b) {
    return Number(a.getVar() * b.getVar());
}

bool operator==(const Number& a, const Number& b) {
    return a.getVar() == b.getVar();
}

ostream& operator<<(ostream& os, const Number& num) {
    os << num.getVar();
    return os;
}

int main() {
    
    int A,B,C;
    
    cout<<"Enter the value of a: ";
    cin>>A;
    cout<<"Enter the value of b: ";
    cin>>B;
    cout<<"Enter the value of C: ";
    cin>>C;

    
    Number a(A);
    Number b(B);
    Number c(C);

    // a^2 – b^2 = (a – b) (a + b)
    cout << "a^2 - b^2 = " << a*a - b*b << endl;
    cout << "(a - b) * (a + b) = " << (a-b)*(a+b) << endl;
    cout << "a^2 - b^2 == (a - b) * (a + b) : " << (a*a - b*b == (a-b)*(a+b)) << endl <<endl;

    // (a + b)^2 = a^2 + 2ab + b^2
    cout << "(a + b)^2 = " << (a+b)*(a+b) << endl;
    cout << "a^2 + 2ab + b^2 = " << a*a + 2*a*b + b*b << endl;
    cout << "(a + b)^2 == a^2 + 2ab + b^2 : " << ((a+b)*(a+b) == a*a + 2*a*b + b*b) << endl<< endl;

    // a^2 + b^2 = (a + b)^2 - 2ab
    cout << "a^2 + b^2 = " << a*a + b*b << endl;
    cout << "(a + b)^2 - 2ab = " << (a+b)*(a+b) - 2*a*b << endl;
    cout << "a^2 + b^2 == (a + b)^2 - 2ab : " << (a*a + b*b == (a+b)*(a+b) - 2*a*b) << endl<< endl;

    // (a - b)^2 = a^2 - 2ab + b^2
    cout << "(a - b)^2 = " << (a-b)*(a-b) << endl;
    cout << "a^2 - 2ab + b^2 = " << a*a - 2*a*b + b*b << endl;
    cout << "(a - b)^2 == a^2 - 2ab + b^2 : " << ((a-b)*(a-b) == a*a - 2*a*b + b*b) << endl<< endl;

    // (a + b + c)^2 = a^2 + b^2 + c^2 + 2ab + 2bc + 2ca
    cout << "(a + b + c)^2 = " << (a+b+c)*(a+b+c) << endl;
    cout << "a^2 + b^2 + c^2 + 2ab + 2bc + 2ca = " << a*a + b*b + c*c + 2*a*b + 2*b*c + 2*c*a << endl;
    cout << "(a + b + c)^2 == a^2 + b^2 + c^2 + 2ab + 2bc + 2ca : " << ((a+b+c)*(a+b+c) == a*a + b*b + c*c + 2*a*b + 2*b*c + 2*c*a) << endl<< endl;
    
    // (a - b - c)^2 = a^2 + b^2 + c^2 - 2ab + 2bc - 2ca
    cout << "(a - b - c)^2 = " << (a-b-c)*(a-b-c) << endl;
    cout << "a^2 + b^2 + c^2 - 2ab + 2bc - 2ca = " << a*a + b*b + c*c - 2*a*b + 2*b*c - 2*c*a << endl;
    cout << "(a - b - c)^2 == a^2 + b^2 + c^2 - 2ab + 2bc - 2ca : " << ((a-b-c)*(a-b-c) == a*a + b*b + c*c - 2*a*b + 2*b*c - 2*c*a) << endl<< endl;
    
    // (a + b)^3 = a^3 + 3a^2b + 3ab^2 + b^3 OR (a + b)^3 = a^3 + b^3 + 3ab (a + b)
    cout << "(a + b)^3 = " << (a+b)*(a+b)*(a+b) << endl;
    cout << "a^3 + 3a^2b + 3ab^2 + b^3 = " << a*a*a + 3*a*a*b + 3*a*b*b + b*b*b << endl;
    cout << "a^3 + b^3 + 3ab (a + b) = " << a*a*a + b*b*b + 3*a*b*(a+b) << endl;
    cout << "(a + b)^3 == a^3 + 3a^2b + 3ab^2 + b^3 : " << ((a+b)*(a+b)*(a+b) == a*a*a + 3*a*a*b + 3*a*b*b + b*b*b) << endl;
    cout << "(a + b)^3 == a^3 + b^3 + 3ab (a + b) : " << ((a+b)*(a+b)*(a+b) == a*a*a + b*b*b + 3*a*b*(a+b)) << endl<< endl;
    
    // (a - b)^3 = a^3 - 3a^2b + 3ab^2 - b^3= a^3 - b^3 - 3ab (a - b)
    cout << "(a - b)^3 = " << (a-b)*(a-b)*(a-b) << endl;
    cout << "a^3 - 3a^2b + 3ab^2 - b^3 = " << a*a*a - 3*a*a*b + 3*a*b*b - b*b*b << endl;
    cout << "a^3 - b^3 - 3ab (a - b) = " << a*a*a - b*b<< endl;
 
 return 0;   
}