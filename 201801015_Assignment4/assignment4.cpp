//NAME        : SHANTANU TYAGI
//SID         : 201801015
//ASSIGNMENT  : 4
//DATE        : 8/4/19
//PROGRAM     : Sorting Algorithms
#include<iostream>

using namespace std;
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

        virtual void printlist() = 0;

};

template <typename E>
class arrayList: public List<E>
{
    int arraySize; // maximum size of the                       //Private Variables of ArrayList class
    int currentSize; // number of data elements stored
    int currentLocation; // location pointer of the list
    E* dataArray; // Array for storing the data

public:
    //constructors and destructors
    arrayList(int size)                             
    {
        arraySize = size;
        currentSize = currentLocation = 0;
        dataArray = new E[arraySize];
    }
    ~arrayList()                                    
    {
        delete [] dataArray;
    }

    int NumberOfElements() const
    {
        return currentSize;
    }

    int CurrentLocation() const
    {
        return currentLocation+1;
    }


    const E& getData() const
    {

        if(currentLocation<=currentSize-1)
        {
            return dataArray[currentLocation];
        }
        else if(currentLocation>currentSize && currentLocation<=arraySize-1)
        {
            cout<<"No entry is made at current location."<<endl;
            return 0;
        }



    }

    void clear()
    {
        for(int i=0;i<currentSize;i++)
        {
            dataArray[i]=0;
        }
        currentSize = 0;
        currentLocation = 0;

    }

    void insert(const E& data)
    {
        if(currentSize==arraySize)				
        {
            cout<<"Array limit exceeded."<<endl;
        }
        else
        {
            if(dataArray[currentLocation]!=0)
            {
                for(int i=currentSize-1;i>=currentLocation;i--)
                {
                    dataArray[i+1]=dataArray[i];
                }
                dataArray[currentLocation]=data;
                currentSize++;
            }
            else
            {
                dataArray[currentLocation]=data;
                currentSize++;
            }
        }
    }

    void append(const E& data)
    {
        int ua=0;
        if(currentSize==arraySize)
        {
            cout<<"Entry is already made at tail of List."<<endl;
            cout<<"Do you want to overwrite it ?"<<endl<<"Enter 0 for NO"<<endl<<"Enter 1 for YES"<<endl;		//Giving user right to overwrite an already made entry
            cin>>ua;
            if(ua==1)
            {
                dataArray[currentSize-1]=data;
            }
        }
        else
        {
            dataArray[currentSize]=data;
            currentSize++;
        }
    }

    E remove()
    {
        E datarem;
        datarem=dataArray[currentLocation];
        if(currentLocation!=currentSize-1)
        {
        for(int i=currentLocation;i<currentSize;i++)   
        {
            dataArray[i]=dataArray[i+1];
        }
        }
        else
        {
            dataArray[currentLocation]=0;
        }
        currentSize--;
        return datarem;
    }

    void setListLocationToStart()
    {
        currentLocation=0;
    }

    void setListLocationToEnd()
    {
        currentLocation=currentSize-1;
    }

    void previousElement()
    {
        if(currentLocation>0)			
            currentLocation--;
        else
            cout<<"Currently you already are at the start of list."<<endl;
    }

    void nextElement()
    {
        if(currentLocation<currentSize-1)		
            currentLocation++;
    }

    int setToNewLocation(int location)
    {
        if(location<=currentSize)			
            currentLocation=location-1;         
        else
            cout<<"Invalid Location entered."<<endl;
    }

