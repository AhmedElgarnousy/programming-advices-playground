SELECT * FROM Employees;

SELECT * FROM oldEmployees;

insert into oldEmployees 
select * from Employees
where salary >=1000

-- delete oldEmployees;


