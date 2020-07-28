//Name :SHANTANU TYAGI
//ID:201801015
//Date:25/3/19
//Program: LINK LIST IMPLEMENTATION

#include<iostream>
#include<stdlib.h>

using namespace std;

template<typename E>
class node
{   public:
    int key;
    node *next;

    node()
    {
        key=0;
        next=NULL;
    }
};


template <typename E>
class List
{
    void operator = (const List&) {}
    List(const List&) {}

    public:
        //constructors and destructors
        List() {}
        virtual ~List() {}

        //Return the number of elements in the List
        virtual int NumberOfElements() const = 0;

        //Return the Location of current element
        virtual int CurrentLocation() const = 0;

        //Return the data of current element
        virtual const E& getData() const = 0;

        //clear all the data from the List
        virtual void clear() = 0;

        //insert a data in the List at current location
        virtual void insert(const E& data) = 0;

        //insert a data in the end of the List
        virtual void append(const E& data) = 0;

        //delete a data at the current Location
        virtual E remove() = 0;

        //set the current Location to the start of the List
        virtual void setListLocationToStart() = 0;

        //set the current Location to the end of the List
        virtual void setListLocationToEnd() = 0;

        //set the current Location to the element on left side
        // of current element
        virtual void previousElement() = 0;

        //set the current Location to the element on left side
        // of current element
        virtual void nextElement() = 0;

        //Set current Location to a new Location
        virtual int setToNewLocation(int location) = 0;

};

template <typename E>
class linkList: public List<E>
{
    node<E>* firstElement;
    node<E>* lastElement;
    node<E>* currentElement;
    int sizeOfList;

    public:
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

        int NumberOfElements() const
        {
            return sizeOfList;

        }

        //Return the Location of current element
        int CurrentLocation() const
        {
            int cnt=0;
            node<E> *ptr;
            ptr=firstElement;
            while(ptr!=currentElement)
            {   ptr=ptr->next;
                cnt++;
            }

            return cnt;
        }

        //Return the data of current element
        const E& getData() const
        {     
			return currentElement->key;
        }

        //clear all the data from the List
        void clear()
        {
            while(firstElement!=NULL)
            {
                currentElement = firstElement;
                firstElement = firstElement->next;
                delete currentElement;
            }
            firstElement = lastElement = currentElement = new node<E>;
            sizeOfList = 0;

        }

        //insert a data in the List at current location
        void insert(const E& data)
        {
          node<E>* ptr= new node<E>;
		if(sizeOfList==0)
		{
			ptr->key=data;
			ptr->next=NULL;
			sizeOfList ++;
			firstElement = lastElement = currentElement = ptr;
		}
        else if(currentElement==firstElement)
		{
			ptr->key=data;
			ptr->next=firstElement;
			firstElement=ptr;
			currentElement=ptr;
			sizeOfList++;
		}
              else if(currentElement==lastElement)
		{
			previousElement();
			ptr->key=data;
			ptr->next=NULL;
            currentElement->next=ptr;
			ptr->next=lastElement;
			currentElement=lastElement;
			sizeOfList ++;
		}


		else
		{
			ptr->key=data;
            ptr->next=NULL;

			int loc=CurrentLocation();
			node<E>* tmp=firstElement;
            node<E>* tmp2=currentElement;

            int i=0;
			while(i<sizeOfList-3)
			{
				tmp=tmp->next;
				i++;
			}

			tmp->next=ptr;
            ptr->next=tmp2;
			currentElement=tmp2;
			sizeOfList ++;
		}
		}

