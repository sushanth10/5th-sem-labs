declare 
    n number;
    j number;
    flag number;
begin 
    flag := 0;
    n := &n;
    for j in 2..n/2 loop
    if mod(n,j)=0 then 
        dbms_output.put_line(n||' is not a prime number');
        flag :=1;
        exit;
    end if;
    end loop;

    if flag=0 then
        dbms_output.put_line(n||' is a prime number');
    end if;
end;