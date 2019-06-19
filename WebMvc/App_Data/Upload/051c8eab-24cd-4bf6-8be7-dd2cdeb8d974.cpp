#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
struct Product{
int ID;
char Barcode[13], ProductName[50], Category[20];
float Qty, PriceIn, Discount, SalePrice;
int active;
};
void Header(){
		printf("\n\t\t\t\t\t\tList Product\n");
		printf("\t\t\t\t\t\t------------\n");
	printf("ID\tBarcode\t\tProduct Name\tCategory\tQty\tPriceIn\t\tDiscount\tSalePrice\tActive\n");
}
void Input(Product *P, int n){
	printf("Input Product Information\n");
	for(int i=0; i<n; i++){
		P[i].ID = i+1;
		printf("ID : %d\n", P[i].ID);
		printf("Barcode : "); fflush(stdin); gets(P[i].Barcode);
		printf("Product Name : "); fflush(stdin); gets(P[i].ProductName);
		printf("Category  : "); fflush(stdin); gets(P[i].Category);
		printf("Quantity : "); scanf("%f", &P[i].Qty);
		printf("PriceIn : "); scanf("%f", &P[i].PriceIn);
		printf("Discount : "); scanf("%f",&P[i].Discount);
		P[i].SalePrice = P[i].PriceIn - P[i].PriceIn*(P[i].Discount/100);
		printf("SalePrice : %.2f", P[i].SalePrice);
		printf("1 -> Active\n0 -> Inactive\n");
		switch(getch()){
			case '1': P[i].active = 1; break;
			case '0': P[i].active = 0; break;
			default : P[i].active = 1; break;
		}
	}
}
void Output(Product *P, int n){
	Header();
	for(int i=0; i<n; i++){
		printf("%d\t", P[i].ID);
		printf("%s\t\t", P[i].Barcode);
		printf("%s\t", P[i].ProductName);
		printf("%s\t", P[i].Category);
		printf("%.2f\t", P[i].Qty);
		printf("%.2f\t\t", P[i].PriceIn);
		printf("%.2f\t", P[i].Discount);
		printf("%.2f\t", P[i].SalePrice);
		printf("%d\n", P[i].active);
	}
	getch();
}
void ListProduct(Product *P,int n){
	Choose:
	printf("\t 2. List all Product\n");
		printf("\t  L -> List all Product\n");
		printf("\t  A -> Active Product\n");
		printf("\t  I -> Inactive Product\n");
	switch(getch()){
		case 'L': case 'l': {
				Output(P,n);
			break;
		}
		case 'A': case 'a':{
				Header();
				for(int i=0; i<n; i++){
					if(P[i].active == 1){
						printf("%d\t", P[i].ID);
						printf("%s\t\t", P[i].Barcode);
						printf("%s\t", P[i].ProductName);
						printf("%s\t", P[i].Category);
						printf("%.2f\t", P[i].Qty);
						printf("%.2f\t\t", P[i].PriceIn);
						printf("%.2f\t", P[i].Discount);
						printf("%.2f\t", P[i].SalePrice);
						printf("%d\t", P[i].active);
					}
				}
				getch();
			break;
		}
		case 'I': case 'i': {
				Header();
				for(int i=0; i<n; i++){
				if(P[i].active == 0){
					printf("%d\t", P[i].ID);
					printf("%s\t\t", P[i].Barcode);
					printf("%s\t", P[i].ProductName);
					printf("%s\t", P[i].Category);
					printf("%.2f\t", P[i].Qty);
					printf("%.2f\t\t", P[i].PriceIn);
					printf("%.2f\t", P[i].Discount);
					printf("%.2f\t", P[i].SalePrice);
					printf("%d\t", P[i].active);
				}
			}
			getch();
			break;
		}
		default: goto Choose;
	}
	
}

void Sort(Product *P,int n){
	printf("\t 3. Sort Product\n");
		printf("\t  I -> Sort by ID\n");
		printf("\t  N -> Sort by Name\n");
		printf("\t  Q -> Sort by Quantity\n");
		printf("\t  P -> Sort by PriceIn \n");
		printf("\t  D -> Sort by Discount \n");
	Product tmp;int i, j;
	switch(getch()){
		case 'I': case 'i':{
				//Sort by ID
				printf("\tSort by ID\n");
				for(i=0; i<n-1; i++)
					for(j=i+1; j<n; j++)
						if(P[i].ID < P[j].ID){
							tmp=P[i];
							P[i]=P[j];
							P[j]=tmp;
						}	
				Output(P, n);
				break;
		}
		case 'N': case 'n': {
				//Sort by ProductName
				printf("\tSort by ProductName\n");
				for(i=0; i<n-1; i++)
					for(j=i+1; j<n; j++)
						if(strcmp(P[i].ProductName , P[j].ProductName) < 0 ){
							tmp=P[i];
							P[i]=P[j];
							P[j]=tmp;
						}	
				Output(P, n);
			break;
		}
		case 'Q': case 'q':{
				//Sort by Qty
				printf("\tSort by Quantity\n");
				for(i=0; i<n-1; i++)
					for(j=i+1; j<n; j++)
						if(P[i].Qty < P[j].Qty){
							tmp=P[i];
							P[i]=P[j];
							P[j]=tmp;
						}	
				Output(P, n);
			break;
		}
		case 'P': case 'p': {
				//Sort by PriceIn
				printf("\tSort by PriceIn\n");
				for(i=0; i<n-1; i++)
					for(j=i+1; j<n; j++)
						if(P[i].PriceIn < P[j].PriceIn){
							tmp=P[i];
							P[i]=P[j];
							P[j]=tmp;
						}	
				Output(P, n);
			break;
		}
		case 'D': case 'd':{
				//Sort by Discount
				printf("\tSort by Discount\n");
				for(i=0; i<n-1; i++)
					for(j=i+1; j<n; j++)
						if(P[i].Discount < P[j].Discount){
							tmp=P[i];
							P[i]=P[j];
							P[j]=tmp;
						}	
				Output(P, n);
			break;
		}
	}
}


