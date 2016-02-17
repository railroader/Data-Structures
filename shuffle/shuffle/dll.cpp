#include <iostream>
#include "shuffleList.h"

using namespace std;

int main(){
	int number; // number entered from user
	int sLen,sHalf;
	bool odd; // is the number entered odd or even
	int shuffleNumber = 0; // count for shuffle loop
	
	cout << "Enter a number \t";
	cin >> number;
	sLen = number;
	sHalf = (((int)sLen) / 2);
	
	//cout << sHalf << endl;
	cout << endl << endl << endl;
	cout << "SHUFFLES	DECK ORDER			" << endl;
	cout << "--------------------------------------------------------------------------------" << endl << endl;
	


	if(number % 2 > 0){
		odd = true;
		sHalf++;
	}else{
		odd = false;
	}

	list *orgList,*list1,*list2,*list3,*listTempS;
	list1 = new list();			//top half of list
	list2 = new list();			//bottom half of list
	list3 = new list();			//shuffled list	
	orgList = new list();		//origional list

	// populate origional ordered list 
		for(int i = 1;i<=sLen;i++){
			orgList->sortedInsert(i);
		}

		list3->copy(orgList);

		list3->displayShuffleResults(shuffleNumber);
		
		
		
		

// /////////////////////////////////////////////////////////////////////////////////////////////////////
// do while used as has to loop at least once
		do{	

	list3->displayNodesTest();


	//populate first section 

			int item1 = list3->getFirst();		
			for(int i = 1;i<= sHalf;i++){
				list1->insertAfterLast(item1);
				item1 = list3->getNextItem(item1);
			}
			//list1->displayNodesTest();
// ---------------------------------------------------

	//populate second section 
			int position2= sHalf + 1;
			int item2 = list3->getItemAtPosition(position2);

			for(int i = position2;i<=sLen;i++){
				list2->insertAfterLast(item2);
				item2 = list3->getNextItem(item2);
			}


			//list2->displayNodesTest();
				
// --------------------------------------------------
// merge the two lists
			list3->emptyList();

			if(odd){
				for(int i = 1;i<=sHalf;i++){
					list3->insertAfterLast(list1->getFirst());
					list1->deleteFirst();
						if(i != sHalf){
							list3->insertAfterLast(list2->getFirst());
							list2->deleteFirst();
						}
				}
			}else{
				for(int i = 1;i<=sHalf;i++){
					list3->insertAfterLast(list2->getFirst());
					list2->deleteFirst();	
					list3->insertAfterLast(list1->getFirst());
					list1->deleteFirst();
					
				}
			}

// --------------------------------------------------------		

		shuffleNumber++;
		list3->displayShuffleResults(shuffleNumber);
		//list3->displayShuffleResultsReverse(shuffleNumber);
		
		}while(!list3->isEquals(orgList));


		cout << endl << endl << endl << endl << endl << endl << endl;

	return 0;

}
































