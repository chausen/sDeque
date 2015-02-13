#include"sDeque.h"

int main(int argc, char **argv) {
  // int op=0;
  // std::string input;
  	Deque *DQ = new Deque();

	std::cout << "-----SIZE TEST 1-----" << std::endl;
	std::cout << "Expected Result: 3" << std::endl;
	 for (int i = 0; i < 9; i++) {
	   DQ->push_back("test string"); 
	 }
	bool test_successful = (DQ->size() == 3);
	std::string pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ->size() << "\t" << pass_fail << std::endl << std::endl;
	
	 
	delete DQ;
	DQ = new Deque();
	 

	std::cout << "-----SIZE TEST 2-----" << std::endl;
	std::cout << "Expected Result: 0" << std::endl;
	for (int i = 0; i < 10; i++) {
	  std::cout << "Current DQ = " << DQ->toStr() << std::endl;
	  (i % 2 == 0) ? DQ->push_back("push_back") : DQ->push_front("push_front");
	}
	for (int i = 0; i < 10; i++) {
	  (i % 2 != 0) ? DQ->pop_back() : DQ->pop_front();
	}
	test_successful = (DQ->size() == 0);
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ->size() << "\t" << pass_fail << std::endl << std::endl;

	
	delete DQ;
	DQ = new Deque();

	
	std::cout << "-----SIZE TEST 3-----" << std::endl;
	std::cout << "Expected Result: 35" << std::endl;
	for (int i = 0; i < 50; i++) {
	  (i % 2 == 0) ? DQ->push_back("push_back") : DQ->push_front("push_front");
	  std::cout << "[Size]: " << DQ->size() << ", [Capacity]: " << DQ->get_capacity() << std::endl;
	}
	for (int i = 0; i < 10; i++) {
	  (i % 2 != 0) ? DQ->pop_back() : DQ->pop_front();
	}
	test_successful = (DQ->size() == 35);
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ->size() << "\t" << pass_fail << std::endl << std::endl;	
	
	
	/*
	while (op<5)
	{
	  std::cout
		std::cin>> op;
		switch(op) {
		case 0:
			std::cin>>input;
			DQ->push_front(input);
			break;
		case 1:
			std::cin>>input;
			DQ->push_back(input);
			break;
		case 2:
			DQ->pop_front();
			break;
		case 3:
			DQ->pop_back();
			break;
		case 4:
			std::cout<<DQ->toStr();
			break;
		}
	}
	*/

	return 0;

}
