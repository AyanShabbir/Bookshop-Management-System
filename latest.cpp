#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class Bookshop
{
	public:
		void Menu();
		int issue(); 
		int issued();
		void pass();
};
	void Bookshop::Menu()
	{
		system("cls");
		cout<<"\n\n\t\t\t\t************WELCOME TO YOUR BOOKSHOP************\n\n";
		cout<<"\n\n 1. Add New Book";
		cout<<"\n 2. Check Stock";
		cout<<"\n 3. Check Specific Book";
		cout<<"\n 4. Update Book";
		cout<<"\n 5. Delete Book";
		cout<<"\n 6. Issue Book";
		cout<<"\n 7. Check Issued Book";
		cout<<"\n 8. Exit";
	}
	
class Addbook:public Bookshop{
	public:
		
		void add_book(){
		
		system("cls");
		fstream file;
		int no_copy,price;
		string b_name,a_name,b_id;
		cout<<"\n\n\t\t\t\t*** NEW BOOK ***";
		cout<<"\n\n Enter Book ID : ";
		cin>>b_id;
		cout<<"\n\n Enter Book Name : ";
		cin>>b_name;
		cout<<"\n\n Enter Author Name : ";
		cin>>a_name;
		cout<<"\n\n Enter total stock : ";
		cin>>no_copy;
		cout<<"\n\n Enter Price : ";
		cin>>price;
		file.open("book.txt",ios::out|ios::app);
		file<<" "<<b_id<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<" "<<price<<"\n";
		file.close();
	}
};

class showbooks:public Addbook{
	
	public:
		void Stock()
	{
		system("cls");
		fstream file;
		int no_copy,price;
		string b_name,b_id,a_name;
		cout<<"\n\n Show All Books";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID      Book      Author      No. of Copies      Price\n\n";
			file>>b_id>>b_name>>a_name>>no_copy>>price;
			while(!file.eof())
			{
				cout<<"      "<<b_id<<"        "<<b_name<<"       "<<a_name<<"\t\t"<<no_copy<<"        "<<price<<"\n\n";
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
		}
	}
};

class Checkbooks:public showbooks{
	
	public:
		void check_book()
	{
		system("cls");
		fstream file;
		int no_copy,count=0;
		string b_id,b_name,a_name,b_idd;
		cout<<"\n\n Check Specific Book";
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_idd;
			file>>b_id>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_idd == b_id)
				{
					system("cls");
					cout<<"\n\n\t\t\t\tCheck Specific Book";
					cout<<"\n\n Book ID : "<<b_id;
					cout<<"\n\n Name : "<<b_name;
					cout<<"\n\n Author : "<<a_name;
					cout<<"\n\n No. of Copies : "<<no_copy;
					count++;
					break;	
				}
				file>>b_id>>b_name>>a_name>>no_copy;
			}
			file.close();
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
	}
};

class Updatebook:public Checkbooks{
	public:
		void update_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,no_co,count=0;
		string b_name,b_na,a_name,a_na,b_idd,b_id;
		cout<<"\n\n Update Book Record";
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n Update Book Record";
					cout<<"\n\n New Book Name : ";
					cin>>b_na;
					cout<<"\n\n Author Name : ";
					cin>>a_na;
					cout<<"\n\n No. of Copies : ";
					cin>>no_co;
					file1<<" "<<b_id<<" "<<b_na<<" "<<a_na<<" "<<no_co<<"\n";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}
};

class Deletebook:public Updatebook{

