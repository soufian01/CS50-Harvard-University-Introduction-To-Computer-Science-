SELECT title FROM movies JOIN stars, people
ON movies.id = stars.movie_id
AND stars.person_id = people.id
name = "Johnny Depp" AND movies.title
IN (SELECT movies.title FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id WHERE name = "Helena Bonham Carter");
