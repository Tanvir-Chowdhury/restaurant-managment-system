#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>


typedef struct Restaurant
{
    char name[100];
    int id;
    char ingre[80];
    int price;
    int dis;
    int vat;
}res;

typedef struct chef
{
    char name[100];
    int id;
    int b_day;
    int b_month;
    int b_year;
    char phone_num[20];
    char address[500];
}chef;

typedef struct orders
{
    char name[100];
    char phone_num[20];
    char email[100];
    int food_id;
    int quantity;
    float price;
}ord;

typedef struct reciept
{
    int ord_num;
    char name[100];
    char phone_num[20];
    char email[100];
    char food_id[200];
    float price;
}rct;

void admin_header() //For printing header in admin window
{
    system("cls");
    printf("\n                                                      BEEF PALAZZO\n");
    printf("                                   *************************************************\n");
    printf("                                                WELCOME TO ADMIN WINDOW\n");
    printf("                                   *************************************************\n\n");
}

void customer_header() //For printing header in customer window
{
    system("cls");
    printf("\n                                                      BEEF PALAZZO\n");
    printf("                                   *************************************************\n");
    printf("                                               WELCOME TO CUSTOMER WINDOW\n");
    printf("                                   *************************************************\n\n");
}

void chef_header() //For printing header in chef window
{
    system("cls");
    printf("\n                                                      BEEF PALAZZO\n");
    printf("                                   *************************************************\n");
    printf("                                                 WELCOME TO CHEF WINDOW\n");
    printf("                                   *************************************************\n\n");
}

void add_food() //For adding food on the menu
{
    int n;
    printf("\tHow many food item do you want to add?\n\t ->");
    scanf("%d",&n);

    FILE *fp;
    fp=fopen("food.txt","a");

    res x[n];
    for(int i=0; i<n; i++){
            admin_header();

            printf("\n  Adding food: %d\n", i+1);
            fflush(stdin);
            printf("\tFood Name (Replace spaces with hyphens): ");
            gets(x[i].name);
            fprintf(fp,"%s ",x[i].name);

            printf("\tFood ID: ");
            scanf("%d",&x[i].id);
            fprintf(fp,"%d ",x[i].id);

            fflush(stdin);
            printf("\tIngredients (Replace spaces with hyphens): ");
            gets(x[i].ingre);
            fprintf(fp,"%s ",x[i].ingre);

            printf("\tPrice per unit: ");
            scanf("%d",&x[i].price);
            fprintf(fp,"%d ",x[i].price);

            printf("\tDiscount: ");
            scanf("%d",&x[i].dis);
            fprintf(fp,"%d ",x[i].dis);

            printf("\tVat: ");
            scanf("%d",&x[i].vat);
            fprintf(fp,"%d\n",x[i].vat);
    }
    fclose(fp);
}

void display_food() // For displaying food menu
{
    res f[1000];
    FILE *fp;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("\tFile Error!!!");
    }
    else
    {
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %s %d %d %d\n",&f[i].name, &f[i].id, &f[i].ingre, &f[i].price, &f[i].dis, &f[i].vat);
            printf("\tFood ID: %d\n",f[i].id);
            printf("\tFood Name: %s\n",f[i].name);
            printf("\tIngredients: %s\n",f[i].ingre);
            printf("\tPrice: %d\n",f[i].price);
            printf("\tDiscount: %d%%\n",f[i].dis);
            printf("\tVat: %d%%\n",f[i].vat);
            printf("\n");
            printf("   ----------------------------------------------------------------------------------------------------------------\n\n");

            i++;
        }
    }

    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

void delete_food() //For deleting food item
{
    int del_id, count;
    fflush(stdin);
    printf("\tEnter the food id that you want to remove from menu: ");
    scanf("%d",&del_id);

    res f[1000];
    FILE *fp;
    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i = 0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %s %d %d %d\n", &f[i].name, &f[i].id, &f[i].ingre, &f[i].price, &f[i].dis, &f[i].vat);
            count++;
            i++;
        }
    }
    fclose(fp);

    fp=fopen("food.txt","w");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(f[i].id==del_id)
            {
                flag++;
                continue;
            }

            fprintf(fp,"%s ",f[i].name);
            fprintf(fp,"%d ",f[i].id);
            fprintf(fp,"%s ",f[i].ingre);
            fprintf(fp,"%d ",f[i].price);
            fprintf(fp,"%d ",f[i].dis);
            fprintf(fp,"%d\n",f[i].vat);


        }
        if(flag==0){
            Beep(600,500);
            printf("\n\tInvalid Food ID!!!\n");
        }
        else{
            printf("\n\tFood Item Removed Successfully\n");
        }
    }
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
    fclose(fp);
}

