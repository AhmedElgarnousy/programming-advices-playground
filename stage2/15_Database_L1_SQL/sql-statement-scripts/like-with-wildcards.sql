
--Execute these satatements to update data
Update Employees 
set FirstName ='Mohammed' , LastName='Abu-Hadhoud'
where ID= 285;

Update Employees 
set FirstName ='Mohammad' , LastName='Maher'
where ID= 286;

insert into Employees 
(FirstName, LastName, Gendor, DateOfBirth, CountryID, DepartmentID, HireDate, MonthlySalary) 
values ('Ahmed', 'Kamal','M', '1972-09-20 00:00:00',1, 1, '2022-02-05 00:00:00', '1000')


select * from Employees
where FirstName like 'Mohamm[ae]d'


select FirstName from Employees
where FirstName like 'a%' or  FirstName like 'b%' or  FirstName like 'c%'
order by FirstName asc

select FirstName from Employees
where FirstName 
in ('a%', 'b%', 'c%')
order by FirstName asc


--------------------

select ID, FirstName, LastName from Employees
Where firstName like 'a%' or firstName like 'b%' or firstName like 'c%';


-- search for all employees that their first name start with a or b or c
select ID, FirstName, LastName from Employees
Where firstName like '[abc]%';


---------------------------------
-- search for all employees that their first name start with any letter from a to l
select ID, FirstName, LastName from Employees
Where firstName like '[a-l]%';
---------------------------------

-- reads as the first character must be anything EXCEPT a–l, followed by anything.

select ID, FirstName, LastName from Employees
Where firstName NOT like '[a-l]%';

select ID, FirstName, LastName from Employees
Where firstName like '[^a-l]%';