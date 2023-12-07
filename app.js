require("dotenv").config();
const express = require("express");
const path = require("path");
const mongoose = require("mongoose");
const cookieParser = require("cookie-parser");
const { checkForAuthenticationCookie } = require("./middlewares/auth");



 const Blog = require("./models/blog")

 const userRoute = require("./routes/user");
 const blogRoute = require("./routes/blog");

const app = express();
const port = process.env.PORT || 8000;

 //mongoDB connection
 mongoose.connect(process.env.MONGO_URL)
 .then((e) => console.log("MongoDB connected!!!"));

app.set("view engine","ejs");
app.set("views",path.resolve("./views"));

//middleware
 app.use(express.urlencoded({ extended: false }));
 app.use(cookieParser());
 app.use(checkForAuthenticationCookie("token"));
 app.use(express.static(path.resolve("./public")))

app.get("/",async(req,res) =>{
	const allBlogs = await Blog.find({});
  res.render("home",{
        user: req.user,
        blogs: allBlogs,
  });
})

app.use("/user",userRoute);
app.use("/blog",blogRoute);


app.listen(port,() => console.log("Server is running on port: ",port));