void edit_food() //For Editing food items
{
    int ed_id;
    fflush(stdin);
    printf("\tEnter the food id that you want to edit from menu: ");
    scanf("%d",&ed_id);

    res f[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %s %d %d %d\n", &f[i].name, &f[i].id, &f[i].ingre, &f[i].price, &f[i].dis, &f[i].vat);
            count++;
            i++;
        }
    }
    fclose(fp);

    fp=fopen("food.txt","w");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(f[i].id==ed_id)
            {
                flag++;
                printf("\tEnter new info of food id - %d:\n",f[i].id);
                fflush(stdin);
                printf("\tFood Name (Replace spaces with hyphens): ");
                gets(f[i].name);
                fprintf(fp,"%s ",f[i].name);

                printf("\tFood ID: ");
                scanf("%d",&f[i].id);
                fprintf(fp,"%d ",f[i].id);

                fflush(stdin);
                printf("\tIngredients (Replace spaces with hyphens): ");
                scanf("%s",&f[i].ingre);
                fprintf(fp,"%s ",f[i].ingre);

                printf("\tPrice per unit: ");
                scanf("%d",&f[i].price);
                fprintf(fp,"%d ",f[i].price);

                printf("\tDiscount: ");
                scanf("%d",&f[i].dis);
                fprintf(fp,"%d ",f[i].dis);

                printf("\tVat: ");
                scanf("%d",&f[i].vat);
                fprintf(fp,"%d\n",f[i].vat);
                continue;
            }

            fprintf(fp,"%s ",f[i].name);
            fprintf(fp,"%d ",f[i].id);
            fprintf(fp,"%s ",f[i].ingre);
            fprintf(fp,"%d ",f[i].price);
            fprintf(fp,"%d ",f[i].dis);
            fprintf(fp,"%d\n",f[i].vat);


        }
        if(flag==0)
        {
            Beep(600,500);
            printf("\n\tInvalid Food ID!!!\n");
        }

        else
        {
            printf("\n\tFood Item Edited Successfully\n");
        }
    }
    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

void search_food() //For searching food
{
    char name[100];
    fflush(stdin);
    printf("\tEnter a food name that you want to search (Replace spaces with hyphens): ");
    gets(name);

    res f[1000];
    FILE *fp;
    int count;

    fp=fopen("food.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        int flag=0;
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %s %d %d %d\n",&f[i].name, &f[i].id, &f[i].ingre, &f[i].price, &f[i].dis, &f[i].vat);
            if(strcmp(name,f[i].name)==0)
            {
                flag++;
                printf("\n\tFood ID: %d\n",f[i].id);
                printf("\tFood Name: %s\n",f[i].name);
                printf("\tIngredients: %s\n",f[i].ingre);
                printf("\tPrice: %d\n",f[i].price);
                printf("\tDiscount: %d%%\n",f[i].dis);
                printf("\tVat: %d%%\n",f[i].vat);
                printf("\n\n");
            }
            i++;
        }

        if(flag==0)
        {
            Beep(600,500);
            printf("\tThere is no food item by this name.\n");
        }
    }

    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

