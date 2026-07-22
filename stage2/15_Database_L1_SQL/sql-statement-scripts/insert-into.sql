---DROP Table Employees, TEST_TABLE;

select * from Employees;

--- DDL - Data Defintion Language
IF NOT EXISTS (select * from sys.databases where name = 'Employees')
BEGIN
	CREATE TABLE Employees(
	ID int NOT NULL,
	Name nvarchar(20) Not NULL,
	Phone  nvarchar(11) NULL,
	Salary smallmoney NULL,
	);
END

ALTER TABLE Employees ADD PRIMARY KEY (ID);

--- insert one record at a time
insert into Employees  values (1, 'Emp1', '01551442559', 1000);

--- insert multiple records at a time
insert into Employees 
values 
(3, 'Emp3', '01010101000', 400),
(4, 'Emp4', '01010101000', 400),
(5, 'Emp5', '01010101000', 400);

--- insert only selected fields
insert into Employees (ID,Name)
values
(6, 'Emp6')

--DELETE from Employees where name = 'Emp2'

--- delete all data into table
-- delete from employees
-- delete from employees where name = 'Emp6'

--- SQLi Auth- classic payload
select * from Employees where ID = ''OR 1=1--'
---select * from Employees where name = 'admin" or "1"="1'

SELECT table_name FROM information_schema.tables;
