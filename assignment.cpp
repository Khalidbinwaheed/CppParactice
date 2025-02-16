#include<iostream>
#include<string>
#define CALCULATE_STOCK_VALUE
#define ENABLE_DISCOUNT
#define GENERATE_SALES_REPORT
using namespace std;
int COUNT=0;

struct productInventory {
	int prod_ID;
	string prod_Name;
	string prod_Category;
	float price;
	int stock;
	float discount;
	float revenue_Gener;
	float sale;
};

void ADDPRODUCT(productInventory prod[200]) {
	cout<<"Enter product ID :    ";  
	cin >> prod[COUNT].prod_ID;
	cin.ignore();
	cout<<"Enter prodcut name :    ";
	getline(cin , prod[COUNT].prod_Name);
	cout<<"Enter product Categoery(Electronics, clothing):   ";
	getline(cin , prod[COUNT].prod_Category);
	cout<<"Enter Price :    ";
	cin>>prod[COUNT].price;
	cout<<"Enter Stock : ";
	cin>>prod[COUNT].stock;
	cout<<"Product saved Successfully "<<endl<<endl;
	
	COUNT++;
}
void DISPLAYDETAILS(productInventory prod[200]) {
	int ID;
	cout<<"Enter product ID : ";
	cin>>ID;
	bool isFound=false;
	for(int i=0; i < COUNT ; i++) {
		if(ID == prod[i].prod_ID) {
			isFound=true;
			cout<<endl<<"Name : "<<prod[i].prod_Name<<endl
			<<"Category :"<<prod[i].prod_Category;
			cout<<endl<<"Price : "<<prod[i].price<<endl<<endl;
		}
	}
	
	if(isFound == false){
		cout<<"Invalid ID "<<endl;
	}
	cout<<endl<<"_"<<endl;
}
#ifdef ENABLE_DISCOUNT
void APPLYDISCOUNT(productInventory prod[200]) {
	int ID ;
	cout<<"Enter product ID : ";
	cin >> ID;
	bool isFound=false;
	for(int i=0 ; i<COUNT ; i++) {
		for(int j=0; j<COUNT; j++) {
		if(ID == prod[j].prod_ID){
			isFound=true;
			cout<<"Enter Discount of "<<prod[i].prod_Name<<" : ";
			cin>>prod[i].discount;
			 prod[i].sale = prod[i].price - (prod[i].price * prod[i].discount) / 100;
			 break;
		}
	}
	if(isFound == false){
		cout<<"Invalid ID "<<endl<<endl;
	}
	}
}
#endif
#ifdef CALCULATE_STOCK_VALUE
void CALCULATESTOCK(productInventory prod[200]) {
	float total_Stock=0.0;
	cout<<"Name          "<<"Stock"<<endl;
	for(int i=0; i<COUNT; i++) {
		cout<<prod[i].prod_Name<<"       "<<prod[i].stock<<endl;
		total_Stock += prod[i].price * prod[i].stock;
	}
	cout<<"Total stock available : "<<total_Stock<<endl<<endl;
}
#endif
#ifdef GENERATE_SALES_REPORT 
void CALCULATESALES(productInventory prod[200]) {
	cout<<endl<<""<<endl;
	cout<<"Name          "<<"Quantity"<<endl;
	for(int i=0; i< COUNT; i++) {
		cout<<i<<" : " << prod[i].prod_Name<<"         "<< prod[i].stock<<endl;
	}
	
	while(true) {
		cout<<"Choose products(or -1 to EXIT) : "<<endl;
		int choice;
		cin>>choice;
		if(choice==-1)
			break;	

	}
		int isdis;
		cout<<"Do you Give Discount(1:yes) : ";
		cin>>isdis;
		if(isdis==1){
			APPLYDISCOUNT(prod);
		}	
		cout<<"Process Done successfully !!"<<endl;

}
#endif
void GENERATEREVENUE(productInventory prod[200]) {
	float total_revenue=0;
	for(int f=0; f<COUNT; f++) {
		total_revenue += prod[f].sale ;
	}
	cout<<"Revenue is : "<<total_revenue<<endl;
	cout<<"_"<<endl;
}
int main() {
	struct productInventory p[200]; 
	cout<<"WELCOME TO BEENISH PRODUCT INVENTORY SYSTEM ";
	cout<<endl<<"_"<<endl<<endl;
	
	int choose ;
	do {
		cout<<"1:Add product"<<endl
		<<"2: Display Product"<<endl<<
		"3:Calculate Sales "<<endl
		<<"4:Calculate Stock values "<<endl
		<<"5:Generate Revenue"<<endl
		<<"6:Exit()"<<endl<<"Enter your Choice :   ";
		cin >> choose;
		
		switch(choose) {
			
			case 1: {
				ADDPRODUCT(p);
				break;
			}
			case 2 : {
				DISPLAYDETAILS(p);
				break;
			}
			case 3 :{
				CALCULATESALES(p);
				break;
			}
			case 4 : {
				CALCULATESTOCK(p);
				break;
			}
			case 5 : {
				GENERATEREVENUE(p);
				break;
			}
			default : {
				cout<<"Enter valid number ";
				break;
			}
			
		}
		
	} while(choose != 6);
	
	
	
	return 0;
}