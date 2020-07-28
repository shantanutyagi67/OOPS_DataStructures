//Name :Shantanu Tyagi
//ID:201801015
//Date:1/4/19
//Program: Implementation of Queue using array

#include<iostream>
#include<stdlib.h>

using namespace std;

template <typename E>
class Queue
{
    //void operator = (const Queue&) {}
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
class QueueArrayList:  public Queue<E>
{
    int maximumSize;  //maximum size of the array list
    int firstElement; //index of the first element
    int lastElement; //index of the last element
    //QueueArrayList<E>* QueueArray; // Array for storing the data
    E* QueueArray;

    public:
        //constructors and destructors
        //constructors and destructors
        QueueArrayList(int size)
        {
            maximumSize = size;
            QueueArray = new E[size];
            firstElement = lastElement = 0;
            for(int i=0;i<size;i++)
                QueueArray[i]=0;
        }
        ~QueueArrayList()
        {
            delete QueueArray;
        }
        void insert(const E &data)
        {   if(lastElement==maximumSize)
              cout<<"Queue is full";
             else
            { 
				QueueArray[lastElement]=data;
            	lastElement++;
            }
        }
        E remove()
        {   if(firstElement==lastElement)
                cout<<"No element present"<<endl;
            else
           {  for(int i=firstElement;i<lastElement;i++)
                QueueArray[i]=QueueArray[i+1];
                lastElement--;
           }

            return QueueArray[lastElement];
        }
        int length() const
        {
           return lastElement-firstElement;
        }
        const E& firstElement1() const
        {       if(firstElement==lastElement)
                    cout<<"No Element";
                     
                return QueueArray[firstElement];
        }
        void clearQueue()
        {
             delete QueueArray;
             QueueArray = new E[maximumSize];
             firstElement = lastElement = 0;
             for(int i=0;i<maximumSize;i++)
                QueueArray[i]=0;
       }
       void display()
       {
               if(firstElement==lastElement)
                 cout<<"No element"<<endl;
               else
                for(int i=firstElement;i<lastElement;i++)
                  cout<<QueueArray[i]<<"  ";
       }
};
int main()
{
    int fn,data,flag,len;
    char ans;
    cout<<"Enter Size of Queue :";
    cin>>len;
    QueueArrayList<int> aa(len);
    do
  {
       cout<<"1: Return the length of the Queue \n"<<"2: Enqueue \n"<<"3: Dequeue \n"<<"4: data \n"<<"5: remove all elements \n"<<"6: Display \n"<<"7: EXIT \n";
       cout<<"Enter your Choice :"<<endl;
       cin>>fn;
       switch(fn)
       {   case 1: cout<<" No of Elements in the Queue are :"<<aa.length()<<endl;
                   break;
           case 2: cout<<"Enter element:";
                   cin>>data;
                   aa.insert(data);
                   break;
           case 3: flag=aa.remove();
                   
                   break;
           case 4: if(aa.firstElement1()!=0)
                   cout<<"Current Element:"<<aa.firstElement1()<<endl;
                   break;
          case 5: aa.clearQueue();
                  cout<<"Cleared"<<endl;
           case 6: aa.display();
                    break;
           case 7:exit(0);
          default:cout<<"Invalid Choice";
       }
       cout<<"Continue?(y/n)";
       cin>>ans;
  }while((ans=='y')||(ans=='Y'));
}




