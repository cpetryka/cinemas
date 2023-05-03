# CINEMAS
**Author: Cezary Petryka**

**This is an application that allows the management of cinemas.**

**Requirements:**
- Data about cinemas, films, screenings, etc. are retrieved into the database from JSON files.
- CRUD operations for all database tables are provided.
- The application allows the management of films and screenings.
- The application allows user accounts to be managed (password change, etc.).
- The application allows the purchase and reservation of tickets.
- Periodically unpaid tickets are automatically deleted.

**How the application works:**
1. The user enters a specific query (e.g. AKCJA,WARSZAWA,2020-11-10,14), and the application searches and displays matching screenings.
2. The user selects the desired screening.
3. The information about seats is displayed and the user selects the desired seats.
4. The user decides whether to buy tickets or just reserve them (the user has a set time to pay for the reserved tickets, if not, they are automatically cancelled).
5. After reserving/buying tickets:
   - The total price for the order is displayed
   - An email is sent to the user
   - A unique id is displayed so that the user can cancel or pay for the order.