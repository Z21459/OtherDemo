//#include <iostream>
#include "UsingNamSpace.h"

//using namespace MyUsingSpace;

namespace  My1 {
	using std::cout;
	using std::endl;
	void fun1() {
		cout << "My1";
	}
}

using namespace My1;
int main() {
	//MyUsingSpace::My_test::call();
	
	fun1();
	system("pause");
	return 0;
}