void order_food() //For ordering food
{
    rct order;
    res f[1000];
    FILE *fp;
    FILE *fp2;
    int count,flag=0,order_num;
    char food_id_quant[1000]="";

    fp=fopen("food.txt","r");
    fp2 = fopen("order.txt", "r");

    if(fp2==NULL)
    {
        order_num = 1;
    }
    else
    {
        while(!feof(fp2))
        {
            fscanf(fp2,"%d %s %s %s %s %f\n", &order.ord_num, &order.name, &order.phone_num, &order.email, &order.food_id, &order.price);
        }
        order_num = order.ord_num+1;
    }

    fclose(fp2);

    ord o;
    fp2 = fopen("order.txt", "a");
    fprintf(fp2, "%d ", order_num);
    fflush(stdin);
    printf("\n\tEnter your name(Replace spaces with hyphens): ");
    gets(o.name);
    fprintf(fp2,"%s ",o.name);

    fflush(stdin);
    printf("\tEnter your phone number: ");
    gets(o.phone_num);
    fprintf(fp2,"%s ",o.phone_num);

    fflush(stdin);
    printf("\tEnter your email: ");
    gets(o.email);
    fprintf(fp2,"%s ",o.email);

    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %s %d %d %d\n",&f[i].name, &f[i].id, &f[i].ingre, &f[i].price, &f[i].dis, &f[i].vat);
            count++;
            i++;
        }
    }
    fclose(fp);
    int ord_id;
    o.price = 0;
    while(1)
    {
        customer_header();
        printf("\n\tEnter food id that your want to order: ");
        scanf("%d",&ord_id);
        for(int i=0; i<count; i++)
        {
            if(ord_id==f[i].id)
            {
                flag++;
                o.food_id = ord_id;
                printf("\tEnter quantity: ");
                fflush(stdin);
                scanf("%d", &o.quantity);
                o.price += (f[i].price*o.quantity)+(f[i].price*o.quantity*(f[i].vat/100.0))-((f[i].price*o.quantity*(f[i].dis/100.0)));
                char food_id_ch[15];
                itoa(o.food_id, food_id_ch, 10);
                strcat(food_id_quant, food_id_ch);
                strcat(food_id_quant, "(");
                char quant_ch[5];
                itoa(o.quantity, quant_ch, 10);
                strcat(food_id_quant, quant_ch);
                strcat(food_id_quant, "),");
            }
        }
        if(flag==0){
            Beep(600,500);
            printf("Invalid Food ID !!!");
            break;
        }
        int x;
        customer_header();
        printf("\tDo you want to order anything else?\n\t1.Yes.\n\t2.No\n");
        printf("\tEnter your choice: ");
        scanf("%d",&x);

        if(x==1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    fprintf(fp2, "%s ", food_id_quant);
    fprintf(fp2, "%.2f\n", o.price);
    fclose(fp);
    fclose(fp2);
    customer_header();
    printf("\n                                             *** Order number - %d ***\n\n",order_num);
    printf("\t\tCustomer Name: %s\n", o.name);
    printf("\t\tCustomer Phone Number: %s\n", o.phone_num);
    printf("\t\tCustomer Email: %s\n", o.email);
    printf("\t\tOrdered Food And Quantity: %s\n", food_id_quant);
    printf("   ----------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                           Total payable money: %.2f BDT\n\n", o.price);

    fflush(stdin);
    printf("\n\t(Press Enter)");
    getchar();

}

int cancel_serve_order() //For canceling order in customer window and serving order in chef window
{
    int count, can_id;
    rct order[1000];

    FILE *fp;
    fp = fopen("order.txt","r");

    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i = 0;
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %s %s %s %f\n", &order[i].ord_num, &order[i].name, &order[i].phone_num, &order[i].email, &order[i].food_id, &order[i].price);
            count++;
            i++;
        }
    }
    fclose(fp);

    fflush(stdin);
    printf("\n\tEnter order ID: ");
    scanf("%d",&can_id);

    fp=fopen("order.txt","w");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(order[i].ord_num == can_id)
            {
                flag++;
                continue;
            }

            fprintf(fp,"%d ",order[i].ord_num);
            fprintf(fp,"%s ",order[i].name);
            fprintf(fp,"%s ",order[i].phone_num);
            fprintf(fp,"%s ",order[i].email);
            fprintf(fp,"%s ",order[i].food_id);
            fprintf(fp,"%.2f\n",order[i].price);


        }
        if(flag==0){
            Beep(600,500);
            printf("\n\tInvalid Order ID!!!\n");
            fclose(fp);
            fflush(stdin);
            printf("\t(Press Enter)");
            getchar();
        }
        else{
            fclose(fp);
            return 1;
        }
    }
return 0;
}

void display_orders_admin() //For displaying orders in admin window
{
    rct order[500];
    FILE *fp;

    fp=fopen("order.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("\tFile Error!!!");
    }
    else
    {
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %s %s %s %f\n", &order[i].ord_num, &order[i].name, &order[i].phone_num, &order[i].email, &order[i].food_id, &order[i].price);
            printf("\tOrder ID: %d\n",order[i].ord_num);
            printf("\tCustomer Name: %s\n",order[i].name);
            printf("\tCustomer Phone Number: %s\n",order[i].phone_num);
            printf("\tCustomer Email: %s\n",order[i].email);
            printf("\tFood ID And Quantity: %s\n",order[i].food_id);
            printf("\tTotal: %.2f BDT\n",order[i].price);
            printf("\n");
            printf("   ----------------------------------------------------------------------------------------------------------------\n\n");

            i++;
        }
    }

    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

