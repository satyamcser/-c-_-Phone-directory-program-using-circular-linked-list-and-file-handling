//Phone directory program using circular linked list and file handling
#include<iostream> 
#include<fstream>
//#include<curses.h> for linux
//#include <ncurses.h> for linux
#include<conio.h> //for windows

using namespace std; 
fstream myfile;
struct clients
{ 
 //parts of a node. 
 string name; 
 string number;
 string address;
 clients*link; 
  clients() 
  { 
   link=NULL; 
  }   
}; 
class directory
{ 
 //pointers to handle the linklist 
 clients *start,*cur,*temp,*end; 
 public: 
   
 directory() 
 { 
  start=NULL; 
 } 
 //function to create nodes 
  void creat_file(string n,string num,string ad) 
 { 
  //create 1st node... 
   if(start==NULL) 
   { 
    start=new clients; 
    start->link=start; 
    start->name=n; 
    start->number=num;
    start->address=ad;
    end=start;
    //open directory file to read data from it..
    myfile.open ("directory.txt",ios::out | ios::app);
    //saving data in file...
	myfile<<"Name_:_"<<start->name<<"__|__ADDRESS:_"<<start->address<<"__|__Phone Number_:_"<<start->number<<endl;
	myfile.close();
   } 
   //to create new node.. 
   else  
   { 
    cur=start; 
    while(cur->link!=start) 
    { 
     cur=cur->link; 
    } 
    temp=new clients; 
    temp->name=n;
	temp->number=num;
    temp->address=ad; 
    temp->link=start; 
    cur->link=temp; 
    end=temp;
    myfile.open ("directory.txt",ios::out | ios::app);
	myfile<<"Name_:_"<<temp->name<<"__|__ADDRESS:_"<<temp->address<<"__|__Phone Number:_"<<temp->number<<endl;
	myfile.close();
   } 
    }  
//this function is use to delete the phone number.. 
 void terminating_file(string n) 
    { 
     cur=start; 
     //if the number is found at start then delete it..
     if(start->name==n) 
     { 
      temp=start; 
      start=start->link; 
      delete temp; 
      end->link=start;
  } 
  else 
     { 
     //else search for the n in the list if it is found exit the loop and delete it.. else print the msg that
     ///data not found and exit the function
     while(cur->name!=n) 
      { 
       if(cur->link==start) 
       { 
       cout<<"Any Contact "<<n<<" does not exist"<<endl; 
       return ; 
       }   
       temp=cur; 
       cur=cur->link; 
   } 
   temp->link=cur->link; 
   delete cur; 
  } 
   
 } 
 
