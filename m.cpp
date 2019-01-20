#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};
//................................................................
class DLL{
    public:
    Node * head;
    DLL(){
        head = NULL;
    }
//.....................................................
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }  
        else{ // If not empty list. 
            Node * current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;    
        }
    }
//...........................................................................
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< "->"; 
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout << endl;
        cout << "Print in R order : ";
        while(last!=NULL){
            cout <<last->data<< "->";
            // Move backwards 
            last = last->prev;
        }
        cout << endl;   
    }
//..............................................................................
    void InsertAt(int value, int pos){
        // insert at any position 

	  // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }

        // Create a node
        Node * temp = new Node(value);
     
        // Moving ptrs like magic ! if not head
        temp->next = current->next;
	temp->next->prev=temp;
        current->next = temp;
	temp->prev=current;
        //we have to arramge total four pointers here 2of insert node and 1 of forward 1of backward node

    }
//.................................................................................
    void DeleteAt(int pos){
        //reach the position
        Node * current = head;
   int i=1;
        while(i<pos-1){
      i++;
     current = current->next;
     }

       //difine new pointer store pos address
    Node * ptr;
//new pointer point to node which we have to delete
   ptr=current-> next;
//delete using ptr,currnt
	current->next=ptr->next;
	    ptr->next->prev=current;
		ptr->next=NULL;
		ptr->prev=NULL;

  	// delete ptr
	delete ptr;
    }
//,..............................................................................
    void Del(){
        // Deletes the last element.

//reach second last position
        Node * current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
//make null the pointer which point further
        current->next = NULL; 

       }
//..............................................................
    void CountItems(){
        // Counts the Number of items.
	Node*current=head;
		int i=0;

	while(current!=NULL){
	current=current->next;
	i++;
	}
cout<<"number of elements are"<< i<<endl;


    }
};
//...................................................................

int main(){
    DLL dll1;
    for(int i= 1; i < 11; i++){
        dll1.insert(i);
    }
    dll1.display();

cout<<"add 5 at 5th position"<<endl;
dll1.InsertAt(5,5);
dll1.display();

cout<<"delete 5 at 5th position"<<endl;
dll1.DeleteAt(5);
dll1.display();

cout<<"delete last node"<<endl;
dll1.Del();
dll1.display();

dll1.CountItems();



}
