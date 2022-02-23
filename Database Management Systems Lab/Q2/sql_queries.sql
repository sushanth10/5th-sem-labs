-- THESE ARE QUERIES IN ORACLESQL ITSELF
-- creating tables --

create table part(
    pid number(10) primary key,
    pname varchar(20),
    color varchar(20)
);

create table supplier(
    sid number(10) primary key,
    sname varchar(20),
    location varchar(20)
);

create table supply(
    pid number(10),
    sid number(10),
    qty number(10),
    primary key(pid,sid), 
    foreign key(pid) references part(pid) on delete cascade,
    foreign key(sid) references supplier(sid) on delete cascade
);


-- inserting records into part --

insert into part values(1, 'bolt', 'red');

insert into part values(2, 'nut', 'blue');

insert into part values(3, 'screw', 'black');

insert into part values(4, 'plug', 'green');

-- inserting records into supplier --

insert into supplier values(10, 'rohan', 'bengaluru');

insert into supplier values(20, 'gyan', 'mumbai');

insert into supplier values(30, 'gautam', 'delhi');

insert into supplier values(40, 'jay', 'kolkata');

-- inserting records into supply --

insert into supply values(1, 20, 250);

insert into supply values(2, 30, 20);

insert into supply values(3, 10, 100);

insert into supply values(4, 20, 25);

insert into supply values(1, 40, 50);

-- displaying records once --

select * from part;

select * from supplier;

select * from supply;


-- SQL Queries --
-- 1 --
select p.pid from part p, supply su, supplier s where p.pid=su.pid and su.sid=s.sid and s.sname='gyan';

-- 2 --
select sname from supplier, part, supply where supplier.sid=supply.sid and part.pid=supply.pid and pname='bolt';

-- 3 --
delete from part where color='black';