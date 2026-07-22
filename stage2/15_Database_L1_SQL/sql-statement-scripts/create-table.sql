

if NOT EXISTS (select * FROM sys.databases where name = N'DB1')
BEGIN
	create database DB1;
END

USE DB1;
GO


create table Employees(
	ID int NOT NULL, 
	Name nvarchar(50) NOT NULL, 
	Phone nvarchar(11) NULL,
	salary smallmoney NULL,
	PRIMARY  KEY (ID)
	)