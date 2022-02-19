# Exercise-I
Consider an Employee with a social security number (SSN) working on multiple projects with
definite hours for each. Each Employee belongs to a Department. Each project is associated
with some domain areas such as Database, Cloud and so on. Each Employee will be assigned
to some project. Assume the attributes for Employee and Project relations.

a) Mention the constraints neatly.

b) Design the ER diagram for the problem statement

c) State the schema diagram for the ER diagram.

d) Create the tables, insert suitable tuples and perform the following operations in

SQL

 1. Obtain the SSN of employees assigned to database projects.

 2. Find the number of employees working in each department.

 3. Update the Project details of Employee bearing SSN = #SSN to ProjectNo = #Project_No

e) Create the table, insert suitable tuples and perform the following operations using MongoDB

 1. List all the employees of Department named #Dept_name.

 2. Name the employees working on Project Number :#Project_No

f) Write a program that gives all employees in Department #number a 15% pay increase. Display a message displaying how many employees were awarded the
increase.

# Exercise-II
Consider the relations: PART, SUPPLIER and SUPPLY. The Supplier relation holds information
about suppliers. The SID attribute identifies the supplier, while the other attributes each
hold one piece of information about the supplier. The Part relation holds information about
parts. Likewise, the PID attribute identifies the part, while the other attributes hold
information about the part. The Shipment relation holds information about shipments. The
SID and PID attributes identify the supplier of the shipment and the part shipped,
respectively. The remaining attribute indicates how many parts where shipped.

a) Mention the constraints neatly.

b) Design the ER diagram for the problem statement

c) State the schema diagram for the ER diagram.

d) Create the above tables, insert suitable tuples and perform the following operations
in Oracle SQL:
 
 1. Obtain the part identifiers of parts supplied by supplier #supplier_name.
 
 2. Obtain the Names of suppliers who supply #part_name.
 
 3. Delete the parts which are in #colour.
 
e) Create the table, insert suitable tuples and perform the following operations using MongoDB
 
 1. Update the parts identifier
 
 2. Display all suppliers who supply the part with part identifier: #Part_No.

g) Write a PL/SQL program to display the contents of the above tables and then
update the quantity of parts shipped by 5%. 


# Exercise-III
Consider the relations BOAT, SAILOR and RESERVES. The relation BOAT identifies the features
of a boat such as unique identifier, color and a name. The list of sailors with attributes such as SailorID,
name, age etc., are stored in the relation SAILOR. The sailors are allowed to reserve any number of
boats on any day of the week and the records are to be updated in the RESERVES table.
a) Mention the constraints neatly.
b) Design the ER diagram for the problem statement

c) State the schema diagram for the ER diagram.

d) Create the tables, insert suitable tuples and perform the following operations in SQL:
 
 1. Obtain the details of the boats reserved by ‘#Sailor_Name’.
 
 2. Retrieve the BID of the boats reserved necessarily by all the sailors.
 
 3. Find the number of boats reserved by each sailor. Display the Sailor_Name along with the number of boats reserved.

e) Create the table, insert suitable tuples and perform the following operations using MongoDB.
 
 1. Obtain the number of boats obtained by sailor :#Sailor_Name
 
 2. Retrieve boats of color :”#color”

f) Write a PL/SQL program to check whether a given number is prime or not.


# Exercise-IV
Consider the Banking database – CUSTOMER, BRANCH, ACCOUNT and TRANSACTION. An account can be a savings account or a current account. Customer can have both types of accounts. The transactions can be a deposit or a withdrawal. Mention the constraints neatly.

a) Design the ER diagram for the problem statement

b) State the schema diagram for the ER diagram.

c) Create the above tables, insert suitable tuples and perform the following operations in SQL:

 1. Obtain the details of customers who have both Savings and Current Account.

 2. Retrieve the details of branches and the number of accounts in each branch.

 3. Obtain the details of customers who have performed at least 3 transactions.

 4. List the details of branches where the number of accounts is less than the average number of accounts in all branches.

d) Create the table, insert suitable tuples and perform the following operations using MongoDB

1. Find the branch name for a given Branch_ID.

2. List the total number of accounts for each customer.

e) Using cursors demonstrate the process of copying the contents of one table to a new table.

# Exercise-V
Consider the Book Lending system from the library- BOOKS, STUDENT,BORROWS. The students are allowed to borrow any number of books on a given date from the library. The details of the book should include ISBN, Title of the Book, author and publisher. All students need not compulsorily borrow books.

a) Mention the constraints neatly.

b) Design the ER diagram for the problem statement

c) State the schema diagram for the ER diagram.

d)Create the above tables, insert suitable tuples and perform the following operations in
SQL:

 1. Obtain the names of the student who has borrowed either book bearing ISBN
‘123’ or ISBN ‘124’.

 2. Obtain the Names of female students who have borrowed “Database” books.

 3. Find the number of books borrowed by each student. Display the student details along with the number of books.

e) Create the table, insert suitable tuples and perform the following operations using
MongoDB
 
 1. Obtain the book details authored by “author_name”.
 
 2. Obtain the Names of students who have borrowed “Database” books.

f) Write a PL/SQL procedure to print the first 8 Fibonacci numbers and a program to call the same.