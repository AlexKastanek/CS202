#include <iostream>
#include <fstream>
#include "listnode.h"

using namespace std;

int main() {

	ListNode list;

	list.insertAfter(1);

	list.insertAfter(2);

	list.insertBefore(3);

	list.insertBefore(4);

	list.insertBefore(5);

	cout << list << endl;

return 0;

}