	public:
		void delete_book()
	{
		system("cls");
		fstream file,file1;
		int no_copy,count=0;
		string b_id,b_idd,b_name,a_name;
		cout<<"\n\n\t\t\t\tDelete Book Record";
		file1.open("book1.txt",ios::app|ios::out);
		file.open("book.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID : ";
			cin>>b_id;
			file>>b_idd>>b_name>>a_name>>no_copy;
			while(!file.eof())
			{
				if(b_id == b_idd)
				{
					system("cls");
					cout<<"\n\n Delete Book Record";
					cout<<"\n\n One Book is Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<b_idd<<" "<<b_name<<" "<<a_name<<" "<<no_copy<<"\n";
				file>>b_idd>>b_name>>a_name>>no_copy;
			}
			if(count == 0)
			cout<<"\n\n Book ID Not Found...";
		}
		file.close();
		file1.close();
		remove("book.txt");
		rename("book1.txt","book.txt");
	}
};



int Bookshop::issue(){
	
  	system("cls");
  	fstream file;
  	int book_id,m_num;
  	string book_name,c_name;
    int i;
    
  
      cout<<"\n>>Please choose genre :\n";
      cout<<"\n 1.Fiction \n\n 2.Nonfiction \n\n 3.Action and adventure \n\n 4.Biography \n\n 5.Poetry \n\n 6.Mystery \n\n 7.Go to menu\n";
      cout<<"\n\nEnter your choice : ";
      cin>>i;
      
      if(i>7){
      	cout<<"\n\t\tPlease enter correct option :(";
      	
	  }
	  else
      switch(i)
      {
          case 1: 
          	system("cls");
			cout<<"\n\n Enter Book ID : ";
			cin>>book_id;
		
			cout<<"\n\n Enter Book Name: ";
			cin>>book_name;
			
			cout<<"\n\n Enter Customer Name: ";
			cin>>c_name;
			
			cout<<"\n\n Enter Membership Number: ";
			cin>>m_num;			
                  break;
          case 2: 
		  	system("cls");
			cout<<"\n\n Enter Book ID : ";
			cin>>book_id;
		
			cout<<"\n\n Enter Book Name: ";
			cin>>book_name;
			
			cout<<"\n\n Enter Customer Name: ";
			cin>>c_name;
			
			cout<<"\n\n Enter Membership Number: ";
			cin>>m_num;	
                  break;
                  
          case 3:
          	system("cls");
			cout<<"\n\n Enter Book ID : ";
			cin>>book_id;
		
			cout<<"\n\n Enter Book Name: ";
			cin>>book_name;
			
			cout<<"\n\n Enter Customer Name: ";
			cin>>c_name;
			
			cout<<"\n\n Enter Membership Number: ";
			cin>>m_num;	
                  break;
                  
          case 4:
          	system("cls");
			cout<<"\n\n Enter Book ID : ";
			cin>>book_id;
		
			cout<<"\n\n Enter Book Name: ";
			cin>>book_name;
			
			cout<<"\n\n Enter Customer Name: ";
			cin>>c_name;
			
			cout<<"\n\n Enter Membership Number: ";
			cin>>m_num;	
                  break;
                  
          case 5:
		  	system("cls");
			cout<<"\n\n Enter Book ID : ";
			cin>>book_id;
		
			cout<<"\n\n Enter Book Name: ";
			cin>>book_name;
			
			cout<<"\n\n Enter Customer Name: ";
			cin>>c_name;
			
			cout<<"\n\n Enter Membership Number: ";
			cin>>m_num;	
                  break;
                  
          case 6:
          	system("cls");
			cout<<"\n\n Enter Book ID : ";
			cin>>book_id;
		
			cout<<"\n\n Enter Book Name: ";
			cin>>book_name;
			
			cout<<"\n\n Enter Customer Name: ";
			cin>>c_name;
			
			cout<<"\n\n Enter Membership Number: ";
			cin>>m_num;	
                  break;
                  
          case 7: system("cls");
                 
                Menu();
                
       	
		file.open("issuebook.txt",ios::in);
		file<<" "<<book_id<<" "<<book_name<<" "<<c_name<<" "<<m_num<<"\n";
		file.close();
          
                    getch();
                    system("cls");
                    issue();
                    
        getch();
		Bookshop::Menu();            
        }
  }

int Bookshop::issued(){
		
		system("cls");
		fstream file;
		int book_id,m_num;
		string book_name,c_name;
		cout<<"\n\n ISSUED BOOKS";
		file.open("issuebook.txt",ios::out|ios::app);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else
		{
			cout<<"\n\n Book ID     Book     Customer name   Membership no.\n\n";
			file>>book_id>>book_name>>c_name>>m_num;
			while(!file.eof())
			{
				cout<<"    "<<book_id<<"     "<<book_name<<"     "<<c_name<<"\t\t"<<m_num<<"\n\n";
				file>>book_id>>book_name>>c_name>>m_num;
			}
			file.close();
		getch();
		Bookshop::Menu();
		}		
}

void Bookshop::pass()
{
	
	cout<<"---Enter Passcode to access the software---\n";
    int i=0;
    char ch,st[21],ch1[21]={"secret"};
    cout<<"\n\n\nEnter Password : ";
    while(1)
    {
	    ch=getch();
	    if(ch==13)
	    {
	        st[i]='\0';
	        break;
	    }
	    else if(ch==8&&i>0)
	    {
	        i--;
	        cout<<"\b \b";
	    }
	    else
	    {
	    cout<<"*";
	    st[i]=ch;
	    i++;
	    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        Menu();
    }
    else
    {
        cout<<"\n\n\n Wrong Password.\n\n Try again\n";
        getch();
        system("cls");
       
    }
}

main()
{
	int choice;
	char x;
	Deletebook d;
	
	d.pass();
	p:
	d.Menu();
	cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			d.add_book();
			cout<<"\n\n Do You Want to addbook another Book (y,n) : ";
			cin>>x;
		    }while(x == 'y');
		    d.Menu();
			break;
		case 2:
			d.Stock();
			break;
		case 3:
			d.check_book();
			break;
		case 4:
			d.update_book();
			break;
		case 5:
			d.delete_book();
			break;
		case 6:
			d.issue();
			cout<<"\n\n\n Record stored. You can Issue the book.\n";
			break;
		case 7:
			d.issued();
			break;
		case 8:
			exit(0);

		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
	getch();
	goto p;
}
