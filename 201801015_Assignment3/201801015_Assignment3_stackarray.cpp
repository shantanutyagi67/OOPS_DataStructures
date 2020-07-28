//NAME		: SHANTANU TYAGI
//ID		: 201801015
//ASSIGNMENT: 3
//TOPIC 	: Stack implementation using array
//DATE 		: 1/4/19

#include<iostream>

using namespace std;

template <typename E>
class arrayList
{
    public:
    int arraySize; // maximum size of the list
    int currentSize; // number of data elements stored
    E* dataArray; // Array for storing the data
    
    public:
        //constructors and destructors
        arrayList(int size)
        {
            arraySize = size;
            currentSize = 0;
            dataArray = new E[arraySize];
        }
	arrayList(){}
        ~arrayList()
        {
            //delete [] dataArray;    
        }
};  

template <typename E> 
class Stack
{
    void operator = (const Stack&) {}
    Stack(const Stack&) {}
    
    public:
        //constructors and destructors
        Stack() {}
        virtual ~Stack() {}
        
        // Return the length of the stack
        virtual int length() const = 0;
        
        //Return the Location of current element
        virtual void push(const E& element) = 0;
        
        //clear the current data element from stack
        virtual E pop() = 0;
        
        //Return a copy of the current element
        virtual const E& currentElement() const= 0;
        
        // Remove all the elements from the stack
        // and free the occupied memory without causing
        // memory leak
        virtual void clearStack() = 0;
        
}; 

template <typename E> 
class StackArrayList: public Stack<E>, arrayList<E>
{
    int stacksize; // size of the stack
    int currentLocation; // location pointer keeping track of
                         // current element
    arrayList<E>* StackArray; // Array for storing the data
    
    public:
        //constructors and destructors
	StackArrayList(){}
        StackArrayList(int size) 
        {
            stacksize = size;
            StackArray = new arrayList<E>(size);
            currentLocation = 0;
        }
        ~StackArrayList() 
        {
            //delete StackArray;    
        }

	int length() const
	{
		if(StackArray->currentSize==0)
		{
			return -1;
		}
		else
		{
			return StackArray->currentSize;
		}
	}

	void push(const E& element)
	{
		if(StackArray->currentSize>=stacksize)
		{
			cout<<"Stack size exceeded"<<endl;
		}
		else
		{
			StackArray->dataArray[currentLocation]=element;
			StackArray->currentSize++;
			currentLocation++;
		}
	}

	E pop()
	{
		if(StackArray->currentSize==0)
		{
			return -1;
		}
		else
		{
			E tmp;
			tmp=StackArray->dataArray[currentLocation-1];
			StackArray->currentSize--;
			currentLocation--;
			return tmp;
		}
	}

	const E& currentElement() const
	{
		if(StackArray->currentSize==0)
		{
			return -1;
		}
		else
		{
			return StackArray->dataArray[currentLocation-1];
		}
	}
	
	void clearStack()
	{
		if(StackArray->currentSize==0)
		{
			cout<<"already empty."<<endl;
		}
		else
		{
			StackArray->currentSize=0;
			currentLocation=0;
			
		}
	}
	
	void print()
	{
		if(StackArray->currentSize==0)
		{
			cout<<"Stack is Empty."<<endl;
		}
		else
		{
				
			for(int i=0;i<StackArray->currentSize;i++)
			{
				cout<<" "<<StackArray->dataArray[i];
			}
			cout<<endl;
		}
	}
};

int main()
{
	int size,loop=1;
    cout<<"Enter stack size : ";
    cin>>size;
    StackArrayList<int> aa(size);
    while(loop!=0)
    {
    	cout<<"Select the operation : \n0:exit\n1:length of the stack\n2:push\n3:pop\n4:current element\n5:clear stack\n6:display\n";
    	cin>>loop;
    	switch(loop)
    	{
    		case 0:
    		{
    			break;
    		}
    		case 1:
    		{
    			int l;
    			l=aa.length();
    			cout<<"\nlength: "<<l;
    			break;
    		}
    		case 2:
    		{
    			int element;
				cout<<"input element";
				cin>>element;
				aa.push(element);
				break;
    		}
    		case 3:
    		{
    			aa.pop();
    			break;
    		}
    		case 4:
    		{
    			aa.currentElement();
    			break;
    		}
    		case 5:
    		{
    			aa.clearStack();
    			break;
    		}
    		case 6:
    		{
    			aa.print();
    			break;
    		}
    		
    	}
    }
	return 0;
}
