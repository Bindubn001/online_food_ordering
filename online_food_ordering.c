#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
  
	float data;
	char foodname[50];
	int quantity;
	float price;
    struct node *next;
}node;
typedef struct head
{
    node *start;
}head;

int   counter =0;

void insertend(head *t, float data, char foodname[25], int quantity, float price)
{
    node *p, *q;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->quantity=quantity;
    p->price=price;
    strcpy(p->foodname, foodname);
    p->next=NULL;
    if(t->start==NULL)
    {
        t->start=p;
    }
    else
    {
        q=t->start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
void foodlist(head *t)
{

	printf("\n\t"); 
	printf("________________________________________________________");
	printf("\n\t"); 
	printf("  Food Code          Name                  Price         ");
	printf("\n\t"); 
	printf("-------------------------------------------------------");

	node *p;
    p=t->start;
    while(p!= NULL)
    {
        printf("\n\t");
        printf("  %0.1f   |  %-25s     |    %0.2f   ",p->data,p->foodname,p->price);
		printf("\n\t");
        printf("-------------------------------------------------------");
        p=p->next;
    }
}
void foodlist1(head *t)
{
	printf("\n\t"); 
	printf("_______________________________________________________");
	printf("\n\t"); 
	printf("  Food Code       Name           Quantity     Price   ");
	printf("\n\t"); 
	printf("--------------------------------------------------------------");

	node *p;
    p=t->start;
    while(p!= NULL)
    {
		printf("\n\t");
        printf("  %0.1f   |  %-25s      |    %2d      |  %0.2f   ",p->data,p->foodname, p->quantity, p->price);
		printf("\n\t");
		printf("----------------------------------------------------------------");
        p=p->next;
    }
}
float getbill(head *t)
{
    node *p;
    float b=0;
    p=t->start;
    while(p!=NULL)
    {
        b=b+p->price;
        p=p->next;
    }
    return b;
}
void order(head *t, head *l,float fc, int qty)
{
    node *p;
    p=t->start;
    while(p->data!=fc)
    {
        p=p->next;
    }
    insertend(l, fc, p->foodname, qty, (p->price*qty));
    counter++;
    return;
}
void cls()
{
    system("clear");
}

void delete(head *t, float fc)
{
	int i = 1;
	node *p, *prev = NULL;
	p = t->start;
	while(p->data != fc)
	{
		prev = p;
		p = p->next;
		i++;
	}
	if(i==1)
	{
		p = p->next;
		t->start = p;
    
    
	}
	else if(i==counter && counter >1)
	{
		free(p);
		prev->next = NULL;
	}
	else
	{
		prev->next = p->next;
		free(p);
	}
	printf("Item Cancelled. Present order is\n");
	foodlist1(t);

}
void main()
{
   printf("\t\t\t WELCOME TO MAGICAL CAFE :)");
    head  s, m, d, o;
    s.start=m.start=d.start=o.start=NULL;
    float fcode;
    int qty, lo;
    insertend(&s, 1.1, "Samosa", 1, 50);
    insertend(&s, 1.2, "Grilled Cheese Sandwich", 1, 100);
    insertend(&s, 1.3, "Nachos", 1, 150);
    insertend(&s, 1.4, "Chicken Burger", 1, 150);
    insertend(&s, 1.5, "BBQ Chicken Roll", 1, 250);
    insertend(&s, 1.6, "Cheesy Fries", 1, 100);
    insertend(&s, 1.7, "Peri Peri Fries", 1, 150);
    insertend(&s, 1.8, "Paneer Tikka", 1, 200);
    insertend(&s ,1.9, "Baby Corn Manchurian", 1, 250);
    insertend(&s, 2.0, "BBQ Paneer Sandwich", 1, 150);
    insertend(&m, 2.1, "Pav Bhaji", 1, 200);
    insertend(&m, 2.2, "Punjabi Thali", 1, 350);
    insertend(&m, 2.3, "Mexican Sizzler", 1, 250);
    insertend(&m, 2.4, "Peri Peri Chicken Pizza", 1, 250);
    insertend(&m, 2.5, "Margherita Pizza", 1, 200);
    insertend(&m, 2.6, "Veg Pulao", 1, 250);
    insertend(&m, 2.7, "Chicken Handi Biryani", 1, 350);
    insertend(&m, 2.8, "mexican green wave pizza", 1, 250);
    insertend(&m, 2.9, "red sauce pasta", 1, 200);
    insertend(&m, 3.0, "non veg treat  pizza", 1, 250);
    

insertend(&m, 3.1, "white sauce pasta", 1, 200);    insertend(&d, 3.2, "Chocolate Overload Waffle", 1, 150);
    insertend(&d, 3.3, "Cinnamon Waffle", 1, 150);
    insertend(&d, 3.4, "Chocolate Cake", 1, 250);
    insertend(&d, 3.5, "Red Velvet Cake", 1, 350);
    insertend(&d, 3.6, "Strawberry Mousse", 1, 100);
    insertend(&d, 3.7, "Orea Freakshake", 1, 150);
    insertend(&d, 3.8, "Fruit Milkshake", 1, 80);
    insertend(&d, 3.9, "lemon juice", 1, 50);
    insertend(&d, 4.0 , "Cocktail", 1, 120);
    
    int i=0, ch;
    while(1)
    {
        cls();

      mainmenu: printf("\n\n\nEnter your choice:\n Enter 1 to View Menu \n Enter 2 to View Previous Order \n Enter 3 to Know About us\n Enter 4 to Exit\n");
                scanf("%d", &ch);
                if(ch==2)
                {
                    if(o.start==NULL)
                    {
                        printf("Previous Order does not exist!\n");
                     
               
                        goto mainmenu;
                    }
                    else
                    {
                        cls();
                        foodlist1(&o);
                        printf("\nPress 0 to continue.\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            goto mainmenu;
                        }
                    }

                }
                else if(ch==1)
                {
             order: printf("Enter your Choice:\n");
                    printf(" Enter 1 to view  SNACKS \n Enter 2 to view MAIN COURSE\n Enter 3 to view DESSERTS\n");
                    scanf("%d", &ch);
                    while(1){
                    switch(ch)
                    {
                        case 1: foodlist(&s);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&s, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 2: foodlist(&m);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&m, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 3: foodlist(&d);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&d, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        default: printf("Invalid Choice.\n");
                    }
        afterorder: printf("\n\n");
                    printf("\n\t\tEnter Choice: \n\t\t1.Hungry For More? \n\t\t2.View Order \n\t\t3. Cancel Item\n\t\t4.Confirm Order?\n");
                    scanf("%d", &ch);
                    if(ch==1)
                    {
                        cls();
                        goto order;
                    }
                    else if(ch==2)
                    {
                        cls();
                        printf("Current Order:\n");
                        foodlist1(&o);
                        goto afterorder;
                    }
		    else if(ch==3)
		    {
			printf("Enter the food code of the item you want to remove from the order\n");
			scanf("%f",&fcode);
			delete(&o,fcode);
			goto afterorder;
		     }
                    //billing
                    else if(ch==4)
                    {
                        char namee[20];
                        char address[20];
                        int phone;
                        cls();
                        printf("Enter your name\n");
                        scanf("%s",namee);
                        printf("Enter your phone number\n");
                        scanf("%d",&phone);
                        printf("Enter your address\n");
                        scanf("%s",address);
                        foodlist1(&o);
                        printf("\nTotal amount to pay: %0.2f\n", getbill(&o));
                        printf("Hey %s sit back and relax while we deliver your order.",namee);
                        printf("\nEnjoy Your Meal!\n");
                        printf("\nPress 0 to continue or Press 1 to give Feedback.\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            cls();
                            goto mainmenu;
                        }
                        else if(ch==1)
                        {
                          int fed;
                          printf("\n\t\t1.worst\n\t\t2.Very bad\n\t\t3.Average\n\t\t4.very good\n\t\t5.Excellent\n");
                          printf("\nPlease rate us accordingly.\n");
                          scanf("%d",&fed);
                          printf("Thank You for your Feedback!");
                          break;
                        }
                    }
                }
                }
                else if(ch==3)
                {
                    cls();
                    printf("Topic : Restaurent Food Ordering System.\nGroup members : Anagha MH and Bindushree BN\n");
                    break;
		    
                    
                }
                else if(ch==4)
                {
                  cls();
                  exit(0);
                  
                }
                else
                    printf("\nInvalid Choice.\n");
                    break;
            }
}
