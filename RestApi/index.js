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
    else res.json({ message: "Kirja lisätty", id: result.insertId });
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
    else res.json({ message: "Kirja päivitetty" });
  });
});

// DELETE
app.delete("/books/:id", (req, res) => {
  const id = req.params.id;
  db.query("DELETE FROM book WHERE id_book=?", [id], (err) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Kirja poistettu" });
  });
});

// Autojen CRUD-operaatiot
// CREATE
app.post("/cars", (req, res) => {
  const { branch, model } = req.body;
  const sql = "INSERT INTO car (branch, model) VALUES (?, ?)";
  db.query(sql, [branch, model], (err, result) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Auto lisätty", id: result.insertId });
  });
});

// READ / GET
app.get("/cars", (req, res) => {
  db.query("SELECT * FROM car", (err, rows) => {
    if (err) res.status(500).json(err);
    else res.json(rows);
  });
});

// UPDATE
app.put("/cars/:id", (req, res) => {
  const { branch, model } = req.body;
  const id = req.params.id;
  const sql = "UPDATE car SET branch=?, model=? WHERE id_car=?";
  db.query(sql, [branch, model, id], (err) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Auto päivitetty" });
  });
});

// DELETE
app.delete("/cars/:id", (req, res) => {
  const id = req.params.id;
  db.query("DELETE FROM car WHERE id_car=?", [id], (err) => {
    if (err) res.status(500).json(err);
    else res.json({ message: "Auto poistettu" });
  });
});

app.listen(3000, () => {
  console.log("Server running on port 3000");
});
