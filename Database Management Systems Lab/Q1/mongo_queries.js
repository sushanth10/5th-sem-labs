db.createCollection("Employee");

db.Employee.insert({'ssn':1, 'name':'James', 'deptnum':10, 'deptname':'it services', 'pno':101, 'domain':'database'});


db.Employee.insert({'ssn':2, 'name':'Nancy', 'deptnum':20, 'deptname':'R&D', 'pno':103, 'domain':'cloud'});


db.Employee.insert({'ssn':3, 'name':'Anil', 'deptnum':30,'deptname':'application development', 'pno':104, 'domain':'machine learning'});

// displaying the details once 
db.Employee.find().pretty()

// Queries 

// 1
db.Employee.find({'deptname':'it services'}).pretty()

// 2

db.Employee.find({'pno':104}).pretty()