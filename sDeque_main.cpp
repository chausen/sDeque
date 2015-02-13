#include"sDeque.h"

int main(int argc, char **argv) {
  // int op=0;
  // std::string input;
  	Deque *DQ = new Deque();
	std::cout << "-----SIZE TEST 1-----" << std::endl;
	std::cout << "Expected Result: 9" << std::endl;
	std::string i_str;
	 for (int i = 0; i < 9; i++) {
	   i_str = std::to_string(i);
	   DQ->push_back(i_str); 
	 }
	bool test_successful = (DQ->size() == 9);
	std::cout << DQ->toStr() << std::endl;
	std::string pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ->size() << "\t" << pass_fail << std::endl << std::endl;
	
	 

	//delete DQ;
	Deque *DQ2 = new Deque();
	 

	std::cout << "-----SIZE TEST 2-----" << std::endl;
	std::cout << "Expected Result: 0" << std::endl;
	for (int i = 0; i < 10; i++) {
	  std::cout << "Current DQ =\n" << DQ2->toStr() << std::endl;
	  i_str = std::to_string(i);
	  (i % 2 == 0) ? DQ2->push_back(i_str) : DQ2->push_front(i_str);
	}
	for (int i = 0; i < 10; i++) {
	  (i % 2 != 0) ? DQ2->pop_back() : DQ2->pop_front();
	}
	test_successful = (DQ2->size() == 0);
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ2->size() << "\t" << pass_fail << std::endl << std::endl;

	
	delete DQ2;
	
	Deque* DQ3 = new Deque();

	
	std::cout << "-----SIZE TEST 3-----" << std::endl;
	std::cout << "Expected Result: 35" << std::endl;
	for (int i = 0; i < 50; i++) {
	  (i % 2 == 0) ? DQ3->push_back("push_back") : DQ3->push_front("push_front");
	  std::cout << "[Size]: " << DQ3->size() << ", [Capacity]: " << DQ3->get_capacity() << std::endl;
	}
	for (int i = 0; i < 10; i++) {
	  (i % 2 != 0) ? DQ3->pop_back() : DQ3->pop_front();
	}
	test_successful = (DQ->size() == 35);
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ3->size() << "\t" << pass_fail << std::endl << std::endl;	
	
	delete DQ3;
	
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
