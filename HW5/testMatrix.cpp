// Main Program Example for HW5

// You can use this file as your main program, or add more functions if you want.
// Please ***MAKE SURE*** that your class works fine in this main program.
// TA will test your class by this program with additional test data.


#include <iostream>
#include "TriangularMatrix.h"
// ****If you need to include more header files, add it here****

using namespace std;

int main(){
	Matrix M1, M2, M3;
	cout << "* Assign values for matrix M1 *" << endl;
	M1.readMatrix();

	cout << "* Assign values for matrix M2 *" << endl;
	M2.readMatrix();

	cout << "M1 is: " << M1 << endl << endl;
	cout << "M2 is: " << M2 << endl << endl;


	M1+=M2;
	cout << "M1+=M2:" << M1 << endl << endl;



	cout <<"M1(1,2)"<<M1(1,2)<<endl;
	cout <<"M1(2,2)"<<M1(2,2)<<endl;
	cout <<"M1(3,2)"<<M1(3,2)<<endl;

	// Note that the size(row count) of M1, M2 may vary,
	// also M1, M2 can be upper or lower triangular matrices.
	// Therefore, please make sure that you check their types first before doing the calculation.

	cout << "M3 = M1 + M2" <<endl;
	M3 = M1 + M2;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 = M2 * 5" <<endl;
	M3 = M2 * 5;
	cout << "Now M3 is: " << M3 << endl << endl;

	cout << "M3 -= M1" << endl;
	M3 -= M1;
	cout << "Now M3 is: " << M3 << endl << endl;


	cout<<"Test *="<<endl;
	cout << "Now M3 is: " << M3 << endl << endl;
	cout << "Now M1 is: " << M1 << endl << endl;
	cout << "M3 *= M1" << endl;
	M3 *= M1;
	cout << "Now M3 is: " << M3 << endl << endl;


	cout << "M3 = M2 * 2 * M1" << endl;
	M3 = M2 * 2 * M1;
	cout << "Now M3 is: " << M3 << endl << endl;



	cout << "double d = M1(1,2)" << endl;
	double d = M1(1,2);
	cout << "Now d is: " << d << endl << endl;

	cout << "M2(1,1) equals to: " << M2(1,1) << endl << endl;



	cout << "---------- END PROGRAM ----------" << endl << endl;

    return 0;
}
