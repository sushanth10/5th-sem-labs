set serveroutput on

begin
    update emp
    set salary=1.15*salary where deptno=10;
    dbms_output.put_line("Number of rows updated : "||sql%rowcount);
end;