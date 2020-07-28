//Name :Shantanu Tyagi
//ID:201801015
//Date:1/4/19
//Program: Queue using linkedlist


#include<iostream>
#include<stdlib.h>

using namespace std;

template<typename E> 
class node
{   public:
    E key;
    node *next;
    node()
    {
        key=0;
        next=NULL;
    }
};

template <typename E>
class linkList
{   public :
    node<E>* firstElement;
    node<E>* lastElement;
    node<E>* currentElement;
    int sizeOfList;
    
    
        //constructors and destructors
        linkList()
        {
            firstElement = lastElement = currentElement = new node<E>;
            sizeOfList = 0;
        }
        ~linkList()
        {
            while(firstElement != NULL)
            {

                currentElement = firstElement;              
                firstElement = firstElement->next;
                delete currentElement;
            }    
        }
       
const E& firstElement2() const
{  if(firstElement==0)
     cout<<"No Element present";
    
   return currentElement->key;
}

int length1() const 
        {   
            return sizeOfList ;
         
        }
void clearQueue1()
{
  while(firstElement != NULL)
            {

                currentElement = firstElement;
                firstElement = firstElement->next;
                delete currentElement;
            }
            firstElement = lastElement = currentElement = new node<E>;
            sizeOfList = 0;
}

void insert1(const E &data)
{ if(sizeOfList==0)
		{
			node<E>* ptr= new node<E>;
			ptr->key=data;
			ptr->next=NULL;
			firstElement = lastElement = currentElement = ptr;
			sizeOfList ++;
		}
		else
		{
			node<E>* n= new node<E>;
			n->key=data;
			n->next=NULL;
			lastElement->next=n;
			lastElement=n;

			sizeOfList ++;
		}
}
E remove1()
{ if(sizeOfList == 0)
               cout<<"NO elements to delete"<<endl;
             else 
		{
			firstElement=firstElement->next;
			currentElement=firstElement;
			sizeOfList --;
		}
  return currentElement->key;
} 
void display1()
        {  node<E> *ptr;
           ptr=firstElement;
           if(sizeOfList==0)
            cout<<"No Element present ";
           else
            { 
              for(int i=0;i<sizeOfList;i++)
		{  cout<<ptr->key<<" ";
		   ptr=ptr->next;
		}
           }


        }
  
};
 

template <typename E> 
class Queue
{
    void operator = (const Queue&) {}
    Queue(const Queue&) {}
    
    public:
        //constructors and destructors
        Queue() {}
        virtual ~Queue() {}
        
        // Insert an element at the end of the queue
        virtual void insert(const E &) = 0;
        
        //Remove the first element of the queue
        virtual E remove() = 0;
        
        // Return the length of the queue
        virtual int length() const = 0;
        
        //Return a copy of the first element
        virtual const E& firstElement1() const= 0;
        
        // Remove all the elements from the Queue
        // and free the occupied memory without causing
        // memory leak
        virtual void clearQueue() = 0;
        
};   
 template <typename E>
class QueueLinkList:  public Queue<E>
{
    //size of the link list 
    int size;  
    // Array for storing the data
    linkList<E>* QueueArray; 
    
    
    
    public:
        //constructors and destructors
        //constructors and destructors
        QueueLinkList() 
        {
            QueueArray = new linkList<E>();
        }
        ~QueueLinkList() 
        {
            //clear();
            //for the next statement ensure 
            // that you have implemented 
            // destructor in the linkList class.
            delete QueueArray;    
        }
        
   
 

const E& firstElement1() const
{ return QueueArray->firstElement2();
}

int length() const 
        {   return QueueArray->length1(); 
         
        }
void clearQueue()
{
  QueueArray->clearQueue1();
}

void insert(const E &data)
{ 
   QueueArray->insert1(data);
}
E remove()
{ 
   QueueArray->remove1();
} 
void display()
        {  QueueArray->display1();

        }
  
};


int main()
{
    int fn,data,flag;
    char ans;
    
    QueueLinkList<int> aa;
    do
  {
       cout<<"1: length of the Queue"<<endl;
       cout<<"2: Enqueue"<<endl;
       cout<<"3: Dequeue"<<endl;
       cout<<"4: Data "<<endl;
       cout<<"5: Remove all elements "<<endl;
       cout<<"6: Display Queue"<<endl;
       cout<<"7: Exit"<<endl;
       cout<<"Enter Choice :"<<endl;
       cin>>fn;
       switch(fn)
       {   case 1: cout<<" length of queue is :"<<aa.length()<<endl;
                   break;
           case 2: cout<<"Enter element :";
                   cin>>data;
                   aa.insert(data);
                   break;
           case 3: flag=aa.remove();
                   if(flag!=0)
                   cout<<"deleted..."<<endl;  
                   break;
           case 4: if(aa.firstElement1()!=0)
                   cout<<"Current Element: "<<aa.firstElement1()<<endl;
                   break;
          case 5: aa.clearQueue();
                  cout<<" Cleared List  :"<<endl;
           case 6: aa.display();
                    break;
           case 7:
		   			break;
          default:cout<<"Invalid Choice";
       }
       cout<<"Continue ?(y/n)";
       cin>>ans;
  }while((ans=='y')||(ans=='Y'));
	return 0;
}




