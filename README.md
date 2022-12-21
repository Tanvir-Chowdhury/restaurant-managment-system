Project: Restaurant Management System

Introduction: Our project is called Restaurant Management System, and we titled the restaurant "Beef Palazzo". The system allows the administrator to manage foods and chefs, customers to order meals and cancel orders, and chefs to see and serve orders. This system stores all the data in text files using the file handling concept.
The project has 3 main parts. These are “Admin Window”, “Customer Window” and “Chef Window”

Methodology and uses: We used twenty-one functions for this restaurant management system. Which are:
1. Admin Window
    int adminLogin();
    void adminpanel();
    void admin_header(); [For printing the header in the admin window]
    void add_food();
    void display_food();
    void delete_food();
    void edit_food();
    void display_orders_admin(); [For displaying the list of orders in the admin window]
    void add_chef();
    void display_chef(); [For displaying chef records in the admin window]
    void remove_chef();
    void edit_chef();
2. Customer Window
    void customer_panel();
    void customer_header(); [For printing the header in the customer window]
    void display_food(); [The same function is used in the admin window]
    void search_food();
    void order_food();
    int cancel_serve_order(); [For canceling the order]
3. Chef Window
    int chefLogin();
    void chef_panel();
    void chef_header(); [For printing the header in the chef window]
    void display_order_chef(); [For displaying the list of orders in the chef window]
    int cancel_serve_order(); [For serving the order. The same function is used in the customer window]
    
In the main() function a switch case has been used to create a menu. Users can choose options between 0 to 3. If the option is outside of 0 to 3, the program won’t be continued by printing an invalid choice message and redirected to the main() function.
By pressing 0, the program will be terminated. By pressing 1 the window will ask for the admin login info. By entering the username “Admin” and the password “admin223”, the admin can enter the admin window where they will get another 10 options:
  1. Add food item [Admin can add food item by this function by entering name, ID, ingredients, price, discount, and vat]
  2. View food items [Admin can view the food menu by this function]
  3. Delete food item [Admin can delete a food item by entering the food ID by this function]
  4. Edit food item [Admin can edit a food item by entering food ID by this function]
  5. Add chef record [Admin can add chef record by entering name, ID, birthday, birth month, birth year, phone number, and address by this function]
  6. View chef records [Admin can view the list of chef records by this function]
  7. Remove chef record [Admin can remove a chef record by entering the chef ID by this function]
  8. Edit chef record [Admin can edit a chef record by entering the chef ID by this function]
  9. View last orders [Admin can view the list of ongoing orders]
  0. Logout [The code will be redirected to the main function] [Here 10 means 0]
      
By pressing 2 in the main menu, the customer can enter into the customer window where they will get another 5 options:
  1. View food items [Customer can view the food menu by this function]
  2. Search food [Customer can search a food item by entering the food name by this function]
  3. Order food [Customer can order food items by entering the name, phone number, email, and food IDs]
  4. Cancel order [Customer can cancel the order by entering the order ID]
  0. Main menu [The code will be redirected to the main function][Here 5 means 0]
  
By pressing 3, the window will ask for the chef login info. By entering the username which is the Chef ID and the password 223(birth year), the chef can enter the chef window where they will get another 3 options:
  1. View list of orders [Chef can view the list of ongoing orders]
  2. Serve order [Chef can serve an order by entering the order ID]
  0. Logout [The code will be redirected to the main function][Here 3 means 0]
     
Conclusion: We have more plans for this restaurant management system project further in the future as the code is not that perfect. We are planning to create a signup system for the customers. The chef’s records are also limited. We are planning to expand the code as well. That is all from group A in this restaurant management System Project.
THANK YOU
