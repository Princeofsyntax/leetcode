# Write your MySQL query statement below
# We will us REGEXP 
SELECT *
FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_\.\-]*@leetcode[.]com$' 
# A-Za-z => means A to Z as well as a to z are allowed, ^ is for start, $ to end and * to connect 