#include"sDeque.h"
#define NUM_ITEMS 300
int main(int argc, char **argv) {
  
  	Deque *DQ = new Deque();
	Deque* DQ2 = new Deque();
	Deque* DQ3 = new Deque();
	Deque* DQ4 = new Deque();
	std::string i_str;

	
	std::cout << "-----SIZE TEST 1-----" << std::endl;
	std::cout << "Expected Result: " << NUM_ITEMS << std::endl;
	 for (int i = 0; i < NUM_ITEMS; i++) {
	   i_str = std::to_string(i);
	   DQ->push_back(i_str);
	 }
	bool test_successful = (DQ->size() == NUM_ITEMS);
	//std::cout << DQ->toStr() << std::endl;
	std::string pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ->size() << "\t" << pass_fail << std::endl << std::endl;

	
	
       	std::cout << "-----POP-BACK TEST-----" << std::endl;
	for (int i = 0; i < NUM_ITEMS; i++) {
	  DQ->pop_back();
	}
	test_successful = (DQ->size() == 0 && DQ->empty());
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "POP-FRONT BACK Results: " << DQ->size()<< "\t" << pass_fail << std::endl << std::endl;


	

	std::cout << "-----SIZE TEST 2-----" << std::endl;
	std::cout << "Expected Result: 0" << std::endl;
	for (int i = 0; i < 10; i++) {
	  std::cout << "Current DQ = " << DQ2->toStr() << std::endl;
	  i_str = std::to_string(i);
	  (i % 2 == 0) ? DQ2->push_back(i_str) : DQ2->push_front(i_str);
	}
	for (int i = 0; i < 10; i++) {
	  std::cout << "Popped: " << ((i % 2 != 0) ? DQ2->pop_back() : DQ2->pop_front()) << std::endl;
	}
	test_successful = (DQ2->size() == 0);
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ2->size() << "\t" << pass_fail << std::endl << std::endl;


	
	
	std::cout << "-----SIZE TEST 3-----" << std::endl;
	std::cout << "Expected Result: 35" << std::endl;
	for (int i = 0; i < 50; i++) {
	  (i % 2 == 0) ? DQ3->push_back("push_back") : DQ3->push_front("push_front");
	}
	for (int i = 0; i < 15; i++) {
	  (i % 2 == 0) ? DQ3->pop_back() : DQ3->pop_front();
	}
	test_successful = (DQ3->size() == 35);
	pass_fail = test_successful ? "(PASS)" : "(FAIL)";
	std::cout << "Result: " << DQ3->size() << "\t" << pass_fail << std::endl << std::endl;


	std::cout << "-----POP EMPTY TEST-----" << std::endl;	
	DQ4->pop_back();
	DQ4->pop_front();
	

	delete DQ;
	delete DQ2;
	delete DQ3;
	return 0;

}
