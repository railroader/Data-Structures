#include<iostream>
using namespace std;

class node{
public:
	int item;
	node *prev;
	node *next;
	node(int data);
	node(node *n,node *p,int data);
	node();
};
node::node(){
	prev = next = NULL;
	item = 0;
}
node::node(int data){
	prev = next = NULL;
	item = data;
}
node::node(node *n,node *p,int data){
	next = n;
	prev = p ;
	item = data;
}

class list{
public:
	list();
	void emptyList(); // list destructor
	void insertAfterLast(int data);
	void insertAfterFirst(int data);
	void insertBeforeFirst(int data);
	void insertAfterCurrent(int data,node *current);
	void insertAfterCurrentItem(int cdata,int data);
	void sortedInsert(int data);
	void deleteLast();
	void deleteFirst();
	void displayNodesTest();
	void displayShuffleResultsReverse(int count);
	void displayShuffleResults(int count);
	void copy(list *listC);

	bool isEmpty();
	bool isEquals(list *list2);

	int getFirst();
	int getLast();
	int getLength();
	int getNextItem(int data);
	int getItemAtPosition(int data);

	node getFirstNode();

private:
	node *head;
	node *tail;
	int size;
};
list::list(){
	head = tail = NULL;
	size = 0;
}



node list::getFirstNode(){
	return *head;
}






void list::insertAfterLast(int data){
	node *tmp = new node(data);
	if(head == NULL){
		head = tmp;
		tail = tmp;
		size++;
	}else{
		tail->next = tmp;
		tmp->prev = tail;
		tail  = tmp;
		size++;
	}
}
void list::insertBeforeFirst(int data){
	node *tmp = new node(data);
	if(head == NULL){
		head = tmp;
		tail = tmp;
		size++;
	}else{
		head->prev = tmp;
		tmp->next = head;
		head = tmp;
		size++;
	}
}
void list::insertAfterFirst(int data){
	node *tmp = new node(data);
	node *tmp2;
	if(head == NULL){
		head = tmp;
		tail = tmp;
		size++;
	}else{
		tmp2 = tmp;
		tmp2->next = head->next;
		tmp2->prev = head;
		head->next = tmp2;
		size++;
	}
}
void list::insertAfterCurrent(int data,node *current){
	node *tmpH = head;
	while(tmpH != NULL){
		if(tmpH == current){
			node *tmp = new node(data);
			tmp->next = tmpH->next;
			tmp->prev = tmpH;
			tmpH->next = tmp;
			size++;
			break;
		}

	tmpH = tmpH->next;
	}
}

void list::insertAfterCurrentItem(int cdata,int data){
	node *current = this->head;
	while(current != NULL){
		if(current->item == data){
			insertAfterCurrent(cdata,current);
		}
		current = current->next;
	}

}
int list::getNextItem(int data){
	node *current = this->head;
	node *tmp;
	while(current != NULL){
		if(current->item == data){
			if(current->next == NULL){
				return current->item;
				break;
			}
			tmp = current->next;
			return tmp->item;
			break;
		}
		current = current->next;
	}
}


int list::getItemAtPosition(int data){
	int i = 1;
	node *current = this->head;
	while(current != NULL){
		if(i == data){
			return current->item;
			break;
		}
		current = current->next;
		i++;
	}
}


void list::sortedInsert(int data){ //inserts new nodes in a sorted order
	if(head == NULL){
		node *tmp = new node(data);
		head = tmp;
		tail = tmp;
		size++;
	}else{
		node *current = head;
		node *max = new node();
		while(current != NULL){
			if( data >= current->item){
				max = current;
			}
			current = current->next;
		}
			insertAfterCurrent(data,max);
	}
}













int list::getFirst(){
	return this->head->item;
}
int list::getLast(){
	node *current = head;
	for(int i = 1;i<= this->size;i++){
		if(i == size){
			return current->item;
		}
		current = current->next;
	}
}
void list::deleteLast(){
	if(!this->isEmpty()){
		node *current = head;
		node *tmp;

		if(current->next == NULL && current->prev == NULL){
			delete current;
			head = NULL;
			tail = NULL;
			size--;
		}else{
				for(int i = 1;i<= this->size;i++){
					if(i == size){
						tmp = current->prev;
						tmp->next = current->next;
						delete current;
						size--;
					}
					current = current->next;
				}
		}
	}
}
void list::deleteFirst(){
	if(!this->isEmpty()){
		node *current = head;
		node *tmp;
			if(current->next == NULL && current->prev == NULL){
				head = NULL;
				tail = NULL;
				delete current;

				size--;
			}else{
				tmp = current->next;
				tmp->prev = NULL;
				delete current;
				head = tail = tmp;
				size--;
			}
		}
}
int list::getLength(){
	return this->size;
}
bool list::isEmpty(){
	if(head == NULL)
		return true;
	else
		return false;
}




void list::displayNodesTest() // display the nodes of list for testing purposes shows the next and previous pointer values
{
	cout << endl << endl << endl;
	cout << "head = " << (int)this->head << endl;
	cout << endl;
	node* temp = head;
	while(temp != NULL){
		cout << "Node = " << temp->item << endl;
		cout <<"next item is :- " <<  (int)temp->next << endl;
		cout <<"this item is :- " <<  (int)temp << endl;
		cout <<"prev item is :- " <<  (int)temp->prev << endl;
		temp = temp->next;
		cout << endl;
	}

	cout << "tail = " << (int)this->tail << endl;
	delete temp;

}
void list::emptyList(){
	while(this->size > 0){
		this->deleteFirst();
	}
}







bool list::isEquals(list *list2){	// method to take in a pointer to an to the comparison list 
	node* h1 = this->head;
	node* h2 = list2->head;
	bool retval;
	while(h1 != NULL){
		if(h1->item != h2->item){
			retval = false;
			break;
		}else{
			retval = true;
		}
		h1 = h1->next;
		h2 = h2->next;
	}
	return retval;
}
void list::copy(list *listC){		// method to take in a pointer to an to an empty instance of type list and then populate it with the current list nodes
	if(this->isEmpty()){
		node *current = listC->head;
		for(int i = 1;i<= listC->size;i++){
			this->insertAfterLast(current->item);
			current = current->next;
		}
	}
}







void list::displayShuffleResults(int count){
	cout << endl << endl << count <<"  ";
	node *current = this->head;
	while(current != NULL){
		if(current->next == NULL){		// to determine wether to place a comma after each node value
			cout << current->item;
		}else{
			cout << current->item << ",";	
		}
			current = current->next;
	}
	cout << endl;
}



void list::displayShuffleResultsReverse(int count){
	cout << endl << endl << count <<"  ";
	node *current = this->tail;
	while(current != NULL){
		cout << current->item << ",";
		current = current->prev;
	}
	cout << endl;
}