

-- RESTORE DATABASE SHOP_Database
-- FROM DISK = 'E:\general_courses\programming-advices\stage2\15_Database_L1_SQL\DataSets\Shop_Database.bak'

SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM     Customers INNER JOIN
                  Orders ON Customers.CustomerID = Orders.CustomerID;

---------------------------------


