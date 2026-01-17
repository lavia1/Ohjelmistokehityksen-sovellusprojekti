const express = require("express");
const cors = require("cors");
const db = require("./db");

const app = express();
app.use(cors());
app.use(express.json());


// Kirjojen CRUD-operaatiot
// CREATE
app.post("/books", (req, res) => {
  const { name, author, isbn } = req.body;
  const sql = "INSERT INTO book (name, author, isbn) VALUES (?, ?, ?)";
  db.query(sql, [name, author, isbn], (err, result) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Book added", id: result.insertId });
  });
});

// READ / GET
app.get("/books", (req, res) => {
  db.query("SELECT * FROM book", (err, rows) => {
    if (err) res.status(500).json(err);
    else res.json(rows);
  });
});

// UPDATE
app.put("/books/:id", (req, res) => {
  const { name, author, isbn } = req.body;
  const id = req.params.id;
  const sql = "UPDATE book SET name=?, author=?, isbn=? WHERE id_book=?";
  db.query(sql, [name, author, isbn, id], (err) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Book updated" });
  });
});

// DELETE
app.delete("/books/:id", (req, res) => {
  const id = req.params.id;
  db.query("DELETE FROM book WHERE id_book=?", [id], (err) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Book deleted" });
  });
});

app.listen(3000, () => {
  console.log("Server running on port 3000");
});
