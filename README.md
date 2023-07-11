# CINEMAS
**Author: Cezary Petryka**

**This is an application for managing cinema infrastructure (rooms, films, screenings, etc.).**

## How the application works
When the application is run for the first time, sample data about cinemas, films, screenings etc. are loaded from a JSON file. They are stored in a database (sqlite was used). Additional safeguards have been applied so that data in the database is not overwritten during future program executions. Each time, however, we check for new data in the JSON files and add it to the database if necessary.

CRUD operations are provided for all tables so that we can easily manage the data in the database.

Once the data has been loaded, a menu is displayed in which the user can select the screening search parameters (film genre, location of the cinema, date and time of the screening).

After selecting these parameters, screenings meeting the criteria are displayed, the user selects the screening he/she is interested in and then chooses the seats he/she wants to sit in (it is possible to select more than one seat).

Another decision the user has to make is whether to reserve or pay for the selected seats. The app analyses the status of reserved tickets every 15 minutes and cancels those reserved for screenings that start in less than half an hour.

Once the booking/purchase has been made, information on the total amount of the order and a unique order number is displayed so that the customer can pay for their order.

## Customer's account management
**The customer is able to manage their account, including:**
- changing their password
- viewing purchased tickets