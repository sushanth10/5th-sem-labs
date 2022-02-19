-- creating tables --

create table emp(
    ssn int primary key,
    name varchar(20),
    deptnum int
);

create table proj(
    pno int primary key,
    domain varchar(30),
);

create table works_on(
    ssn int,
    pno int, 
    hours int,
    primary key(ssn, pno),
    foreign key(ssn) references emp(ssn) on delete cascade on update cascade, 
    foreign key(pno) references proj(pno) on delete cascade on update cascade
);

-- inserting data into emp --

insert into emp values(1, 'Harry', 10);

insert into emp values(2, 'Xavier', 20);

insert into emp values(3, 'Hermoine', 10);

insert into emp values(4, 'Ron', 30);

insert into emp values(5, 'Draco', 30);

-- inserting data into proj --

insert into proj values(101, 'Networking');

insert into proj values(102, 'Cloud');

insert into proj values(103, 'Database');

insert into proj values(104, 'Image processing');

insert into proj values(105, 'App Development');

-- inserting data into works_on -- 

insert into works_on values(1, 103, 20);

insert into works_on values(2, 101, 30);

insert into works_on values(3, 104, 24);

insert into works_on values(2, 102, 10);

insert into works_on values(4, 105, 32);


-- SQL Queries --

-- 1. Obtain the SSN of employees assigned to database projects.

select e.* from emp e natural join works_on w natural join proj p where p.domain = 'Database';

--2--

select count(ssn), deptnum from emp group by deptnum;

--3--

update works_on 
    set pno=104
    where ssn = 4;
