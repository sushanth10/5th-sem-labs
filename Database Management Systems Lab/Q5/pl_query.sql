-- set serveroutput on 
declare
    a number;
    b number;
    c number;
    n number;
    j number;
begin
    a := 0;
    b := 1;
    n := 8;
    c := 1;
    dbms_output.put_line(a);
    dbms_output.put_line(b);
    for j in 1..n-2 loop
        c:= a+b;
        a :=b;
        b:=c;
        dbms_output.put_line(c);
    end loop;
end;