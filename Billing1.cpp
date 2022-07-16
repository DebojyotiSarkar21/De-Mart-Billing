#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float discount;
		string pname;
		
		public:
			void menu();
			void admin();
			void customer();
			void add();
			void edit();
			void delet();
			void list();
			void receipt();
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t\t____________________________\n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\t\t\t\t\t    De-Market Main Menu     \n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\t\t\t\t\t____________________________\n";
	cout<<"\t\t\t\t\t                            \n";
	cout<<"\t\t\t   |  1) Administrator  |\n";
	cout<<"\t\t\t   |                    |\n";
	cout<<"\t\t\t   |  2) Consumer       |\n";
	cout<<"\t\t\t   |                    |\n";
	cout<<"\t\t\t   |  3) Exit           |\n";
	cout<<"\t\t\t   |                    |\n";
	cout<<"\t\t\t      Please select! \n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email  ";
			cin>>email;
			cout<<"\t\t\t Password     ";
			cin>>password;
			
			if(email == "debojyoti21@email.com" && password == "debo@123")
			{
				admin();
			}
			else
			{
				cout<<"Invalid email/password";
				                                            
			}
			break;
	
		case 2:
			{
				customer();
			}
		
		case 3:
			{
				exit(0);
			}
		
		default:
			{
				cout<<"Please select from the given options!";
			}
	
}
			

goto m;
}

void shopping :: admin()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t\t Administrator Menu\n";
	cout<<"\n\t\t\t|                             |\n";
	cout<<"\n\t\t\t|_____1) Add Product          |\n";
	cout<<"\n\t\t\t|                             |\n";
	cout<<"\n\t\t\t|_____2) Modify Product       |\n";
	cout<<"\n\t\t\t|                             |\n";
	cout<<"\n\t\t\t|_____3) Delete Product       |\n";
	cout<<"\n\t\t\t|                             |\n";
	cout<<"\n\t\t\t|_____4) Back to main menu    |\n";
	
	
	cout<<"\n\t\t\t Please enter your choice!";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
			
		case 2:
			edit();
			break;
			
		case 3:
			delet();
			break;
			
		case 4:
			menu();
			break;
			
		default:
			cout<<"Invalid Choice!";
							
	}
	goto m;
}


void shopping :: customer()
{
	m:
	int choice;
	cout<<"\n\t\t\t   Consumer Interface   \n";
	cout<<"\n\t\t\t|________________________|";
	cout<<"\n\t\t\t|                        |";	
	cout<<"\n\t\t\t|1) Buy Product          |";
	cout<<"\n\t\t\t|                        |";
	cout<<"\n\t\t\t|2) Go Back              |";
	cout<<"\t\t\t Enter ypur choice :";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout<<"Invalid Choice!"	;
	}
	
	goto m;
		
}

void shopping :: add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t   Add new product  \n";
	cout<<"\n\t\t\t                                      ";	
	cout<<"\n\t\t\t   Product code of the product  \n";
	cin>>pcode;
	cout<<"\n\t\t\t   Name of the product   \n";
	cin>>pname;
	cout<<"\n\t\t\t   Price of the product   \n";
	cin>>price;
	cout<<"\n\t\t\t   Discount on product   \n";
	cin>>discount;
	
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	
	if(token == 1)
	goto m;
	else{
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
}
	cout<<"\n\n\t\t  Record inserted !";
	
}

void shopping :: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t  Modify record";
	cout<<"\n\t\t\t product code :";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n File doesnot exist!";
	}
	else{
		
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pkey == pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
				
			}
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found! Sorry! ";
		}
	}
}

void shopping :: delet()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t\t Delete Product ";
	cout<<"\n\n\t\t Product code : ";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<" File doesnot exist!";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product removed successfully";
				token++;
			}
			else
			{
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			}
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token == 0)
		{
			cout<<"\n\n Record not found";
		}
	}
	
}

void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n ________________________________\n";
	cout<<"ProCode\t\tName\t\tPrice\n";
	cout<<"\n\n ________________________________\n";
	data>>pcode>>pname>>price>>discount;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>discount;
		
	}
	data.close();
}

void shopping :: receipt()
{
	
	fstream data;
	
	int arrc[100];
	int arrq[100];
	string choice;
	int c=0;
	float amount = 0;
	float discount = 0;
	float total = 0;
	
	cout<<"\n\n\t\t\t SHOPPING Menu ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"Empty DataBase";
	}
	else
	{
		data.close();
		
		list();
		cout<<"\n______________________________________\n";
		cout<<"\n                                      \n";
		cout<<"\n        Please place your order       \n";
		cout<<"\n                                      \n";
		cout<<"\n______________________________________\n";
		do
		{
			m:
			cout<<"\n\n Enter Product Code :";
			cin>>arrc[c];
			cout<<"\n\n Enter Product Quantity :";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code. Please try again";
					goto m;
				}
			}
			c++;
			cout<<"\n\n\t Do you want to buy another product? If yes press y else press no :";
			cin>>choice;
		}
		while(choice == "y" );
		
		cout<<"\n\n\t\t\t_________________RECEIPT____________________\n";
		cout<<"\n Product No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with Discount\n";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>discount;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount = price * arrq[i];
					discount = amount - (amount * discount/100);
					total = total + discount+ amount;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount;
				}
				data>>pcode>>pname>>price>>discount;
			}
		}
		data.close();
	}
	cout<<"\n\n\n____________________________________________________";
	cout<<"\n Total Amount: "<<total;
}

int main()
{
	shopping s;
	s.menu();
}

