select DepartmentID, TotalCount=Count(MonthlySalary), 
	   TotalSum=Sum(MonthlySalary),
	   Average=Avg(MonthlySalary),
	   MinSalary=Min(MonthlySalary),
	   MaxSalary=Max(MonthlySalary) 
	   
	   from Employees
       Group By DepartmentID
	  having Count(MonthlySalary) > 100

select 
TotalCount = Count(MonthlySalary),
TotalSUm = sum(MonthlySalary) ,
TotalAvg = Avg(MonthlySalary) ,
AvgSalary = Min(MonthlySalary) ,
Maxsalaey = Max(MonthlySalary)

from Employees where DepartmentID = 1;

select  TotalCount = Count(MonthlySalary),
	TotalSUm = sum(MonthlySalary) ,
	TotalAvg = Avg(MonthlySalary) ,
	AvgSalary = Min(MonthlySalary) ,
	Maxsalaey = Max(MonthlySalary)
from Employees
GROUP BY DepartmentID
having Count(MonthlySalary) > 100;

-- we can use where statement with indirect way

select * from (
select  TotalCount = Count(MonthlySalary),
	TotalSUm = sum(MonthlySalary) ,
	TotalAvg = Avg(MonthlySalary) ,
	AvgSalary = Min(MonthlySalary) ,
	Maxsalaey = Max(MonthlySalary)
from Employees
GROUP BY DepartmentID
) R1
where R1.TotalCount > 100;



