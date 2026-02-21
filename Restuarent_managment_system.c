#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEM 50
#define MAX_ORDER 100

struct MenuItem{
    int id;
    char name[50];
    float price;
};

struct order{
    int itemID;
    int quantity;
};

struct MenuItem menu[MAX_ITEM];
struct order allOrders[MAX_ORDER];
    int itemCount =0, orderCountTotal =0;
    float grandTotal=0;

    void clearInputBuffer(){
        while(getchar() != '\n');
    }

void addMenuItem(){
    if(itemCount >= MAX_ITEM){
    printf("Menu Is full\n");
    return;
    }
    menu[itemCount].id = itemCount + 1;
    printf("Enter Item Name: ");
    clearInputBuffer();
    fgets(menu[itemCount].name,50, stdin);
    menu[itemCount].name[strcspn(menu[itemCount].name,"\n")] = 0;
    printf("Enter Item Price: ");
    scanf("%f",&menu[itemCount].price);
    itemCount++;
    printf("!!Item added Successfully!!\n");
}
void displayMenu(){
    if(itemCount == 0){
       printf("Please order something first\n");
       return;
    }
    printf("\n.......Menu.......\n");
    for(int i=0;i<itemCount;i++){
    printf("%d.%s---%0.2f\n",menu[i].id,menu[i].name,menu[i].price);
    }
}
void allOrder(){
   if(itemCount==0){
     printf("You haven't' ordered anything. Add item/s fist\n");
     return;
   }

   int orderCount;
   printf("How many items do you want to order: ");
   scanf("%d",&orderCount);

   float total =0;
   for(int i=0;i<orderCount;i++){
    printf("Enter items ID: ");
    scanf("%d",&allOrders[orderCountTotal].itemID);
    printf("Enter quantity: ");
    scanf("%d",&allOrders[orderCountTotal].quantity);

      if(allOrders[orderCountTotal].itemID<=0 || allOrders[orderCountTotal].itemID> itemCount){
       printf("This item doesn't exit\n");
       i--;
       continue;
      }


      total += menu[allOrders[orderCountTotal].itemID - 1].price * allOrders[orderCountTotal].quantity;
      orderCountTotal++;
   }

   grandTotal +=total;
   printf("\n.................Bill............\n");
   for(int i=orderCountTotal - orderCount; i<orderCountTotal; i++){
     printf("%s x %d----%.2lf\n",menu[allOrders[i].itemID - 1].name, allOrders[i].quantity, menu[allOrders[i].itemID - 1].price * allOrders[i].quantity);
     printf("\n..................................\n");
   }
   printf("Total: %.2lf\n",total);
}

void displaySummary(){
    if(orderCountTotal==0){
        printf("No Orders have been decleared.\n");
        return;
    }
    printf("\n...........Order Summery............\n");
    for(int i=0; i<orderCountTotal;i++){
        printf("%s x %d----%.2lf",menu[allOrders[i].itemID - 1].name, allOrders[i].quantity, menu[allOrders[i].itemID - 1].price * allOrders[i].quantity);
        printf("\n...........................................\n");
    }
    printf("Grand total: %.2lf",grandTotal);
}

int main(){
    int options;
    while(1){
        printf("\t \n--- Restaurant Management System ---\n");
        printf("Press (1) to ADD MENU ITEM \n");
        printf("Press (2) to DISPLAY MENU\n ");
        printf("Press (3) to TAKE ORDER\n");
        printf("Press (4) to EXIT\n");


        printf("Enter your choice: ");
        scanf("%d",&options);



    switch(options){
      case 1:
      addMenuItem();
      break;

      case 2:
      displayMenu();
      break;

      case 3:
      allOrder();
      break;

      case 4:
      displaySummary();
      printf("\nThanks for your order\n");
      return 0;


      default:
        printf("Please choose among showing numbers\n");
          }
    }
          return 0;

}