void Search(Product *P,int n){
	int id,k=0;
	char name[50], barcode[13];
	printf("\t 4. Search Product\n");
		printf("\t  I -> Sort by ID\n");
		printf("\t  B -> Sort by barcode\n");
		printf("\t  N -> Sort by Name\n");
		
	switch(getch())	{
		case 'I': case 'i':{
			printf("Search(ID) :"); scanf("%d", &id);
			for(int i=0; i<n; i++){
				if(id == P[i].ID){
					Header();
					printf("%d\t", P[i].ID);
					printf("%s\t\t", P[i].Barcode);
					printf("%s\t", P[i].ProductName);
					printf("%s\t", P[i].Category);
					printf("%.2f\t", P[i].Qty);
					printf("%.2f\t\t", P[i].PriceIn);
					printf("%.2f\t", P[i].Discount);
					printf("%.2f\t", P[i].SalePrice);
					printf("%d\t", P[i].active);
					k=1;
				}
			}
				if(k==0){
					printf("ID that you enter is incorrect\n\n");
					printf("Try again..Thank you\n");
					printf("**********************\n\n");
				}
			break;
		}
		case 'B':{
			printf(" Search Barcode : "); fflush(stdin); gets(barcode);
			for(int i=0; i<n; i++){
				if(strcmp(P[i].Barcode, barcode) == 0){
					Header();
					printf("%d\t", P[i].ID);
					printf("%s\t\t", P[i].Barcode);
					printf("%s\t", P[i].ProductName);
					printf("%s\t", P[i].Category);
					printf("%.2f\t", P[i].Qty);
					printf("%.2f\t\t", P[i].PriceIn);
					printf("%.2f\t", P[i].Discount);
					printf("%.2f\t", P[i].SalePrice);
					printf("%d\t", P[i].active);
					k=1;
				}
			}
				if(k==0){
					printf("Barcode that you enter is incorrect\n\n");
					printf("Try again..Thank you\n");
					printf("**********************\n\n");
				}
			break;
		}
		case 'N':{
			printf(" Search Product Name : "); fflush(stdin); gets(name);
			for(int i=0; i<n; i++){
				if(strcmp(P[i].ProductName, name) == 0){
					Header();
					printf("%d\t", P[i].ID);
					printf("%s\t\t", P[i].Barcode);
					printf("%s\t", P[i].ProductName);
					printf("%s\t", P[i].Category);
					printf("%.2f\t", P[i].Qty);
					printf("%.2f\t\t", P[i].PriceIn);
					printf("%.2f\t", P[i].Discount);
					printf("%.2f\t", P[i].SalePrice);
					printf("%d\t", P[i].active);
					k=1;
				}
			}
				if(k==0){
					printf("Product Name that you enter is incorrect\n\n");
					printf("Try again..Thank you\n");
					printf("**********************\n\n");
				}
			break;
		}
	}
	
}
/*
void max_PriceIn(Product *P,int n){
long max;  int k;
		max=s[0].PriceIn;
		for(i=0;i<n;i++){
			if(max<P[i].PriceIn) max=P[i].PriceIn;k=i;
cout<<" "<<"The Max-PriceIn will show you below\n";
cout<<"\t\tID    : "<<P[k].ID<<endl;
cout<<"\t\tProductName  : "<<P[k].ProductName<<endl;
cout<<"\t\tPriceIn : "<<P[k].PriceIn<<endl;
cout<<"\t\tCategory : "<<P[k].Category<<endl<<endl;
}*/
void update(Product *P,int n){
	int id;
	int i, k = 0;
	char newBarcode[13], newProductName[50], newCategory[20];
	float newQty, newPriceIn, newDiscount, newSalePrice; 
	printf("\t 5. Update Product\n");
		printf("\t  1 -> Update by Product\n");
		printf("\t  2 -> Update Discount for all Product\n");
	
	switch(getch()){
		case '1': {
			printf("\t1 -> Update by Product\n");
			printf("Enter Product ID : ");scanf("%d",&id);
			for(i=0; i<n; i++){
				if(id == P[i].ID){
					printf("Enter New Discount to all Product : ");scanf("%f",newDiscount);
						Barcode:
						printf("Do you want to update Barcode? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("Enter New Barcode : "); fflush(stdin); gets(newBarcode);
								strcpy(P[i].Barcode, newBarcode);
								break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto Barcode; 
						}
						ProductName:
						printf("Do you want to update Product Name? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("Enter New Product Name : "); fflush(stdin); gets(newProductName);
								strcpy(P[i].ProductName, newProductName);
								break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto ProductName; 
						}
						Category:
						printf("Do you want to update Category? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("Enter New Category : "); fflush(stdin); gets(newCategory);
								strcpy(P[i].Category, newCategory);
								break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto Category; 
						}
						Quantity:
						printf("Do you want to update Quantity? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("Enter New Quantity : "); scanf("%f", newQty);
								P[i].Qty = newQty;
								break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto Quantity; 
						}
						PriceIn:
						printf("Do you want to update PrinceIn? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("Enter New PrinceIn : "); scanf("%f", newPriceIn);
								P[i].Qty = newPriceIn;
								break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto PriceIn; 
						}
						Discount:
						printf("Do you want to update Discount? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("Enter New Discount : "); scanf("%f", newDiscount);
								P[i].Qty = newDiscount;
								break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto Discount; 
						}
						//Sale Price
						newSalePrice = P[i].PriceIn - P[i].PriceIn*(P[i].Discount/100);
						P[i].SalePrice = newSalePrice;
						Active:
						printf("Do you want to update Product to Inactive? <Y/N>");
						switch(getch()){
							case 'Y': case 'y':{
								printf("1 -> Active\n0. Inactive\n");
									switch(getch()){
										case '1': P[i].active = 1; break;
										case '0': P[i].active = 0; break;
										default : P[i].active = 1; break;
									}
								 break;
							}
							case 'N': case 'n':{
								break;
							}
							default: goto Active; 
						}
					printf("Update Successfully...\n");
					printf("**********************\n\n");
					k=1;
				}
			}
				if(k==0){
					printf("ID that you enter is incorrect\n\n");
					printf("Update failed...Try again.\n");
					printf("**********************\n\n");
				}
			
			break;
		}
		case '2': {
			printf("\t2 -> Update Discount for all Product\n");
					printf("Enter New Discount to all Product : ");scanf("%f",newDiscount);
					for(i=0;i<n;i++){
						P[i].Discount = newDiscount;
					}
				printf("Update Successfully...\n");
					printf("**********************\n\n");
					k=1;
			break;
		}
	}
}
void Menu(){
	printf("\t********** Menu **********\n");
	printf("\t* 1. New Product\n");
		printf("\t*  C -> Create New Product\n");
		printf("\t*  A -> Add Product to List\n");
	printf("\t* 2. List all Product\n");
		printf("\t*  L -> List all Product\n");
		printf("\t*  A -> Active Product\n");
		printf("\t*  I -> Inactive Product\n");
	printf("\t* 3. Sort Product\n");
		printf("\t*  I -> Sort by ID\n");
		printf("\t*  N -> Sort by Name\n");
		printf("\t*  Q -> Sort by Quantity\n");
		printf("\t*  P -> Sort by PriceIn \n");
		printf("\t*  D -> Sort by Discount \n");
	printf("\t* 4. Search Product\n");
		printf("\t*  I -> Sort by ID\n");
		printf("\t*  B -> Sort by Barcode\n");
		printf("\t*  N -> Sort by Name\n");	
	printf("\t* 5. Update Product\n");
		printf("\t*  1 -> Update by Product\n");
		printf("\t*  2 -> Update Discount for all Product\n");
}
int main(){
	int n = 0;
	Menu:
	Menu();
	Header();
	char ch;
	scanf("%c",&ch);
	ch = getch();
	switch(ch){
		case '1': {
			Create:
			printf("*** Create Object : ***\n");
			char ch2;
			scanf("%c",&ch2);
			ch2 = getch();
			switch(ch2){
				case 'C': case 'c':{
					printf("Create N Object : "); scanf("%d",n);
					goto Menu;
				}
				case 'A': case 'a': {
					if(n == 0){
						printf("Now Product Nothing to add so you must <<Create Object First>> "); goto Menu;
					}
					else{
						printf("n is not 0 ");
					}
					goto Menu;
				}
				case 'X': case 'x': {
					break;
				}
				default: goto Menu;
			}
			//New Product
			goto Menu;
		}
		case '2':{
			//List Product
			goto Menu;
		}
		case '3': {
			//Sort Prouct
			goto Menu;
		}
		case '4': {
			//Search Product
			goto Menu;
		}
		case '5': {
			//Update Product
			goto Menu;
		}
		default: goto Menu;
	}
	return 0;
}

