    void printlist()
    {
        if(currentSize!=0)				
        {
            for(int i=0;i<currentSize;i++)                 
            {
                cout<<" "<<dataArray[i];
            }
            cout<<"."<<endl;
        }
        else
        {
            cout<<" no elements."<<endl;
        }
    }
};
template <typename E>
void selectionSort(List<E>* l)
{
    int minValue,temp,Imin,Ivalue;
    for(int i=0;i<=l->NumberOfElements()-2;i++)
    {
        Imin=i;
        l->setToNewLocation(i+1);
        minValue=l->getData();
        Ivalue=minValue;
        for(int j=i+1;j<=l->NumberOfElements()-1;j++)
        {
            l->setToNewLocation(j+1);
            if(l->getData()<minValue)
            {
                minValue=l->getData();
                Imin=j;
            }
        }
        if(Imin!=i)
        {
            l->setToNewLocation(Imin+1);
            l->remove();
            l->insert(Ivalue);
            l->setToNewLocation(i+1);
            l->remove();
            l->insert(minValue);

        }
    }
}
template <typename E>
void bubbleSort(List<E>* l)
{
    int curvalue,adjvalue;
    for(int loop1=1;loop1<l->NumberOfElements();loop1++)
    {
        int flag=0;
        for(int loop2=0;loop2<l->NumberOfElements()-1;loop2++)
        {
            l->setToNewLocation(loop2+1);
            curvalue=l->getData();
            l->nextElement();
            adjvalue=l->getData();
            if(curvalue>adjvalue)
            {
                l->remove();
                l->insert(curvalue);
                l->previousElement();
                l->remove();
                l->insert(adjvalue);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

template <typename E>
void quickSort(List<E>* l,int start, int last)
{
    int pIndex;                             
    if(start<last)
    {
        pIndex=Partition(l,start,last);
        quickSort(l,start,pIndex-1);
        quickSort(l,pIndex+1,last);
    }
}

template <typename E>
int Partition(List<E>* l,int start, int last)
{
    int pivot,pIndex,temp,pValue;
    l->setToNewLocation(last+1);
    pivot=l->getData();
    pIndex=start;
    for(int i=start;i<last;i++)
    {
        l->setToNewLocation(i+1);
        temp=l->getData();
        if(temp<=pivot)
        {
            l->setToNewLocation(pIndex+1);
            pValue=l->getData();
            l->setToNewLocation(i+1);
            l->remove();
            l->insert(pValue);
            l->setToNewLocation(pIndex+1);
            l->remove();
            l->insert(temp);
            pIndex=pIndex+1;

        }
    }
    l->setToNewLocation(last+1);
    temp=l->getData();
    l->setToNewLocation(pIndex+1);
    pValue=l->getData();
    l->remove();
    l->insert(temp);
    l->setToNewLocation(last+1);
    l->remove();
    l->insert(pValue);
    return pIndex;
}
template <typename E>
void mergeSort(List<E>* a)
{
    int n,mid;
    n=a->NumberOfElements();
    if(n<2)
        return ;
    mid=n/2;
    List<E>* l;
    List<E>* r;
    arrayList<int> al(mid);
    arrayList<int> ar(n-mid);
    l=&al;
    r=&ar;
    a->setToNewLocation(1);
    for(int i=0;i<mid;i++)
    {
        l->insert(a->getData());
        l->nextElement();
        a->nextElement();
    }
    a->setToNewLocation(mid+1);
    for(int j=mid;j<n;j++)
    {
        r->insert(a->getData());
        r->nextElement();
        a->nextElement();
    }
    mergeSort(l);
    mergeSort(r);
    Merge(l,r,a);
}
template <typename  E>
void Merge(List<E>* l,List<E>* r,List<E>* a)
{
    int nl,nr,i,j,k;
    i=0;
    j=0;
    k=0;
    nl=l->NumberOfElements();
    nr=r->NumberOfElements();
    l->setToNewLocation(1);
    r->setToNewLocation(1);
    a->setToNewLocation(1);
    while(i<nl && j<nr)
    {
        if(l->getData()<=r->getData())
        {
            a->remove();
            a->insert(l->getData());
            a->nextElement();
            l->nextElement();
            i=i+1;
        }
        else
        {
            a->remove();
            a->insert(r->getData());
            a->nextElement();
            r->nextElement();
            j=j+1;
        }
    }
    while(i<nl)
    {
        a->remove();
        a->insert(l->getData());
        a->nextElement();
        l->nextElement();
        i=i+1;
    }
    while(j<nr)
    {
        a->remove();
        a->insert(r->getData());
        a->nextElement();
        r->nextElement();
        j=j+1;
    }
}
int main()
{
    int size;
    int uans=1;
    int uans1;
    int data;
    cout<<"Enter size of array :"<<endl;
    cin>>size;
    arrayList<int> a(size);
    List<int>* l;
    l=&a;

    while(uans==1)					
    {
        cout<<"Do you want to perform any operation ? "<<endl<<"Enter 1 for YES"<<endl<<"Enter 0 for NO"<<endl;
        cin>>uans;
        if(uans==1)
        {
            cout<<"Choose operation you want to perform :"<<endl;
	    cout<<"1  : Numbers of elements in the list."<<endl<<"2  : Current location of List."<<endl;
            cout<<"3  : Data at current Location."<<endl<<"4  : Clear whole data of the list."<<endl;
	    cout<<"5  : Insert at current location."<<endl<<"6  : Append at tail of list."<<endl;
            cout<<"7  : Remove data from current location."<<endl<<"8  : Set current location to start of list."<<endl;
            cout<<"9  : Set current location to end of list."<<endl<<"10 : Set current location to left of the current element."<<endl;
            cout<<"11 : Set current location to right of current element."<<endl<<"12 : Set current location to a specific location."<<endl;
            cout<<"13 : Print the whole List."<<endl<<"14 : Selection Sort."<<endl<<"15 : Bubble Sort"<<endl<<"16 : Quick Sort"<<endl;
            cout<<"17 : Merge Sort."<<endl;
            cin>>uans1;
            switch(uans1)			
            {
                case 1:
                    cout<<"Number of elements in list :"<<a.NumberOfElements()<<endl;
                    break;
                case 2:
                    cout<<"Current Location is :"<<a.CurrentLocation()<<endl;
                    break;
                case 3:
                    cout<<"Data at current location is :"<<a.getData()<<endl;
                    break;
                case 4:
                    a.clear();
                    cout<<"Complete list is whipped out."<<endl;
                    break;
                case 5:
                {
                    cout<<"Enter data to be inserted :"<<endl;
                    cin>>data;
                    a.insert(data);
                    break;
                }
                case 6:
                {
                    cout<<"Enter data to be inserted at end of list :"<<endl;
                    cin>>data;
                    a.append(data);
                    break;
                }
                case 7:
                    a.remove();
                    break;
                case 8:
                    a.setListLocationToStart();
                    break;
                case 9:
                    a.setListLocationToEnd();
                    break;
                case 10:
                    a.previousElement();
                    break;
                case 11:
                    a.nextElement();
                    break;
                case 12:
                {
                    cout<<"Enter location you want to go :"<<endl;
                    cin>>data ;
                    a.setToNewLocation(data);
                    break;
                }
                case 13:
                {
                    cout<<"Current List contains";
                    a.printlist();
                    break;
                }
                case 14:
                    {
                        cout<<"Before sorting :"<<endl;
                        a.printlist();
                        selectionSort(l);
                        cout<<"After sorting :"<<endl;
                        a.printlist();
                        break;
                    }

                case 15:
                    {
                        cout<<"Before Sorting :"<<endl;
                        a.printlist();
                        bubbleSort(l);
                        cout<<"After sorting :"<<endl;
                        a.printlist();
                        break;
                    }

                case 16:
                    {
                        cout<<"Before Sorting :"<<endl;
                        a.printlist();
                        quickSort(l,0,a.NumberOfElements()-1);
                        cout<<"After sorting :"<<endl;
                        a.printlist();
                        break;
                    }

                case 17:
                    {
                        cout<<"Before Sorting :"<<endl;
                        a.printlist();
                        mergeSort(l);
                        cout<<"After Sorting:"<<endl;
                        a.printlist();
                        break;
                    }
                default :
                    cout<<"Invalid input entered."<<endl;
                    break;
            }
        }
    }
    return 0;
}