void display_order_chef() //For displaying orders in chef window
{
    rct order[500];
    FILE *fp;

    fp=fopen("order.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("\tFile Error!!!");
    }
    else
    {
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %s %s %s %f\n", &order[i].ord_num, &order[i].name, &order[i].phone_num, &order[i].email, &order[i].food_id, &order[i].price);
            printf("\tOrder ID: %d\n",order[i].ord_num);
            printf("\tFood ID And Quantity: %s\n",order[i].food_id);
            printf("\n");
            printf("   ----------------------------------------------------------------------------------------------------------------\n\n");

            i++;
        }
    }

    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

void add_chef() //For adding chef
{
    int n;
    printf("\tHow many chef's account do you want to add?\n\t ->");
    scanf("%d",&n);

    FILE *fp;
    fp=fopen("chefs.txt","a");

    chef c[n];
    for(int i=0; i<n; i++){
            admin_header();

            printf("\n  Adding Chef account: %d\n", i+1);
            fflush(stdin);
            printf("\tChef Name (Replace spaces with hyphens): ");
            gets(c[i].name);
            fprintf(fp,"%s ",c[i].name);

            printf("\tChef ID: ");
            scanf("%d",&c[i].id);
            fprintf(fp,"%d ",c[i].id);

            fflush(stdin);
            printf("\tBirth Day (DD): ");
            scanf("%d", &c[i].b_day);
            fprintf(fp,"%d ",c[i].b_day);

            fflush(stdin);
            printf("\tBirth Month (MM): ");
            scanf("%d", &c[i].b_month);
            fprintf(fp,"%d ",c[i].b_month);

            fflush(stdin);
            printf("\tBirth Year (YYYY): ");
            scanf("%d", &c[i].b_year);
            fprintf(fp,"%d ",c[i].b_year);

            fflush(stdin);
            printf("\tPhone Number: ");
            gets(c[i].phone_num);
            fprintf(fp,"%s ",c[i].phone_num);

            fflush(stdin);
            printf("\tAddress (Replace spaces with hyphens): ");
            gets(c[i].address);
            fprintf(fp,"%s\n",c[i].address);
    }
    fclose(fp);

}

void display_chef() //For displaying all chef's info
{
    chef c[100];
    FILE *fp;

    fp=fopen("chefs.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("\tFile Error!!!");
    }
    else
    {
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %d %d %d %s %s\n",&c[i].name, &c[i].id, &c[i].b_day, &c[i].b_month, &c[i].b_year, &c[i].phone_num, &c[i].address);
            printf("\tChef ID: %d\n",c[i].id);
            printf("\tChef Name: %s\n",c[i].name);
            printf("\tBirth Date: %d.%d.%d\n",c[i].b_day, c[i].b_month, c[i].b_year);
            printf("\tPhone Number: %s\n",c[i].phone_num);
            printf("\tAddress: %s\n",c[i].address);
            printf("\n");
            printf("   ----------------------------------------------------------------------------------------------------------------\n\n");

            i++;
        }
    }

    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

void remove_chef() //For removing chefs
{
    int del_id, count;
    fflush(stdin);
    printf("\tEnter the chef id that you want to remove: ");
    scanf("%d",&del_id);

    chef c[100];
    FILE *fp;
    fp=fopen("chefs.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i = 0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %d %d %d %s %s\n",&c[i].name, &c[i].id, &c[i].b_day, &c[i].b_month, &c[i].b_year, &c[i].phone_num, &c[i].address);
            count++;
            i++;
        }
    }
    fclose(fp);

    fp=fopen("chefs.txt","w");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(c[i].id==del_id)
            {
                flag++;
                continue;
            }

            fprintf(fp,"%s ",c[i].name);
            fprintf(fp,"%d ",c[i].id);
            fprintf(fp,"%d ",c[i].b_day);
            fprintf(fp,"%d ",c[i].b_month);
            fprintf(fp,"%d ",c[i].b_year);
            fprintf(fp,"%s ",c[i].phone_num);
            fprintf(fp,"%s\n",c[i].address);


        }
        if(flag==0){
            Beep(600,500);
            printf("\n\tInvalid Chef ID!!!\n");
        }
        else{
            printf("\n\tChef Account Removed Successfully\n");
        }
    }
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
    fclose(fp);
}

