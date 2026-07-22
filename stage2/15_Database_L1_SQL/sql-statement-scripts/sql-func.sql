select MaxSalary = MAX(MonthlySalary) from Employees;



select 
TotalCount = Count(MonthlySalary),
TotalSUm = sum(MonthlySalary) ,
TotalAvg = Avg(MonthlySalary) ,
AvgSalary = Min(MonthlySalary) ,
Maxsalaey = Max(MonthlySalary)

from Employees;

select 
TotalCount = Count(MonthlySalary),
TotalSUm = sum(MonthlySalary) ,
TotalAvg = Avg(MonthlySalary) ,
AvgSalary = Min(MonthlySalary) ,
Maxsalaey = Max(MonthlySalary)

from Employees where DepartmentID = 1;