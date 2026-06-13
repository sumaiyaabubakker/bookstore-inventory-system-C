#include<stdio.h>
char display_menu(void);
int add_book(int isbns[100],char titles[100][50],float prices[100],int quantities[100],int bookstock);
void process_sale(int bookstock,int quantities[100],int isbns[100]);
void low_stock_report(int quantity[100],int isbn[100],float prices[100],char titles[100][50],int bookstock);
int main()
{
	int isbns[100],quantities[100];
	char titles[100][50];
	float prices[100];
	int bookstock=0;
	printf("A command-line application to manage inventory.\n\n");
	
	

char choice;
do
{
	choice = display_menu();


switch (choice)
 {
    case '1':
    	bookstock = add_book(isbns, titles, prices, quantities, bookstock);
        break;
    case '2':
        process_sale(bookstock, quantities, isbns);
        break;
    case '3':
        low_stock_report(quantities, isbns, prices, titles,bookstock);
        break;
    default:
                printf("Invalid choice! Try again.\n");
    
}

}
while(choice!='4');
return 0;

}
char display_menu(void)
{
	char choice;
	printf("\n*******************************\n");
	printf("   LIBERTY BOOKS INVENTORY\n");
	printf("*******************************\n");
	printf("\nThese are the available choices for you:\nChoose any option:\n");
	printf("\t1.Add new book\n");
	printf("\t2.Process a sale\n");
	printf("\t3.Generate low-stock report\n");
	printf("\t4.Exit\n");
	printf("\nEnter choice:");
	while((choice=getchar())=='\n');
	return choice;
}
int add_book(int isbns[100],char titles[100][50],float prices[100],int quantities[100],int bookstock)
{
	int isbn;
	if(bookstock>=100)
	{
		printf("Book storage is full!\n");
        return bookstock;
	}
	printf("\nEnter ISBN: ");
	scanf("%d",&isbn);
	
	for(int i=0;i<bookstock;i++)
	{
		if(isbns[i]==isbn)
		{
			printf("\nThis isbn already exists in our system");
			return bookstock;
		}
	}
	isbns[bookstock]=isbn;
	printf("Enter title: ");
	scanf(" %[^\n]", titles[bookstock]);
	printf("Enter price: ");
	scanf("%f",&prices[bookstock]);
	printf("Enter quantity: ");
	scanf("%d",&quantities[bookstock]);
	printf("\nBook added successfully!\n");
	printf("-------------------------------------------\n");
	printf("\nISBN:%d\tTitle:%s\tPrice:%.2f\tQuantity:%d\n",isbns[bookstock], titles[bookstock], prices[bookstock], quantities[bookstock]);
    printf("-------------------------------------------\n");
bookstock++;
return bookstock;
	
}

void process_sale(int bookstock,int quantities[100],int isbns[100])
{
	int isbn,bookfound=0;
	int num_of_copies_sold;
	printf("\nEnter ISBN to process sale: ");
	scanf("%d",&isbn);
	printf("Enter number of copies sold: ");
	scanf("%d",&num_of_copies_sold);

	
		for(int i=0;i<bookstock;i++)
	{
		if(isbns[i]==isbn)
		{
			bookfound=1;
			if(quantities[i]>=num_of_copies_sold)
			{
				quantities[i]=quantities[i]-num_of_copies_sold;
				printf("\nSale processed successfully!\n");
				printf("Remaining Quantity:\t%d\n\n", quantities[i]);
			
			}
			else
			{
				printf("\nError! Not enough copies!\n\n");
			}
			
			break;
		}
	
		
	}		
	if (!bookfound)
	{
    printf("\nBook with ISBN %d not found.\n\n", isbn);
	}	
	
}
void low_stock_report(int quantity[100],int isbn[100],float prices[100],char titles[100][50],int bookstock)
{
	printf("\n=======LOW STOCK REPORT=======\n\n");
	int found=0;
	for (int i = 0; i < bookstock; i++)
	{
    if (quantity[i] < 5 && quantity[i] > 0)
	{
        printf("ISBN: %d\nTitle: %s\nPrice: %.2f\nQuantity: %d\n\n",
        isbn[i], titles[i], prices[i], quantity[i]);
        printf("------------------------------------\n");
        found=1;
    }
  
	}
	  if (!found) 
{
    printf("No low-stock books (quantity < 5) found.\n");

}

}