void edit_chef() //For editing chef info
{
    int ed_id;
    fflush(stdin);
    printf("\tEnter the chef id that you want to edit: ");
    scanf("%d",&ed_id);

    chef c[1000];
    FILE *fp;
    int count;

    fp=fopen("chefs.txt","r");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %d %d %d %s %s\n",&c[i].name, &c[i].id, &c[i].b_day, &c[i].b_month, &c[i].b_year, &c[i].phone_num, &c[i].address);
            count++;
            i++;
        }
    }
    fclose(fp);

    fp=fopen("chefs.txt","w");
    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(c[i].id==ed_id)
            {
                flag++;
                fflush(stdin);
                printf("\tChef Name (Replace spaces with hyphens): ");
                gets(c[i].name);
                fprintf(fp,"%s ",c[i].name);

                printf("\tChef ID: ");
                scanf("%d",&c[i].id);
                fprintf(fp,"%d ",c[i].id);

                fflush(stdin);
                printf("\tBirth Day (DD): ");
                scanf("%d", &c[i].b_day);
                fprintf(fp,"%d ",c[i].b_day);

                fflush(stdin);
                printf("\tBirth Month (MM): ");
                scanf("%d", &c[i].b_month);
                fprintf(fp,"%d ",c[i].b_month);

                fflush(stdin);
                printf("\tBirth Year (YYYY): ");
                scanf("%d", &c[i].b_year);
                fprintf(fp,"%d ",c[i].b_year);

                fflush(stdin);
                printf("\tPhone Number: ");
                gets(c[i].phone_num);
                fprintf(fp,"%s ",c[i].phone_num);

                fflush(stdin);
                printf("\tAddress (Replace spaces with hyphens): ");
                gets(c[i].address);
                fprintf(fp,"%s\n",c[i].address);

                continue;
            }

            fprintf(fp,"%s ",c[i].name);
            fprintf(fp,"%d ",c[i].id);
            fprintf(fp,"%d ",c[i].b_day);
            fprintf(fp,"%d ",c[i].b_month);
            fprintf(fp,"%d ",c[i].b_year);
            fprintf(fp,"%s ",c[i].phone_num);
            fprintf(fp,"%s\n",c[i].address);



        }
        if(flag==0)
        {
            Beep(600,500);
            printf("\n\tInvalid Chef ID!!!\n");
        }

        else
        {
            printf("\n\tChef Account Edited Successfully\n");
        }
    }
    fclose(fp);
    fflush(stdin);
    printf("\t(Press Enter)");
    getchar();
}

int adminLogin() //For authenticating the Admin login
{
    char username[15], password[9];

    printf("\n\tEnter username: ");
    scanf("%s",username);
    if((strcmp(username,"Admin"))!=0)
        return 0;
    else
    {
        printf("\tEnter Password: ");
        int i = 0;
        for(i=0;i<8;i++)
        {
            if (i>=8){
                break;
            }
            password[i]=getche();
            printf("\b%c",'*');
            fflush(stdin);
        }
        password[i]='\0';
        if((strcmp(password,"admin223"))!=0)
            return 0;
    }
    return 1;
}

void adminpanel() //For admin window
{
    int choice;
    fflush(stdin);
    printf("\n\tLogged in successfully.(Press enter)");
    getchar();
    while(1){
        admin_header();
        printf("\n\t\t\t1.Add food item\n\t\t\t2.View food items\n\t\t\t3.Delete food item\n\t\t\t4.Edit food item\n\t\t\t5.Add chef record\n\t\t\t6.View chef records\n\t\t\t7.Remove chef record\n\t\t\t8.Edit chef record\n\t\t\t9.View last orders\n\t\t\t0.Logout\n\t\t\t");
            printf("\n\tEnter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 0:
                return;
            case 1:
                admin_header();
                add_food();
                break;
            case 2:
                admin_header();
                printf("\n                                                      *** Menu ***\n\n");
                display_food();
                break;
            case 3:
                admin_header();
                delete_food();
                break;
            case 4:
                admin_header();
                edit_food();
                break;
            case 5:
                admin_header();
                add_chef();
                break;
            case 6:
                admin_header();
                printf("\n                                                      *** Chefs ***\n");
                display_chef();
                break;
            case 7:
                admin_header();
                remove_chef();
                break;
            case 8:
                admin_header();
                edit_chef();
                break;
            case 9:
                admin_header();
                printf("\n                                                     *** Orders ***\n\n");
                display_orders_admin();
                break;
            default:
                printf("\n\tInvalid Choice!!!\n\t(Press enter)");
                fflush(stdin);
                getchar();
            }
    }
}

