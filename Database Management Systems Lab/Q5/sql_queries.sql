-- creating tables

create table books(
    isbn number(10) primary key,
    title varchar(10),
    author varchar(20),
    publisher varchar(20)
);

create table student(
    usn varchar(10) primary key,
    name varchar(20),
    gender char(2),
    sem int,
    dept varchar(3)
);

create table borrows(
    isbn number(10),
    usn varchar(10),
    dates varchar(10),
    foreign key(isbn) references books(isbn),
    foreign key(usn) references student(usn)
);

-- inserting records into books 

insert into books values(123, 'MC','A1','P1');

insert into books values(002, 'ML','A2','P2');

insert into books values(003, 'AI','A3','P3');

insert into books values(004, 'CC','A4','P4');

insert into books values(124, 'DB','A5','P5');

-- inserting records into student 

insert into student values('101','Mohan','M', 3, 'ISE');

insert into student values('202','Suhani','F', 5, 'ISE');

insert into student values('104','Soham','M', 3, 'ISE');

insert into student values('201','Maazraan', 'M', 5, 'CSE');

-- inserting records into borrows 

insert into borrows values(123, '202', '24-12-2021');

insert into borrows values(124, '104', '13-12-2021');

insert into borrows values(004, '104', '23-12-2021');

insert into borrows values(004, '202', '24-12-2021');

insert into borrows values(003, '201', '27-12-2021');

insert into borrows values(002, '101', '01-12-2021');

insert into borrows values(124, '202', '14-01-2022');

-- displaying details once
select * from student;

select * from books;

select * from borrows;

-- SQL Queries 

-- 1
select name from books bk, borrows br, student s where bk.isbn=br.isbn and s.usn=br.usn and (br.isbn=124 or br.isbn=123);

-- 2
select name from books bk, borrows br, student s where bk.isbn=br.isbn and s.usn=br.usn and s.gender='F' and bk.title='DB';

-- 3
select s.*, count(bk.isbn) from books bk, borrows br, student s where bk.isbn=br.isbn and s.usn=br.usn group by s.name, s.gender, s.usn, s.sem, s.dept;