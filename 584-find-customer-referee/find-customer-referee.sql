# Write your MySQL query statement below
SELECT name 
FROM Customer
-- WHERE referee_id != 2 OR referee_id IS NULL; // --> will also work
WHERE 
    IFNULL(referee_id, 0) <> 2; # means change refree_id to 0 where it is null (by default sql do not take null as output so these are required)
    
