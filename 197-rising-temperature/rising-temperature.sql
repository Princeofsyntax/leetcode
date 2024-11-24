# Write your MySQL query statement below
SELECT 
    w1.id
FROM 
    Weather w1
INNER JOIN
    weather w2
WHERE 
    DATEDIFF(w1.recordDate ,w2.recordDate ) = 1 AND w1.temperature > w2.temperature
# DATEDIFF provides the difference between two dates in days