# Write your MySQL query statement below
SELECT DISTINCT(author_id) AS id from Views # DISTINCT 처음에 안 함
WHERE author_id = viewer_id # 이게 자기꺼 봤다는 거겠징?!
ORDER BY author_id # 처음에 안 함