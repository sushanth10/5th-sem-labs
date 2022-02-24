-- creating tables --

create table boat(
    bid varchar(5) primary key,
    bname varchar(20),
    color varchar(20)
);  

create table sailor(
    sid varchar(5) primary key,
    sname varchar(20),
    age number(6)
);

create table reserves(
    bid varchar(5),
    sid varchar(5),
    day varchar(10),
    foreign key(bid) references boat(bid) on delete cascade,
    foreign key(sid) references sailor(sid) on delete cascade
);

-- inserting records into boat --

insert into boat values('01','ABC', 'Red');

insert into boat values('02','XYZ', 'Yellow');

insert into boat values('03','LMN', 'Blue');

insert into boat values('04','DEF', 'Black');

-- inserting records into sailor 

insert into sailor values('10', 'Ram', 25);

insert into sailor values('20','Shyam', 40);

insert into sailor values('30', 'Mohan',53);

insert into sailor values('40','Rohan', 34);

-- inserting records into reserves table 

insert into reserves values('01','10','Thursday');

insert into reserves values('02','30','Monday');

insert into reserves values('03','20','Tuesday');

insert into reserves values('02','10','Friday');

insert into reserves values('02','20','Sunday');

insert into reserves values('02','40','Wednesday');

-- displaying records

select * from boat;

select * from sailor;

select * from reserves;

-- SQL Queries

-- 1
select b.bid from boat b, reserves r, sailor s where b.bid=r.bid and s.sid=r.sid and sname='Ram';

-- 2
select b.bid from boat b, reserves r where b.bid=r.bid
    group by b.bid having count(distinct(r.sid))=(select count(sid) from sailor);

-- 3
select s.*, count(r.bid) from boat b, reserves r, sailor s where b.bid=r.bid and s.sid=r.sid group by s.sid, s.sname, s.age;