const mysql = require("mysql2");

const connection = mysql.createConnection({
  host: "127.0.0.1",    
  user: "root",
  password: "",          
  database: "library",
  port: 3306
});

connection.connect(error => {
  if (error) {
    console.log("Database connection failed:", error);
  } else {
    console.log("Connected to MySQL");
  }
});

module.exports = connection;
