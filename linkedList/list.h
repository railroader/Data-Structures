class Node{
public:
	Node();
	Node(int el,Node *ptr);
	int info;
	Node *next;
};

Node::Node(int el,Node *ptr = 0){
	info = el;
	next = ptr;
}
class List{

public:
	List();
	~List();
	void addToHead(int);
	void addToTail(int);

	void deleteNode(int);
	bool isInList(int) const;
	
	int isEmpty();
	int deleteFromHead();
	int deleteFromTail();

private:
	Node *head,*tail;
};

List::List(){
		head = 0;
		tail = 0;
}
List::~List(){
	for(Node *p;!isEmpty();){
		p = head->next;
		delete head;
		head = p;
	}
}
int List::isEmpty(){
	return (head == 0);
}
void List::addToHead(int el){
	head = new Node(el,head);
	if(tail == 0){
		tail = head;
	}
}
void List::addToTail(int el){
	if(tail != 0){
		tail->next = new Node(el);
		tail = tail->next;
	}
	else
	{
		tail = new Node(el);
		head = tail;
	}
}