    //print data of the linklist. 
    void print_now() 
    { 
     cur=start; 
     int c; 
     cout<<"Person #"<<" ---> Name    \tNumber  \tAddress"<<endl;
     for(c=1;cur->link!=start;c++) 
     { 
      cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->address<<endl; 
      cur=cur->link; 
     } 
  cout<<"Person "<<c<<" ---> "<<cur->name<<"\t"<<cur->number<<"\t"<<cur->address<<endl; 
 } 
 //this function has been used to search for any data in the list.. 
 //after searching if the number found allow user to choose if he want to modify it or not
 //if he want to modify it.. else exit. 
 void search(string n)
 {
 	cur=start;
 	while(cur->link!=start)
 	{
 		if(cur->name==n)
 		{
 			char mod;
 			cout<<"\n\t_________DATA FOUND__________\n\n";
 			cout<<"Name : "<<cur->name<<endl;
 			cout<<"Address : "<<cur->address<<endl;
 			cout<<"Phone # : "<<cur->number<<endl;
 			cout<<"\nDo You want to modify Phone Number (y/n) : ";
 			cin>>mod;
 			if(mod=='y' || mod=='Y')
 			{
 				cout<<"Enter New Phone Number ";
 				cin>>cur->number;
 				cout<<"\n\t_________Data Updated________"<<endl;
			 }
 			break;
		 }
		 cur=cur->link;
	 }
	 if(cur->name==n)
 		{
 			char mod;
 			cout<<"\n\t_________DATA FOUND__________\n\n";
 			cout<<"Name : "<<cur->name<<endl;
 			cout<<"Address : "<<cur->address<<endl;
 			cout<<"Phone # : "<<cur->number<<endl;
 			cout<<"\nDo You want to modify Phone Number (y/n) : ";
 			cin>>mod;
 			if(mod=='y' || mod=='Y')
 			{
 				cout<<"Enter New Phone Number ";
 				cin>>cur->number;
 				cout<<"\n\t_________Data Updated________"<<endl;
			 }
		 }
	 else
	 cout<<"\n\t_______DATA NOT FOUND_________\n\n";	
 }
  //this function reads the data from file
 void print()
 {
 	 
 	string s;
 	myfile.open("directory.txt",ios::in);
 	while(!myfile.eof())
 	{
 		getline(myfile,s);
 		cout<<s<<endl;
	 }
	 myfile.close();
 }
}; 
int main() 
{ 
 directory l1; 
 int nooffiles,i,p,ch; 
 string n,nm,add; 
 cout<<"\n\t===================================================================\n\n"; 
 cout<<"\t\t\t TELEPHONE DIRECTORY SYSTEM\n"; 
 cout<<"\n\t===================================================================\n\n"; 
 cout<<"\n\t===================================================================\n\n"; 
 cout<<"\n\t1- SAVE NUMBERS\n"; 
 cout<<"\n\t2- CAN SEARCH AND UPDATE THE NUMBER\n";
 cout<<"\n\t3- WHEN A NUMBER IS OFF,,, YOU CAN DELETE IT FROM YOUR DIRECTORY\n"; 
 cout<<"\n\t4- CAN SEE ALL THE LIST ANY TIME\n"; 
 cout<<"\n\t===================================================================\n\n"; 
 cout<<"\n\t========================SAVE NUMBERs===============================\n"<<endl; 
 //no. of files. 
 cout<<"\tHow many numbers you want to save?"<<endl; 
 cin>>nooffiles; 
 //create/save data of each member....function call pass data.. 
 
 for(i=1;i<=nooffiles;i++) 
 { 
  cout<<"\n\tEnter Name: \t"; 
  //getline(cin,n); 
  cin>>n; 
  cout<<"\n\tEnter Phone number: \t";
  cin>>nm;
  cout<<"\n\tEnter Address: \t";
  cin>>add;
  l1.creat_file(n,nm,add); 
 } 
	system("CLS");
	//after the user have entered the record.. ask user what he/she want to do.. from these options..
	//and continue asking and performing tasks unless it chooses exit option..
 do 
 { 
 cout<<"\n\nWhat You want to do with your cases now"<<endl; 
 cout<<"\n1-Save new phone number\n"; 
 cout<<"2-Delete any number"<<endl; 
 cout<<"3-Search and Modify"<<endl;
 cout<<"4-See All list"<<endl;
 cout<<"5-Exit\n"<<endl; 
 cin>>ch; 
 	system("CLS");
 switch(ch) 
 { 
  case 1:  //this case is for saving new record.. 
   cout<<"\n\t============================SAVE NEW NUMBER============================\n\n"; 
   cout<<"Enter Data to insert new person's data'"<<endl; 

  cout<<"\nEnter Name \t"; 
  //getline(cin,n); 
  cin>>n; 
  cout<<"\nEnter Phone number \t";
  cin>>nm;
  cout<<"Enter Address \t";
  cin>>add;
  l1.creat_file(n,nm,add); 
   cout<<"Number of "<<n<<" has been Saved in your phone directory "<<endl; 
   break; 
  case 2:  //this case is for deletion of record..
   cout<<"\n\t=========================DELETE NUMBER============================\n\n"; 
   cout<<"\nEnter name of person whose number you want to delete\n"<<endl; 
   //getline(cin,n); 
   cin>>n; 
   l1.terminating_file(n); 
   cout<<"\nNumber of "<<n<<" Has been removed from your list"<<endl; 
   break; 
   case 3: //for searching and update..
   	cout<<"\n\t=====================SEARCH AND UPDATE NUMBER=====================\n\n";
   	cout<<"Enter NAME of Person to search it from list\t";
   	cin>>n;
   	l1.search(n);
   	break;
	case 4://for printing whole list.. including the data that is saved in file
	cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
   	l1.print_now();
   	break;	
  case 5: //printing the list that has been added now just.. it doesnot include the data of file
   cout<<"\n\t====================LIST OF Numbers added now======================\n\n"; 
   l1.print_now();
   break; 
  default: 
   cout<<"\t----------Invalid----------"<<endl; 
 } 
} 
 while(ch!=5); 
 cout<<"\nTHANK YOU"<<endl; 
 getch(); 
} 
 
 
