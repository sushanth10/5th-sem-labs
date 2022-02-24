-- creating table --

create table branch(
    bid number(10) primary key,
    bname varchar(20),
    loc varchar(20)
);

create table customer(
    cid number(10) primary key,
    name varchar(20), 
    city varchar(20),
    phone number(20)
);

create table account(
    aid number(15) primary key,
    cid number(10),
    bid number(10),
    balance number(10),
    atype varchar(2),
    foreign key(cid) references customer(cid) on delete cascade,
    foreign key(bid) references branch(bid) on delete cascade
);

create table transaction(
    tid number(10) primary key,
    aid number(10),
    amt number(10),
    ttype varchar(2),
    foreign key(aid) references account(aid) on delete cascade
);

-- inserting record into branch 
insert into branch values(1,'BOI','BLR');

insert into branch values(2, 'HDFC','MUM');

insert into branch values(3, 'ICICI','BLR');

-- inserting records into customer 
insert into customer values(10, 'abc', 'MUM', 11223);

insert into customer values(20, 'def', 'BLR', 5564);

insert into customer values(30, 'ghi', 'CAN', 13584);

insert into customer values(40, 'jkl', 'BLR', 56876);

-- inserting records into account

insert into account values(1234, 10, 2, )

-- HAHA I ABANDONED IT COZ EXAM OVER NOW --