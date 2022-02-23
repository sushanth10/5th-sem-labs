 -- before running program create a duplicate table with the same datatypes --

set serveroutput on
declare
    cursor p is select * from part;
    counter int;
    prow part%rowtype;
begin
    open p;
    loop
    fetch p into prow;
    exit when p%notfound;
    insert into part1 values(prow.pid, prow.pname, prow.color);
    end loop;
    counter := p%rowcount;
    dbms_output.put_line('Number of rows inserted into part1 : '||counter);
    close p;
end;
