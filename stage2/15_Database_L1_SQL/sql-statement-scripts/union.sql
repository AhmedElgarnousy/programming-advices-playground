select ID, FirstName from ActiveEmps
union
select ID, FirstName from RetiredEmps

--this will remove the redundancy from the resultset (distinct results only)
select * from Departments
union 
select * from Departments;

--this will append data regardeless of any redundancy
select * from Departments
union ALL
select * from Departments;

-- same # of colums, same data types, same order

select ID from Employees
union
select ID_Person from Persons;

Create Table Persons(
ID_Person   INT   NOT NULL
);
insert into Persons
values
(100);

drop table Persons;





