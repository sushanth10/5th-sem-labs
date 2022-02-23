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

g) Write a PL/SQL program to copy the contents of the Shipment table to another table
 for maintaining records for specific part number. 
