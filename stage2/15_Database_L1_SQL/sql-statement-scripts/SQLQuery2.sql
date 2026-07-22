SELECT
    DB_NAME() AS DatabaseName,
    name AS LogicalFileName,
    physical_name AS PhysicalFilePath
FROM sys.master_files
WHERE database_id = DB_ID('DB1');