        //insert a data in the end of the List
        void append(const E& data)
        {  
			if(sizeOfList==0)
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

        //delete a data at the current Location
        E remove()
        {    if(sizeOfList == 0)
               cout<<"No elements"<<endl;
             else if(currentElement==firstElement)
		{
			firstElement=firstElement->next;
			currentElement=firstElement;
			sizeOfList --;
		}
		else if(currentElement==lastElement)
		{
			node<E>* ptr=firstElement;
			int j,i;
			j=CurrentLocation();
			for(i=0;i<j-1;i++)
			{
				ptr=ptr->next;
			}
			currentElement=ptr;
			currentElement->next=NULL;
			sizeOfList --;
		}
		else
		{
			node<E>* ptr=firstElement;
			int j,i;
			j=CurrentLocation();
			for(i=0;i<j-1;i++)
			{
				ptr=ptr->next;
			}
			currentElement=ptr;
			currentElement->next=(currentElement->next)->next;
			sizeOfList --;
		}

       }

        //set the current Location to the start of the List
        void setListLocationToStart()
        {
            currentElement=firstElement;
        }

        //set the current Location to the end of the List
        void setListLocationToEnd()
        {
            currentElement=lastElement;
        }

        //set the current Location to the element on left side
        // of current element
        void previousElement()
        {   if(currentElement==firstElement)
              {cout<<"Already at First Element";
               return;
              }
            else
            {
            node<E> * tmp;
            node<E> * tmp2;
            tmp=currentElement;
            tmp2=firstElement;
            while(tmp2->next!=tmp)
            {
                tmp2=tmp2->next;
            }
            currentElement=tmp2;
            }
        }

        //set the current Location to the element on left side
        // of current element
        void nextElement()
        {   if(currentElement==lastElement)
              { cout<<"Already at Last Element!"<<endl;
                 return;
              }
            else
            currentElement=currentElement->next;
            
        }

        //Set current Location to a new Location
        int setToNewLocation(int location)
        {   if(location<0 || location>sizeOfList)
                {
                    cout<<"Invalid Location...";
                    return -1;
                }
            node<E> *tmp;
            tmp=firstElement;
            for(int i=0;i<location;i++)
			{
			  tmp=tmp->next;
			}
			currentElement=tmp;
            return 0;
        }
        void display()
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




int main()
{   int fnc;
    char x;
	int n,i,j;

	linkList<int> aa,ab;



  do
  {
       cout<<"1.number of elements in the List"<<endl;
       cout<<"2.Location of current element"<<endl;
       cout<<"3.data of current element"<<endl;
       cout<<"4.Clear all the data"<<endl;
       cout<<"5.insert data at current location"<<endl;
       cout<<"6.insert data at the end of the List"<<endl;
       cout<<"7.delete data at the current Location"<<endl;
       cout<<"8.set the current Location to the start of the List"<<endl;
       cout<<"9.set the current Location to the end of the List"<<endl;
       cout<<"10.set the current Location to the element on left side of current element"<<endl;
       cout<<"11.set the current Location to the element on right side of current element"<<endl;
       cout<<"12.Set current Location to a new Location"<<endl;
       cout<<"13.Display"<<endl;
       cout<<"Enter your Choice :"<<endl;
       cin>>fnc;
      switch(fnc)
       {   case 1: cout<<" No of Elements in the List are :"<<aa.NumberOfElements()<<endl;
                   break;
           case 2: cout<<" Location of Current Element is :"<<aa.CurrentLocation()<<endl;
                   break;
           case 3: cout<<" Data of current element is :"<<aa.getData()<<endl;
                   break;
           case 4: aa.clear();
                   cout<<" Cleared List  :"<<endl;
                   break;
           case 5: int info;
                   cout<<"\nEnter data to be inserted at current location : ";
			       cin>>info;
                   aa.insert(info);
                   cout<<" "<<endl;
                   break;
           case 6:
                   cout<<"\nEnter data to be appended : ";
			       cin>>info;
			       aa.append(info);
					break;
           case 7:  aa.remove();
		   			break;
           case 8: aa.setListLocationToStart();
                   cout<<"Current Location is :"<<aa.CurrentLocation();
                   break;
           case 9: aa.setListLocationToEnd();
                   cout<<"Current Location is :"<<aa.CurrentLocation();
                   break;
           case 10:aa.previousElement();
                   cout<<"Current Location is :"<<aa.CurrentLocation() ;
                   break;
           case 11:aa.nextElement();
                   cout<<"Current Location is :"<<aa.CurrentLocation();
                   break;
           case 12:int loc;
                   cout<<"Enter New Location :";
                   cin>>loc;
                   aa.setToNewLocation(loc);
                   break;

           case 13: aa.display();
                    break;
          default:cout<<"Invalid Choice";
       }
       cout<<"CONTINUE ?(y/n)"<<endl;
       cin>>x;
    
  }while((x=='y')||(x=='Y'));
}
