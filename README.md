# Grocery Store System

This C++ program simulates a grocery store system. It implements various functionalities and features for admins, managers, and customers.

## Features

- **Login System:** Users can log in as admins, managers, or customers, each with their respective functionalities and access levels.
- **Registration:** Admins can register managers, and customers can register using their credentials.
- **Managing Inventory:** Managers can add, update, and delete items from the store's inventory.
- **Product Catalog:** Admins can manage the product catalog, including adding, updating, and deleting products.
- **Online Shopping:** Customers can browse items, add them to the cart, and proceed to payment.
- **Feedback System:** Customers can provide feedback after checkout, which is reflected across all stores.
- **Payment Options:** Different payment methods are available for customers, including Cash on Delivery, Credit Card, and Online Wallets.

## File Structure

The program utilizes multiple files/classes to manage data:
- **grocery_store.h**: Header file containing the main functionalities of the grocery store.
- **user.h, admin.h, manager.h, customer.h**: Classes defining different user types and their functionalities.
- **product_catalog.h**: Class handling the product catalog management.
- **stores and inventory.h**: Classes managing stores and their respective inventories.
- **online_shopping.h**: Class for handling online shopping functionalities.
- **Feedback.h**: Class managing the feedback system.
- **Payment.h**: Class defining payment methods and transactions.
- **Binary File Handling**: Utilizes binary file handling for data storage and retrieval.

## How to Use

1. **Compilation**: Compile the source code using any compatible C++ compiler.
2. **Execution**: Run the compiled program.
3. **Navigation**: Follow on-screen instructions to navigate through different menus and functionalities.
4. **Interacting with the System**: Perform actions like login, registration, managing inventory, shopping, giving feedback, and making payments.

## Notes

- The system uses binary file handling for storing and retrieving data.
- Ensure proper inputs are provided for different functionalities to avoid errors.
