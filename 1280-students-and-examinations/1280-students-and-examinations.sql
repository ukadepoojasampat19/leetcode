WITH StudentSubject AS (
    SELECT
        s.student_id,
        s.student_name,
        sub.subject_name
    FROM
        Students s
        CROSS JOIN Subjects sub
)

SELECT
    SS.student_id,
    SS.student_name,
    SS.subject_name,
    COUNT(E.subject_name) AS attended_exams
FROM
    StudentSubject SS
    LEFT JOIN Examinations E ON SS.student_id = E.student_id AND SS.subject_name = E.subject_name
GROUP BY
    SS.student_id, SS.student_name, SS.subject_name
ORDER BY
    SS.student_id, SS.subject_name;
