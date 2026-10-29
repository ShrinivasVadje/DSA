    #include<iostream>
    using namespace std;
    class Node{
        public:
        string name;
        Node*next;
        int pr;
        Node(string n,int p=0){
            name=n;
            next=NULL;
            pr=p;
        }
    };
    class normalqueue{
        public:
        Node*front;
        Node*rear;
        normalqueue(){
            front=rear=NULL;
        }
        void enque(string name){
            Node*newNode=new Node(name);
            if(front==NULL){
                front=rear=newNode;
            }
            else{
                rear->next=newNode;
                rear=newNode;
            }
        }
        void deque(){
            if(front==NULL){
                cout<<"queue is empty";
            }
            else{
                Node*temp=front;
                front=front->next;
                delete temp;
            }
        }
    void display(){
        if(front==NULL){
                cout<<"queue is empty";
            }
        else{
            Node*temp=front;
            while(temp!=NULL){
                cout<<temp->name<<"->";
                temp=temp->next;
            }
        }

    }
    };
    class priorityqueue{
        public:
        Node*front;
        priorityqueue(){
            front=nullptr;
        }
        void enque(string name,int p){
            Node*newNode=new Node(name,p);        
            if(front==NULL or p<=front->pr){
                newNode->next=front;
                front=newNode; 
            }
            else{
                Node*temp=front;
                while(temp!=NULL and temp->next->pr<=p){
                    temp=temp->next;
                }
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
        void deque(){
            if(front==NULL){
                cout<<"queue is empty";
            }
            else{
                Node*temp=front;
                front=front->next;
                delete temp;
            }
        }
    void display(){
        if(front==NULL){
                cout<<"queue is empty";
            }
        else{
            Node*temp=front;
            while(temp!=NULL){
                cout<<temp->name<<"->";
                temp=temp->next;
            }
        }
    }
    };
    class circular{
        Node*front;
        Node*rear;
        public:
            circular(){
                front=NULL;
            }
        void enque(string name){
            Node*newNode=new Node(name);
            if(front==NULL){
            front=rear=newNode;
            }
            else{
            rear->next=newNode;
            rear=newNode;
            rear->next=front;
            }
        }
    void deque(){
            if(front==NULL){
                cout<<"queue is empty";
            }
            else{
                Node*temp=front;
                front=front->next;
                rear->next=front;
                delete temp;
            }
        }
    void display(){
        if(front==NULL){
                cout<<"queue is empty";
            }
        else{
            Node* temp = front;
    do{
        cout << temp->name << "->";
        temp = temp->next;
    } while(temp != front);

        }
    }
    };
    int main(){
        normalqueue q;
        circular c;
        priorityqueue p;
        q.enque("shrinivas");
        q.enque("Vishal");
        cout<<endl;
        q.display();
        q.deque();
        cout<<endl;
        q.display();
        c.enque("sayali");
        c.enque("Sanap");
        cout<<endl;
        c.display();
        c.deque();
        cout<<endl;
        c.display();
        p.enque("shri",2);
        p.enque("sakhi",1);
        cout<<endl;
        p.display();
        p.deque();
        cout<<endl;
        p.display();

    }