void customer_panel() //For customer window
{
    int choice;
    while(1){
        customer_header();
        printf("\n\t\t\t1.View food items\n\t\t\t2.Search food\n\t\t\t3.Order food\n\t\t\t4.Cancel order\n\t\t\t0.Main menu\n\t\t\t");
            printf("\n\tEnter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 0:
                return;
            case 1:
                customer_header();
                printf("\n                                                      *** Menu ***\n\n");
                display_food();
                break;
            case 2:
                customer_header();
                search_food();
                break;
            case 3:
                customer_header();
                order_food();
                break;
            case 4:
                customer_header();
                if(cancel_serve_order()){
                    printf("\tOrder Canceled Successfully.\n");
                    fflush(stdin);
                    printf("\t(Press Enter)");
                    getchar();
                }
                break;
            default:
                printf("\n\tInvalid Choice!!!\n\t(Press enter)");
                fflush(stdin);
                getchar();
            }
    }
}

int chefLogin() //For authenticating the Chef login
{
    int count, password=0;
    chef c[100];
    FILE *fp;
    fp=fopen("chefs.txt","r");

    int username;
    char pass;

    printf("\tEnter username: ");
    scanf("%d",&username);

    if(fp==NULL)
    {
        Beep(600,500);
        printf("File Error!!!");
    }
    else
    {
        count=0;
        int i = 0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d %d %d %d %s %s\n",&c[i].name, &c[i].id, &c[i].b_day, &c[i].b_month, &c[i].b_year, &c[i].phone_num, &c[i].address);
            if(username == c[i].id)
            {
                printf("\tEnter Password: ");
                int j = 0;
                for(j=0;j<7;j++)
                {
                    if (j>=7){
                        break;
                    }
                    if(j == 0){
                        pass=getche();
                        password = pass-'0';
                        printf("\b%c",'*');
                    }
                    else{
                        pass=getche();
                        password = (password*10)+(pass-'0');
                        printf("\b%c",'*');
                    }
                }
                if(password==(2230000+c[i].b_year)) {
                        return 1;
                }
                else{
                        return 0;
                }
            }
        }
    }
    fclose(fp);
    printf("\tEnter Password: ");
    int j=0;
    for(j=0;j<7;j++)
    {
        if (j>=7){
            break;
        }
        if(j == 0){
            pass=getche();
            password = pass-'0';
            printf("\b%c",'*');
        }
        else{
            pass=getche();
            password = (password*10)+(pass-'0');
            printf("\b%c",'*');
        }
    }
    return 0;

}

void chef_panel()
{
    int choice;
    fflush(stdin);
    printf("\n\tLogged in successfully.(Press enter)");
    getchar();
    while(1){
        chef_header();
        printf("\n\t\t\t1.View list of orders\n\t\t\t2.Serve orders\n\t\t\t0.Logout\n\t\t\t");
            printf("\n\tEnter your choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 0:
                return;
            case 1:
                chef_header();
                printf("\n                                                    *** Orders ***\n\n");
                display_order_chef();
                break;
            case 2:
                chef_header();
                if(cancel_serve_order()){
                    printf("\tOrder Served Successfully.\n");
                    fflush(stdin);
                    printf("\t(Press Enter)");
                    getchar();
                }
                break;
            default:
                printf("\n\tInvalid Choice!!!\n\t(Press enter)");
                fflush(stdin);
                getchar();
            }
    }
}

int main()
{
    system("color CF");
    int choice;
    while(1){
        printf("\n                                   *************************************************\n");
        printf("                                                WELCOME TO BEEF PALAZZO\n");
        printf("                                   *************************************************\n\n");
        printf("\n\t\t\t1.Admin\n\t\t\t2.Customer\n\t\t\t3.Chef\n\t\t\t0.Exit\n\t\t\t");
        printf("\n\tEnter your choice: ");
        scanf("%d",&choice);

    switch(choice){
        case 0:
            system("cls");
            return 0;
        case 1:
            if (adminLogin()){
                adminpanel();
            }
            else{
                Beep(600,500);
                printf("\n\tWrong username or password.(Press enter)\n");
                fflush(stdin);
                getchar();
            }
            break;
        case 2:
            customer_panel();
            break;
        case 3:
            if (chefLogin()){
                chef_panel();
            }
            else{
                Beep(600,500);
                printf("\n\tWrong chef ID or password.(Press enter)\n");
                fflush(stdin);
                getchar();
            }
            break;
        default:
            printf("\n\tInvalid Choice!!!\n\t(Press enter)");
            fflush(stdin);
            getchar();
    }
    system("cls");
    }
    return 0;
}
