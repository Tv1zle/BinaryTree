#include"MyArray.h"

int main()
{
	srand(time(0));
	MyArray<int> arrint(5);
	arrint.Input();
	arrint.Print();

	MyArray<double> arrdouble(10);
	arrdouble.Input();
	arrdouble.Print();


	MyArray<char> arrchar(3);
	arrchar.Input();
	arrchar.Print();
}