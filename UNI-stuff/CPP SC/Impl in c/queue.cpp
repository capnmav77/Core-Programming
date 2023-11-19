#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

class node{
    private:
        node *next = NULL;
    public:
        int value;
        void set_next(node *nextnode){
            next = nextnode;
        }
        node* get_next(){
            return next;
        }
        
        
};

class Queue{
    node*front = NULL;
    node*rear = NULL;
    int number_nodes =0;
    public:

    void add_node(){
        number_nodes +=1;
    }
    void decrement_node(){
        number_nodes -= 1;
    }

    void init_front(node *Node){
        front = Node;
        if(!rear){
            rear = Node;
        }
        add_node();
    }
    void Move_rear(node *Node){
        rear = Node;
    }

    int enqueue(node *QNode){
        rear->set_next(QNode);
        Move_rear(QNode);
        add_node();
        return 1;
    }

    int dequeue() {
    if (!front) {
        cout << "Queue empty!" << endl;
        return 0;
    }
    
    node* temp = front->get_next();
    int value = front->value;
    delete front;
    front = temp;
    cout << "Front freed" << endl;
    return value;
    }


    void traverse(){
        node*temp = front;
        cout<<temp->value<<"-";
        while(temp->get_next() != NULL){
            temp = temp->get_next();
            cout<<temp->value<<"-";
        }
        cout<<"eoq"<<endl;
    }

    void get_front(){
        cout<<front->value<<endl;
    }
};

int main()
{
    Queue Q1;
    node N;
    N.value=69;
    Q1.init_front(&N);
    node N1;
    N1.value=2;
    Q1.enqueue(&N1);
    node N2;
    N2.value=3;
    Q1.enqueue(&N2);
    Q1.traverse();
    Q1.get_front();
    return 0;
}
