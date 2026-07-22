CREATE Database DB_Practice;

USE DB_Practice

CREATE TABLE Persons(
	ID			INT            NOT NULL  ,
	FirstName   nvarchar(30)   NOT NULL  ,
	LastName    nvarchar(30)   NOT NULL ,
	City        nvarchar(30)   DEFAULT 'Cairo' 
);

ALTER TABLE Persons
ADD UNIQUE (LastName);

CREATE TABLE Orders(
	ID			 INT NOT NULL,
	orderNumber  INT NOT NULL,
	orderDate    date NULL, 
);


ALTER TABLE Orders
ADD CONSTRAINT de_orderDate
DEFAULT getdate() for orderDate;

select * from Orders;